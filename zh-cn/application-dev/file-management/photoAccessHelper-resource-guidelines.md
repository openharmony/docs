# 媒体资源使用指导

应用可以通过photoAccessHelper的接口，对媒体资源（图片、视频）进行相关操作。

> **说明：**
>
> - 在进行功能开发前，请开发者查阅[相册管理模块开发概述](photoAccessHelper-overview.md)，了解如何获取相册管理模块实例和如何申请相册管理模块功能开发相关权限。
> - 文档中使用到photoAccessHelper的地方默认为使用相册管理模块开发概述中获取的对象，如未添加此段代码报photoAccessHelper未定义的错误请自行添加。

为了保证应用的运行效率，大部分PhotoAccessHelper调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用Promise函数，更多方式可以查阅[API参考](../reference/apis/js-apis-photoAccessHelper.md)。

## 获取指定媒体资源

开发者可以根据特定的条件查询媒体资源，如指定类型、指定日期、指定相册等。

应用通过调用[PhotoAccessHelper.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-1)获取媒体资源，并传入[FetchOptions](../reference/apis/js-apis-photoAccessHelper.md#fetchoptions)对象指定检索条件。如无特别说明，文档中涉及的待获取的资源均视为已经预置且在数据库中存在相应数据。如出现按照示例代码执行出现获取资源为空的情况请确认文件是否已预置，数据库中是否存在该文件的数据。

如果只想获取某个位置的对象（如第一个、最后一个、指定索引等），可以通过[FetchResult](../reference/apis/js-apis-photoAccessHelper.md#fetchresult)中的接口获取对应位置的媒体资源对象。

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
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.displayName : ' + photoAsset.displayName);
    fetchResult.close();
  } catch (err) {
    console.error('getAssets failed with err: ' + err);
  }
}
```

### 指定URI获取图片或视频资源

下面以查询指定URI为'file://media/Photo/1/IMG_datetime_0001/displayName.jpg'为例。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let uri = 'file://media/Photo/1/IMG_datetime_0001/displayName.jpg' // 需保证此uri已存在。
  predicates.equalTo(photoAccessHelper.PhotoKeys.URI, uri.toString());
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.uri : ' + photoAsset.uri);
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
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.displayName : ' + photoAsset.displayName);
    fetchResult.close();
  } catch (err) {
    console.error('getAssets failed with err: ' + err);
  }
}
```

## 获取图片和视频缩略图

通过接口[PhotoAsset.getThumbnail](../reference/apis/js-apis-photoAccessHelper.md#getthumbnail-2)，传入缩略图尺寸，可以获取图片和视频缩略图。缩略图常用于UI界面展示。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块读权限'ohos.permission.READ_IMAGEVIDEO'。
- 导入[dataSharePredicates](../reference/apis/js-apis-data-dataSharePredicates.md)模块。

### 获取某张图片的缩略图

当需要在相册展示图片和视频、编辑预览，应用需要获取某张图片的缩略图。

下面以获取一张图片的缩略图为例，缩略图尺寸为720*720。

**开发步骤：**

1. 建立检索条件，用于获取图片资源。
2. 调用[PhotoAccessHelper.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-1)接口获取图片资源。
3. 调用[FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject-1)接口获取第一张图片。
4. 调用PhotoAsset.getThumbnail获取图片的缩略图的[PixelMap](../reference/apis/js-apis-image.md#pixelmap7)。

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
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.displayName : ' + photoAsset.displayName);
    let size: image.Size = { width: 720, height: 720 };
    let pixelMap: image.PixelMap =  await photoAsset.getThumbnail(size);
    let imageInfo: image.ImageInfo = await pixelMap.getImageInfo()
    console.info('getThumbnail successful, pixelMap ImageInfo size: ' + JSON.stringify(imageInfo.size));
    fetchResult.close();
  } catch (err) {
    console.error('getThumbnail failed with err: ' + err);
  }
}
```

## 创建媒体资源

通过接口[PhotoAccessHelper.createAsset](../reference/apis/js-apis-photoAccessHelper.md#createasset-3)创建媒体资源。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.WRITE_IMAGEVIDEO'。

### 创建图片或视频资源

下面以创建一张图片资源为例。

**开发步骤：**

1. 设置文件名并建立创建选项，用于创建图片资源时设置属性。
2. 调用PhotoAccessHelper.createAsset接口创建图片资源。

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

    let photoAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(displayName, createOption);
    console.info('createAsset successfully, file displayName: ' + photoAsset.displayName);
  } catch (err) {
    console.error('createAsset failed, message = ', err);
  }
}
```

