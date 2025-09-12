# @ohos.file.cloudSync (端云同步能力)(系统接口)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @zsyztt; @Hermits; @reminder2352-->
<!--Designer: @yunlanying-->
<!--Tester: @liuhonggang123-->
<!--Adviser: @foryourself-->

该模块向应用提供端云同步能力，包括启动/停止端云同步以及启动/停止原图下载功能。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.file.cloudSync (端云同步能力)](js-apis-file-cloudsync.md)。

## 导入模块

```ts
import { cloudSync } from '@kit.CoreFileKit';
```

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
| callback | (pg: SyncProgress) => void | 是   | 同步过程事件回调，回调入参为[SyncProgress](./js-apis-file-cloudsync.md#syncprogress12)，返回值为void。|

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
| callback | (pg: SyncProgress) => void | 是   | 同步过程事件回调，回调入参为[SyncProgress](./js-apis-file-cloudsync.md#syncprogress12)，返回值为void。|

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

异步方法启动端云同步，以Promise形式返回结果。

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

异步方法启动端云同步，以callback形式返回结果。

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

异步方法停止端云同步，以Promise形式返回结果。

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

异步方法停止端云同步，以callback形式返回结果。

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
| callback | (pg: DownloadProgress) => void | 是   | 云文件下载过程事件回调，回调入参为[DownloadProgress](js-apis-file-cloudsync.md#downloadprogress11)，返回值为void。|

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
| callback | (pg: DownloadProgress) => void | 是   | 云文件下载过程事件回调，回调入参为[DownloadProgress](js-apis-file-cloudsync.md#downloadprogress11)，返回值为void。|

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

异步方法启动云文件下载，以Promise形式返回结果。

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

异步方法启动云文件下载，以callback形式返回结果。

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

异步方法停止云文件下载，以Promise形式返回结果。

> **说明：**
>
> 调用stop接口，当前文件下载流程会终止，缓存文件会被删除，再次调用start接口会重新开始下载。

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

异步方法停止云文件下载，以callback形式返回结果。

> **说明：**
>
> 调用stop接口，当前文件下载流程会终止，缓存文件会被删除，再次调用start接口会重新开始下载。

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

异步方法获取文件同步状态，以promise形式返回结果。

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

异步方法获取文件同步状态，以callback形式返回结果。

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
    let state = cloudSync.getFileSyncState(uri);
  } catch (err) {
    let error:BusinessError = err as BusinessError;
    console.error("getFileSyncStatefailed with error:" + JSON.stringify(error));
  }
  ```

## FileSyncState<sup>11+</sup>

端云文件同步状态，为枚举类型。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

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

## cloudSync.optimizeStorage<sup>17+</sup>

optimizeStorage(): Promise&lt;void&gt;

优化图库已同步云空间的本地资源，按照本地剩余空间执行自动老化策略。使用Promise异步回调。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：此接口为系统接口。

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 13600001  | IPC error. |
| 13900042  | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  cloudSync.optimizeStorage().then(() => {
	  console.info("optimize storage successfully");   // 前台UX按需阻塞等待
  }).catch((err: BusinessError) => {
	  console.error("optimize storage failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSync.startOptimizeSpace<sup>17+</sup>

startOptimizeSpace(optimizePara: OptimizeSpaceParam, callback?: Callback\<OptimizeSpaceProgress>): Promise&lt;void&gt;

优化图库已同步云空间的本地资源，执行立即优化空间策略，对老化天数前未访问的本地图片/视频进行优化。使用Promise异步回调。

startOptimizeSpace的使用和stopOptimizeSpace方法调用一一对应，重复开启将返回其他任务正在执行的错误信息（22400006）。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| optimizePara | [OptimizeSpaceParam](#optimizespaceparam17) | 是   | 优化参数。 |
| callback | Callback&lt;[OptimizeSpaceProgress](#optimizespaceprogress17)&gt; | 否   | 返回优化进度。缺省情况下返回401错误，不执行清理任务 |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 22400005  | Inner error. |
| 22400006  | The same task is already in progress. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let para:cloudSync.OptimizeSpaceParam = {totalSize: 1073741824, agingDays: 30};
  let callback = (data:cloudSync.OptimizeSpaceProgress) => {
    if (data.state == cloudSync.OptimizeState.FAILED) {
      console.info("optimize space failed");
    } else if (data.state == cloudSync.OptimizeState.COMPLETED && data.progress == 100) {
      console.info("optimize space successfully");
    } else if (data.state == cloudSync.OptimizeState.RUNNING) {
      console.info("optimize space progress:" + data.progress);
    }
  }
  cloudSync.startOptimizeSpace(para, callback).then(() => {
	  console.info("start optimize space");
  }).catch((err: BusinessError) => {
	  console.error("start optimize space failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSync.stopOptimizeSpace<sup>17+</sup>

stopOptimizeSpace(): void

同步方法停止图库云图资源空间优化，和startOptimizeSpace配对使用。

**需要权限**：ohos.permission.CLOUDFILE_SYNC

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：此接口为系统接口。

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 13600001  | IPC error. |
| 22400005  | Inner error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let para:cloudSync.OptimizeSpaceParam = {totalSize: 1073741824, agingDays: 30};
  let callback = (data:cloudSync.OptimizeSpaceProgress) => {
    if (data.state == cloudSync.OptimizeState.FAILED) {
      console.info("optimize space failed");
    } else if (data.state == cloudSync.OptimizeState.RUNNING) {
      console.info("optimize space progress:" + data.progress);
    }
  }
  cloudSync.startOptimizeSpace(para, callback);
  cloudSync.stopOptimizeSpace();   // 停止空间优化
  ```

## OptimizeState<sup>17+</sup>

优化空间状态，为枚举类型。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：此接口为系统接口。

| 名称 |  值|  说明 |
| ----- |  ---- |  ---- |
| RUNNING |  0 | 正在优化空间。 |
| COMPLETED |  1 | 优化空间成功结束。 |
| FAILED |  2 | 优化空间失败。 |
| STOPPED |  3 | 优化空间停止。 |

## OptimizeSpaceProgress<sup>17+</sup>

立即优化空间状态和当前进度。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：此接口为系统接口。

| 名称     | 类型   | 只读 | 可选 | 说明 |
| ---------- | ------ | ---- | ---- | ---- |
| state | [OptimizeState](#optimizestate17) | 否   | 否   | 枚举值，优化空间状态。|
| progress | number | 否   | 否   | 优化进度百分比，范围[0,100]。|

## OptimizeSpaceParam<sup>17+</sup>

立即优化空间设置参数，设置优化总空间和老化天数。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**系统接口**：此接口为系统接口。

| 名称     | 类型   | 只读 | 可选 | 说明 |
| ---------- | ------ | ---- | ---- | ---- |
| totalSize | number | 否   | 否   | 优化空间总大小。查询媒体库接口获得需要老化的所有文件总大小，由应用传入，单位byte。|
| agingDays | number | 否   | 否   | 老化天数。系统会以当前时间为基准，优化老化天数前未访问、已同步云空间的本地图片/视频。|