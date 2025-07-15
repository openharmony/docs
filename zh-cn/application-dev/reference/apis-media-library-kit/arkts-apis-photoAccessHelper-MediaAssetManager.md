# Class (MediaAssetManager)

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Class首批接口从API version 11开始支持。

媒体资产管理类，管理媒体资源读取。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

## 导入模块

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
```

## requestImage<sup>11+</sup>

static requestImage(context: Context, asset: PhotoAsset, requestOptions: RequestOptions, dataHandler: MediaAssetDataHandler&lt;image.ImageSource&gt;): Promise&lt;string&gt;

根据不同的策略模式，请求图片资源。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

- 通过picker的方式调用该接口来请求图片资源，不需要申请'ohos.permission.READ_IMAGEVIDEO'权限，详情请参考[开发指南](../../media/medialibrary/photoAccessHelper-photoviewpicker.md#指定uri获取图片或视频资源)。
- 对于本应用保存到媒体库的图片资源，应用无需额外申请'ohos.permission.READ_IMAGEVIDEO'权限即可访问。

**参数：**

| 参数名            | 类型                                                                                                        | 必填 | 说明                      |
|----------------|-----------------------------------------------------------------------------------------------------------| ---- | ------------------------- |
| context        | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                                                           | 是   | 传入Ability实例的上下文。 |
| asset         | [PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)                                                                                | 是   | 待请求的媒体文件对象。 |
| requestOptions | [RequestOptions](arkts-apis-photoAccessHelper-i.md#requestoptions11)                                                                        | 是   | 图片请求策略模式配置项。|
| dataHandler    | [MediaAssetDataHandler](arkts-apis-photoAccessHelper-MediaAssetDataHandler.md)&lt;[image.ImageSource](../apis-image-kit/arkts-apis-image-ImageSource.md)&gt; | 是   | 媒体资源处理器，请求完成时触发回调。|

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise\<string> | Promise对象，返回请求id，可用于[cancelRequest](#cancelrequest12)取消请求。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201      |  Permission denied         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail. Possible causes: 1. The database is corrupted; 2. The file system is abnormal; 3. The IPC request timed out; 4. Permission denied.        |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';

class MediaHandler implements photoAccessHelper.MediaAssetDataHandler<image.ImageSource> {
  onDataPrepared(data: image.ImageSource) {
    if (data === undefined) {
      console.error('Error occurred when preparing data');
      return;
    }
    console.info('on image data prepared');
  }
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('requestImage');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let requestOptions: photoAccessHelper.RequestOptions = {
    deliveryMode: photoAccessHelper.DeliveryMode.HIGH_QUALITY_MODE,
  }
  const handler = new MediaHandler();

  phAccessHelper.getAssets(fetchOptions, async (err, fetchResult) => {
      console.info('fetchResult success');
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      await photoAccessHelper.MediaAssetManager.requestImage(context, photoAsset, requestOptions, handler);
      console.info('requestImage successfully');
  });
}
```

## requestImageData<sup>11+</sup>

static requestImageData(context: Context, asset: PhotoAsset, requestOptions: RequestOptions, dataHandler: MediaAssetDataHandler&lt;ArrayBuffer&gt;): Promise&lt;string&gt;

根据不同的策略模式，请求图片资源数据。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

