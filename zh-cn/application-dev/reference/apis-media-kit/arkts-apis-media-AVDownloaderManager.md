# Interface (AVDownloaderManager)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chennotfound-->
<!--Designer: @dongyu_dy-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

离线下载任务管理接口，用于管理媒体资源的离线下载任务，包括创建、暂停、恢复、移除下载任务以及监听下载状态和进度变化事件。适用于需要在应用内支持流媒体资源离线缓存、实现无网络环境下播放等场景，可帮助用户节省流量并提升弱网或离线场景下的媒体播放体验。通过[createAVDownloaderManager()](arkts-apis-media-f.md#mediacreateavdownloadermanager)创建实例。

> **说明：**
>
> - 本Interface首批接口从API版本26.0.0开始支持。

## 导入模块

```ts
import { media } from '@kit.MediaKit';
```

## allowsCellularAccess

allowsCellularAccess(value: boolean): void

设置是否允许在蜂窝网络环境下进行下载。默认情况下仅在Wi-Fi环境下进行下载。若不允许蜂窝网络下载且当前为蜂窝网络环境，下载任务将暂停等待Wi-Fi环境可用后继续。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| value | boolean | 是   | 是否允许在蜂窝网络环境下进行下载。<br>- true：允许在蜂窝网络环境下下载。<br>- false：不允许在蜂窝网络环境下下载（默认）。 |

**示例：**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  downloaderManager.allowsCellularAccess(true);
}
```

## setRequestTimeout

setRequestTimeout(expired: number): void

设置HTTP请求的网络超时时间。超时后下载任务将失败。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| expired | number | 是   | 超时时间，单位为毫秒。<br>取值限定为整数。<br>- 若值大于0，表示超时时间，取值范围(0, +∞)。<br>- 若值小于等于0，表示无超时限制，建议根据业务场景设置合理的超时时间以避免任务长时间挂起。<br>- 若不设置，使用默认超时时间，默认时间为60000毫秒。 |

**示例：**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  downloaderManager.setRequestTimeout(30000);
}
```

## addAVDownloadTask

addAVDownloadTask(source: MediaSource): string

根据媒体源创建一个离线下载任务。默认情况下，下载任务仅在Wi-Fi环境下进行，如需在蜂窝网络环境下下载，请先调用allowsCellularAccess(true)。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| source | [MediaSource](arkts-apis-media-MediaSource.md) | 是   | 媒体资源描述，至少包含资源URL。<br>值不能为null。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| string | 成功添加的离线下载任务ID。 |

**示例：**

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

从离线下载管理器中移除离线下载任务，移除后该任务将停止下载并从管理器中删除。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| taskId | string | 否   | 要移除的离线下载任务ID。<br>默认值：不指定此参数时，移除所有离线下载任务。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400108  | If the specified ID is not in the offline download task manager. |

**示例：**

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

暂停指定离线下载任务，已下载的部分数据将保留，恢复后可从断点继续下载。任务需处于下载中状态，否则会返回错误码5400102。不指定任务ID时，暂停所有离线下载任务。暂停后的任务可通过resumeDownloadTask恢复。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| taskId | string | 否   | 要暂停的离线下载任务ID，任务需处于下载状态。<br>默认值：不指定此参数时，暂停所有下载任务。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400108  | If the specified ID is not in the offline download task manager. |
| 5400102  | Operation not allowed. |

**示例：**

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

恢复指定离线下载任务，从上次暂停的断点处继续下载。任务需处于暂停的状态，否则会返回错误码5400102。不指定任务ID时，恢复所有已暂停的离线下载任务。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| taskId | string | 否   | 要恢复的离线下载任务ID，任务需处于已暂停状态。<br>默认值：不指定此参数时，恢复所有已暂停的离线下载任务。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400108  | If the specified ID is not in the offline download task manager. |
| 5400102  | Operation not allowed. |

**示例：**

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

获取离线下载管理器中的当前所有离线下载任务。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Array\<string> | 若任务管理器中存在任务，返回任务ID数组；否则返回空数组。 |

**示例：**

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

获取指定离线下载任务的缓存目录。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| taskId | string | 是   | 要查询缓存目录的离线下载任务ID。取值应为当前管理器中已存在的任务ID。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| string | 离线下载任务的缓存目录在磁盘上的路径。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400108  | If the specified ID is not in the manager, an error is returned. |

**示例：**

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

获取指定离线下载任务的状态。状态类型详见[AVDownloadTaskState](arkts-apis-media-t.md#avdownloadtaskstate)。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| taskId | string | 是   | 要查询状态的离线下载任务ID。取值应为当前管理器中已存在的任务ID。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| [AVDownloadTaskState](arkts-apis-media-t.md#avdownloadtaskstate) | 指定任务的下载状态。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400108  | If the specified ID is not in the manager, an error is returned. |

**示例：**

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

获取指定离线下载任务的下载进度。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| taskId | string | 是   | 要查询进度的离线下载任务ID。取值应为当前管理器中已存在的任务ID。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| number | 下载进度比例值。<br>- 取值范围：[0.0, 1.0]<br>- 若返回值为-1，表示资源大小未知。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400108  | If the specified ID is not in the manager, an error is returned. |

**示例：**

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

注册离线下载任务状态变化的事件监听函数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | [OnAVDownloadTaskStateHandle](arkts-apis-media-t.md#onavdownloadtaskstatehandle) | 是   | 状态变化事件的处理函数。由应用实现。<br>第一个参数为状态变化的任务ID，第二个参数为任务的新状态。 |

**示例：**

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

注册离线下载任务进度变化的事件监听函数。当下载进度相比上次变化超过1%，且距上次触发时间超过500ms时，触发该事件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | [OnAVDownloadProgressChangeHandle](arkts-apis-media-t.md#onavdownloadprogresschangehandle) | 是   | 进度变化事件的处理函数。由应用实现。<br>第一个参数为下载任务ID，第二个参数为下载进度值。<br>进度值范围：-1或[0.0, 1.0]，若为-1则表示资源大小未知。 |

**示例：**

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

取消注册离线下载任务状态变化的事件监听函数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | [OnAVDownloadTaskStateHandle](arkts-apis-media-t.md#onavdownloadtaskstatehandle) | 否   | 状态变化事件的处理函数，需为通过onStatusChange注册过的处理函数。<br>默认值：不指定此参数时，取消注册该事件的所有处理函数。 |

**示例：**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  downloaderManager.offStatusChange();
}
```

## offProgressChange

offProgressChange(callback?: OnAVDownloadProgressChangeHandle): void

取消注册离线下载任务进度变化的事件监听函数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | [OnAVDownloadProgressChangeHandle](arkts-apis-media-t.md#onavdownloadprogresschangehandle) | 否   | 进度变化事件的处理函数，需为通过onProgressChange注册过的处理函数。<br>默认值：不指定此参数时，取消注册该事件的所有处理函数。 |

**示例：**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  downloaderManager.offProgressChange();
}
```

## release

release(): void

释放AVDownloaderManager对象使用的资源。调用此方法后，所有下载任务将被停止并移除，不可再通过该实例管理下载任务。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**示例：**

```ts
async function test() {
  let downloaderManager: media.AVDownloaderManager = await media.createAVDownloaderManager();
  downloaderManager.release();
}
```
