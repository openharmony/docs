# @ohos.filemanagement.userFileManager (用户数据管理)(系统接口)

该模块提供用户数据管理能力：包括访问、修改用户公共媒体数据信息等常用功能。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块为系统接口。

## 导入模块

```ts
import userFileManager from '@ohos.filemanagement.userFileManager';
```

## userFileManager.getUserFileMgr

getUserFileMgr(context: Context): UserFileManager

获取用户数据管理模块的实例，用于访问和修改用户公共媒体数据信息（如音频、视频、图片、文档等）。

**模型约束**： 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-app-context.md) | 是   | 传入Ability实例的Context。 |

**返回值：**

| 类型                            | 说明    |
| ----------------------------- | :---- |
| [UserFileManager](#userfilemanager) | 媒体库实例。 |

**示例：**

```ts
// 此处获取的userFileManager实例mgr为全局对象，后续使用到mgr的地方默认为使用此处获取的对象，如未添加此段代码报mgr未定义的错误请自行添加
// 请在组件内获取context，确保this.getUiContext().getHostContext()返回结果为UIAbilityContext
import { common } from '@kit.AbilityKit';
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let mgr = userFileManager.getUserFileMgr(context);
```

## UserFileManager

### getPhotoAssets

getPhotoAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void

获取图片和视频资源，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](#fetchoptions)        | 是   | 图片和视频检索选项。              |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | 是   | callback返回图片和视频检索结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getPhotoAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  mgr.getPhotoAssets(fetchOptions, async (err, fetchResult) => {
    if (fetchResult != undefined) {
      console.info('fetchResult success');
      let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

getPhotoAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getPhotoAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
    if (fetchResult != undefined) {
      console.info('fetchResult success');
      let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

createPhotoAsset(displayName: string, albumUri: string, callback: AsyncCallback&lt;FileAsset&gt;): void

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type displayName or albumUri is not string.         |
| 14000001   | if type displayName invalid.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('createPhotoAssetDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.AlbumFetchOptions = {
    predicates: predicates
  };
  let albums: userFileManager.FetchResult<userFileManager.Album> = await mgr.getPhotoAlbums(fetchOptions);
  let album: userFileManager.Album = await albums.getFirstObject();
  let testFileName: string = 'testFile' + Date.now() + '.jpg';
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

createPhotoAsset(displayName: string, callback: AsyncCallback&lt;FileAsset&gt;): void

指定待创建的图片或者视频的文件名，创建图片或视频资源，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | 是   | 创建的图片或者视频文件名。              |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | 是   | callback返回创建的图片和视频结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |
| 14000001   | if type displayName invalid.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('createPhotoAssetDemo');
  let testFileName: string = 'testFile' + Date.now() + '.jpg';
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

createPhotoAsset(displayName: string, albumUri?: string): Promise&lt;FileAsset&gt;

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type displayName or albumUri is not string.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('createPhotoAssetDemo');
  try {
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.error('createPhotoAsset failed, message = ', err);
  }
}
```

### createPhotoAsset

createPhotoAsset(displayName: string, createOption: PhotoCreateOptions, callback: AsyncCallback&lt;FileAsset&gt;): void

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |
| 14000001   | if type displayName invalid.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('createPhotoAssetDemo');
  let testFileName: string = 'testFile' + Date.now() + '.jpg';
  let createOption: userFileManager.PhotoCreateOptions = {
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

createPhotoAsset(displayName: string, createOption: PhotoCreateOptions): Promise&lt;FileAsset&gt;

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('createPhotoAssetDemo');
  try {
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let createOption: userFileManager.PhotoCreateOptions = {
      subType: userFileManager.PhotoSubType.DEFAULT
    }
    let fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName, createOption);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.error('createPhotoAsset failed, message = ', err);
  }
}
```

### createAudioAsset<sup>10+</sup>

createAudioAsset(displayName: string, callback: AsyncCallback&lt;FileAsset&gt;): void

创建音频文件资源，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_AUDIO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | 是   | 创建的音频文件名。              |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | 是   | callback返回创建的音频资源结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |
| 14000001   | if type displayName invalid.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('createAudioAssetDemo');
  let testFileName: string = 'testFile' + Date.now() + '.mp3';
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

createAudioAsset(displayName: string): Promise&lt;FileAsset&gt;

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('createAudioAssetDemo');
  try {
    let testFileName: string = 'testFile' + Date.now() + '.mp3';
    let fileAsset: userFileManager.FileAsset = await mgr.createAudioAsset(testFileName);
    console.info('createAudioAsset file displayName' + fileAsset.displayName);
    console.info('createAudioAsset successfully');
  } catch (err) {
    console.error('createAudioAsset failed, message = ', err);
  }
}
```

### createAlbum<sup>10+</sup>

createAlbum(name: string, callback: AsyncCallback&lt;Album&gt;): void

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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('createAlbumDemo');
  let albumName: string = 'newAlbumName' + new Date().getTime();
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

createAlbum(name: string): Promise&lt;Album&gt;

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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('createAlbumDemo');
  let albumName: string  = 'newAlbumName' + new Date().getTime();
  mgr.createAlbum(albumName).then((album) => {
    console.info('createAlbumPromise successfully, album: ' + album.albumName + ' album uri: ' + album.albumUri);
  }).catch((err: BusinessError) => {
    console.error('createAlbumPromise failed with err: ' + err);
  });
}
```

### deleteAlbums<sup>10+</sup>

deleteAlbums(albums: Array&lt;Album&gt;, callback: AsyncCallback&lt;void&gt;): void

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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  // 示例代码为删除相册名为newAlbumName的相册。
  console.info('deleteAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions);
  let album: userFileManager.Album = await fetchResult.getFirstObject();
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

deleteAlbums(albums: Array&lt;Album&gt;): Promise&lt;void&gt;

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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  // 示例代码为删除相册名为newAlbumName的相册。
  console.info('deleteAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions);
  let album: userFileManager.Album = await fetchResult.getFirstObject();
  mgr.deleteAlbums([album]).then(() => {
    console.info('deletePhotoAlbumsPromise successfully');
    }).catch((err: BusinessError) => {
      console.error('deletePhotoAlbumsPromise failed with err: ' + err);
  });
  fetchResult.close();
}
```

### getAlbums<sup>10+</sup>

getAlbums(type: AlbumType, subType: AlbumSubType, options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void

根据检索选项和相册类型获取相册，使用callback方式返回结果。

该接口不支持获取隐藏相册，请使用[getHiddenAlbums](../apis-media-library-kit/js-apis-photoAccessHelper-sys.md#gethiddenalbums11)获得。

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOption.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  // 示例代码中为获取相册名为newAlbumName的相册。
  console.info('getAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: userFileManager.FetchOptions = {
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
    let album: userFileManager.Album = await fetchResult.getFirstObject();
    console.info('getAlbumsCallback successfully, albumName: ' + album.albumName);
    fetchResult.close();
  });
}
```

### getAlbums<sup>10+</sup>

getAlbums(type: AlbumType, subType: AlbumSubType, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void

根据相册类型获取相册，使用callback方式返回结果。

该接口不支持获取隐藏相册，请使用[getHiddenAlbums](../apis-media-library-kit/js-apis-photoAccessHelper-sys.md#gethiddenalbums11)获得。

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOption.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
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
    let album: userFileManager.Album = await fetchResult.getFirstObject();
    console.info('getAlbumsCallback successfully, albumUri: ' + album.albumUri);
    fetchResult.close();
  });
}
```

### getAlbums<sup>10+</sup>

getAlbums(type: AlbumType, subType: AlbumSubType, options?: FetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;

根据检索选项和相册类型获取相册，使用Promise方式返回结果。

该接口不支持获取隐藏相册，请使用[getHiddenAlbums](../apis-media-library-kit/js-apis-photoAccessHelper-sys.md#gethiddenalbums11)获得。

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOption.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  // 示例代码中为获取相册名为newAlbumName的相册。
  console.info('getAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions).then( async (fetchResult) => {
    if (fetchResult == undefined) {
      console.error('getAlbumsPromise fetchResult is undefined');
      return;
    }
    let album: userFileManager.Album = await fetchResult.getFirstObject();
    console.info('getAlbumsPromise successfully, albumName: ' + album.albumName);
    fetchResult.close();
  }).catch((err: BusinessError) => {
    console.error('getAlbumsPromise failed with err: ' + err);
  });
}
```

### getPhotoAlbums

getPhotoAlbums(options: AlbumFetchOptions, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void

获取相册，使用callback方式返回结果。

该接口不支持获取隐藏相册，请使用[getHiddenAlbums](../apis-media-library-kit/js-apis-photoAccessHelper-sys.md#gethiddenalbums11)获得。

此接口即将废弃，请使用[getAlbums<sup>10+</sup>](#getalbums10)的新接口。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [AlbumFetchOptions](#albumfetchoptions)        | 是   | 相册检索选项。              |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | 是   | callback返回相册检索结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not AlbumFetchOptions.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getPhotoAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: userFileManager.AlbumFetchOptions = {
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

getPhotoAlbums(options: AlbumFetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;

获取相册，使用Promise方式返回结果。

该接口不支持获取隐藏相册，请使用[getHiddenAlbums](../apis-media-library-kit/js-apis-photoAccessHelper-sys.md#gethiddenalbums11)获得。

此接口即将废弃，请使用[getAlbums<sup>10+</sup>](#getalbums10)的新接口。

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not AlbumFetchOptions.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getPhotoAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: userFileManager.AlbumFetchOptions = {
    predicates: predicates
  };
  try {
    let fetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getPhotoAlbums(albumFetchOptions);
    console.info('album.count = ' + fetchResult.getCount());
    const album: userFileManager.Album = await fetchResult.getFirstObject();
    console.info('first album.albumName = ' + album.albumName);
  } catch (err) {
    console.error('getPhotoAlbums fail, message = ' + err);
  }
}
```

### getPrivateAlbum

getPrivateAlbum(type: PrivateAlbumType, callback: AsyncCallback&lt;FetchResult&lt;PrivateAlbum&gt;&gt;): void

获取系统相册，使用 callback 方式返回系统相册的数组。

此接口即将废弃，请使用[getAlbums<sup>10+</sup>](#getalbums10)的新接口。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [PrivateAlbumType](#privatealbumtype)        | 是   | 系统相册类型。              |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[PrivateAlbum](#privatealbum)&gt;&gt; | 是   | callback返回相册检索结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type type is not PrivateAlbumType.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('getPrivateAlbumDemo');
  mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH, async (err, fetchResult) => {
    if (fetchResult != undefined) {
      let trashAlbum: userFileManager.PrivateAlbum = await fetchResult.getFirstObject();
      console.info('first album.albumName = ' + trashAlbum.albumName);
    } else {
      console.error('getPrivateAlbum failed. message = ', err);
    }
  });
}
```

### getPrivateAlbum

getPrivateAlbum(type: PrivateAlbumType): Promise&lt;FetchResult&lt;PrivateAlbum&gt;&gt;

获取系统相册，使用Promise方式返回结果。

此接口即将废弃，请使用[getAlbums<sup>10+</sup>](#getalbums10)的新接口。

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type type is not PrivateAlbumType.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('getPrivateAlbumDemo');
  try {
    let fetchResult: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
    let trashAlbum: userFileManager.PrivateAlbum = await fetchResult.getFirstObject();
    console.info('first album.albumName = ' + trashAlbum.albumName);
  } catch (err) {
    console.error('getPrivateAlbum failed. message = ', err);
  }
}
```

### getAudioAssets

getAudioAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void

获取音频文件，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_AUDIO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](#fetchoptions)        | 是   | 检索选项。              |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | 是   | callback返回音频检索结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getAudioAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  mgr.getAudioAssets(fetchOptions, async (err, fetchResult) => {
    if (fetchResult != undefined) {
      console.info('fetchFileResult success');
      let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

getAudioAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;


获取音频文件，使用promise方式返回结果。

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getAudioAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getAudioAssets(fetchOptions);
    if (fetchResult != undefined) {
      console.info('fetchFileResult success');
      let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
      if (fileAsset != undefined) {
        console.info('fileAsset.displayName :' + fileAsset.displayName);
      }
    }
  } catch (err) {
    console.error('getAudioAssets failed, message = ', err);
  }
}
```

### delete

delete(uri: string, callback: AsyncCallback&lt;void&gt;): void

删除媒体文件，删除的文件进入到回收站。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 媒体文件uri。 |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type uri is not string.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('deleteAssetDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    const fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();


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
  } catch (err) {
    console.error('fetch failed, message =', err);
  }
}
```

### delete

delete(uri: string): Promise&lt;void&gt;

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type uri is not string.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('deleteDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    const fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    if (asset == undefined) {
      console.error('asset not exist');
      return;
    }
    await mgr.delete(asset.uri);
    console.info('delete successfully');
  } catch (err) {
    console.error('delete failed with error: ' + err);
  }
}
```

### getActivePeers

getActivePeers(callback: AsyncCallback&lt;Array&lt;PeerInfo&gt;&gt;): void

获取在线对端设备的信息，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

**参数：**

| 参数名   | 类型                              | 必填 | 说明         |
| -------- | --------------------------------- | ---- | ------------ |
| callback | AsyncCallback&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | 是   | 返回在线设备列表。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
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

getActivePeers(): Promise&lt;Array&lt;PeerInfo&gt;&gt;

获取在线对端设备的信息，使用promise方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

**返回值：**

| 类型                        | 说明                          |
| --------------------------- | ----------------------------- |
| Promise&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Promise对象，返回在线设备列表。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('getActivePeersDemo');
  try {
    let devicesInfo: Array<userFileManager.PeerInfo> = await mgr.getActivePeers();
    if (devicesInfo != undefined) {
      console.log('getActivePeers succeed.');
      for (let i = 0; i < devicesInfo.length; i++) {
        console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
      }
    } else {
      console.error('get distributed fail');
    }
  } catch (err) {
    console.error('getActivePeers failed. message = ', err);
  }
}
```

### getAllPeers

getAllPeers(callback: AsyncCallback&lt;Array&lt;PeerInfo&gt;&gt;): void

获取所有对端设备的信息，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

**参数：**

| 参数名   | 类型                              | 必填 | 说明         |
| -------- | --------------------------------- | ---- | ------------ |
| callback | AsyncCallback&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | 是   | 返回在线设备列表。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
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

getAllPeers(): Promise&lt;Array&lt;PeerInfo&gt;&gt;

获取所有对端设备的信息，使用promise方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

**返回值：**

| 类型                        | 说明                          |
| --------------------------- | ----------------------------- |
| Promise&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Promise对象，返回所有设备列表。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('getAllPeersDemo');
  try {
    let devicesInfo: Array<userFileManager.PeerInfo> = await mgr.getAllPeers();

    if (devicesInfo != undefined) {
      console.log('getAllPeers succeed.');
      for (let i = 0; i < devicesInfo.length; i++) {
        console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
      }
    } else {
      console.error('get distributed fail');
    }
  } catch (err) {
    console.error('getAllPeers failed. message = ', err);
  }
}
```

### getPhotoIndex<sup>10+</sup>

getPhotoIndex(photoUri: string, albumUri: string, options: FetchOptions, callback: AsyncCallback&lt;number&gt;): void

获取相册中图片或视频的位置，使用callback方式返回结果。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| photoUri | string | 是   | 所查询的图库资源的uri。 |
| albumUri | string | 是   | 相册uri，可以为空字符串，为空字符串时默认查询全部图库资源。   |
| options  | [FetchOptions](#fetchoptions)       | 是   |  检索选项，predicates中必须设置一种检索排序方式，不设置或多设置均会导致接口调用异常。      |
| callback | AsyncCallback&lt;number&gt;| 是   | callback返回相册中资源的索引。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('getPhotoIndexDemo');
    let predicatesForGetAsset: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOp: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicatesForGetAsset
    };
    // Obtain the uri of the album
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.FAVORITE, fetchOp);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.orderByAsc(userFileManager.ImageVideoKey.DATE_MODIFIED.toString());
    let fetchOptions: userFileManager.FetchOptions = {
      fetchColumns: [userFileManager.ImageVideoKey.DATE_MODIFIED.toString()],
      predicates: predicates
    };
    let photoFetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOptions);
    let expectIndex = 1;
    // Obtain the uri of the second file
    let photoAsset: userFileManager.FileAsset = await photoFetchResult.getPositionObject(expectIndex);
    mgr.getPhotoIndex(photoAsset.uri, album.albumUri, fetchOptions, (err, index) => {
      if (err == undefined) {
        console.info(`getPhotoIndex successfully and index is : ${index}`);
      } else {
        console.error(`getPhotoIndex failed;`);
      }
    });
  } catch (error) {
    console.error(`getPhotoIndex failed; error: ${error}`);
  }
}
```

### getPhotoIndex<sup>10+</sup>

getPhotoIndex(photoUri: string, albumUri: string, options: FetchOptions): Promise&lt;number&gt;

获取相册中图片或视频的位置，使用Promise方式返回结果。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| photoUri | string | 是   | 所查询的图库资源的uri。 |
| albumUri | string | 是   | 相册uri，可以为空字符串，为空字符串时默认查询全部图库资源。   |
| options  | [FetchOptions](#fetchoptions)       | 是   |  检索选项，predicates中必须设置一种检索排序方式，不设置或多设置均会导致接口调用异常。      |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;number&gt;| 返回相册中资源的索引。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('getPhotoIndexDemo');
    let predicatesForGetAsset: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOp: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicatesForGetAsset
    };
    // Obtain the uri of the album
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.FAVORITE, fetchOp);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.orderByAsc(userFileManager.ImageVideoKey.DATE_MODIFIED.toString());
    let fetchOptions: userFileManager.FetchOptions = {
      fetchColumns: [userFileManager.ImageVideoKey.DATE_MODIFIED.toString()],
      predicates: predicates
    };
    let photoFetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOptions);
    let expectIndex = 1;
    // Obtain the uri of the second file
    let photoAsset: userFileManager.FileAsset = await photoFetchResult.getPositionObject(expectIndex);
    mgr.getPhotoIndex(photoAsset.uri, album.albumUri, fetchOptions).then((index) => {
      console.info(`getPhotoIndex successfully and index is : ${index}`);
    }).catch((err: BusinessError) => {
      console.error(`getPhotoIndex failed; error: ${err}`);
    });
  } catch (error) {
    console.error(`getPhotoIndex failed; error: ${error}`);
  }
}
```

