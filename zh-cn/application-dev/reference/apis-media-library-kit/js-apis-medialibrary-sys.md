# @ohos.multimedia.medialibrary (媒体库管理)(系统接口)

从API version 12开始，该模块中的接口不再支持使用，相应功能可使用PhotoAccessHelper替代。不同功能的使用指导，请参考[Media Library Kit（媒体文件管理服务）简介](../../media/medialibrary/photoAccessHelper-overview.md)中的能力范围说明。

> **说明：**
>
> - 该组件从API version 6开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> - 本模块从API version 9开始废弃。对应的替代接口请参考具体接口说明。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.multimedia.medialibrary (媒体库管理)](js-apis-medialibrary.md)。

## 导入模块

```ts
import mediaLibrary from '@ohos.multimedia.mediaLibrary';
```

## MediaLibrary

### deleteAsset<sup>8+</sup>

deleteAsset(uri: string): Promise\<void>

删除媒体文件资源。

调用该接口彻底删除文件前，需要先调用[FileAsset.trash](js-apis-medialibrary.md#trash8)将文件放入回收站，否则文件会删除失败。

> **说明：**
>
> 此接口从API version 9开始废弃。请使用[deleteAssets](js-apis-photoAccessHelper-sys.md#deleteassetsdeprecated-3)替代。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.READ_MEDIA 和 ohos.permission.WRITE_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名      | 类型                           | 必填   | 说明              |
| -------- | ---------------------------- | ---- | --------------- |
| uri | string | 是    | 需要删除的媒体文件资源的uri。 |

**返回值：**

| 类型                  | 说明                   |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise对象，返回删除的结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 8000001 | This API is no longer supported. | 

**示例：**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let fileType = mediaLibrary.MediaType.FILE;
  let option: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [fileType.toString()],
  };
  const fetchFileResult = await media.getFileAssets(option);
  let asset = await fetchFileResult.getFirstObject();
  if (asset == undefined) {
    console.error('asset not exist');
    return;
  }
  media.deleteAsset(asset.uri).then(() => {
    console.info('deleteAsset successfully');
  }).catch((error: BusinessError) => {
    console.error('deleteAsset failed with error: ' + error);
  });
  fetchFileResult.close();
}
```

### deleteAsset<sup>8+</sup>

deleteAsset(uri: string, callback: AsyncCallback\<void>): void

删除媒体文件资源。

调用该接口彻底删除文件前，需要先调用[FileAsset.trash](js-apis-medialibrary.md#trash8)将文件放入回收站，否则文件会删除失败。

> **说明：**
>
> 此接口从API version 9开始废弃。请使用[deleteAssets](js-apis-photoAccessHelper-sys.md#deleteassetsdeprecated-2)替代。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.READ_MEDIA 和 ohos.permission.WRITE_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名      | 类型                           | 必填   | 说明              |
| -------- | ---------------------------- | ---- | --------------- |
| uri | string | 是    | 需要删除的媒体文件资源的uri。 |
|callback |AsyncCallback\<void>| 是  |callback返回空。|

**错误码：**

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 8000001 | This API is no longer supported. | 

**示例：**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let fileType = mediaLibrary.MediaType.FILE;
  let option: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [fileType.toString()],
  };
  const fetchFileResult = await media.getFileAssets(option);
  let asset = await fetchFileResult.getFirstObject();
  if (asset == undefined) {
    console.error('asset not exist');
    return;
  }
  media.deleteAsset(asset.uri, (error) => {
    if (error != undefined) {
      console.error('deleteAsset failed with error: ' + error);
    } else {
      console.info('deleteAsset successfully');
    }
  });
  fetchFileResult.close();
}
```

### getActivePeers<sup>8+</sup>

getActivePeers(): Promise\<Array\<PeerInfo>>;

获取在线对端设备的信息，使用Promise方式返回异步结果。

> **说明：**
>
> 此接口从API version 9开始废弃。无替代接口。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.DistributedCore

**返回值：**

