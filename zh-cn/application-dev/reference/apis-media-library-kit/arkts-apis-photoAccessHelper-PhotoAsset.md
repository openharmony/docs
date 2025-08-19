# Interface (PhotoAsset)
<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

提供封装文件属性的方法。

## 导入模块

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
```

## 属性

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                      | 类型                     | 可读 | 可写 | 说明                                                   |
| ------------------------- | ------------------------ | ---- | ---- | ------------------------------------------------------ |
| uri                       | string                   | 是   | 否   | 媒体文件资源uri（如：file://media/Photo/1/IMG_datetime_0001/displayName.jpg），详情参见用户文件uri介绍中的[媒体文件uri](../../file-management/user-file-uri-intro.md#媒体文件uri)<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| photoType   | [PhotoType](arkts-apis-photoAccessHelper-e.md#phototype) | 是   | 否   | 媒体文件类型。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。                                               |
| displayName               | string                   | 是   | 否   | 显示文件名，包含后缀名。字符串长度为1~255。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。           |

## get

get(member: string): MemberType

获取PhotoAsset成员参数的值。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明    |
| -------- | ------------------------- | ---- | ----- |
| member | string | 是    | 成员参数名称，在get时，除了'uri'、'media_type'、'subtype'和'display_name'四个属性之外，其他的属性都需要在fetchColumns中填入需要获取的[PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys)，例如：get title属性fetchColumns: ['title']。 |

**返回值：**

| 类型                | 说明                              |
| ------------------- | --------------------------------- |
| [MemberType](arkts-apis-photoAccessHelper-t.md#membertype) | 获取PhotoAsset成员参数的值。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020     | Invalid argument.         |
| 14000014     | The provided member must be a property name of PhotoKey.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('photoAssetGetDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: ['title'],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let title: photoAccessHelper.PhotoKeys = photoAccessHelper.PhotoKeys.TITLE;
    let photoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title.toString());
    console.info('photoAsset Get photoAssetTitle = ', photoAssetTitle);
  } catch (err) {
    console.error(`release failed. error: ${err.code}, ${err.message}`);
  }
}
```

## set

set(member: string, value: string): void

设置PhotoAsset成员参数。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明    |
| -------- | ------------------------- | ---- | ----- |
| member | string | 是    | 成员参数名称例如：[PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).TITLE。字符串长度为1~255。 |
| value | string | 是    | 设置成员参数名称，只能修改[PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).TITLE的值。title的参数规格为：<br>- 不应包含扩展名。<br>- 文件名字符串长度为1~255（资产文件名为标题+扩展名）。<br>- 不允许出现的非法英文字符，包括：. \ / : * ? " ' ` < > \| { } [ ]  |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900020     | Invalid argument.         |
| 14000014     | The provided member must be a property name of PhotoKey.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('photoAssetSetDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: ['title'],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let title: string = photoAccessHelper.PhotoKeys.TITLE.toString();
    photoAsset.set(title, 'newTitle');
  } catch (err) {
    console.error(`release failed. error: ${err.code}, ${err.message}`);
  }
}
```

## commitModify

commitModify(callback: AsyncCallback&lt;void&gt;): void

修改文件的元数据，使用callback方式返回异步结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明    |
| -------- | ------------------------- | ---- | ----- |
| callback | AsyncCallback&lt;void&gt; | 是    | callback返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

错误码14000001，请参考 [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys)获取有关文件名的格式和长度要求。

错误码13900012，请参考[开发准备](../../media/medialibrary/photoAccessHelper-preparation.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 201     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000001      | Invalid display name.         |
| 14000011       | System inner fail.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('commitModifyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: ['title'],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  let title: string = photoAccessHelper.PhotoKeys.TITLE.toString();
  let photoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title);
  console.info('photoAsset get photoAssetTitle = ', photoAssetTitle);
  photoAsset.set(title, 'newTitle2');
  photoAsset.commitModify((err) => {
    if (err === undefined) {
      let newPhotoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title);
      console.info('photoAsset get newPhotoAssetTitle = ', newPhotoAssetTitle);
    } else {
      console.error(`commitModify failed, error: ${err.code}, ${err.message}`);
    }
  });
}
```

## commitModify

commitModify(): Promise&lt;void&gt;

