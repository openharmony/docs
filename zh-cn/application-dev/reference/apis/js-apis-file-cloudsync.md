# @ohos.file.cloudSync (端云同步能力)

该模块向应用提供端云同步能力，包括启动/停止端云同步以及启动/停止原图下载功能。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口，三方应用不支持调用。

## 导入模块

```ts
import cloudSync from '@ohos.file.cloudSync';
```

## SyncState

端云同步状态，为枚举类型。

> **说明：**
>
> 以下同步状态发生变更时，如果应用注册了同步过程事件监听，则通过回调通知应用。

**系统能力**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称 |  值|  说明 |
| ----- |  ---- |  ---- |
| UPLOADING |  0 | 上行同步中 |
| UPLOAD_FAILED |  1 | 上行同步失败 |
| DOWNLOADING |  2 | 下行同步中 |
| DOWNLOAD_FAILED |  3 | 下行同步失败 |
| COMPLETED |  4 | 同步成功 |
| STOPPED |  5 | 同步已停止 |

## ErrorType

端云同步失败类型，为枚举类型。

- 当前阶段，同步过程中，当移动数据网络和WIFI均不可用时，才会返回NETWORK_UNAVAILABLE；若有一种类型网络可用，则能正常同步。
- 同步过程中，非充电场景下，电量低于15%，完成当前批上行同步后停止同步，返回低电量；电量低于10%，完成当前批上行同步后停止同步，返回告警电量。
- 触发同步时，非充电场景下，若电量低于15%，则不允许同步，start接口返回对应错误。
- 上行时，若云端空间不足，则文件上行失败，云端无该文件记录。
- 下行时，若本地空间不足，则文件下行失败，本地空间释放后再次同步会重新下行。

**系统能力**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称 |  值|  说明 |
| ----- |  ---- |  ---- |
| NO_ERROR |  0 | 没有错误 |
| NETWORK_UNAVAILABLE |  1 | 所有网络不可用 |
| WIFI_UNAVAILABLE |  2 | WIFI不可用 |
| BATTERY_LEVEL_LOW |  3 | 低电量（低于15%） |
| BATTERY_LEVEL_WARNING |  4 | 告警电量（低于10%） |
| CLOUD_STORAGE_FULL |  5 | 云端空间不足 |
| LOCAL_STORAGE_FULL |  6 | 本地空间不足 |

## SyncProgress

端云同步过程。

