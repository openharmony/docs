# Interface (AVDownloaderManager)

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @zhaoyunfei-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=39ee8583645d55abbaea4002eba3f819dc0cd1a2 translatedAt=2026-08-17T10:24:40.261Z pushedAt=2026-08-19T06:51:40.448Z -->

This module provides APIs for managing offline download tasks of media resources, including creating, pausing, resuming, and removing download tasks, as well as listening for download status and progress change events. This module is applicable to scenarios where streaming media resources need to be cached offline in an app and played without network access. It helps users save traffic and improves media playback experience in poor network connection or offline scenarios. You can call [createAVDownloaderManager()](arkts-apis-media-f.md#mediacreateavdownloadermanager) to create an instance.

> **NOTE**
>
> - The initial APIs of this Interface are supported since API version 26.0.0.

## Modules to Import

```ts
import { media } from '@kit.MediaKit';
```

## allowsCellularAccess

allowsCellularAccess(value: boolean): void

Sets whether download is allowed on a cellular network. By default, download is allowed only over Wi-Fi. If download is not allowed on a cellular network but the current network is a cellular network, the download task will be paused and resumed when Wi-Fi is available.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | ---- | -------------------- |
| value | boolean | Yes | Whether download is allowed on a cellular network.<br>- **true**: allowed.<br>- **false**: not allowed (default). |

**Example**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  downloaderManager.allowsCellularAccess(true);
}
```

## setRequestTimeout

setRequestTimeout(timeout: number): void

Sets the network timeout interval for an HTTP request. If the timeout interval is reached, the download task will fail.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Parameters**

| Name    | Type   | Mandatory | Description                 |
| ------- | ------ | --------- | --------------------------- |
| timeout | number | Yes       | Timeout interval, in milliseconds.<br>The value must be an integer.<br>- If the value is greater than 0, it indicates the timeout interval. The value range is (0, +∞).<br>- If the value is less than or equal to 0, there is no timeout limit. You are advised to set a proper timeout interval based on the service scenario to prevent tasks from being suspended for a long time.<br>- If this parameter is not specified, the default timeout interval of 60,000 milliseconds is used. |

**Example**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  downloaderManager.setRequestTimeout(30000);
}
```

## addAVDownloadTask

addAVDownloadTask(source: MediaSource): string

Creates an offline download task based on the media source. By default, download tasks are performed only over Wi-Fi. To perform download tasks on the cellular network, set **allowsCellularAccess** to **true**.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Parameters**

| Name   | Type     | Mandatory | Description                 |
| -------- | -------- | ---- | -------------------- |
| source | [MediaSource](arkts-apis-media-MediaSource.md) | Yes   | Media resource, which must contain at least the resource URL.<br>The value cannot be null. |

**Return value**

| Type           | Description                                       |
| -------------- | ------------------------------------------ |
| string | ID of the offline download task that is successfully added. |

**Example**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  let headers: Record<string, string> = {'User-Agent' : 'MyApp/1.0'};
  let mediaSource: media.MediaSource = media.createMediaSourceWithUrl('http://example.com/video.mp4', headers);
  let taskId: string = downloaderManager.addAVDownloadTask(mediaSource);
  console.info(`Succeeded in adding download task, taskId: ${taskId}`);
}
```

## removeDownloadTask

removeDownloadTask(taskId?: string): void

Removes an offline download task from the offline download manager. After the task is removed, the download will stop and the task will be deleted from the manager.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Parameters**

| Name   | Type     | Mandatory | Description                 |
| -------- | -------- | ---- | -------------------- |
| taskId | string | No   | ID of the offline download task to remove.<br>By default, if this parameter is not specified, all offline download tasks are removed. |

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID | Error Message                                  |
| -------- | ----------------------------------------- |
| 5400108  | If the specified ID is not in the offline download task manager. |

**Example**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  let headers: Record<string, string> = {'User-Agent' : 'MyApp/1.0'};
  let mediaSource: media.MediaSource = media.createMediaSourceWithUrl('http://example.com/video.mp4', headers);
  let taskId: string = downloaderManager.addAVDownloadTask(mediaSource);
  downloaderManager.removeDownloadTask(taskId);
}
```

## pauseDownloadTask

pauseDownloadTask(taskId?: string): void

Pauses a specified offline download task. The downloaded data will be retained. After the task is resumed, the download can continue from the breakpoint. The task must be in the downloading state. Otherwise, error code 5400102 will be returned. If no task ID is specified, all offline download tasks are paused. A paused task can be resumed using **resumeDownloadTask**.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Parameters**