修改文件的元数据，使用promise方式返回异步结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**返回值：**

| 类型                  | 说明         |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

错误码14000001，请参考 [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys)获取有关文件名的格式和长度要求。

在API 13及之前的版本，无相关权限返回错误码13900012；从API 14开始，无相关权限返回错误码201。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 201     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000001      | Invalid display name.         |
| 14000011       | System inner fail.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('commitModifyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: ['title'],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  let title: string = photoAccessHelper.PhotoKeys.TITLE.toString();
  let photoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title);
  console.info('photoAsset get photoAssetTitle = ', photoAssetTitle);
  photoAsset.set(title, 'newTitle3');
  try {
    await photoAsset.commitModify();
    let newPhotoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title);
    console.info('photoAsset get newPhotoAssetTitle = ', newPhotoAssetTitle);
  } catch (err) {
    console.error(`release failed. error: ${err.code}, ${err.message}`);
  }
}
```

## close<sup>(deprecated)</sup>

close(fd: number, callback: AsyncCallback&lt;void&gt;): void

关闭当前文件，使用callback方式返回异步结果。

> **说明：**
>
> 从API version 10开始支持，从API version 11开始废弃。出于安全考量，不再提供获取正式媒体文件句柄的接口。对应的close接口一并废弃。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明    |
| -------- | ------------------------- | ---- | ----- |
| fd       | number                    | 是    | 文件描述符。 |
| callback | AsyncCallback&lt;void&gt; | 是    | callback返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('closeDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let fd: number = await photoAsset.open('rw');
    console.info('file fd', fd);
    photoAsset.close(fd, (err) => {
      if (err === undefined) {
        console.info('asset close succeed.');
      } else {
        console.error(`close failed, error: ${err.code}, ${err.message}`);
      }
    });
  } catch (err) {
    console.error(`close failed, error: ${err.code}, ${err.message}`);
  }
}
```

## close<sup>(deprecated)</sup>

close(fd: number): Promise&lt;void&gt;

关闭当前文件，使用promise方式返回异步结果。

> **说明：**
>
> 从API version 10开始支持，从API version 11开始废弃。出于安全考量，不再提供获取正式媒体文件句柄的接口。对应的close接口一并废弃。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| fd   | number | 是    | 文件描述符。 |

**返回值：**

| 类型                  | 说明         |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('closeDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let fd = await asset.open('rw');
    console.info('file fd', fd);
    await asset.close(fd);
    console.info('asset close succeed.');
  } catch (err) {
    console.error(`close failed, error: ${err.code}, ${err.message}`);
  }
}
```

## getThumbnail

getThumbnail(callback: AsyncCallback&lt;image.PixelMap&gt;): void

获取文件的缩略图，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名      | 类型                                  | 必填   | 说明               |
| -------- | ----------------------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | 是    | callback返回缩略图的PixelMap。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

错误码13900012，请参考[开发准备](../../media/medialibrary/photoAccessHelper-preparation.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getThumbnailDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName);
  asset.getThumbnail((err, pixelMap) => {
    if (err === undefined) {
      console.info('getThumbnail successful ' + pixelMap);
    } else {
      console.error(`getThumbnail fail with error: ${err.code}, ${err.message}`);
    }
  });
}
```

## getThumbnail

getThumbnail(size: image.Size, callback: AsyncCallback&lt;image.PixelMap&gt;): void

获取文件的缩略图，传入缩略图尺寸，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名      | 类型                                  | 必填   | 说明               |
| -------- | ----------------------------------- | ---- | ---------------- |
| size     | [image.Size](../apis-image-kit/arkts-apis-image-i.md#size) | 是    | 缩略图尺寸。            |
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | 是    | callback返回缩略图的PixelMap。 |

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
import { image } from '@kit.ImageKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getThumbnailDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let size: image.Size = { width: 720, height: 720 };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName);
  asset.getThumbnail(size, (err, pixelMap) => {
    if (err === undefined) {
      console.info('getThumbnail successful ' + pixelMap);
    } else {
      console.error(`getThumbnail fail with error: ${err.code}, ${err.message}`);
    }
  });
}
```

## getThumbnail

getThumbnail(size?: image.Size): Promise&lt;image.PixelMap&gt;

获取文件的缩略图，传入缩略图尺寸，使用promise方式返回异步结果。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名  | 类型             | 必填   | 说明    |
| ---- | -------------- | ---- | ----- |
| size | [image.Size](../apis-image-kit/arkts-apis-image-i.md#size) | 否    | 缩略图尺寸。 |

**返回值：**

| 类型                            | 说明                    |
| ----------------------------- | --------------------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Promise对象，返回缩略图的PixelMap。 |

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
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getThumbnailDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let size: image.Size = { width: 720, height: 720 };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName);
  asset.getThumbnail(size).then((pixelMap) => {
    console.info('getThumbnail successful ' + pixelMap);
  }).catch((err: BusinessError) => {
    console.error(`getThumbnail fail with error: ${err.code}, ${err.message}`);
  });
}
```

