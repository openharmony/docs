# @ohos.request (上传下载)(系统接口)

request部件主要给应用提供上传下载文件、后台传输代理的基础能力。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前界面仅包含本模块的系统接口，其他公开接口参见[@ohos.request](js-apis-request.md)。


## 导入模块


```js
import { request } from '@kit.BasicServicesKit';
```


## Filter<sup>10+</sup>
过滤条件。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundle | string | 否 | 指定应用程序的包名，仅对系统应用开放。<br/>**系统接口**：此接口为系统接口。 |


## TaskInfo<sup>10+</sup> 
查询结果的任务信息数据结构，提供普通查询和系统查询，两种字段的可见范围不同。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uid | string | 否 | 应用程序的UID，仅用于系统查询。<br/>**系统接口**：此接口为系统接口。|
| bundle | string | 否 | 应用程序的包名，仅用于系统查询。<br/>**系统接口**：此接口为系统接口。|



## request.agent.query<sup>10+</sup>

query(id: string, callback: AsyncCallback&lt;TaskInfo&gt;): void

根据任务id查询任务的详细信息。使用callback异步回调。

**需要权限**：ohos.permission.DOWNLOAD_SESSION_MANAGER 或 ohos.permission.UPLOAD_SESSION_MANAGER

**系统能力**: SystemCapability.Request.FileTransferAgent

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型                                           | 必填 | 说明 |
|----------------------------------------------| -------- | -------- | -------- |
| id | string                                       | 是 | 任务id。 |
| callback | AsyncCallback&lt;[TaskInfo](#taskinfo10)&gt; | 是 | 回调函数，返回任务详细信息。 |

**错误码：**
以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | permission denied. |
| 202 | permission verification failed, application which is not a system application uses system API. |
| 401 | parameter error. Possible causes: 1. Missing mandatory parameters 2. Incorrect parameter type |
| 13400003 | task service ability error. |
| 21900006 | task not found. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  request.agent.query("123456", (err: BusinessError, taskInfo: request.agent.TaskInfo) => {
    if (err) {
      console.error(`Failed to query a upload task, Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in querying a upload task. result: ${taskInfo.uid}`);
  });
  ```


## request.agent.query<sup>10+</sup>

query(id: string): Promise&lt;TaskInfo&gt;

根据任务id查询任务的详细信息。使用Promise异步回调。

**需要权限**：ohos.permission.DOWNLOAD_SESSION_MANAGER 或 ohos.permission.UPLOAD_SESSION_MANAGER

**系统能力**: SystemCapability.Request.FileTransferAgent

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| id | string | 是 | 任务id。 |

**返回值：**

| 类型                                     | 说明                      |
|----------------------------------------| ------------------------- |
| Promise&lt;[TaskInfo](#taskinfo10)&gt; | Promise对象。返回任务详细信息的Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | permission denied. |
| 202 | permission verification failed, application which is not a system application uses system API. |
| 401 | parameter error. Possible causes: 1. Missing mandatory parameters 2. Incorrect parameter type |
| 13400003 | task service ability error. |
| 21900006 | task not found. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  request.agent.query("123456").then((taskInfo: request.agent.TaskInfo) => {
    console.info(`Succeeded in querying a upload task. result: ${taskInfo.uid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to query a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```
