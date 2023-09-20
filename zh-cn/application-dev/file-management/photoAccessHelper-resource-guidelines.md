# 媒体资源使用指导

应用可以通过photoAccessHelper的接口，对媒体资源（图片、视频）进行相关操作。

> **说明：**
>
> 在进行功能开发前，请开发者查阅[相册管理模块开发概述](photoAccessHelper-overview.md)，了解如何获取相册管理模块实例和如何申请相册管理模块功能开发相关权限。
> 文档中使用到photoAccessHelper的地方默认为使用相册管理模块开发概述中获取的对象，如未添加此段代码报photoAccessHelper未定义的错误请自行添加。

为了保证应用的运行效率，大部分PhotoAccessHelper调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用Promise函数，更多方式可以查阅[API参考](../reference/apis/js-apis-photoAccessHelper.md)。

## 获取指定媒体资源

开发者可以根据特定的条件查询媒体资源，如指定类型、指定日期、指定相册等。

应用通过调用[PhotoAccessHelper.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets)获取媒体资源，并传入[FetchOptions](../reference/apis/js-apis-photoAccessHelper.md#fetchoptions)对象指定检索条件。如无特别说明，文档中涉及的待获取的资源均视为已经预置且在数据库中存在相应数据。如出现按照示例代码执行出现获取资源为空的情况请确认文件是否已预置，数据库中是否存在该文件的数据。

如果只想获取某个位置的对象（如第一个、最后一个、指定索引等），可以通过[FetchFileResult](../reference/apis/js-apis-photoAccessHelper.md#fetchresult)中的接口获取对应位置的媒体资源对象。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块读权限'ohos.permission.READ_IMAGEVIDEO'。
- 导入[dataSharePredicates](../reference/apis/js-apis-data-dataSharePredicates.md)模块。

### 指定媒体文件名获取图片或视频资源

下面以查询文件名为'test.jpg'的图片资源为例。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
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
    let fileAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets fileAsset.displayName : ' + fileAsset.displayName);
    fetchResult.close();
  } catch (err) {
    console.error('getAssets failed with err: ' + err);
  }
}
```

### 指定URI获取图片或视频资源

下面以查询指定URI为'file://media/Photo/1'为例。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo(photoAccessHelper.PhotoKeys.URI, 'file://media/Photo/1');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let fileAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets fileAsset.uri : ' + fileAsset.uri);
    fetchResult.close();
  } catch (err) {
    console.error('getAssets failed with err: ' + err);
  }
}
```

### 指定文件添加的时间获取图片或视频资源

下面以查询指定添加时间为'2022-06-01'至'2023-06-01'这一年内为例。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let startTime = Date.parse(new Date('2022-06-01').toString()) / 1000; // 查询起始时间距1970年1月1日的秒数值。
  let endTime = Date.parse(new Date('2023-06-01').toString()) / 1000;  // 查询结束时间距1970年1月1日的秒数值。
  let date_added: photoAccessHelper.PhotoKeys = photoAccessHelper.PhotoKeys.DATE_ADDED;
  predicates.between(date_added, startTime, endTime);
  predicates.orderByDesc(date_added); // 查询结果按照降序排序。
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [date_added], // date_added属性不属于默认查询列，需要自行添加。
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    console.info('getAssets count: ' + fetchResult.getCount());
    let fileAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets fileAsset.displayName : ' + fileAsset.displayName);
    fetchResult.close();
  } catch (err) {
    console.error('getAssets failed with err: ' + err);
  }
}
```

## 获取图片和视频缩略图

通过接口[FileAsset.getThumbnail](../reference/apis/js-apis-photoAccessHelper.md#getthumbnail)，传入缩略图尺寸，可以获取图片和视频缩略图。缩略图常用于UI界面展示。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块读权限'ohos.permission.READ_IMAGEVIDEO'。
- 导入[dataSharePredicates](../reference/apis/js-apis-data-dataSharePredicates.md)模块。

### 获取某张图片的缩略图

当需要在相册展示图片和视频、编辑预览，应用需要获取某张图片的缩略图。

下面以获取一张图片的缩略图为例，缩略图尺寸为720*720。

**开发步骤：**

1. 建立检索条件，用于获取图片资源。
2. 调用PhotoAccessHelper.getAssets接口获取图片资源。
3. 调用[FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject)接口获取第一张图片。
4. 调用getThumbnail获取图片的缩略图的[PixelMap](../reference/apis/js-apis-image.md#pixelmap7)。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import image from '@ohos.multimedia.image';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let fileAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets fileAsset.displayName : ' + fileAsset.displayName);
    let size: image.Size = { width: 720, height: 720 };
    let pixelMap: image.PixelMap =  await fileAsset.getThumbnail(size);
    let imageInfo: image.ImageInfo = await pixelMap.getImageInfo()
    console.info('getThumbnail successful, pixelMap ImageInfo size: ' + JSON.stringify(imageInfo.size));
    fetchResult.close();
  } catch (err) {
    console.error('getThumbnail failed with err: ' + err);
  }
}
```

