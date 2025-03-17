# @ohos.file.cloudSync (端云同步能力)(系统接口)

该模块向应用提供端云同步能力，包括启动/停止端云同步以及启动/停止原图下载功能。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.file.cloudSync (端云同步能力)](js-apis-file-cloudsync.md)。

## 导入模块

```ts
import { cloudSync } from '@kit.CoreFileKit';
```

## SyncState<sup>12+</sup>

端云同步状态，为枚举类型。

> **说明：**
>
> 以下同步状态发生变更时，如果应用注册了同步过程事件监听，则通过回调通知应用。

**系统能力**： SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

| 名称 |  值|  说明 |
| ----- |  ---- |  ---- |
| UPLOADING |  0 | 上行同步中。 |
| UPLOAD_FAILED |  1 | 上行同步失败。 |
| DOWNLOADING |  2 | 下行同步中。 |
| DOWNLOAD_FAILED |  3 | 下行同步失败。 |
| COMPLETED |  4 | 同步成功。 |
| STOPPED |  5 | 同步已停止。 |

## ErrorType<sup>12+</sup>

端云同步失败类型，为枚举类型。

- 当前阶段，同步过程中，当开启无限量使用移动数据网络，移动数据网络和WIFI均不可用时，才会返回NETWORK_UNAVAILABLE；开启无限量使用移动数据网络，若有一种类型网络可用，则能正常同步。
- 同步过程中，非充电场景下，电量低于10%，完成当前批上行同步后停止同步，返回低电量；
- 触发同步时，非充电场景下，若电量低于10%，则不允许同步，start接口返回对应错误。
- 上行时，若云端空间不足，则文件上行失败，云端无该文件记录。

**系统能力**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

| 名称 |  值|  说明 |
| ----- |  ---- |  ---- |
| NO_ERROR |  0 | 没有错误。 |
| NETWORK_UNAVAILABLE |  1 | 所有网络不可用。 |
| WIFI_UNAVAILABLE |  2 | WIFI不可用。 |
| BATTERY_LEVEL_LOW |  3 | 低电量（低于10%）。 |
| BATTERY_LEVEL_WARNING |  4 | 告警电量（低于15%）。 |
| CLOUD_STORAGE_FULL |  5 | 云端空间不足。 |
| LOCAL_STORAGE_FULL |  6 | 本地空间不足。 |
| DEVICE_TEMPERATURE_TOO_HIGH |  7 | 设备温度过高。 |

## SyncProgress<sup>12+</sup>

端云同步过程。

**系统能力**： SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