## clone<sup>14+</sup>

clone(title: string): Promise&lt;PhotoAsset&gt;

克隆资产。可设置文件名，但不支持修改文件类型。

**需要权限**：ohos.permission.WRITE\_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名        | 类型      | 必填   | 说明                                 |
| ---------- | ------- | ---- | ---------------------------------- |
| title| string | 是    | 克隆后资产的标题。参数规格为：<br>- 不应包含扩展名。<br>- 文件名字符串长度为1~255（资产文件名为标题+扩展名）。<br>- 不允许出现的非法英文字符，包括：. \ / : * ? " ' ` < > \| { } [ ] |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;[PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)&gt; | Promise对象，返回[PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID    | 错误信息                              |
| :------- | :-------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { systemDateTime } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let title: string = systemDateTime.getTime().toString();
    let newAsset: photoAccessHelper.PhotoAsset = await photoAsset.clone(title);
    console.info('get new asset successfully');
  } catch (error) {
    console.error(`failed to get new asset. message =  ${error.code}, ${error.message}`);
  }
}
```

## getReadOnlyFd<sup>(deprecated)</sup>

getReadOnlyFd(callback: AsyncCallback&lt;number&gt;): void

以只读方式打开当前文件，使用callback方式返回异步结果。

> **说明：**
>
> 从API version 10开始支持，从API version 11开始废弃。出于安全考量，不再提供获取正式媒体文件句柄的接口。

**注意**：使用完毕后调用close释放文件描述符。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名      | 类型                          | 必填   | 说明                                  |
| -------- | --------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是    | callback返回文件描述符。                            |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

在API 13及之前的版本，无相关权限返回错误码13900012；从API 14开始，无相关权限返回错误码201。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 201     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.        |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getReadOnlyFdDemo');
  // 需要保证设备中存在可读取图片视频文件。
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let assetResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
  let photoAsset: photoAccessHelper.PhotoAsset = await assetResult.getFirstObject();
  photoAsset.getReadOnlyFd((err, fd) => {
    if (fd !== undefined) {
      console.info('File fd' + fd);
      photoAsset.close(fd);
    } else {
      console.error(`getReadOnlyFd err: ${err.code}, ${err.message}`);
    }
  });
}
```

## getReadOnlyFd<sup>(deprecated)</sup>

getReadOnlyFd(): Promise&lt;number&gt;

以只读方式打开当前文件，使用promise方式返回异步结果。

> **说明：**
>
> 从API version 10开始支持，从API version 11开始废弃。出于安全考量，不再提供获取正式媒体文件句柄的接口。

**注意**：返回的文件描述符在使用完毕后需要调用close进行释放。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**返回值：**

| 类型                    | 说明            |
| --------------------- | ------------- |
| Promise&lt;number&gt; | Promise对象，返回文件描述符。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

在API 13及之前的版本，无相关权限返回错误码13900012；从API 14开始，无相关权限返回错误码201。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 201     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.        |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getReadOnlyFdDemo');
  try {
    // 需要保证设备中存在可读取图片视频文件。
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let assetResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await assetResult.getFirstObject();
    let fd: number = await photoAsset.getReadOnlyFd();
    if (fd !== undefined) {
      console.info('File fd' + fd);
      photoAsset.close(fd);
    } else {
      console.error('getReadOnlyFd fail');
    }
  } catch (err) {
    console.error(`getReadOnlyFd demo err: ${err.code}, ${err.message}`);
  }
}
```