| Name   | Type     | Mandatory | Description                 |
| -------- | -------- | ---- | -------------------- |
| taskId | string | No   | ID of the offline download task to pause.<br>By default, if this parameter is not specified, all download tasks are paused. |

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID | Error Message                                  |
| -------- | ----------------------------------------- |
| 5400108  | If the specified ID is not in the offline download task manager. |
| 5400102  | Operation not allowed. |

**Example**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  let headers: Record<string, string> = {'User-Agent' : 'MyApp/1.0'};
  let mediaSource: media.MediaSource = media.createMediaSourceWithUrl('http://example.com/video.mp4', headers);
  let taskId: string = downloaderManager.addAVDownloadTask(mediaSource);
  downloaderManager.pauseDownloadTask(taskId);
}
```

## resumeDownloadTask

resumeDownloadTask(taskId?: string): void

Resumes a specified offline download task from the breakpoint where the task was paused last time. The task must be in the paused state. Otherwise, error code 5400102 will be returned. If no task ID is specified, all paused offline download tasks are resumed.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Parameters**

| Name   | Type     | Mandatory | Description                 |
| -------- | -------- | ---- | -------------------- |
| taskId | string | No   | ID of the offline download task to resume. The task must be in the paused state.<br>By default, if this parameter is not specified, all paused offline download tasks are resumed. |

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID | Error Message                                  |
| -------- | ----------------------------------------- |
| 5400108  | If the specified ID is not in the offline download task manager. |
| 5400102  | Operation not allowed. |

**Example**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  let headers: Record<string, string> = {'User-Agent' : 'MyApp/1.0'};
  let mediaSource: media.MediaSource = media.createMediaSourceWithUrl('http://example.com/video.mp4', headers);
  let taskId: string = downloaderManager.addAVDownloadTask(mediaSource);
  downloaderManager.pauseDownloadTask(taskId);
  downloaderManager.resumeDownloadTask(taskId);
}
```

## getDownloadTasks

getDownloadTasks(): Array\<string>

Obtains all offline download tasks in the offline download manager.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Return value**

| Type           | Description                                       |
| -------------- | ------------------------------------------ |
| Array\<string> | If tasks exist in the task manager, an array of the task IDs is returned. Otherwise, an empty array is returned. |

**Example**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  let headers: Record<string, string> = {'User-Agent' : 'MyApp/1.0'};
  let mediaSource: media.MediaSource = media.createMediaSourceWithUrl('http://example.com/video.mp4', headers);
  let taskId: string = downloaderManager.addAVDownloadTask(mediaSource);
  let tasks: Array<string> = downloaderManager.getDownloadTasks();
  console.info(`Download tasks: ${tasks}`);
}
```

## getTaskCacheDirectory

getTaskCacheDirectory(taskId: string): string

Obtains the cache directory of a specified offline download task.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Parameters**

| Name   | Type     | Mandatory | Description                 |
| -------- | -------- | ---- | -------------------- |
| taskId | string | Yes   | ID of the offline download task whose cache directory is to be queried. The value must be the ID of an existing task in the current manager. |

**Return value**

| Type           | Description                                       |
| -------------- | ------------------------------------------ |
| string | Path of the cache directory of the offline download task on the disk. |

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID | Error Message                                  |
| -------- | ----------------------------------------- |
| 5400108  | If the specified ID is not in the manager, an error is returned. |

**Example**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  let headers: Record<string, string> = {'User-Agent' : 'MyApp/1.0'};
  let mediaSource: media.MediaSource = media.createMediaSourceWithUrl('http://example.com/video.mp4', headers);
  let taskId: string = downloaderManager.addAVDownloadTask(mediaSource);
  let cacheDir: string = downloaderManager.getTaskCacheDirectory(taskId);
  console.info(`Task cache directory: ${cacheDir}`);
}
```

## getTaskStatus

getTaskStatus(taskId: string): AVDownloadTaskState