| 名称     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| state | [SyncState](#syncstate12) | 是   | 枚举值，端云同步状态。|
| error | [ErrorType](#errortype12) | 是   | 枚举值，同步失败错误类型。|

## GallerySync

云图同步对象，用来支撑图库应用媒体资源端云同步流程。在使用前，需要先创建GallerySync实例。

### constructor

constructor()

端云同步流程的构造函数，用于获取GallerySync类的实例。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**示例：**

  ```ts
  let gallerySync = new cloudSync.GallerySync()
  ```

### on

on(evt: 'progress', callback: (pg: SyncProgress) => void): void

添加同步过程事件监听。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| evt | string | 是   | 订阅的事件类型，取值为'progress'（同步过程事件）。 |
| callback | (pg: SyncProgress) => void | 是   | 同步过程事件回调，回调入参为[SyncProgress](#syncprogress12), 返回值为void。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.on('progress', (pg: cloudSync.SyncProgress) => {
    console.info("syncState：" + pg.state);
  });
  ```

### off

off(evt: 'progress', callback: (pg: SyncProgress) => void): void

移除同步过程事件监听。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| evt | string | 是   | 取消订阅的事件类型，取值为'progress'（同步过程事件）。|
| callback | (pg: SyncProgress) => void | 是   | 同步过程事件回调，回调入参为[SyncProgress](#syncprogress12), 返回值为void。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  let gallerySync = new cloudSync.GallerySync();

  let callback = (pg: cloudSync.SyncProgress) => {
    console.info("gallery sync state：" + pg.state + "error type:" + pg.error);
  }

  gallerySync.on('progress', callback);

  gallerySync.off('progress', callback);
  ```

### off

off(evt: 'progress'): void

移除同步过程事件监听。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| evt | string | 是   | 取消订阅的事件类型，取值为'progress'（同步过程事件）。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.on('progress', (pg: cloudSync.SyncProgress) => {
      console.info("syncState：" + pg.state);
  });

  gallerySync.off('progress');
  ```

### start

start(): Promise&lt;void&gt;

异步方法启动端云同步, 以Promise形式返回结果。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回启动端云同步的结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |
| 22400001 | Cloud status not ready. |
| 22400002 | Network unavailable. |
| 22400003  | Low battery level. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.on('progress', (pg: cloudSync.SyncProgress) => {
	  console.info("syncState：" + pg.state);
  });

  gallerySync.start().then(() => {
	  console.info("start sync successfully");
  }).catch((err: BusinessError) => {
	  console.error("start sync failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### start

start(callback: AsyncCallback&lt;void&gt;): void

异步方法启动端云同步, 以callback形式返回结果。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步启动端云同步的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 22400001 | Cloud status not ready. |
| 22400002 | Network unavailable. |
| 22400003  | Low battery level. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.start((err: BusinessError) => {
    if (err) {
      console.error("start sync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("start sync successfully");
    }
  });
  ```

### stop

stop(): Promise&lt;void&gt;

异步方法停止端云同步, 以Promise形式返回结果。

> **说明：**
>
> 调用stop接口，同步流程会停止。再次调用[start](#start)接口会继续同步。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回停止端云同步的结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.stop().then(() => {
	  console.info("stop sync successfully");
  }).catch((err: BusinessError) => {
	  console.error("stop sync failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### stop

stop(callback: AsyncCallback&lt;void&gt;): void

异步方法停止端云同步, 以callback形式返回结果。

> **说明：**
>
> 调用stop接口，同步流程会停止。再次调用[start](#start)接口会继续同步。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步停止端云同步的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.stop((err: BusinessError) => {
    if (err) {
      console.error("stop sync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("stop sync successfully");
    }
  });
  ```

## Download

云文件下载对象，用来支撑图库应用原图文件下载流程。在使用前，需要先创建Download实例。

### constructor

constructor()

云文件下载流程的构造函数，用于获取Download类的实例。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**示例：**

  ```ts
  let download = new cloudSync.Download()
  ```

### on

on(evt: 'progress', callback: (pg: DownloadProgress) => void): void

添加云文件下载过程事件监听。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| evt | string | 是   | 订阅的事件类型，取值为'progress'（下载过程事件）。|
| callback | (pg: DownloadProgress) => void | 是   | 云文件下载过程事件回调，回调入参为[DownloadProgress](js-apis-file-cloudsync.md#downloadprogress11), 返回值为void。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  let download = new cloudSync.Download();

  download.on('progress', (pg: cloudSync.DownloadProgress) => {
    console.info("download state：" + pg.state);
  });
  ```

### off

off(evt: 'progress', callback: (pg: DownloadProgress) => void): void

移除云文件下载过程事件监听。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| evt | string | 是   | 取消订阅的事件类型，取值为'progress'（同步过程事件）。|
| callback | (pg: DownloadProgress) => void | 是   | 云文件下载过程事件回调，回调入参为[DownloadProgress](js-apis-file-cloudsync.md#downloadprogress11), 返回值为void。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  let download = new cloudSync.Download();

  let callback = (pg: cloudSync.DownloadProgress) => {
    console.info("download state：" + pg.state);
  }

  download.on('progress', callback);

  download.off('progress', callback);
  ```

### off

off(evt: 'progress'): void

移除云文件下载过程事件监听。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| evt | string | 是   | 取消订阅的事件类型，取值为'progress'（下载过程事件）。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  let download = new cloudSync.Download();

  download.on('progress', (pg: cloudSync.DownloadProgress) => {
      console.info("download state:" + pg.state);
  });

  download.off('progress');
  ```

### start

start(uri: string): Promise&lt;void&gt;

异步方法启动云文件下载, 以Promise形式返回结果。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri。 |

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回启动云文件下载的结果。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let download = new cloudSync.Download();
  let uri: string = "file:///media/Photo/1";

  download.on('progress', (pg: cloudSync.DownloadProgress) => {
	  console.info("download state:" + pg.state);
  });

  download.start(uri).then(() => {
	  console.info("start download successfully");
  }).catch((err: BusinessError) => {
	  console.error("start download failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13900002 | No such file or directory. |
| 13900025 | No space left on device. |

### start

start(uri: string, callback: AsyncCallback&lt;void&gt;): void

异步方法启动云文件下载, 以callback形式返回结果。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步启动云文件下载的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13900002 | No such file or directory. |
| 13900025 | No space left on device. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let download = new cloudSync.Download();
  let uri: string = "file:///media/Photo/1";

  download.start(uri, (err: BusinessError) => {
    if (err) {
      console.error("start download failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("start download successfully");
    }
  });
  ```

### stop

stop(uri: string): Promise&lt;void&gt;

异步方法停止云文件下载, 以Promise形式返回结果。

> **说明：**
>
> 调用stop接口, 当前文件下载流程会终止, 缓存文件会被删除，再次调用start接口会重新开始下载。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri。 |

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回停止云文件下载的结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let download = new cloudSync.Download();
  let uri: string = "file:///media/Photo/1";

  download.stop(uri).then(() => {
	  console.info("stop download successfully");
  }).catch((err: BusinessError) => {
	  console.error("stop download failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### stop

stop(uri: string, callback: AsyncCallback&lt;void&gt;): void

异步方法停止云文件下载, 以callback形式返回结果。

> **说明：**
>
> 调用stop接口, 当前文件下载流程会终止, 缓存文件会被删除, 再次调用start接口会重新开始下载。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步停止云文件下载的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let download = new cloudSync.Download();
  let uri: string = "file:///media/Photo/1";

  download.stop(uri, (err: BusinessError) => {
    if (err) {
      console.error("stop download failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("stop download successfully");
    }
  });
  ```

## FileSync<sup>12+</sup>

云盘同步对象，用于支撑文件管理器应用完成云盘文件的端云同步流程。在使用前，需要先创建FileSync实例。

### constructor<sup>12+</sup>

constructor()

端云同步流程的构造函数，用于获取FileSync类的实例。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |

**示例：**

  ```ts
  let fileSync = new cloudSync.FileSync()
  ```

### constructor<sup>12+</sup>

constructor(bundleName: string)

端云同步流程的构造函数，用于获取FileSync类的实例。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| bundleName | string | 是   | 应用包名。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

  ```ts
  let fileSync = new cloudSync.FileSync("com.ohos.demo")
  ```

### on<sup>12+</sup>

on(event: 'progress', callback: Callback\<SyncProgress>): void

添加同步过程事件监听。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| event | string | 是   | 订阅的事件类型，取值为'progress'（同步过程事件）。 |
| callback | Callback\<[SyncProgress](#syncprogress12)> | 是   | 同步过程事件回调。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  let fileSync = new cloudSync.FileSync();
  let callback = (pg: cloudSync.SyncProgress) => {
    console.info("file sync state：" + pg.state + "error type:" + pg.error);
  }

  fileSync.on('progress', callback);
  ```

### off<sup>12+</sup>

off(event: 'progress', callback?: Callback\<SyncProgress>): void

移除同步过程事件监听。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| event | string | 是   | 取消订阅的事件类型，取值为'progress'（同步过程事件）。|
| callback | Callback\<[SyncProgress](#syncprogress12)> |  否   | 同步过程事件回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  let fileSync = new cloudSync.FileSync();

  let callback = (pg: cloudSync.SyncProgress) => {
    console.info("file sync state：" + pg.state + "error type:" + pg.error);
  }

  fileSync.on('progress', callback);

  fileSync.off('progress', callback);
  ```

### start<sup>12+</sup>

start(): Promise&lt;void&gt;

异步方法启动云盘端云同步, 以Promise形式返回结果。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise对象，无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |
| 13600001  | IPC error. |
| 22400001  | Cloud status not ready. |
| 22400002  | Network unavailable. |
| 22400003  | Low battery level. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  let callback = (pg: cloudSync.SyncProgress) => {
    console.info("file sync state：" + pg.state + "error type:" + pg.error);
  }

  fileSync.on('progress', callback);

  fileSync.start().then(() => {
	  console.info("start sync successfully");
  }).catch((err: BusinessError) => {
	  console.error("start sync failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### start<sup>12+</sup>

start(callback: AsyncCallback&lt;void&gt;): void

异步方法启动云盘端云同步, 以callback形式返回结果。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步启动端云同步的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 22400001  | Cloud status not ready. |
| 22400002  | Network unavailable. |
| 22400003  | Low battery level. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  fileSync.start((err: BusinessError) => {
    if (err) {
      console.error("start sync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("start sync successfully");
    }
  });
  ```

### stop<sup>12+</sup>

stop(): Promise&lt;void&gt;

异步方法停止云盘端云同步, 以Promise形式返回结果。

调用stop接口，同步流程会停止。再次调用[start](#start)接口会继续同步。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回停止端云同步的结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  fileSync.stop().then(() => {
	  console.info("stop sync successfully");
  }).catch((err: BusinessError) => {
	  console.error("stop sync failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### stop<sup>12+</sup>

stop(callback: AsyncCallback&lt;void&gt;): void

异步方法停止云盘端云同步, 以callback形式返回结果。

调用stop接口，同步流程会停止。再次调用[start](#start)接口会继续同步。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步停止端云同步的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  fileSync.stop((err: BusinessError) => {
    if (err) {
      console.error("stop sync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("stop sync successfully");
    }
  });
  ```

### getLastSyncTime<sup>12+</sup>

getLastSyncTime(): Promise&lt;number&gt;

异步方法获取上次同步时间, 以promise形式返回结果。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;number&gt; | 使用Promise形式返回上次同步时间。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  fileSync.getLastSyncTime().then((timeStamp: number) => {
    let date = new Date(timeStamp);
    console.info("get last sync time successfully:"+ date);
  }).catch((err: BusinessError) => {
	  console.error("get last sync time failed with error message: " + err.message + ", error code: " + err.code);
  });

  ```

### getLastSyncTime<sup>12+</sup>

getLastSyncTime(callback: AsyncCallback&lt;number&gt;): void

异步方法获取上次同步时间, 以callback形式返回结果。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;number&gt; | 是   | 异步获取上次同步时间的回调。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  fileSync.getLastSyncTime((err: BusinessError, timeStamp: number) => {
    if (err) {
      console.error("get last sync time with error message: " + err.message + ", error code: " + err.code);
    } else {
      let date = new Date(timeStamp);
      console.info("get last sync time successfully:"+ date);
    }
  });
  ```

## CloudFileCache<sup>11+</sup>

云盘文件缓存对象，用来支撑文件管理应用原文件下载流程。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

### cleanCache<sup>11+</sup>

cleanCache(uri: string): void

同步方法删除文件缓存。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待删除缓存文件的uri。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002  | No such file or directory. |
| 14000002  | Invalid URI. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileUri } from '@kit.CoreFileKit';
  let fileCache = new cloudSync.CloudFileCache();
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);

  try {
    fileCache.cleanCache(uri);
  } catch (err) {
    let error:BusinessError = err as BusinessError;
    console.error("clean cache failed with error message: " + err.message + ", error code: " + err.code);
  } 

  ```

## cloudSync.getFileSyncState<sup>11+</sup>

getFileSyncState(uri: Array&lt;string&gt;): Promise&lt;Array&lt;FileSyncState&gt;&gt;

异步方法获取文件同步状态, 以promise形式返回结果。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | Array&lt;string&gt; | 是   | 待获取同步状态的uri。 |

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;Array&lt;FileSyncState&gt;&gt; | 使用Promise形式返回文件同步状态的结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002  | No such file or directory. |
| 14000002  | Invalid URI. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let uris: Array<string> = ["file://uri"];
  cloudSync.getFileSyncState(uris).then((syncStates: Array<cloudSync.FileSyncState>) => {
    for(let i = 0, len = syncStates.length; i < len; i++){
        console.info("get file sync state successfully" + syncStates[i]);
    }
  }).catch((err: BusinessError) => {
	  console.error("get file sync state failed with error message: " + err.message + ", error code: " + err.code);
  });

  ```

## cloudSync.getFileSyncState<sup>11+</sup>

getFileSyncState(uri: Array&lt;string&gt;, callback: AsyncCallback&lt;Array&lt;FileSyncState&gt;&gt;): void

异步方法获取文件同步状态, 以callback形式返回结果。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | Array&lt;string&gt; | 是   | 待获取同步状态的uri。 |
| callback | AsyncCallback&lt;Array&lt;FileSyncState&gt;&gt; | 是   | 异步获取文件状态的回调。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002  | No such file or directory. |
| 14000002  | Invalid URI. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let uris: Array<string> = ["file://uri"];
  cloudSync.getFileSyncState(uris, (err: BusinessError, syncStates: Array<cloudSync.FileSyncState>) => {
    if (err) {
      console.error("get file sync state with error message: " + err.message + ", error code: " + err.code);
    } else {
      for(let i = 0, len = syncStates.length; i < len; i++){
        console.info("get file sync state successfully" + syncStates[i]);
    }
    }
  });
  ```

## cloudSync.getFileSyncState<sup>12+</sup>

getFileSyncState(uri: string): FileSyncState

获取文件同步状态。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri。 |

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| [FileSyncState](#filesyncstate11) | 返回给定文件的同步状态。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13900002  | No such file or directory. |
| 13900004  | Interrupted system call. |
| 13900010  | Try again. |
| 13900012  | Permission denied by the file system. |
| 13900031  | Function not implemented. |
| 13900042  | Unknown error. |
| 14000002  | Invalid URI. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileUri } from '@kit.CoreFileKit';
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);
  try {
    let state = fileSync.getFileSyncState(uri)
  }.catch(err) {
    let error:BusinessError = err as BusinessError;
    console.error("getFileSyncStatefailed with error:" + JSON.stringify(error));
  }
  ```

## cloudSync.registerChange<sup>12+</sup>

registerChange(uri: string, recursion: boolean, callback: Callback&lt;ChangeData&gt;): void

订阅监听指定文件的变化通知。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri。 |
| recursion | boolean | 是   | true为监听该uri以及子文件和子目录，false为仅监听该uri文件。|
| callback | Callback&lt;[ChangeData](#changedata12)&gt; | 是   | 返回更改的数据。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13900001  | Operation not permitted. |
| 13900002  | No such file or directory. |
| 13900012  | Permission denied. |
| 14000002  | Invalid URI. |

**示例：**

  ```ts
  import { fileUri } from '@kit.CoreFileKit';
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);
  let onCallback1 = (changeData: ChangeData) => {
    if (changeData.type == cloudSync.NotifyType.NOTIFY_ADDED) {
      //file had added, do something
    } else if (changeData.type== cloudSync.NotifyType.NOTIFY_DELETED) {
      //file had removed, do something
    }
	}
  cloudSync.registerChange(uri, false, onCallback1);
  // 取消注册监听
  cloudSync.unRegisterChange(uri);
  ```

## cloudSync.unregisterChange<sup>12+</sup>

unregisterChange(uri: string): void

取消订阅监听指定文件的变化通知。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13900001  | Operation not permitted. |
| 13900002  | No such file or directory. |
| 13900012  | Permission denied. |
| 14000002  | Invalid URI. |

**示例：**

  ```ts
  import { fileUri } from '@kit.CoreFileKit';
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);
  let onCallback1 = (changeData: ChangeData) => {
    if (changeData.type == cloudSync.NotifyType.NOTIFY_ADDED) {
      //file had added, do something
    } else if (changeData.type== cloudSync.NotifyType.NOTIFY_DELETED) {
      //file had removed, do something
    }
	}
  cloudSync.registerChange(uri, false, onCallback1);
  // 取消注册监听
  cloudSync.unRegisterChange(uri);
  ```

## NotifyType<sup>12+</sup>

数据变更通知类型。

**系统能力**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

| 名称 |  值|  说明 |
| ----- |  ---- |  ---- |
| NOTIFY_ADDED |  0 | 文件已新建。 |
| NOTIFY_MODIFIED |  1 | 文件已修改。 |
| NOTIFY_DELETED |  2 | 文件已被删除。 |
| NOTIFY_RENAMED |  3 | 文件被重命名或者移动。 |

## ChangeData<sup>12+</sup>

定义变更数据。

**系统能力**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

| 名称     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| type | [NotifyType](#notifytype12) | 是   | 更改的通知类型。|
| isDirectory | Array&lt;boolean&gt; | 是   | 指示更改的uri是否为目录。|
| uris | Array&lt;string&gt; | 是   | 更改的uris。|

## FileSyncState<sup>11+</sup>

端云文件同步状态，为枚举类型。

**系统能力**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：该接口为系统接口。

| 名称 |  值|  说明 |
| ----- |  ---- |  ---- |
| UPLOADING |  0 | 上行同步中。 |
| DOWNLOADING |  1 | 下行同步中。 |
| COMPLETED |  2 | 同步成功。 |
| STOPPED |  3 | 同步已停止。 |
| TO_BE_UPLOADED<sup>12+</sup> |  4 | 正在等待上行。 |
| UPLOAD_SUCCESS<sup>12+</sup> |  5 | 文件已成功上行。 |
| UPLOAD_FAILURE<sup>12+</sup> |  6 | 文件上行失败。 |