| 类型                  | 说明                   |
| ------------------- | -------------------- |
|  Promise\<Array\<[PeerInfo](#peerinfo8)>> | Promise对象，返回获取的所有在线对端设备的PeerInfo。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 8000001 | This API is no longer supported. | 

**示例：**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  media.getActivePeers().then((devicesInfo) => {
    if (devicesInfo != undefined) {
      console.info('get distributed info ' + JSON.stringify(devicesInfo));
    } else {
      console.info('get distributed info is undefined!');
    }
  }).catch((error: BusinessError) => {
    console.error('get distributed info failed with error: ' + error);
  });
}
```

### getActivePeers<sup>8+</sup>

getActivePeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;

获取在线对端设备的信息，使用callback方式返回异步结果。

> **说明：**
>
> 此接口从API version 9开始废弃。无替代接口。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.DistributedCore

**返回值：**

| 类型                  | 说明                   |
| ------------------- | -------------------- |
| callback: AsyncCallback\<Array\<[PeerInfo](#peerinfo8)>> | callback返回获取的所有在线对端设备的PeerInfo对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 8000001 | This API is no longer supported. | 

**示例：**

```ts
async function example() {
  media.getActivePeers((error, devicesInfo) => {
    if (devicesInfo != undefined) {
      console.info('get distributed info ' + JSON.stringify(devicesInfo));
    } else {
      console.error('get distributed failed with error: ' + error);
    }
  });
}
```

### getAllPeers<sup>8+</sup>

getAllPeers(): Promise\<Array\<PeerInfo>>;

获取所有对端设备的信息，使用Promise方式返回异步结果。

> **说明：**
>
> 此接口从API version 9开始废弃。无替代接口。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.DistributedCore

**返回值：**

| 类型                  | 说明                   |
| ------------------- | -------------------- |
|  Promise\<Array\<[PeerInfo](#peerinfo8)>> | Promise对象，返回获取的所有对端设备的PeerInfo。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 8000001 | This API is no longer supported. | 

**示例：**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  media.getAllPeers().then((devicesInfo) => {
    if (devicesInfo != undefined) {
      console.info('get distributed info ' + JSON.stringify(devicesInfo));
    } else {
      console.info('get distributed info is undefined!');
    }
  }).catch((error: BusinessError) => {
    console.error('get distributed info failed with error: ' + error);
  });
}
```

### getAllPeers<sup>8+</sup>

getAllPeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;

获取所有对端设备的信息，使用callback方式返回异步结果。

> **说明：**
>
> 此接口从API version 9开始废弃。无替代接口。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.DistributedCore

**返回值：**

| 类型                  | 说明                   |
| ------------------- | -------------------- |
| callback: AsyncCallback\<Array\<[PeerInfo](#peerinfo8)>> | callback返回获取的所有对端设备的PeerInfo对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 8000001 | This API is no longer supported. | 

**示例：**

```ts
async function example() {
  media.getAllPeers((error, devicesInfo) => {
    if (devicesInfo != undefined) {
      console.info('get distributed info ' + JSON.stringify(devicesInfo));
    } else {
      console.error('get distributed failed with error: ' + error);
    }
  });
}
```

## PeerInfo<sup>8+</sup>

注册设备的信息。

> **说明：**
>
> 此接口从API version 9开始废弃。无替代接口。

**系统接口**：此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.MediaLibrary.DistributedCore

| 名称       | 类型                       | 可读 | 可写 | 说明             |
| ---------- | -------------------------- | ---- | ---- | ---------------- |
| deviceName | string                     | 是   | 否   | 注册设备的名称。   |
| networkId  | string                     | 是   | 否   | 注册设备的网络ID。 |
| deviceType | [DeviceType](#devicetype8) | 是   | 否   | 设备类型。         |
| isOnline   | boolean                    | 是   | 否   | 是否在线。         |

## DeviceType<sup>8+</sup>

枚举，设备类型。

> **说明：**
>
> 此接口从API version 9开始废弃。无替代接口。

**系统接口**：此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.MediaLibrary.DistributedCore

| 名称         |  值 | 说明       |
| ------------ | --- | ---------- |
| TYPE_UNKNOWN |  0 | 未识别设备。 |
| TYPE_LAPTOP  |  1 | 笔记本电脑。 |
| TYPE_PHONE   |  2 | 手机。       |
| TYPE_TABLET  |  3 | 平板电脑。   |
| TYPE_WATCH   |  4 | 智能手表。   |
| TYPE_CAR     |  5 | 车载设备。   |
| TYPE_TV      |  6 | 电视设备。   |