Obtains the status of a specified offline download task. For details about the status types, see [AVDownloadTaskState](arkts-apis-media-t.md#avdownloadtaskstate).

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Parameters**

| Name   | Type     | Mandatory | Description                 |
| -------- | -------- | ---- | -------------------- |
| taskId | string | Yes   | ID of the offline download task whose state is to be queried. The value must be the ID of an existing task in the current manager. |

**Return value**

| Type           | Description                                       |
| -------------- | ------------------------------------------ |
| [AVDownloadTaskState](arkts-apis-media-t.md#avdownloadtaskstate) | Download status of the specified task. |

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID | Error Message                                  |
| -------- | ----------------------------------------- |
| 5400108  | If the specified ID is not in the manager, an error is returned. |

**Example**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  let headers: Record<string, string> = {'User-Agent' : 'MyApp/1.0'};
  let mediaSource: media.MediaSource = media.createMediaSourceWithUrl('http://example.com/video.mp4', headers);
  let taskId: string = downloaderManager.addAVDownloadTask(mediaSource);
  let status: media.AVDownloadTaskState = downloaderManager.getTaskStatus(taskId);
  console.info(`Task status: ${status}`);
}
```

## getTaskProgress

getTaskProgress(taskId: string): number

Obtains the download progress of a specified offline download task.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Parameters**

| Name   | Type     | Mandatory | Description                 |
| -------- | -------- | ---- | -------------------- |
| taskId | string | Yes   | ID of the offline download task whose progress is to be queried. The value must be the ID of an existing task in the current manager. |

**Return value**

| Type           | Description                                       |
| -------------- | ------------------------------------------ |
| number | Download progress percentage.<br>- Value range: [0.0, 1.0]<br>- If the return value is **-1**, the resource size is unknown. |

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID | Error Message                                  |
| -------- | ----------------------------------------- |
| 5400108  | If the specified ID is not in the manager, an error is returned. |

**Example**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  let headers: Record<string, string> = {'User-Agent' : 'MyApp/1.0'};
  let mediaSource: media.MediaSource = media.createMediaSourceWithUrl('http://example.com/video.mp4', headers);
  let taskId: string = downloaderManager.addAVDownloadTask(mediaSource);
  let progress: number = downloaderManager.getTaskProgress(taskId);
  console.info(`Task progress: ${progress}`);
}
```

## onStatusChange

onStatusChange(callback: OnAVDownloadTaskStateHandle): void

Registers a listener for the status change event of an offline download task.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Parameters**

| Name     | Type     | Mandatory | Description                 |
| -------- | -------- | ---- | -------------------- |
| callback | [OnAVDownloadTaskStateHandle](arkts-apis-media-t.md#onavdownloadtaskstatehandle) | Yes   | Callback for status changes, which is implemented by the app.<br>The first parameter indicates the ID of the task whose status changes, and the second parameter indicates the new status of the task. |

**Example**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  downloaderManager.onStatusChange((taskId: string, state: media.AVDownloadTaskState) => {
    console.info(`Task status changed, taskId: ${taskId}, state: ${state}`);
  });
}
```

## onProgressChange

onProgressChange(callback: OnAVDownloadProgressChangeHandle): void

Registers a listener for the progress change event of an offline download task. This event is triggered when the download progress changes by more than 1% compared to the last time and the interval since the last triggering exceeds 500 ms.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | ---- | -------------------- |
| callback | [OnAVDownloadProgressChangeHandle](arkts-apis-media-t.md#onavdownloadprogresschangehandle) | Yes | Callback for progress changes, which is implemented by the app.<br>The first parameter indicates the download task ID, and the second parameter indicates the download progress.<br>The value can be **-1** or a number within the range of [0.0, 1.0]. The value **-1** indicates that the resource size is unknown. |

**Example**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  downloaderManager.onProgressChange((taskId: string, progress: number) => {
    console.info(`Task progress changed, taskId: ${taskId}, progress: ${progress}`);
  });
}
```

## offStatusChange

offStatusChange(callback?: OnAVDownloadTaskStateHandle): void

Unregisters the listener for the status change event of an offline download task.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | ---- | -------------------- |
| callback | [OnAVDownloadTaskStateHandle](arkts-apis-media-t.md#onavdownloadtaskstatehandle) | No | Callback for status changes, which must be registered using **onStatusChange**.<br>By default, if this parameter is not specified, all callbacks for the event are unregistered. |

**Example**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  downloaderManager.offStatusChange();
}
```

## offProgressChange

offProgressChange(callback?: OnAVDownloadProgressChangeHandle): void

Unregisters the listener for the progress change event of an offline download task.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | ---- | -------------------- |
| callback | [OnAVDownloadProgressChangeHandle](arkts-apis-media-t.md#onavdownloadprogresschangehandle) | No | Callback for progress changes, which must be registered using **onProgressChange**.<br>By default, if this parameter is not specified, all callbacks for the event are unregistered. |

**Example**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  downloaderManager.offProgressChange();
}
```

## release

release(): void

Releases the resources used by the **AVDownloaderManager** instance. After this method is called, all download tasks will be stopped and removed, and the instance cannot be used to manage download tasks anymore.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Example**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  downloaderManager.release();
}
```