# @ohos.request (上传下载)(系统接口)

request部件主要给应用提供上传下载文件、后台传输代理的基础能力。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```js
import request from '@ohos.request';
```

## Filter<sup>10+</sup>
过滤条件。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 类型                                  | 必填 | 说明 |
| -------- |-------------------------------------| -------- | -------- |
| bundle | string                              | 否 | 指定应用程序的包名，仅对系统应用开放。<br/>**系统接口**：此接口为系统接口。 |
| before | number                              | 否 | 结束的Unix时间戳（毫秒），默认为调用时刻。 |
| after | number                              | 否 | 开始的Unix时间戳（毫秒），默认值为调用时刻减24小时。 |
| state | [State](js-apis-request.md#state10) | 否 | 指定任务的状态。 |
| action | [Action](js-apis-request.md#action10)              | 否 | 任务操作选项。<br/>-UPLOAD表示上传任务。<br/>-DOWNLOAD表示下载任务。 |
| mode | [Mode](js-apis-request.md#mode10)                  | 否 | 任务模式。<br/>-FOREGROUND表示前端任务。<br/>-BACKGROUND表示后台任务。<br/>-如果未填写，则查询所有任务。 |


## TaskInfo<sup>10+</sup>
查询结果的任务信息数据结构，提供普通查询和系统查询，两种字段的可见范围不同。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 类型 | 必填                                                     | 说明 |
| -------- | -------- |--------------------------------------------------------| -------- |
| uid | string | 否                                                      | 应用程序的UID，仅用于系统查询。<br/>**系统接口**：此接口为系统接口。|
| bundle | string | 否                                                      | 应用程序的包名，仅用于系统查询。<br/>**系统接口**：此接口为系统接口。|
| saveas | string | 否                                                      | 保存下载文件的路径，包括如下两种：<br/>-相对路径，如"./xxx/yyy/zzz.html"、"xxx/yyy/zzz.html"，位于调用方的缓存路径下。<br/>-uri路径，如"datashare://bundle/xxx/yyy/zzz.html"，仅对具有访问url路径权限的应用开放。该功能暂不支持。<br/>默认为相对路径，即下载至应用当前缓存路径下。|
| url | string | 否                                                      | 任务的url。<br/>- 通过[request.agent.show<sup>10+</sup>](js-apis-request.md#requestagentshow10-1)、[request.agent.touch<sup>10+</sup>](js-apis-request.md#requestagenttouch10-1)、[request.agent.query<sup>10+</sup>](#requestagentquery10-1)进行查询。其中，使用[request.agent.query<sup>10+</sup>](#requestagentquery10-1)进行查询时会返回空字符串。 |
| data | string \| Array&lt;[FormItem](js-apis-request.md#formitem10)&gt; | 否 | 任务值。<br/>- 通过[request.agent.show<sup>10+</sup>](js-apis-request.md#requestagentshow10-1)、[request.agent.touch<sup>10+</sup>](js-apis-request.md#requestagenttouch10-1)、[request.agent.query<sup>10+</sup>](#requestagentquery10-1)进行查询。其中，使用[request.agent.query<sup>10+</sup>](#requestagentquery10-1)进行查询时会返回空字符串。 |
| tid | string | 是                                                      | 任务id。 |
| title | string | 是                                                      | 任务标题。 |
| description | string | 是                                                      | 任务描述。 |
| action | [Action](js-apis-request.md#action10) | 是                                                      | 任务操作选项。<br/>-UPLOAD表示上传任务。<br/>-DOWNLOAD表示下载任务。 |
| mode | [Mode](js-apis-request.md#mode10) | 是                                                      | 指定任务模式。<br/>-FOREGROUND表示前端任务。<br/>-BACKGROUND表示后台任务。 |
| priority<sup>11+</sup> | number | 否                                                      | 任务配置中的优先级。前端任务的优先级比后台任务高。相同模式的任务，数字越小优先级越高。 |
| mimeType | string | 是                                                      | 任务配置中的mimetype。 |
| progress | [Progress](js-apis-request.md#progress10) | 是                                                      | 任务的过程进度。 |
| gauge | boolean | 是                                                      | 后台任务的进度通知策略。 |
| ctime | number | 是                                                      | 创建任务的Unix时间戳（毫秒），由当前设备的系统生成。<br/>说明：使用[request.agent.search<sup>10+</sup>](js-apis-request.md#requestagentsearch10-1)进行查询时，该值需处于[after,before]区间内才可正常查询到任务id，before和after信息详见[Filter](#filter10)。
| mtime | number | 是                                                      | 任务状态改变时的Unix时间戳（毫秒），由当前设备的系统生成。|
| retry | boolean | 是                                                      | 任务的重试开关，仅应用于后台任务。 |
| tries | number | 是                                                      | 任务的尝试次数。 |
| faults | [Faults](js-apis-request.md#faults10) | 是                                                      | 任务的失败原因。<br/>-OTHERS表示其他故障。<br/>-DISCONNECT表示网络断开连接。<br/>-TIMEOUT表示任务超时。<br/>-PROTOCOL表示协议错误。<br/>-FSIO表示文件系统io错误。|
| reason | string | 是                                                      | 等待/失败/停止/暂停任务的原因。|
| extras | string | 否                                                      | 任务的额外部分。|


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
| 13400003 | task service ability error. |
| 21900006 | task not found error. |

**示例：**

  ```ts
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
| 13400003 | task service ability error. |
| 21900006 | task not found error. |

**示例：**

  ```ts
  request.agent.query("123456").then((taskInfo: request.agent.TaskInfo) => {
    console.info(`Succeeded in querying a upload task. result: ${taskInfo.uid}`);
}).catch((err: BusinessError) => {
    console.error(`Failed to query a upload task, Code: ${err.code}, message: ${err.message}`);
});
  ```

<!--no_check-->