### release

release(callback: AsyncCallback&lt;void&gt;): void

释放UserFileManager实例，使用callback方式返回结果。
当后续不需要使用UserFileManager实例中的方法时调用。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                 |
| -------- | ------------------------- | ---- | -------------------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调表示成功还是失败。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
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

释放UserFileManager实例，使用Promise方式返回结果。
当后续不需要使用UserFileManager 实例中的方法时调用。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                | 说明                              |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | Promise对象，返回void。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
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

对指定uri注册监听，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名    | 类型                                        | 必填 | 说明                                                         |
| --------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri       | string                                      | 是   | FileAsset的uri, Album的uri或[DefaultChangeUri](#defaultchangeuri10)的值。 |
| forSubUri | boolean                                     | 是   | 是否模糊监听。uri为相册uri时，forSubUri 为true能监听到相册中文件的变化；如果是false只能监听相册本身变化。uri为fileAsset时，forSubUri 为true、false没有区别。uri为DefaultChangeUri时，forSubUri必须为true；如果为false将找不到该uri，收不到任何消息。 |
| callback  | Callback&lt;[ChangeData](#changedata10)&gt; | 是   | 返回要监听的[ChangeData](#changedata10)。注：uri可以注册多个不同的callback监听，[off<sup>10+</sup>](#off10)可以关闭该uri所有监听，也可以关闭指定callback的监听。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if parameter is invalid.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('onDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  if (fileAsset != undefined) {
    console.info('fileAsset.displayName : ' + fileAsset.displayName);
  }
  let onCallback1 = (changeData: userFileManager.ChangeData) => {
      console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));
    //file had changed, do something
  }
  let onCallback2 = (changeData: userFileManager.ChangeData) => {
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

取消对指定uri的监听，一个uri可以注册多个监听，存在多个callback监听时，可以取消指定注册的callback的监听；不指定callback时解除该uri的所有监听。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                         |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                                      | 是   | FileAsset的uri, Album的uri或[DefaultChangeUri](#defaultchangeuri10)的值。 |
| callback | Callback&lt;[ChangeData](#changedata10)&gt; | 否   | 取消[on<sup>10+</sup>](#on10)注册时的callback的监听，不填时，取消该uri的所有监听。注：off指定注册的callback后不会进入此回调。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if parameter is invalid.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('offDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  if (fileAsset != undefined) {
    console.info('fileAsset.displayName : ' + fileAsset.displayName);
  }
  let onCallback1 = (changeData: userFileManager.ChangeData) => {
    console.info('onCallback1 on');
  }
  let onCallback2 = (changeData: userFileManager.ChangeData) => {
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

### on

on(type: ChangeEvent, callback: Callback&lt;void&gt;): void

打开文件管理库变更通知，使用callback方式返回异步结果。

此接口即将废弃，请使用[on<sup>10+</sup>](#on10)的新接口。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | [ChangeEvent](#changeevent)               | 是   | 媒体类型 <br/>'deviceChange'：&nbsp;注册设备变更。 <br/>'albumChange'：&nbsp;相册变更。<br/>'imageChange'：&nbsp;图片文件变更。<br/>'audioChange'： &nbsp;音频文件变更。<br/>'videoChange'：  &nbsp;视频文件变更。<br/>'remoteFileChange'：&nbsp;注册设备上文件变更。 |
| callback | Callback&lt;void&gt; | 是   | callback返回void。                                                   |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('onDemo');
  let count = 0;
  mgr.on('imageChange', () => {
    count++;
    // image file had changed, do something
  });
  try {
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName);
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

此接口即将废弃，请使用[off<sup>10+</sup>](#off10)的新接口。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | [ChangeEvent](#changeevent)               | 是   | 媒体类型 <br/>'deviceChange'：&nbsp;注册设备变更。 <br/>'albumChange'：&nbsp;相册变更。<br/>'imageChange'：&nbsp;图片文件变更。<br/>'audioChange'： &nbsp;音频文件变更。<br/>'videoChange'：  &nbsp;视频文件变更。<br/>'remoteFileChange'：&nbsp;注册设备上文件变更。 |
| callback | Callback&lt;void&gt; | 否   | callback返回void。                                                   |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
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
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName);
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

## FileAsset

提供封装文件属性的方法。

### 属性

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称                      | 类型                     | 只读 | 可写 | 说明                                                   |
| ------------------------- | ------------------------ | ---- | ---- | ------------------------------------------------------ |
| uri                       | string                   | 是   | 否   | 媒体文件资源uri（如：file://media/Photo/1/IMG_datetime_0001/displayName.jpg），详情参见用户文件uri介绍中的[媒体文件uri](../../file-management/user-file-uri-intro.md#媒体文件uri)。         |
| fileType   | [FileType](#filetype) | 是   | 否   | 媒体文件类型。                                               |
| displayName               | string                   | 是   | 是   | 显示文件名，包含后缀名。                                 |

### get

get(member: string): MemberType

获取FileAsset成员参数。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明    |
| -------- | ------------------------- | ---- | ----- |
| member | string | 是    | 成员参数名称例如：ImageVideoKey.DISPLAY_NAME。在get时，除了uri、photoType和displayName三个属性之外，其他的属性都需要在fetchColumns中填入需要get的PhotoKeys。例如：get title属性fetchColumns: ['title']。 |

**返回值：**

| 类型                    | 说明            |
| --------------------- | ------------- |
| MemberType | 返回成员参数。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('fileAssetGetDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: ['title'],
      predicates: predicates
    };
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    let title: userFileManager.ImageVideoKey = userFileManager.ImageVideoKey.TITLE;
    let fileAssetTitle: userFileManager.MemberType = fileAsset.get(title.toString());
    console.info('fileAsset Get fileAssetTitle = ', fileAssetTitle);
  } catch (err) {
    console.error('release failed. message = ', err);
  }
}
```

### set

set(member: string, value: string): void

设置FileAsset成员参数。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明    |
| -------- | ------------------------- | ---- | ----- |
| member | string | 是    | 成员参数名称例如：ImageVideoKey.DISPLAY_NAME。 |
| value | string | 是    | 设置成员参数名称，只能修改DISPLAY_NAME和TITLE的值。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('fileAssetSetDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    let displayName: string = userFileManager.ImageVideoKey.DISPLAY_NAME.toString();
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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('commitModifyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  let displayName: string = userFileManager.ImageVideoKey.DISPLAY_NAME.toString();
  let fileAssetDisplayName: userFileManager.MemberType = fileAsset.get(displayName);
  console.info('fileAsset get fileAssetDisplayName = ', fileAssetDisplayName);
  let newFileAssetDisplayName = 'new' + fileAssetDisplayName;
  console.info('fileAsset newFileAssetDisplayName = ', newFileAssetDisplayName);
  fileAsset.set(displayName, newFileAssetDisplayName);
  fileAsset.commitModify((err) => {
    if (err == undefined) {
      let commitModifyDisplayName = fileAsset.get(displayName);
      console.info('fileAsset commitModify successfully, commitModifyDisplayName = ', commitModifyDisplayName);
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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('commitModifyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  let displayName = userFileManager.ImageVideoKey.DISPLAY_NAME.toString();
  let fileAssetDisplayName: userFileManager.MemberType = fileAsset.get(displayName);
  console.info('fileAsset get fileAssetDisplayName = ', fileAssetDisplayName);
  let newFileAssetDisplayName = 'new' + fileAssetDisplayName;
  console.info('fileAsset newFileAssetDisplayName = ', newFileAssetDisplayName);
  fileAsset.set(displayName, newFileAssetDisplayName);
  try {
    await fileAsset.commitModify();
    let commitModifyDisplayName = fileAsset.get(displayName);
    console.info('fileAsset commitModify successfully, commitModifyDisplayName = ', commitModifyDisplayName);
  } catch (err) {
    console.error('commitModify failed. message = ', err);
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
| mode     | string                      | 是    | 打开文件方式。如：'r'（只读）, 'w'（只写）, 'rw'（读写）。 |
| callback | AsyncCallback&lt;number&gt; | 是    | callback返回文件描述符。                            |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('openDemo');
   let testFileName: string = 'testFile' + Date.now() + '.jpg';
  const fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName);
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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('openDemo');
  try {
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    const fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName);
    let fd: number = await fileAsset.open('rw');
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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('closeDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
    const fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    let fd: number = await fileAsset.open('rw');
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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('closeDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
    const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    let fd: number = await asset.open('rw');
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
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | 是    | callback返回缩略图的PixelMap。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getThumbnailDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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
| size     | [image.Size](../apis-image-kit/js-apis-image.md#size) | 是    | 缩略图尺寸。            |
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | 是    | callback返回缩略图的PixelMap。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getThumbnailDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let size: image.Size = { width: 720, height: 720 };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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
| size | [image.Size](../apis-image-kit/js-apis-image.md#size) | 否    | 缩略图尺寸。 |

**返回值：**

| 类型                            | 说明                    |
| ----------------------------- | --------------------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | Promise对象，返回缩略图的PixelMap。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getThumbnailDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let size: image.Size = { width: 720, height: 720 };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName);
  asset.getThumbnail(size).then((pixelMap) => {
    console.info('getThumbnail successful ' + pixelMap);
  }).catch((err: BusinessError) => {
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
| isFavorite | boolean                   | 是    | 是否设置为收藏文件。true：设置为收藏文件；false：取消收藏。 |
| callback   | AsyncCallback&lt;void&gt; | 是    | callback返回void。                              |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('favoriteDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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
| isFavorite | boolean | 是    | 是否设置为收藏文件。true：设置为收藏文件；false：取消收藏。 |

**返回值：**

| 类型                  | 说明         |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，返回void。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('favoriteDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  asset.favorite(true).then(() => {
    console.info('favorite successfully');
  }).catch((err: BusinessError) => {
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
| hiddenState | boolean                   | 是    | 是否设置为隐藏文件。true：将文件资产放入隐藏相册；false：从隐藏相册中恢复。 |
| callback   | AsyncCallback&lt;void&gt; | 是    | callback返回void。                              |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202   | Called by non-system application.                |
| 13900020   | if parameter is invalid.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('setHiddenDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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
| hiddenState | boolean | 是    | 是否设置为隐藏文件。true：将文件资产放入隐藏相册；false：从隐藏相册中恢复。 |

**返回值：**

| 类型                  | 说明         |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202   | Called by non-system application.                |
| 13900020   | if parameter is invalid.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  // 示例代码为将文件从隐藏相册中恢复，需要先在隐藏相册预置资源
  console.info('setHiddenDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let albumList: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.HIDDEN);
  const album: userFileManager.Album = await albumList.getFirstObject();
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  asset.setHidden(false).then(() => {
    console.info('setHidden successfully');
  }).catch((err: BusinessError) => {
    console.error('setHidden failed with error:' + err);
  });
}
```

### getExif<sup>10+</sup>

getExif(): Promise&lt;string&gt;

返回jpg格式图片Exif标签组成的json格式的字符串，该方法使用Promise方式返回结果。

**注意**：此接口返回的是exif标签组成的json格式的字符串，完整exif信息由all_exif与[ImageVideoKey.USER_COMMENT](#imagevideokey)组成，fetchColumns需要传入这两个字段。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;string&gt; | 返回exif标签组成的json格式的字符串。 |

**支持Exif标签列表**：

Exif标签的详细信息请参考[image.PropertyKey](../apis-image-kit/js-apis-image.md#propertykey7)。

| 标签key值                                    | 标签说明              |
| --------------------------------------- | ----------------- |
| BitsPerSample | 每个像素比特数。 |
| Orientation | 图像方向。 |
| ImageLength | 图像长度。 |
| ImageWidth | 图像宽度。 |
| GPSLatitude | GPS纬度。 |
| GPSLongitude | GPS经度。 |
| GPSLatitudeRef | 经度引用，例如W或E。 |
| GPSLongitudeRef | 纬度引用，例如N或S。 |
| DateTimeOriginal | 拍摄时间。 |
| ExposureTime | 曝光时间。 |
| SceneType | 场景类型。 |
| ISOSpeedRatings | ISO感光度分值。 |
| FNumber | 光圈F值。 |
| DateTime | 修改时间。 |
| GPSTimeStamp | GPS时间戳。 |
| GPSDateStamp | GPS日期戳。 |
| ImageDescription | 图像描述。 |
| Make | 制造商。 |
| MakeNote | 制造商。 |
| Model | 型号。 |
| PhotoMode | 拍摄模式。 |
| SensitivityType | 感光类型。 |
| StandardOutputSensitivity | 标准输出感光度。 |
| RecommendedExposureIndex | 推荐曝光指数。 |
| ApertureValue | 光圈。 |
| MeteringMode | 测光模式。 |
| LightSource | 光源。 |
| Flash | 闪光灯。 |
| FocalLength | 镜头焦距。 |
| UserComment | 用户注释。 |
| PixelXDimension | 有效图像宽度。 |
| PixelYDimension | 有效图像高度。 |
| WhiteBalance | 白平衡。 |
| FocalLengthIn35mmFilm | 35mm等效焦距。 |
| ExposureBiasValue | 曝光补偿。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('getExifDemo');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.isNotNull('all_exif')
    let fetchOptions: userFileManager.FetchOptions = {
      fetchColumns: ['all_exif', userFileManager.ImageVideoKey.USER_COMMENT.toString()],
      predicates: predicates
    };
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    console.info('getExifDemo fileAsset displayName: ' + JSON.stringify(fileAsset.displayName));
    let exifMessage: string = await fileAsset.getExif();
    let userCommentKey: string = 'UserComment';
    let userComment: string = JSON.stringify(JSON.parse(exifMessage), [userCommentKey]);
    console.info('getExifDemo userComment: ' + JSON.stringify(userComment));
    fetchResult.close();
  } catch (err) {
    console.error('getExifDemoCallback failed with error: ' + err);
  }
}
```

### getExif<sup>10+</sup>

getExif(callback: AsyncCallback&lt;string&gt;): void

返回jpg格式图片Exif标签组成的json格式的字符串，该方法使用Promise方式返回结果。

**注意**：此接口返回的是exif标签组成的json格式的字符串，完整exif信息由all_exif与[ImageVideoKey.USER_COMMENT](#imagevideokey)组成，fetchColumns需要传入这两个字段。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;string&gt; | 是   | 返回exif标签组成的json格式的字符串。 |

**支持Exif标签列表**：

Exif标签的详细信息请参考[image.PropertyKey](../apis-image-kit/js-apis-image.md#propertykey7)。

| 标签key值                                    | 标签说明              |
| --------------------------------------- | ----------------- |
| BitsPerSample | 每个像素比特数。 |
| Orientation | 图像方向。 |
| ImageLength | 图像长度。 |
| ImageWidth | 图像宽度。 |
| GPSLatitude | GPS纬度。 |
| GPSLongitude | GPS经度。 |
| GPSLatitudeRef | 经度引用，例如W或E。 |
| GPSLongitudeRef | 纬度引用，例如N或S。 |
| DateTimeOriginal | 拍摄时间。 |
| ExposureTime | 曝光时间。 |
| SceneType | 场景类型。 |
| ISOSpeedRatings | ISO感光度分值。 |
| FNumber | 光圈F值。 |
| DateTime | 修改时间。 |
| GPSTimeStamp | GPS时间戳。 |
| GPSDateStamp | GPS日期戳。 |
| ImageDescription | 图像描述。 |
| Make | 制造商。 |
| MakeNote | 制造商。 |
| Model | 型号。 |
| PhotoMode | 拍摄模式。 |
| SensitivityType | 感光类型。 |
| StandardOutputSensitivity | 标准输出感光度。 |
| RecommendedExposureIndex | 推荐曝光指数。 |
| ApertureValue | 光圈。 |
| MeteringMode | 测光模式。 |
| LightSource | 光源。 |
| Flash | 闪光灯。 |
| FocalLength | 镜头焦距。 |
| UserComment | 用户注释。 |
| PixelXDimension | 有效图像宽度。 |
| PixelYDimension | 有效图像高度。 |
| WhiteBalance | 白平衡。 |
| FocalLengthIn35mmFilm | 35mm等效焦距。 |
| ExposureBiasValue | 曝光补偿。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('getExifDemo');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.isNotNull('all_exif')
    let fetchOptions: userFileManager.FetchOptions = {
      fetchColumns: ['all_exif', userFileManager.ImageVideoKey.USER_COMMENT.toString()],
      predicates: predicates
    };
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    console.info('getExifDemo fileAsset displayName: ' + JSON.stringify(fileAsset.displayName));
    let userCommentKey: string = 'UserComment';
    fileAsset.getExif((err, exifMessage) => {
      if (exifMessage != undefined) {
        let userComment: string = JSON.stringify(JSON.parse(exifMessage), [userCommentKey]);
        console.info('getExifDemo userComment: ' + JSON.stringify(userComment));
      } else {
        console.error('getExif failed, message = ', err);
      }
    });
    fetchResult.close();
  } catch (err) {
    console.error('getExifDemoCallback failed with error: ' + err);
  }
}
```

### setUserComment<sup>10+</sup>

setUserComment(userComment: string): Promise&lt;void&gt;

修改图片或者视频的备注信息，该方法使用Promise来返回结果。

**注意**：此接口只可修改图片或者视频的备注信息。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| userComment | string | 是   | 待修改的图片或视频的备注信息，备注信息最长为140字符。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise对象，返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202   | Called by non-system application.                |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('setUserCommentDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    let userComment: string = 'test_set_user_comment';
    await fileAsset.setUserComment(userComment);
  } catch (err) {
    console.error('setUserCommentDemoCallback failed with error: ' + err);
  }
}
```

### setUserComment<sup>10+</sup>

setUserComment(userComment: string, callback: AsyncCallback&lt;void&gt;): void

修改图片或者视频的备注信息，该方法使用callback形式来返回结果。

**注意**：此接口只可修改图片或者视频的备注信息。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| userComment | string | 是   | 待修改的图片或视频的备注信息，备注信息最长为140字符。 |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202   | Called by non-system application.                |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('setUserCommentDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    let userComment: string = 'test_set_user_comment';
    fileAsset.setUserComment(userComment, (err) => {
      if (err === undefined) {
        console.info('setUserComment successfully');
      } else {
        console.error('setUserComment failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('setUserCommentDemoCallback failed with error: ' + err);
  }
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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getCountDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  const fetchCount: number = fetchResult.getCount();
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
| boolean | 当读到最后一条记录后，后续没有记录返回true；否则返回false。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  const fetchCount: number = fetchResult.getCount();
  console.info('count:' + fetchCount);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getLastObject();
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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('fetchResultCloseDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
    fetchResult.close();
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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getFirstObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getFirstObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  console.info('fileAsset displayName: ', fileAsset.displayName);
}
```

### getNextObject

getNextObject(callback: AsyncCallback&lt;T&gt;): void

获取文件检索结果中的下一个文件资产。此方法使用callback形式返回结果。
在调用此方法之前，必须使用[isAfterLast()](#isafterlast)来检查当前位置是否为最后一行。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名    | 类型                                          | 必填 | 说明                                      |
| --------- | --------------------------------------------- | ---- | ----------------------------------------- |
| callback | AsyncCallback&lt;T&gt; | 是   | 异步返回结果集中下一个之后的回调。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getNextObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  await fetchResult.getFirstObject();
  if (!fetchResult.isAfterLast()) {
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
在调用此方法之前，必须使用[isAfterLast()](#isafterlast)来检查当前位置是否为最后一行。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;T&gt; | Promise对象，返回结果集中下一个对象。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getNextObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  await fetchResult.getFirstObject();
  if (!fetchResult.isAfterLast()) {
    let fileAsset: userFileManager.FileAsset = await fetchResult.getNextObject();
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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getLastObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getLastObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getLastObject();
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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type index is not number.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getPositionObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type index is not number.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getPositionObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getPositionObject(0);
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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getAllObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
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

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getAllObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  let fileAssetList: Array<userFileManager.FileAsset> = await fetchResult.getAllObject();
  console.info('fileAssetList length: ', fileAssetList.length);
}
```

## Album

实体相册。

### 属性

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称           | 类型    | 只读   | 可写  | 说明   |
| ------------ | ------ | ---- | ---- | ------- |
| albumType<sup>10+</sup> | [AlbumType]( #albumtype10) | 是    | 否    | 相册类型。    |
| albumSubType<sup>10+</sup> | [AlbumSubType]( #albumsubtype10) | 是    | 否   | 相册子类型。    |
| albumName | string | 是    | 用户相册可写，预置相册不可写   | 相册名称。    |
| albumUri | string | 是    | 否    | 相册Uri。   |
| count | number | 是    | 否    |  相册中文件数量。 |
| coverUri | string | 是    | 用户相册可写，预置相册不可写	    | 封面文件Uri。 |

### getPhotoAssets

getPhotoAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void

获取相册中的文件。该方法使用callback形式来返回文件。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | 是   | 检索选项。 |
| callback | AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | 是   | callback返回图片和视频数据结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('albumGetFileAssetsDemoCallback');

  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: userFileManager.AlbumFetchOptions = {
    predicates: predicates
  };
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let albumList: userFileManager.FetchResult<userFileManager.Album> = await mgr.getPhotoAlbums(albumFetchOptions);
  let album: userFileManager.Album = await albumList.getFirstObject();
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

getPhotoAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('albumGetFileAssetsDemoPromise');

  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: userFileManager.AlbumFetchOptions = {
    predicates: predicates
  };
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  const albumList: userFileManager.FetchResult<userFileManager.Album> = await mgr.getPhotoAlbums(albumFetchOptions);
  const album: userFileManager.Album = await albumList.getFirstObject();
  album.getPhotoAssets(fetchOption).then((albumFetchResult) => {
    console.info('album getFileAssets successfully, getCount: ' + albumFetchResult.getCount());
  }).catch((err: BusinessError) => {
    console.error('album getFileAssets failed with error: ' + err);
  });
}
```

### commitModify

commitModify(callback: AsyncCallback&lt;void&gt;): void

更新相册属性修改到数据库中。该方法使用callback形式来返回结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('albumCommitModifyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: userFileManager.AlbumFetchOptions = {
    predicates: predicates
  };
  const albumList: userFileManager.FetchResult<userFileManager.Album> = await mgr.getPhotoAlbums(albumFetchOptions);
  const album: userFileManager.Album = await albumList.getFirstObject();
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

commitModify(): Promise&lt;void&gt;

更新相册属性修改到数据库中。该方法使用Promise来返回结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                  | 说明           |
| ------------------- | ------------ |
| Promise&lt;void&gt; | Promise对象，返回void。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('albumCommitModifyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: userFileManager.AlbumFetchOptions = {
    predicates: predicates
  };
  try {
    let albumList: userFileManager.FetchResult<userFileManager.Album> = await mgr.getPhotoAlbums(albumFetchOptions);
    let album: userFileManager.Album = await albumList.getFirstObject();
    album.albumName = 'hello';
    album.commitModify().then(() => {
      console.info('commitModify successfully');
    }).catch((err: BusinessError) => {
      console.error('commitModify failed with error: ' + err);
    });
  } catch (err) {
    console.error('getPhotoAlbums failed. message = ', err);
  }
}
```

### addPhotoAssets<sup>10+</sup>

addPhotoAssets(assets: Array&lt;FileAsset&gt;, callback: AsyncCallback&lt;void&gt;): void

往相册中添加图片或者视频，需要先预置相册和文件资源。该方法使用callback形式来返回结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | 是   | 待添加到相册中的图片或视频数组。 |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('addPhotoAssetsDemoCallback');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

addPhotoAssets(assets: Array&lt;FileAsset&gt;): Promise&lt;void&gt;

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('addPhotoAssetsDemoPromise');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    album.addPhotoAssets([asset]).then(() => {
      console.info('album addPhotoAssets successfully');
    }).catch((err: BusinessError) => {
      console.error('album addPhotoAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('addPhotoAssetsDemoPromise failed with error: ' + err);
  }
}
```

### removePhotoAssets<sup>10+</sup>

removePhotoAssets(assets: Array&lt;FileAsset&gt;, callback: AsyncCallback&lt;void&gt;): void

从相册中移除图片或者视频，需要先预置相册和文件资源。该方法使用callback形式来返回结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | 是   | 相册中待移除的图片或视频数组。 |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('removePhotoAssetsDemoCallback');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

removePhotoAssets(assets: Array&lt;FileAsset&gt;): Promise&lt;void&gt;

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('removePhotoAssetsDemoPromise');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    album.removePhotoAssets([asset]).then(() => {
      console.info('album removePhotoAssets successfully');
    }).catch((err: BusinessError) => {
      console.error('album removePhotoAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('removePhotoAssetsDemoPromise failed with error: ' + err);
  }
}
```

### recoverPhotoAssets<sup>10+</sup>

recoverPhotoAssets(assets: Array&lt;FileAsset&gt;, callback: AsyncCallback&lt;void&gt;): void

从回收站中恢复图片或者视频，需要先在回收站中预置文件资源。该方法使用callback形式来返回结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | 是   | 回收站中待恢复图片或者视频数组。 |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('recoverPhotoAssetsDemoCallback');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

recoverPhotoAssets(assets: Array&lt;FileAsset&gt;): Promise&lt;void&gt;

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('recoverPhotoAssetsDemoPromise');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    album.recoverPhotoAssets([asset]).then(() => {
      console.info('album recoverPhotoAssets successfully');
    }).catch((err: BusinessError) => {
      console.error('album recoverPhotoAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('recoverPhotoAssetsDemoPromise failed with error: ' + err);
  }
}
```

### deletePhotoAssets<sup>10+</sup>

deletePhotoAssets(assets: Array&lt;FileAsset&gt;, callback: AsyncCallback&lt;void&gt;): void

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('deletePhotoAssetsDemoCallback');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

deletePhotoAssets(assets: Array&lt;FileAsset&gt;): Promise&lt;void&gt;

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('deletePhotoAssetsDemoPromise');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    album.deletePhotoAssets([asset]).then(() => {
      console.info('album deletePhotoAssets successfully');
    }).catch((err: BusinessError) => {
      console.error('album deletePhotoAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('deletePhotoAssetsDemoPromise failed with error: ' + err);
  }
}
```

## PrivateAlbum

系统相册。

此接口即将废弃，请使用[Album](#album)接口替代。

### 属性

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称           | 类型    | 只读   | 可写   | 说明      |
| ------------ | ------ | ---- | ---- | ------- |
| albumName | string | 是    | 是    | 相册名称。    |
| albumUri | string | 是    | 否    | 相册Uri。   |
| dateModified | number | 是    | 否    | 修改日期。    |
| count | number | 是    | 否    | 相册中文件数量。 |
| coverUri | string | 是    | 否    | 封面文件Uri。 |

### getPhotoAssets

getPhotoAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void

获取系统相册中的文件。该方法使用callback形式来返回文件。

此接口即将废弃，请使用[Album.getPhotoAssets](#getphotoassets-2)接口替代。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | 是   | 检索选项。 |
| callback | AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | 是   | callback返回图片和视频数据结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('privateAlbumGetFileAssetsDemoCallback');
  let albumList: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  const trashAlbum: userFileManager.PrivateAlbum = await albumList.getFirstObject();
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

getPhotoAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;

获取系统相册中的文件。该方法使用Promise来返回文件。

此接口即将废弃，请使用[Album.getPhotoAssets](#getphotoassets-3)接口替代。

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

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('privateAlbumGetFileAssetsDemoPromise');
  let albumList: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  const trashAlbum: userFileManager.PrivateAlbum = await albumList.getFirstObject();
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await trashAlbum.getPhotoAssets(fetchOption);
  let count = fetchResult.getCount();
  console.info('fetchResult.count = ', count);
}
```

### delete

delete(uri: string, callback: AsyncCallback&lt;void&gt;): void

删除系统相册中的文件，仅支持删除回收站相册中文件。

此接口即将废弃，请使用[Album.deletePhotoAssets](#deletephotoassets10)接口替代。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 系统相册中文件的uri。 |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('privateAlbumDeleteCallback');
  let albumList: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let trashAlbum: userFileManager.PrivateAlbum = await albumList.getFirstObject();
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await trashAlbum.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

delete(uri: string): Promise&lt;void&gt;

删除系统相册中的文件，仅支持删除回收站相册中文件。

此接口即将废弃，请使用[Album.deletePhotoAssets](#deletephotoassets10)接口替代。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 系统相册中文件的uri。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise对象，返回void。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('privateAlbumDeleteDemoPromise');
  let albumList: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let trashAlbum: userFileManager.PrivateAlbum = await albumList.getFirstObject();
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await trashAlbum.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  let deleteFileUri = fileAsset.uri;
  trashAlbum.delete(deleteFileUri).then(() => {
    console.info('trashAlbum.delete successfully');
  }).catch((err: BusinessError) => {
    console.error('trashAlbum.delete failed, message = ', err);
  });
}
```

### recover

recover(uri: string, callback: AsyncCallback&lt;void&gt;): void

恢复系统相册中的文件，仅支持恢复回收站相册中文件。

此接口即将废弃，请使用[Album.recoverPhotoAssets](#recoverphotoassets10)接口替代。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 系统相册中文件的uri。 |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('privateAlbumRecoverDemoCallback');
  let albumList: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let trashAlbum: userFileManager.PrivateAlbum = await albumList.getFirstObject();
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await trashAlbum.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  let recoverFileUri: string = fileAsset.uri;
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

recover(uri: string): Promise&lt;void&gt;

恢复系统相册中的文件，仅支持恢复回收站相册中文件。

此接口即将废弃，请使用[Album.recoverPhotoAssets](#recoverphotoassets10)接口替代。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 系统相册中文件的uri。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise对象，返回void。 |

**示例：**

mgr的创建请参考[userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('privateAlbumRecoverDemoPromise');
  let albumList: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let trashAlbum: userFileManager.PrivateAlbum = await albumList.getFirstObject();
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await trashAlbum.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  let recoverFileUri: string = fileAsset.uri;
  trashAlbum.recover(recoverFileUri).then(() => {
    console.info('trashAlbum.recover successfully');
  }).catch((err: BusinessError) => {
    console.error('trashAlbum.recover failed, message = ', err);
  });
}
```

## MemberType

成员类型。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称  |  类型 |  只读  |  可写  |  说明  |
| ----- |  ---- |  ---- |  ---- |  ---- |
| number |  number | 是 | 是 | number类型。 |
| string |  string | 是 | 是 | string类型。|
| boolean |  boolean | 是 | 是 | boolean类型。 |

## ChangeEvent

变更监听的媒体文件类型。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称  |  类型 |  只读  |  可写  |  说明 |
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

| 名称       | 类型                       | 只读 | 可写 | 说明             |
| ---------- | -------------------------- | ---- | ---- | ---------------- |
| deviceName | string                     | 是   | 否   | 注册设备的名称。   |
| networkId  | string                     | 是   | 否   | 注册设备的网络ID。 |
| isOnline   | boolean                    | 是   | 否   | 是否在线。true是在线，false为不在线         |

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
| LOCAL |  1 |  文件只存在于本地。 |
| CLOUD |  2 |  文件只存在于云端。 |
| BOTH |  3 |  文件在本地和云端中都存在。 |

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

此接口即将废弃，请使用[AlbumType](#albumtype10)和[AlbumSubType](#albumsubtype10)和接口替代。

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
| CAMERA_SHOT_KEY<sup>10+</sup>    | camera_shot_key           | 锁屏相机拍照或录像的标记字段（仅开放给系统相机,其key值由系统相机定义）。    |
| USER_COMMENT<sup>10+</sup>  | user_comment            | 用户注释信息。                               |

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
| cameraShotKey           | string | 否  | 锁屏相机拍照或录像的标记字段（仅开放给系统相机,其key值由系统相机定义）。  |

## FetchOptions

检索条件。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称                   | 类型                | 只读 | 可写 | 说明                                              |
| ---------------------- | ------------------- | ---- |---- | ------------------------------------------------ |
| fetchColumns           | Array&lt;string&gt; | 是   | 是   | 检索条件，指定列名查询，如果该参数为空时默认查询uri、name、fileType（具体字段名称以检索对象定义为准）且使用[get](#get)接口去获取当前对象的其他属性时将会报错。示例：<br />fetchColumns: ['uri', 'title']。 |
| predicates           | [dataSharePredicates.DataSharePredicates](../apis-arkdata/js-apis-data-dataSharePredicates-sys.md) | 是   | 是   | 谓词查询，显示过滤条件。 |

## AlbumFetchOptions

相册检索条件。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称                   | 类型                | 只读 | 可写 | 说明                                              |
| ---------------------- | ------------------- | ---- |---- | ------------------------------------------------ |
| predicates           | [dataSharePredicates.DataSharePredicates](../apis-arkdata/js-apis-data-dataSharePredicates-sys.md) | 是   | 是   | 谓词查询，显示过滤条件。 |

## ChangeData<sup>10+</sup>

监听器回调函数的值。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称    | 类型                        | 只读 | 可写 | 说明                                                         |
| ------- | --------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type    | [NotifyType](#notifytype10) | 是   | 否   | ChangeData的通知类型。                                       |
| uris    | Array&lt;string&gt;         | 是   | 否   | 相同[NotifyType](#notifytype10)的所有uri，可以是FileAsset或Album。 |
| subUris | Array&lt;string&gt;         | 是   | 否   | 相册中变动文件的uri数组。可能为undefined，使用前需要检查是否为undefined。|

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