**系统能力**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| state | [SyncState](#syncstate) | 是   | 枚举值，端云同步状态|
| error | [ErrorType](#errortype) | 是   | 枚举值，同步失败错误类型|

## GallerySync

云图同步对象，用来支撑图库应用媒体资源端云同步流程。在使用前，需要先创建GallerySync实例。

### constructor

constructor()

端云同步流程的构造函数，用于获取GallerySync类的实例。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**示例：**

  ```ts
  let gallerySync = new cloudSync.GallerySync()
  ```

### on

on(evt: 'progress', callback: (pg: SyncProgress) => void): void

添加同步过程事件监听。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| evt | string | 是   | 订阅的事件类型，取值为'progress'（同步过程事件） |
| callback | (pg: SyncProgress) => void | 是   | 同步过程事件回调，回调入参为[SyncProgress](#syncprogress), 返回值为void|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
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

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| evt | string | 是   | 取消订阅的事件类型，取值为'progress'（同步过程事件）|
| callback | (pg: SyncProgress) => void | 是   | 同步过程事件回调，回调入参为[SyncProgress](#syncprogress), 返回值为void|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
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

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| evt | string | 是   | 取消订阅的事件类型，取值为'progress'（同步过程事件）|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
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

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回启动端云同步的结果 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 22400001 | Cloud status not ready. |
| 22400002 | Network unavailable. |
| 22400003  | Battery level warning. |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.on('progress', (pg: cloudSync.SyncProgress) => {
	  console.info("syncState：" + pg.state);
  });

  gallerySync.start().then(() => {
	  console.info("start sync successfully");
  }).catch((err: BusinessError) => {
	  console.info("start sync failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### start

start(callback: AsyncCallback&lt;void&gt;): void

异步方法启动端云同步, 以callback形式返回结果。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步启动端云同步的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 22400001 | Cloud status not ready. |
| 22400002 | Network unavailable. |
| 22400003  | Battery level warning. |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.start((err: BusinessError) => {
    if (err) {
      console.info("start sync failed with error message: " + err.message + ", error code: " + err.code);
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

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回停止端云同步的结果 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.stop().then(() => {
	  console.info("stop sync successfully");
  }).catch((err: BusinessError) => {
	  console.info("stop sync failed with error message: " + err.message + ", error code: " + err.code);
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

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步停止端云同步的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.stop((err: BusinessError) => {
    if (err) {
      console.info("stop sync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("stop sync successfully");
    }
  });
  ```

## State

云文件下载状态，为枚举类型。

**系统能力**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称 |  值|  说明 |
| ----- |  ---- |  ---- |
| RUNNING |  0 | 云文件正在下载中 |
| COMPLETED |  1 | 云文件下载完成 |
| FAILED |  2 | 云文件下载失败 |
| STOPPED |  3 | 云文件下载已停止 |

## DownloadProgress

云文件下载过程。

**系统能力**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| state | [State](#state) | 是   | 枚举值，云文件下载状态|
| processed | number | 是   | 已下载数据大小|
| size | number | 是   | 当前云文件大小|
| uri | string | 是   | 当前云文件uri|

## Download

云文件下载对象，用来支撑图库应用原图文件下载流程。在使用前，需要先创建Download实例。

### constructor

constructor()

云文件下载流程的构造函数，用于获取Download类的实例。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**示例：**

  ```ts
  let download = new cloudSync.Download()
  ```

### on

on(evt: 'progress', callback: (pg: DownloadProgress) => void): void

添加云文件下载过程事件监听。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| evt | string | 是   | 订阅的事件类型，取值为'progress'（下载过程事件）|
| callback | (pg: DownloadProgress) => void | 是   | 云文件下载过程事件回调，回调入参为[DownloadProgress](#downloadprogress), 返回值为void|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
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

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| evt | string | 是   | 取消订阅的事件类型，取值为'progress'（同步过程事件）|
| callback | (pg: DownloadProgress) => void | 是   | 云文件下载过程事件回调，回调入参为[DownloadProgress](#downloadprogress), 返回值为void|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
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

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| evt | string | 是   | 取消订阅的事件类型，取值为'progress'（下载过程事件）|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
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

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri |

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回启动云文件下载的结果 |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  let download = new cloudSync.Download();
  let uri: string = "file:///media/Photo/1";

  download.on('progress', (pg: cloudSync.DownloadProgress) => {
	  console.info("download state:" + pg.state);
  });

  download.start(uri).then(() => {
	  console.info("start download successfully");
  }).catch((err: BusinessError) => {
	  console.info("start download failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13900002 | No such file or directory. |
| 13900025 | No space left on device. |

### start

start(uri: string, callback: AsyncCallback&lt;void&gt;): void

异步方法启动云文件下载, 以callback形式返回结果。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步启动云文件下载的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13900002 | No such file or directory. |
| 13900025 | No space left on device. |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  let download = new cloudSync.Download();
  let uri: string = "file:///media/Photo/1";

  download.start(uri, (err: BusinessError) => {
    if (err) {
      console.info("start download failed with error message: " + err.message + ", error code: " + err.code);
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
> 调用stop接口, 当前文件下载流程会终止, 缓存文件会被删除，再次调用start接口会重新开始下载

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri |

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回停止云文件下载的结果 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  let download = new cloudSync.Download();
  let uri: string = "file:///media/Photo/1";

  download.stop(uri).then(() => {
	  console.info("stop download successfully");
  }).catch((err: BusinessError) => {
	  console.info("stop download failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### stop

stop(uri: string, callback: AsyncCallback&lt;void&gt;): void

异步方法停止云文件下载, 以callback形式返回结果。

> **说明：**
>
> 调用stop接口, 当前文件下载流程会终止, 缓存文件会被删除, 再次调用start接口会重新开始下载

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步停止云文件下载的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  let download = new cloudSync.Download();
  let uri: string = "file:///media/Photo/1";

  download.stop(uri, (err: BusinessError) => {
    if (err) {
      console.info("stop download failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("stop download successfully");
    }
  });
  ```