## 创建媒体资源

通过接口[createAsset](../reference/apis/js-apis-photoAccessHelper.md#createasset)创建媒体资源。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.WRITE_IMAGEVIDEO'。

### 创建图片或视频资源

下面以创建一张图片资源为例。

**开发步骤：**

1. 设置文件名并建立创建选项，用于创建图片资源时设置属性。
2. 调用createAsset接口创建图片资源。

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  try {
    let displayName: string = 'testPhoto' + Date.now() + '.jpg';
    let createOption: photoAccessHelper.PhotoCreateOptions = {
      subtype: photoAccessHelper.PhotoSubtype.DEFAULT
    };

    let fileAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(displayName, createOption);
    console.info('createAsset successfully, file displayName: ' + fileAsset.displayName);
  } catch (err) {
    console.error('createAsset failed, message = ', err);
  }
}
```

## 重命名媒体资源

重命名修改的是文件的FileAsset.displayName属性，即文件的显示文件名，包含文件后缀。

修改后再通过[FileAsset.commitModify](../reference/apis/js-apis-photoAccessHelper.md#commitmodify)更新到数据库中完成修改。

在重命名文件之前，需要先获取文件对象，可以通过[FetchResult](../reference/apis/js-apis-photoAccessHelper.md#fetchresult)中的接口获取对应位置的文件。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.WRITE_IMAGEVIDEO'和'ohos.permission.READ_IMAGEVIDEO'。

下面以将获取的图片资源中第一个文件重命名为例。

**开发步骤：**

1. 建立检索条件，用于获取图片资源。
2. 调用getAssets接口获取目标图片资源。
3. 调用[FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject)接口获取第一张图片，即要重命名的图片对象。
4. 调用FileAsset.set接口将图片重命名为新的名字。
5. 调用FileAsset.commitModify接口将修改的图片属性更新到数据库中完成修改。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: ['title'],
    predicates: predicates
  };
  let newTitle = 'newTestPhoto';

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let fileAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let title: photoAccessHelper.PhotoKeys = photoAccessHelper.PhotoKeys.TITLE;
    let fileAssetTitle: photoAccessHelper.MemberType = fileAsset.get(title);
    console.info('getAssets fileAsset.title : ' + fileAssetTitle);
    fileAsset.set(title, newTitle);
    await fileAsset.commitModify();
    fetchResult.close();
  } catch (err) {
    console.error('commitModify failed with err: ' + err);
  }
}
```

## 将文件放入回收站

通过[deleteAssets](../reference/apis/js-apis-photoAccessHelper.md#deleteassets)可以将文件放入回收站。

放入回收站的文件将会保存30天，30天后会自动彻底删除。在此期间，应用用户可以通过系统应用“文件管理”或“图库”恢复文件。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.WRITE_IMAGEVIDEO'和'ohos.permission.READ_IMAGEVIDEO'。

下面以将文件检索结果中第一个文件放入回收站为例。

**开发步骤：**

1. 建立检索条件，用于获取图片资源。
2. 调用PhotoAccessHelper.getAssets接口获取目标图片资源。
3. 调用[FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject)接口获取第一张图片，即要放入回收站的图片对象。
4. 调用deleteAssets接口将文件放入回收站。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let fileAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets fileAsset.uri : ' + fileAsset.uri);
    await phAccessHelper.deleteAssets([fileAsset.uri]);
    fetchResult.close();
  } catch (err) {
    console.error('deleteAssets failed with err: ' + err);
  }
}
```
