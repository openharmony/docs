# @ohos.file.sendablePhotoAccessHelper (相册管理模块)(系统接口)

该模块基于Sendable对象，提供相册管理模块能力，包括创建相册以及访问、修改相册中的媒体数据信息等。

> **说明：**
>
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.file.sendablePhotoAccessHelper (基于Sendable对象的相册管理模块)](js-apis-sendablePhotoAccessHelper.md)。

## 导入模块

```ts
import { sendablePhotoAccessHelper } from '@kit.MediaLibraryKit';
```

## PhotoAccessHelper

### createAsset

createAsset(displayName: string): Promise&lt;PhotoAsset&gt;

指定待创建的图片或者视频的文件名，创建图片或视频资源，使用Promise方式返回结果。

待创建的文件名参数规格为：
- 应包含有效文件主名和图片或视频扩展名。
- 文件名字符串长度为1~255。
- 文件主名中不允许出现的非法英文字符，包括：<br> . .. \ / : * ? " ' ` < > | { } [ ]

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名      | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | -------------------------- |
| displayName | string | 是   | 创建的图片或者视频文件名。 |

**返回值：**

| 类型                                     | 说明                                    |
| ---------------------------------------- | --------------------------------------- |
| Promise&lt;[PhotoAsset](#photoasset)&gt; | Promise对象，返回创建的图片和视频结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Called by non-system application.                            |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 201      | Permission denied.                                           |
| 13900020 | Invalid argument.                                            |
| 14000001 | Invalid display name.                                        |
| 14000011 | Internal system error                                        |

**示例：**

```ts
async function example() {
  console.info('createAssetDemo');
  try {
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(testFileName);
    console.info('createAsset file displayName' + photoAsset.displayName);
    console.info('createAsset successfully');
  } catch (err) {
    console.error(`createAsset failed, error: ${err.code}, ${err.message}`);
  }
}
```

### createAsset

createAsset(displayName: string, options: PhotoCreateOptions): Promise&lt;PhotoAsset&gt;

指定待创建的图片或者视频的文件名和创建选项，创建图片或视频资源，使用Promise方式返回结果。

待创建的文件名参数规格为：
- 应包含有效文件主名和图片或视频扩展名。
- 文件名字符串长度为1~255。
- 文件主名中不允许出现的非法英文字符，包括：<br> . .. \ / : * ? " ' ` < > | { } [ ]

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名      | 类型                                                         | 必填 | 说明                       |
| ----------- | ------------------------------------------------------------ | ---- | -------------------------- |
| displayName | string                                                       | 是   | 创建的图片或者视频文件名。 |
| options     | [PhotoCreateOptions](js-apis-photoAccessHelper-sys.md#photocreateoptions) | 是   | 图片或视频的创建选项。     |

**返回值：**

| 类型                                     | 说明                                    |
| ---------------------------------------- | --------------------------------------- |
| Promise&lt;[PhotoAsset](#photoasset)&gt; | Promise对象，返回创建的图片和视频结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Called by non-system application.                            |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 201      | Permission denied.                                           |
| 13900020 | Invalid argument.                                            |
| 14000001 | Invalid display name.                                        |
| 14000011 | Internal system error                                        |

**示例：**

```ts
async function example() {
  console.info('createAssetDemo');
  try {
    let testFileName:string = 'testFile' + Date.now() + '.jpg';
    let createOption: photoAccessHelper.PhotoCreateOptions = {
      subtype: photoAccessHelper.PhotoSubtype.DEFAULT
    }
    let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(testFileName, createOption);
    console.info('createAsset file displayName' + photoAsset.displayName);
    console.info('createAsset successfully');
  } catch (err) {
    console.error(`createAsset failed, error: ${err.code}, ${err.message}`);
  }
}
```

### getHiddenAlbums

getHiddenAlbums(mode: HiddenPhotosDisplayMode, options?: FetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;

根据隐藏文件显示模式和检索选项获取系统中的隐藏相册，使用Promise方式返回结果。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.MANAGE_PRIVATE_PHOTOS

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                           |
| ------- | ------------------------------------------------------------ | ---- | ---------------------------------------------- |
| mode    | [HiddenPhotosDisplayMode](js-apis-photoAccessHelper-sys.md#hiddenphotosdisplaymode11) | 是   | 隐藏文件显示模式                               |
| options | [FetchOptions](js-apis-photoAccessHelper.md#fetchoptions)    | 否   | 检索选项，不填时默认根据隐藏文件显示模式检索。 |

**返回值：**

| 类型                                                         | 说明                                |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise&lt;[FetchResult](js-apis-photoAccessHelper.md#fetchresult)&lt;[Album](#album)&gt;&gt; | Promise对象，返回获取相册的结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14000011 | Internal system error                                        |

**示例：**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

// 获取系统预置的隐藏相册
async function getSysHiddenAlbum() {
  console.info('getSysHiddenAlbumDemo');
  phAccessHelper.getHiddenAlbums(photoAccessHelper.HiddenPhotosDisplayMode.ASSETS_MODE)
    .then( async (fetchResult) => {
      if (fetchResult === undefined) {
        console.error('getSysHiddenAlbumPromise fetchResult is undefined');
        return;
      }
      let hiddenAlbum: sendablePhotoAccessHelper.Album = await fetchResult.getFirstObject();
      console.info('getAlbumsPromise successfully, albumUri: ' + hiddenAlbum.albumUri);
      fetchResult.close();
    }).catch((err: BusinessError) => {
      console.error(`getSysHiddenAlbumPromise failed with err: ${err.code}, ${err.message}`);
    });
}

// 获取隐藏相册-相册视图，即系统中包含隐藏文件的相册（不包含系统预置的隐藏相册本身和回收站相册）
async function getHiddenAlbumsView() {
  console.info('getHiddenAlbumsViewDemo');
  phAccessHelper.getHiddenAlbums(photoAccessHelper.HiddenPhotosDisplayMode.ALBUMS_MODE).then( async (fetchResult) => {
    if (fetchResult === undefined) {
      console.error('getHiddenAlbumsViewPromise fetchResult is undefined');
      return;
    }
    let albums: Array<sendablePhotoAccessHelper.Album> = await fetchResult.getAllObjects();
    console.info('getHiddenAlbumsViewPromise successfully, albums size: ' + albums.length);

    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    for (let i = 0; i < albums.length; i++) {
      // 获取相册中的隐藏文件
      albums[i].getAssets(fetchOption).then((assetFetchResult) => {
        console.info('album get hidden assets successfully, getCount: ' + assetFetchResult.getCount());
      }).catch((err: BusinessError) => {
        console.error(`album get hidden assets failed with error: ${err.code}, ${err.message}`);
      });
    }
    fetchResult.close();
  }).catch((err: BusinessError) => {
    console.error(`getHiddenAlbumsViewPromise failed with err: ${err.code}, ${err.message}`);
  });
}
```

## PhotoAsset

提供封装文件属性的方法。

### requestSource

requestSource(): Promise&lt;number&gt;

打开源文件并返回fd，该方法使用Promise形式来返回结果。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**返回值：**

| 类型                  | 说明                        |
| --------------------- | --------------------------- |
| Promise&lt;number&gt; | Promise对象，返回源文件fd。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011 | Internal system error                                        |

**示例：**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('requsetSourcePromiseDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let fd = await photoAsset.requestSource();
    console.info('Source fd is ' + fd);
  } catch (err) {
    console.error(`requsetSourcePromiseDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### getAnalysisData

getAnalysisData(analysisType: AnalysisType): Promise\<string>

根据智慧分析类型获取指定分析结果数据。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.READ\_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名       | 类型                                                         | 必填 | 说明                     |
| :----------- | :----------------------------------------------------------- | :--- | :----------------------- |
| analysisType | [AnalysisType](js-apis-photoAccessHelper-sys.md#analysistype11) | 是   | 需要获取的智慧分析类型。 |

**返回值：**

| 类型                | 说明                                |
| :------------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise对象，返回指定分析数据结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                     |
| :------- | :----------------------------------------------------------- |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14000011 | Internal system error                                        |

**示例：**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('getAnalysisDataDemo')
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    }
    let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> =
      await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    if (photoAsset != undefined) {
      let analysisData: string = await photoAsset.getAnalysisData(
        photoAccessHelper.AnalysisType.ANALYSIS_OCR);
      console.info('get ocr result: ' + JSON.stringify(analysisData));
    }
    fetchResult.close();
  } catch (err) {
    console.error(`getAnalysisDataDemofailed with error: ${err.code}, ${err.message}`);
  }
}
```

### getFaceId<sup>13+</sup>

getFaceId(): Promise\<string>

获取人像相册或合影相册的封面人脸标识。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.READ\_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**返回值：**

| 类型                | 说明                                |
| :------------------ | :---------------------------------- |
| Promise&lt;string&gt; | Promise对象，人像相册返回tag_id，合影相册返回group_tag，未找到返回空字符串。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                     |
| :------- | :----------------------------------------------------------- |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 14000011 | Internal system error                                        |

**示例：**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('getFaceIdDemo');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.equalTo("user_display_level", 1);
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult =
      await phAccessHelper.getAlbums(sendablePhotoAccessHelper.AlbumType.SMART,
        sendablePhotoAccessHelper.AlbumSubtype.PORTRAIT,
        fetchOptions);
    let album = await fetchResult?.getFirstObject();
    let faceId = await album?.getFaceId();
    console.info(`getFaceId successfully, faceId: ${faceId}`);
    fetchResult.close();
  } catch (err) {
    console.error(`getFaceId failed with err: ${err.code}, ${err.message}`);
  }
}
```

## Album

实体相册

## AlbumType

枚举，相册类型，表示是用户相册还是系统预置相册。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称  | 值   | 说明                                           |
| ----- | ---- | ---------------------------------------------- |
| SMART | 4096 | 智慧分析相册。**系统接口**：此接口为系统接口。 |

## AlbumSubtype

枚举，相册子类型，表示具体的相册类型。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                  | 值   | 说明                                                       |
| --------------------- | ---- | ---------------------------------------------------------- |
| HIDDEN                | 1027 | 隐藏相册。**系统接口**：此接口为系统接口。                 |
| TRASH                 | 1028 | 回收站。**系统接口**：此接口为系统接口。                   |
| SCREENSHOT            | 1029 | 截屏和录屏相册。**系统接口**：此接口为系统接口。           |
| CAMERA                | 1030 | 相机拍摄的照片和视频相册。**系统接口**：此接口为系统接口。 |
| SOURCE\_GENERIC       | 2049 | 来源相册。**系统接口**：此接口为系统接口。                 |
| CLASSIFY              | 4097 | 分类相册。**系统接口**：此接口为系统接口。                 |
| GEOGRAPHY\_LOCATION   | 4099 | 地图相册。**系统接口**：此接口为系统接口。                 |
| GEOGRAPHY\_CITY       | 4100 | 城市相册。**系统接口**：此接口为系统接口。                 |
| SHOOTING\_MODE        | 4101 | 拍摄模式相册。**系统接口**：此接口为系统接口。             |
| PORTRAIT              | 4102 | 人像相册。**系统接口**：此接口为系统接口。                 |
| GROUP_PHOTO           | 4103 | 合影相册。**系统接口**：此接口为系统接口。                 |
| HIGHLIGHT             | 4104 | 时刻相册。**系统接口**：此接口为系统接口。                 |
| HIGHLIGHT_SUGGESTIONS | 4105 | 时刻建议相册。**系统接口**：此接口为系统接口。             |