- 通过picker的方式调用该接口来请求图片资源数据，不需要申请'ohos.permission.READ_IMAGEVIDEO'权限，详情请参考[开发指南](../../media/medialibrary/photoAccessHelper-photoviewpicker.md#指定uri获取图片或视频资源)。
- 对于本应用保存到媒体库的图片资源，应用无需额外申请'ohos.permission.READ_IMAGEVIDEO'权限即可访问。

**参数：**

| 参数名   | 类型                                                                   | 必填 | 说明                      |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                      | 是   | 传入Ability实例的上下文。 |
| asset | [PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)                                            | 是   | 待请求的媒体文件对象。 |
| requestOptions  | [RequestOptions](arkts-apis-photoAccessHelper-i.md#requestoptions11)                                  | 是   | 图片请求策略模式配置项。 |      
| dataHandler  | [MediaAssetDataHandler](arkts-apis-photoAccessHelper-MediaAssetDataHandler.md)&lt;ArrayBuffer&gt; | 是   | 媒体资源处理器，当所请求的图片资源准备完成时会触发回调。|

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise\<string> | Promise对象，返回请求id，可用于[cancelRequest](#cancelrequest12)取消请求。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201      |  Permission denied         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail. Possible causes: 1. The database is corrupted; 2. The file system is abnormal; 3. The IPC request timed out; 4. Permission denied.        |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

class MediaDataHandler implements photoAccessHelper.MediaAssetDataHandler<ArrayBuffer> {
  onDataPrepared(data: ArrayBuffer) {
    if (data === undefined) {
      console.error('Error occurred when preparing data');
      return;
    }
    console.info('on image data prepared');
  }
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('requestImageData');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let requestOptions: photoAccessHelper.RequestOptions = {
    deliveryMode: photoAccessHelper.DeliveryMode.HIGH_QUALITY_MODE,
  }
  const handler = new MediaDataHandler();

  phAccessHelper.getAssets(fetchOptions, async (err, fetchResult) => {
      console.info('fetchResult success');
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      await photoAccessHelper.MediaAssetManager.requestImageData(context, photoAsset, requestOptions, handler);
      console.info('requestImageData successfully');
  });
}
```

## requestMovingPhoto<sup>12+</sup>

static requestMovingPhoto(context: Context, asset: PhotoAsset, requestOptions: RequestOptions, dataHandler: MediaAssetDataHandler&lt;MovingPhoto&gt;): Promise&lt;string&gt;

根据不同的策略模式，请求动态照片对象。动态照片对象可用于请求动态照片的资源数据。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

- 通过picker的方式调用该接口来请求动态照片对象，不需要申请'ohos.permission.READ_IMAGEVIDEO'权限，详情请参考[开发指南](../../media/medialibrary/photoAccessHelper-photoviewpicker.md#指定uri获取图片或视频资源)。
- 对于本应用保存到媒体库的动态照片资源，应用无需额外申请'ohos.permission.READ_IMAGEVIDEO'权限即可访问。

**参数：**

| 参数名   | 类型                                                                   | 必填 | 说明                      |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                      | 是   | 传入Ability实例的上下文。 |
| asset | [PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)                                            | 是   | 待请求的媒体文件对象。 |
| requestOptions  | [RequestOptions](arkts-apis-photoAccessHelper-i.md#requestoptions11)                                  | 是   | 图片请求策略模式配置项。|       
| dataHandler  | [MediaAssetDataHandler](arkts-apis-photoAccessHelper-MediaAssetDataHandler.md)&lt;[MovingPhoto](arkts-apis-photoAccessHelper-MovingPhoto.md)&gt; | 是   | 媒体资源处理器，当所请求的图片资源准备完成时会触发回调。|

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise\<string> | Promise对象，返回请求id，可用于[cancelRequest](#cancelrequest12)取消请求。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201      |  Permission denied         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 801   | Capability not supported.       |
| 14000011       | System inner fail         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

class MovingPhotoHandler implements photoAccessHelper.MediaAssetDataHandler<photoAccessHelper.MovingPhoto> {
  async onDataPrepared(movingPhoto: photoAccessHelper.MovingPhoto) {
    if (movingPhoto === undefined) {
      console.error('Error occurred when preparing data');
      return;
    }
    console.info("moving photo acquired successfully, uri: " + movingPhoto.getUri());
  }
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo(photoAccessHelper.PhotoKeys.PHOTO_SUBTYPE, photoAccessHelper.PhotoSubtype.MOVING_PHOTO);
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  // 请确保图库内存在动态照片。
  let assetResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
  let asset: photoAccessHelper.PhotoAsset = await assetResult.getFirstObject();
  let requestOptions: photoAccessHelper.RequestOptions = {
    deliveryMode: photoAccessHelper.DeliveryMode.FAST_MODE,
  }
  const handler = new MovingPhotoHandler();
  try {
    let requestId: string = await photoAccessHelper.MediaAssetManager.requestMovingPhoto(context, asset, requestOptions, handler);
    console.info("moving photo requested successfully, requestId: " + requestId);
  } catch (err) {
    console.error(`failed to request moving photo, error code is ${err.code}, message is ${err.message}`);
  }
}

```

## requestVideoFile<sup>12+</sup>

static requestVideoFile(context: Context, asset: PhotoAsset, requestOptions: RequestOptions, fileUri: string, dataHandler: MediaAssetDataHandler&lt;boolean&gt;): Promise&lt;string&gt;

根据不同的策略模式，请求视频资源数据到沙箱路径。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

- 通过picker的方式调用该接口来请求视频资源数据到应用沙箱，不需要申请'ohos.permission.READ_IMAGEVIDEO'权限，详情请参考[开发指南](../../media/medialibrary/photoAccessHelper-photoviewpicker.md#指定uri获取图片或视频资源)。
- 对于本应用保存到媒体库的视频资源，应用无需额外申请'ohos.permission.READ_IMAGEVIDEO'权限即可访问。

**参数：**

| 参数名   | 类型                                                                   | 必填 | 说明                      |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                      | 是   | 传入Ability实例的上下文。|
| asset | [PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)                                            | 是   | 待请求的媒体文件对象。 |
| requestOptions  | [RequestOptions](arkts-apis-photoAccessHelper-i.md#requestoptions11)                                  | 是   | 视频请求策略模式配置项。|
| fileUri| string                                                              | 是 | 目标写入沙箱路径uri。示例fileUri：'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.mp4'。 |
| dataHandler  | [MediaAssetDataHandler](arkts-apis-photoAccessHelper-MediaAssetDataHandler.md)&lt;boolean&gt; | 是   | 媒体资源处理器，当所请求的视频资源写入完成时会触发回调。|

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise\<string> | Promise对象，返回请求id，可用于[cancelRequest](#cancelrequest12)取消请求。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201      |  Permission denied         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 801<sup>15+</sup>   | Capability not supported.       |
| 14000011       | System inner fail. Possible causes: 1. The database is corrupted; 2. The file system is abnormal; 3. The IPC request timed out; 4. Permission denied.        |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

class MediaDataHandler implements photoAccessHelper.MediaAssetDataHandler<boolean> {
    onDataPrepared(data: boolean) {
        console.info('on video request status prepared');
    }
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('requestVideoFile');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let requestOptions: photoAccessHelper.RequestOptions = {
    deliveryMode: photoAccessHelper.DeliveryMode.HIGH_QUALITY_MODE,
  }
  const handler = new MediaDataHandler();
  let fileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.mp4';
  phAccessHelper.getAssets(fetchOptions, async (err, fetchResult) => {
      console.info('fetchResult success');
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      await photoAccessHelper.MediaAssetManager.requestVideoFile(context, photoAsset, requestOptions, fileUri, handler);
      console.info('requestVideoFile successfully');
  });
}
```

## cancelRequest<sup>12+</sup>

static cancelRequest(context: Context, requestId: string): Promise\<void>

取消未触发回调的资产内容请求。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                                                                   | 必填 | 说明                      |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                      | 是   | 传入Ability实例的上下文。 |
| requestId | string     | 是   | 需要取消的请求id，requestImage等接口返回的有效请求id。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise\<void> | Promise对象，返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201      |  Permission denied         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail         |

**示例：**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
  try {
    let requestId: string = 'xxx-xxx'; // 应用需使用requestImage等接口返回的有效requestId
    await photoAccessHelper.MediaAssetManager.cancelRequest(context, requestId);
    console.info("request cancelled successfully");
  } catch (err) {
    console.error(`cancelRequest failed with error: ${err.code}, ${err.message}`);
  }
}

```

## loadMovingPhoto<sup>12+</sup>

static loadMovingPhoto(context: Context, imageFileUri: string, videoFileUri: string): Promise\<MovingPhoto>

加载应用沙箱的动态照片。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名   | 类型                                                                   | 必填 | 说明                      |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md)   | 是   | 传入AbilityContext或者UIExtensionContext的实例。 |
| imageFileUri | string     | 是   | 应用沙箱动态照片的图片uri。<br>示例：'file://com.example.temptest/data/storage/el2/base/haps/ImageFile.jpg' |
| videoFileUri | string     | 是   | 应用沙箱动态照片的视频uri。<br>示例：'file://com.example.temptest/data/storage/el2/base/haps/VideoFile.mp4' |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise\<MovingPhoto> | Promise对象，返回[MovingPhoto](arkts-apis-photoAccessHelper-MovingPhoto.md)实例。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error. |

**示例：**

```ts
async function example(context: Context) {
  try {
    let imageFileUri: string = 'file://com.example.temptest/data/storage/el2/base/haps/ImageFile.jpg'; // 应用沙箱动态照片的图片uri。
    let videoFileUri: string = 'file://com.example.temptest/data/storage/el2/base/haps/VideoFile.mp4'; // 应用沙箱动态照片的视频uri。
    let movingPhoto: photoAccessHelper.MovingPhoto = await photoAccessHelper.MediaAssetManager.loadMovingPhoto(context, imageFileUri, videoFileUri);
  } catch (err) {
    console.error(`loadMovingPhoto failed with error: ${err.code}, ${err.message}`);
  }
}

```

## quickRequestImage<sup>13+</sup>

static quickRequestImage(context: Context, asset: PhotoAsset, requestOptions: RequestOptions, dataHandler: QuickImageDataHandler&lt;image.Picture&gt;): Promise&lt;string&gt;

根据不同的策略模式，快速请求图片资源。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

- 通过picker的方式调用该接口来请求图片资源，不需要申请'ohos.permission.READ_IMAGEVIDEO'权限，详情请参考[开发指南](../../media/medialibrary/photoAccessHelper-photoviewpicker.md#指定uri获取图片或视频资源)。

**参数：**

| 参数名            | 类型                                                                                                        | 必填 | 说明                      |
|----------------|-----------------------------------------------------------------------------------------------------------| ---- | ------------------------- |
| context        | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                                                           | 是   | 传入Ability实例的上下文。 |
| asset         | [PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)                                                                                | 是   | 待请求的媒体文件对象。 |
| requestOptions | [RequestOptions](arkts-apis-photoAccessHelper-i.md#requestoptions11)                                                                        | 是   | 图片请求策略模式配置项。|
| dataHandler    | [QuickImageDataHandler](arkts-apis-photoAccessHelper-QuickImageDataHandler.md)&lt;[image.Picture](../apis-image-kit/arkts-apis-image-Picture.md)&gt; | 是   | 媒体资源处理器，当所请求的图片资源准备完成时会触发回调。|

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise\<string> | Promise对象，返回请求id，可用于[cancelRequest](#cancelrequest12)取消请求。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201      |  Permission denied         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14000011       | Internal system error.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';

class MediaHandler implements photoAccessHelper.QuickImageDataHandler<image.Picture> {
  onDataPrepared(data: image.Picture, imageSource: image.ImageSource, map: Map<string, string>) {
    console.info('on image data prepared');
  }
}

async function example(context: Context) {
  console.info('quickRequestImage');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let requestOptions: photoAccessHelper.RequestOptions = {
    deliveryMode: photoAccessHelper.DeliveryMode.HIGH_QUALITY_MODE,
  }
  const handler = new MediaHandler();
  let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
  phAccessHelper.getAssets(fetchOptions, async (err, fetchResult) => {
      console.info('fetchResult success');
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      await photoAccessHelper.MediaAssetManager.quickRequestImage(context, photoAsset, requestOptions, handler);
      console.info('quickRequestImage successfully');
  });
}
```