## 使用安全控件创建媒体资源

下面以使用安全控件创建一张图片资源为例。使用安全控件创建媒体资源无需在应用中申请相册管理模块权限'ohos.permission.WRITE_IMAGEVIDEO'，详情请参考[安全控件的保存控件](../reference/arkui-ts/ts-security-components-savebutton.md)。

**开发步骤：**

1. 设置安全控件按钮属性。
2. 创建安全控件按钮。
3. 调用[PhotoAccessHelper.createAsset](../reference/apis/js-apis-photoAccessHelper.md#createasset-6)接口创建图片资源。

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper'
import fs from '@ohos.file.fs';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'
  @State saveButtonOptions: SaveButtonOptions = {
    icon: SaveIconStyle.FULL_FILLED,
    text: SaveDescription.SAVE_IMAGE,
    buttonType: ButtonType.Capsule
  } // 设置安全控件按钮属性

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        SaveButton(this.saveButtonOptions) // 创建安全控件按钮
          .onClick(async (event, result: SaveButtonOnClickResult) => {
             if (result == SaveButtonOnClickResult.SUCCESS) {
               try {
                 let context = getContext();
                 let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
                 let uri = await phAccessHelper.createAsset(photoAccessHelper.PhotoType.IMAGE, 'jpg'); // 创建媒体文件
                 console.info('createAsset successfully, uri: ' + uri);
                 let file = await fs.open(uri, fs.OpenMode.READ_WRITE);
                 await fs.close(file);
               } catch (err) {
                 console.error('createAsset failed, message = ', err);
               }
             } else {
               console.error('SaveButtonOnClickResult createAsset failed');
             }
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 重命名媒体资源

重命名修改的是文件的PhotoAsset.displayName属性，即文件的显示文件名，包含文件后缀。

修改后再通过[PhotoAsset.commitModify](../reference/apis/js-apis-photoAccessHelper.md#commitmodify-1)更新到数据库中完成修改。

在重命名文件之前，需要先获取文件对象，可以通过[FetchResult](../reference/apis/js-apis-photoAccessHelper.md#fetchresult)中的接口获取对应位置的文件。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.WRITE_IMAGEVIDEO'和'ohos.permission.READ_IMAGEVIDEO'。

下面以将获取的图片资源中第一个文件重命名为例。

**开发步骤：**

1. 建立检索条件，用于获取图片资源。
2. 调用[PhotoAccessHelper.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-1)接口获取目标图片资源。
3. 调用[FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject-1)接口获取第一张图片，即要重命名的图片对象。
4. 调用[PhotoAsset.set](../reference/apis/js-apis-photoAccessHelper.md#set)接口将图片重命名为新的名字。
5. 调用PhotoAsset.commitModify接口将修改的图片属性更新到数据库中完成修改。

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
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let title: photoAccessHelper.PhotoKeys = photoAccessHelper.PhotoKeys.TITLE;
    let photoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title);
    console.info('getAssets photoAsset.title : ' + photoAssetTitle);
    photoAsset.set(title, newTitle);
    await photoAsset.commitModify();
    fetchResult.close();
  } catch (err) {
    console.error('commitModify failed with err: ' + err);
  }
}
```

## 将文件放入回收站

通过[PhotoAccessHelper.deleteAssets](../reference/apis/js-apis-photoAccessHelper.md#deleteassets-1)可以将文件放入回收站。

放入回收站的文件将会保存30天，30天后会自动彻底删除。在此期间，应用用户可以通过系统应用“文件管理”或“图库”恢复文件。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.WRITE_IMAGEVIDEO'和'ohos.permission.READ_IMAGEVIDEO'。

下面以将文件检索结果中第一个文件放入回收站为例。

**开发步骤：**

1. 建立检索条件，用于获取图片资源。
2. 调用[PhotoAccessHelper.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-1)接口获取目标图片资源。
3. 调用[FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject-1)接口获取第一张图片，即要放入回收站的图片对象。
4. 调用PhotoAccessHelper.deleteAssets接口将文件放入回收站。

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
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.uri : ' + photoAsset.uri);
    await phAccessHelper.deleteAssets([photoAsset.uri]);
    fetchResult.close();
  } catch (err) {
    console.error('deleteAssets failed with err: ' + err);
  }
}
```

## 使用Picker选择媒体库资源

用户有时需要分享图片、视频等用户文件，开发者可以通过特定接口拉起系统图库，用户自行选择待分享的资源，然后最终分享出去。此接口本身无需申请权限，目前适用于界面UIAbility，使用窗口组件触发。具体使用方式如下：

1. 导入选择器模块和文件管理模块。

   ```ts
   import photoAccessHelper from '@ohos.file.photoAccessHelper';
   import fs from '@ohos.file.fs';
   import { BusinessError } from '@ohos.base';
   ```

2. 创建图片-音频类型文件选择选项实例。

   ```ts
   const photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
   ```

3. 选择媒体文件类型和选择媒体文件的最大数目。
   以下示例以图片选择为例，媒体文件类型请参见[PhotoViewMIMETypes](../reference/apis/js-apis-photoAccessHelper.md#photoviewmimetypes)。

   ```ts
   photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE; // 过滤选择媒体文件类型为IMAGE
   photoSelectOptions.maxSelectNumber = 5; // 选择媒体文件的最大数目
   ```

4. 创建图库选择器实例，调用[PhotoViewPicker.select](../reference/apis/js-apis-photoAccessHelper.md#select)接口拉起图库界面进行文件选择。文件选择成功后，返回[PhotoSelectResult](../reference/apis/js-apis-photoAccessHelper.md#photoselectresult)结果集。

   select返回的uri权限是只读权限，可以根据结果集中uri进行读取文件数据操作。注意不能在picker的回调里直接使用此uri进行打开文件操作，需要定义一个全局变量保存uri，使用类似一个按钮去触发打开文件。

   如有获取元数据需求，可以通过[文件管理接口](../reference/apis/js-apis-file-fs.md)和[文件URI](../reference/apis/js-apis-file-fileuri.md)根据uri获取部分文件属性信息，比如文件大小、访问时间、修改时间、文件名、文件路径等。

   ```ts
   let uris: Array<string> = [];
   const photoViewPicker = new photoAccessHelper.PhotoViewPicker();
   photoViewPicker.select(photoSelectOptions).then((photoSelectResult: photoAccessHelper.PhotoSelectResult) => {
     uris = photoSelectResult.photoUris;
     console.info('photoViewPicker.select to file succeed and uris are:' + uris);
   }).catch((err: BusinessError) => {
     console.error(`Invoke photoViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

5. 待界面从图库返回后，再通过类似一个按钮调用其他函数，使用[fs.openSync](../reference/apis/js-apis-file-fs.md#fsopensync)接口，通过uri打开这个文件得到fd。这里需要注意接口权限参数是fs.OpenMode.READ_ONLY。

   ```ts
   let uri: string = '';
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

6. 通过fd使用[fs.readSync](../reference/apis/js-apis-file-fs.md#readsync)接口读取这个文件内的数据，读取完成后关闭fd。

   ```ts
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   fs.closeSync(file);
   ```
