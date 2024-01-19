# @ohos.request (上传下载)

request部件主要给应用提供上传下载文件、后台传输代理的基础能力。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```js
import request from '@ohos.request';
```

## Action<sup>10+</sup>  

定义操作选项。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| DOWNLOAD | 0 |表示下载任务。 |
| UPLOAD | 1 |表示上传任务。 |


## Mode<sup>10+</sup>  
定义模式选项。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| BACKGROUND | 0 |表示后台任务。 |
| FOREGROUND | 1 |表示前端任务。 |

## Network<sup>10+</sup>  

定义网络选项。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| ANY | 0 |表示不限网络类型。 |
| WIFI | 1 |表示无线网络。 |
| CELLULAR | 2 |表示蜂窝数据网络。 |


## FileSpec<sup>10+</sup> 
表单项的文件信息。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| path | string | 是 | 文件路径位于调用方的缓存文件夹下的相对路径。 |
| mimeType | string | 否 | 文件的mimetype通过文件名获取。 |
| filename | string | 否 | 文件名，默认值通过路径获取。 |
| extras | Object | 否 | 文件信息的附加内容。 |


## FormItem<sup>10+</sup> 
任务的表单项信息。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 表单参数名。 |
| value | string \| [FileSpec](#filespec10) \| Array&lt;[FileSpec](#filespec10)&gt; | 是 | 表单参数值。 |


## Config<sup>10+</sup> 
上传/下载任务的配置信息。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| action | [Action](#action10) | 是 | 任务操作选项。<br/>-UPLOAD表示上传任务。<br/>-DOWNLOAD表示下载任务。 |
| url | string | 是 | 资源地址，其最大长度为2048个字符。 |
| title | string | 否 | 任务标题，其最大长度为256个字符，默认值为小写的 upload 或 download，与上面的 action 保持一致。 |
| description | string | 否 | 任务的详细信息，其最大长度为1024个字符，默认值为空字符串。 |
| mode | [Mode](#mode10) | 否 | 任务模式,默认为后台任务。<br/>-对于前端任务，有回调通知。<br/>-对于后台任务，有系统通知、检测网络连接、恢复、自动重试功能。 |
| overwrite | boolean | 否 | 下载过程中路径已存在时的解决方案选择，默认为false。<br/>- true，覆盖已存在的文件。<br/>- false，下载失败。 |
| method | string | 否 | 上传或下载的HTTP标准方法，包括GET、POST和PUT，不区分大小写。<br/>-上传时，使用PUT或POST，默认值为PUT。<br/>-下载时，使用GET或POST，默认值为GET。 |
| headers | object | 否 | 添加要包含在任务中的HTTP协议标志头。<br/>-对于上传请求，默认的Content-Type为"multipart/form-data"。<br/>-对于下载请求，默认的Content-Type为"application/json"。 |
| data | string \| Array&lt;[FormItem](#formitem10)&gt; | 否 | -下载时，data为字符串类型，通常使用json(object将被转换为json文本)，默认为空。<br/>-上传时，data是表单项数组Array&lt;[FormItem](#formitem10)&gt;，默认为空。 |
| saveas | string | 否 | 保存下载文件的路径，包括如下两种：<br/>-相对路径，如"./xxx/yyy/zzz.html"、"xxx/yyy/zzz.html"，位于调用方的缓存路径下。<br/>-uri路径，如"datashare://bundle/xxx/yyy/zzz.html"，仅对具有访问url路径权限的应用开放。该功能暂不支持。<br/>默认为相对路径，即下载至应用当前缓存路径下。 |
| network | [Network](#network10) | 否 | 网络选项，当前支持无线网络WIFI和蜂窝数据网络CELLULAR，默认为ANY（WIFI或CELLULAR）。 |
| metered | boolean | 否 | 是否允许在按流量计费的网络中工作，默认为false。<br/>-true：是 <br/>-false：否|
| roaming | boolean | 否 | 是否允许在漫游网络中工作，默认为true。<br/>-true：是 <br/>-false：否 |
| retry | boolean | 否 | 是否为后台任务启用自动重试，仅应用于后台任务，默认为true。<br/>-true：是 <br/>-false：否 |
| redirect | boolean | 否 | 是否允许重定向，默认为true。<br/>-true：是 <br/>-false：否 |
| index | number | 否 | 任务的路径索引，通常用于任务断点续传，默认为0。 |
| begins | number | 否 | 文件起点，通常用于断点续传。默认值为0，取值为闭区间。<br/>-下载时，请求读取服务器开始下载文件时的起点位置（http协议中设置"Range"选项）。<br/>-上传时，在上传开始时读取。 |
| ends | number | 否 | 文件终点，通常用于断点续传。默认值为-1，取值为闭区间。<br/>-下载时，请求读取服务器开始下载文件时的结束位置（http协议中设置"Range"选项）。<br/>-上传时，在上传时结束读取。 |
| gauge | boolean | 否 | 后台任务的过程进度通知策略，仅应用于后台任务，默认值为false。<br/>-false：代表仅完成或失败的通知。<br/>-true，发出每个进度已完成或失败的通知。 |
| precise | boolean | 否 | -如果设置为true，在上传/下载无法获取文件大小时任务失败。<br/>-如果设置为false，将文件大小设置为-1时任务继续。<br/>默认值为false。 |
| token | string | 否 | 当创建了一个带有token的任务后，token则为正常查询期间必须提供的，否则将无法通过查询进行检索。其最小为8个字节，最大为2048个字节。默认为空。 |
| extras | object | 否 | 配置的附加功能，默认为空。 |

## State<sup>10+</sup>  

定义任务当前的状态。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| INITIALIZED | 0x00 |通过配置信息（[Config](#config10)）创建初始化任务。 |
| WAITING | 0x10 |表示任务缺少运行或重试的资源与网络状态不匹配。 |
| RUNNING | 0x20 |表示正在处理的任务。 |
| RETRYING | 0x21 |表示任务至少失败一次，现在正在再次处理中。 |
| PAUSED | 0x30 |表示任务暂停，通常后续会恢复任务。 |
| STOPPED | 0x31 |表示任务停止。 |
| COMPLETED | 0x40 |表示任务完成。 |
| FAILED | 0x41 |表示任务失败。 |
| REMOVED | 0x50 |表示任务移除。 |


## Progress<sup>10+</sup> 
任务进度的数据结构。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| state | [State](#state10) | 是 | 任务当前的状态。 |
| index | number | 是 | 任务中当前正在处理的文件索引。 |
| processed | number | 是 | 任务中当前文件的已处理数据大小，单位为B。|
| sizes | Array&lt;number&gt; | 是 | 任务中文件的大小，单位为B。 |
| extras | object | 否 | 交互的额外内容，例如来自服务器的响应的header和body。 |


## Faults<sup>10+</sup>  

定义任务失败的原因。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| OTHERS | 0xFF |表示其他故障。 |
| DISCONNECTED | 0x00 |表示网络断开连接。 |
| TIMEOUT | 0x10 |表示任务超时。 |
| PROTOCOL | 0x20 |表示协议错误，例如:服务器内部错误（500）、无法处理的数据区间（416）等。 |
| FSIO | 0x40 |表示文件系统io错误，例如打开/查找/读取/写入/关闭。 |


## Filter<sup>10+</sup>
过滤条件。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundle | string | 否 | 指定应用程序的包名，仅对系统应用开放。<br/>**系统接口**：此接口为系统接口。 |
| before | number | 否 | 结束的Unix时间戳（毫秒），默认为调用时刻。 |
| after | number | 否 | 开始的Unix时间戳（毫秒），默认值为调用时刻减24小时。 |
| state | [State](#state10) | 否 | 指定任务的状态。 |
| action | [Action](#action10) | 否 | 任务操作选项。<br/>-UPLOAD表示上传任务。<br/>-DOWNLOAD表示下载任务。 |
| mode | [Mode](#mode10) | 否 | 任务模式。<br/>-FOREGROUND表示前端任务。<br/>-BACKGROUND表示后台任务。<br/>-如果未填写，则查询所有任务。 |


## Task<sup>10+</sup> 
上传或下载任务。使用该方法前需要先获取Task对象，promise形式通过[request.agent.create<sup>10+</sup>](#requestagentcreate10-1)获取，callback形式通过[request.agent.create<sup>10+</sup>](#requestagentcreate10)获取。

### 属性
包括任务id和任务的配置信息。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| tid | string | 是 | 任务id，在系统上是唯一的，由系统自动生成。 |
| config | [Config](#config10) | 是 | 任务的配置信息。 |


### on('progress')<sup>10+</sup>

on(event: 'progress', callback: (progress: Progress) =&gt; void): void

订阅前端任务进度的事件，异步方法，使用callback形式返回结果。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'progress'，表示任务进度。 |
  | callback | function | 是 | 发生相关的事件时触发该回调方法，返回任务进度的数据结构。|

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 21900005 | task mode error. |

**示例：**

  ```ts
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOnTest",
    value: {
      filename: "taskOnTest.avi",
      mimeType: "application/octet-stream",
      path: "./taskOnTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1',
    title: 'taskOnTest',
    description: 'Sample code for event listening',
    mode: request.agent.Mode.FOREGROUND,
    overwrite: false,
    method: "PUT",
    data: attachments,
    saveas: "./",
    network: request.agent.Network.CELLULAR,
    metered: false,
    roaming: true,
    retry: true,
    redirect: true,
    index: 0,
    begins: 0,
    ends: -1,
    gauge: false,
    precise: false,
    token: "it is a secret"
  };
  let createOnCallback = (progress: request.agent.Progress) => {
    console.info('upload task progress.');
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    task.on('progress', createOnCallback);
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

### on('completed')<sup>10+</sup>

on(event: 'completed', callback: (progress: Progress) =&gt; void): void

订阅前端任务完成事件，异步方法，使用callback形式返回结果。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'completed'，表示任务完成。 |
  | callback | function | 是 | 发生相关的事件时触发该回调方法，返回任务进度的数据结构。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 21900005 | task mode error. |

**示例：**

  ```ts
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOnTest",
    value: {
      filename: "taskOnTest.avi",
      mimeType: "application/octet-stream",
      path: "./taskOnTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1',
    title: 'taskOnTest',
    description: 'Sample code for event listening',
    mode: request.agent.Mode.FOREGROUND,
    overwrite: false,
    method: "PUT",
    data: attachments,
    saveas: "./",
    network: request.agent.Network.CELLULAR,
    metered: false,
    roaming: true,
    retry: true,
    redirect: true,
    index: 0,
    begins: 0,
    ends: -1,
    gauge: false,
    precise: false,
    token: "it is a secret"
  };
  let createOnCallback = (progress: request.agent.Progress) => {
    console.info('upload task completed.');
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    task.on('completed', createOnCallback);
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

### on('failed')<sup>10+</sup>

on(event: 'failed', callback: (progress: Progress) =&gt; void): void

订阅前端任务失败事件，异步方法，使用callback形式返回结果。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'failed'，表示任务失败。 |
  | callback | function | 是 | 发生相关的事件时触发该回调方法，返回任务进度的数据结构。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 21900005 | task mode error. |

**示例：**

  ```ts
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOnTest",
    value: {
      filename: "taskOnTest.avi",
      mimeType: "application/octet-stream",
      path: "./taskOnTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1',
    title: 'taskOnTest',
    description: 'Sample code for event listening',
    mode: request.agent.Mode.FOREGROUND,
    overwrite: false,
    method: "PUT",
    data: attachments,
    saveas: "./",
    network: request.agent.Network.CELLULAR,
    metered: false,
    roaming: true,
    retry: true,
    redirect: true,
    index: 0,
    begins: 0,
    ends: -1,
    gauge: false,
    precise: false,
    token: "it is a secret"
  };
  let createOnCallback = (progress: request.agent.Progress) => {
    console.info('upload task failed.');
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    task.on('failed', createOnCallback);
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

### off('progress')<sup>10+</sup>

off(event: 'progress', callback?: (progress: Progress) =&gt; void): void

取消订阅前端任务进度事件。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'progress'，表示任务进度。 |
  | callback | function | 否 | 需要取消订阅的回调函数。若无此参数，则取消订阅当前类型的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 21900005 | task mode error. |

**示例：**

  ```ts
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOffTest",
    value: {
      filename: "taskOffTest.avi",
      mimeType: "application/octet-stream",
      path: "./taskOffTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1',
    title: 'taskOffTest',
    description: 'Sample code for event listening',
    mode: request.agent.Mode.FOREGROUND,
    overwrite: false,
    method: "PUT",
    data: attachments,
    saveas: "./",
    network: request.agent.Network.CELLULAR,
    metered: false,
    roaming: true,
    retry: true,
    redirect: true,
    index: 0,
    begins: 0,
    ends: -1,
    gauge: false,
    precise: false,
    token: "it is a secret"
  };
  let createOffCallback1 = (progress: request.agent.Progress) => {
    console.info('upload task progress.');
  };
  let createOffCallback2 = (progress: request.agent.Progress) => {
    console.info('upload task progress.');
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    task.on('progress', createOffCallback1);
    task.on('progress', createOffCallback2);
    //表示取消createOffCallback1的订阅
    task.off('progress', createOffCallback1);
    //表示取消订阅前端任务进度的所有回调
    task.off('progress');
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

### off('completed')<sup>10+</sup>

off(event: 'completed', callback?: (progress: Progress) =&gt; void): void

取消订阅前端任务完成事件。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'completed'，表示任务完成。 |
  | callback | function | 否 | 需要取消订阅的回调函数。若无此参数，则取消订阅当前类型的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 21900005 | task mode error. |

**示例：**

  ```ts
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOffTest",
    value: {
      filename: "taskOffTest.avi",
      mimeType: "application/octet-stream",
      path: "./taskOffTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1',
    title: 'taskOffTest',
    description: 'Sample code for event listening',
    mode: request.agent.Mode.FOREGROUND,
    overwrite: false,
    method: "PUT",
    data: attachments,
    saveas: "./",
    network: request.agent.Network.CELLULAR,
    metered: false,
    roaming: true,
    retry: true,
    redirect: true,
    index: 0,
    begins: 0,
    ends: -1,
    gauge: false,
    precise: false,
    token: "it is a secret"
  };
  let createOffCallback1 = (progress: request.agent.Progress) => {
    console.info('upload task completed.');
  };
  let createOffCallback2 = (progress: request.agent.Progress) => {
    console.info('upload task completed.');
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    task.on('completed', createOffCallback1);
    task.on('completed', createOffCallback2);
    //表示取消createOffCallback1的订阅
    task.off('completed', createOffCallback1);
    //表示取消订阅前端任务完成的所有回调
    task.off('completed');
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

### off('failed')<sup>10+</sup>

off(event: 'failed', callback?: (progress: Progress) =&gt; void): void

取消订阅前端任务失败事件。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'failed'，表示任务失败。 |
  | callback | function | 否 | 需要取消订阅的回调函数。若无此参数，则取消订阅当前类型的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 21900005 | task mode error. |

**示例：**

  ```ts
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOffTest",
    value: {
      filename: "taskOffTest.avi",
      mimeType: "application/octet-stream",
      path: "./taskOffTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1',
    title: 'taskOffTest',
    description: 'Sample code for event listening',
    mode: request.agent.Mode.FOREGROUND,
    overwrite: false,
    method: "PUT",
    data: attachments,
    saveas: "./",
    network: request.agent.Network.CELLULAR,
    metered: false,
    roaming: true,
    retry: true,
    redirect: true,
    index: 0,
    begins: 0,
    ends: -1,
    gauge: false,
    precise: false,
    token: "it is a secret"
  };
  let createOffCallback1 = (progress: request.agent.Progress) => {
    console.info('upload task failed.');
  };
  let createOffCallback2 = (progress: request.agent.Progress) => {
    console.info('upload task failed.');
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    task.on('failed', createOffCallback1);
    task.on('failed', createOffCallback2);
    //表示取消createOffCallback1的订阅
    task.off('failed', createOffCallback1);
    //表示取消订阅前端任务失败的所有回调
    task.off('failed');
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

### start<sup>10+</sup>

start(callback: AsyncCallback&lt;void&gt;): void

启动任务，无法启动已初始化的任务。使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | function | 是 | 回调函数，开启任务成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | task service ability error. |
  | 21900007 | task state error. |

**示例：**

  ```ts
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1',
    title: 'taskStartTest',
    description: 'Sample code for start the download task',
    mode: request.agent.Mode.BACKGROUND,
    overwrite: false,
    method: "GET",
    data: "",
    saveas: "./",
    network: request.agent.Network.CELLULAR,
    metered: false,
    roaming: true,
    retry: true,
    redirect: true,
    index: 0,
    begins: 0,
    ends: -1,
    gauge: false,
    precise: false,
    token: "it is a secret"
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    task.start((err: BusinessError) => {
      if (err) {
        console.error(`Failed to start the download task, Code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info(`Succeeded in starting a download task.`);
    });
    console.info(`Succeeded in creating a download task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

### start<sup>10+</sup>

start(): Promise&lt;void&gt;

启动任务，无法启动已初始化的任务。使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.Request.FileTransferAgent

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | task service ability error. |
  | 21900007 | task state error. |

**示例：**

  ```ts
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1',
    title: 'taskStartTest',
    description: 'Sample code for start the download task',
    mode: request.agent.Mode.BACKGROUND,
    overwrite: false,
    method: "GET",
    data: "",
    saveas: "./",
    network: request.agent.Network.CELLULAR,
    metered: false,
    roaming: true,
    retry: true,
    redirect: true,
    index: 0,
    begins: 0,
    ends: -1,
    gauge: false,
    precise: false,
    token: "it is a secret"
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    task.start().then(() => {
      console.info(`Succeeded in starting a download task.`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to start the download task, Code: ${err.code}, message: ${err.message}`);
    });
    console.info(`Succeeded in creating a download task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

### stop<sup>10+</sup>

stop(callback: AsyncCallback&lt;void&gt;): void

停止任务，可以停止正在运行/正在等待/正在重试的任务。使用callback异步回调。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | function | 是 | 回调函数，停止任务成功，err为undefined，否则为错误对象 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | task service ability error. |
  | 21900007 | task state error. |

**示例：**

  ```ts
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1',
    title: 'taskStopTest',
    description: 'Sample code for stop the download task',
    mode: request.agent.Mode.BACKGROUND,
    overwrite: false,
    method: "GET",
    data: "",
    saveas: "./",
    network: request.agent.Network.CELLULAR,
    metered: false,
    roaming: true,
    retry: true,
    redirect: true,
    index: 0,
    begins: 0,
    ends: -1,
    gauge: false,
    precise: false,
    token: "it is a secret"
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    task.stop((err: BusinessError) => {
      if (err) {
        console.error(`Failed to stop the download task, Code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info(`Succeeded in stopping a download task. `);
    });
    console.info(`Succeeded in creating a download task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
  });
  ```


### stop<sup>10+</sup>

stop(): Promise&lt;void&gt;

停止任务，可以停止正在运行/正在等待/正在重试的任务。使用Promise异步回调。

**系统能力**: SystemCapability.Request.FileTransferAgent

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | task service ability error. |
  | 21900007 | task state error. |

**示例：**

  ```ts
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1',
    title: 'taskStopTest',
    description: 'Sample code for stop the download task',
    mode: request.agent.Mode.BACKGROUND,
    overwrite: false,
    method: "GET",
    data: "",
    saveas: "./",
    network: request.agent.Network.CELLULAR,
    metered: false,
    roaming: true,
    retry: true,
    redirect: true,
    index: 0,
    begins: 0,
    ends: -1,
    gauge: false,
    precise: false,
    token: "it is a secret"
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    task.stop().then(() => {
      console.info(`Succeeded in stopping a download task. `);
    }).catch((err: BusinessError) => {
      console.error(`Failed to stop the download task, Code: ${err.code}, message: ${err.message}`);
    });
    console.info(`Succeeded in creating a download task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

## request.agent.create<sup>10+</sup>

create(context: BaseContext, config: Config, callback: AsyncCallback&lt;Task&gt;): void

创建要上传或下载的任务，并将其排入队列，每个应用最多支持创建10个未完成的任务。使用callback异步回调。


**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [BaseContext](js-apis-inner-application-baseContext.md) | 是 | 基于应用程序的上下文。 |
  | config | [Config](#config10) | 是 | 上传/下载任务的配置信息。 |
  | callback | AsyncCallback&lt;[Task](#task10)&gt; | 是 | 回调函数，返回创建任务的配置信息。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400001 | file operation error. |
  | 13400003 | task service ability error. |
  | 21900004 | application task queue full error. |
  | 21900005 | task mode error. |

**示例：**

  ```ts
  let attachments: Array<request.agent.FormItem> = [{
    name: "createTest",
    value: {
      filename: "createTest.avi",
      mimeType: "application/octet-stream",
      path: "./createTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1',
    title: 'createTest',
    description: 'Sample code for create task',
    mode: request.agent.Mode.BACKGROUND,
    overwrite: false,
    method: "PUT",
    data: attachments,
    saveas: "./",
    network: request.agent.Network.CELLULAR,
    metered: false,
    roaming: true,
    retry: true,
    redirect: true,
    index: 0,
    begins: 0,
    ends: -1,
    gauge: false,
    precise: false,
    token: "it is a secret"
  };
  request.agent.create(getContext(), config, (err: BusinessError, task: request.agent.Task) => {
    if (err) {
      console.error(`Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in creating a download task. result: ${task.config}`);
  });
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

## request.agent.create<sup>10+</sup>

create(context: BaseContext, config: Config): Promise&lt;Task&gt;

创建要上传或下载的任务，并将其排入队列，每个应用最多支持创建10个未完成的任务。使用Promise异步回调。


**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [BaseContext](js-apis-inner-application-baseContext.md) | 是 | 基于应用程序的上下文。 |
  | config | [Config](#config10) | 是 | 上传/下载任务的配置信息。 |

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Task](#task10)&gt; | Promise对象。返回任务配置信息的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400001 | file operation error. |
  | 13400003 | task service ability error. |
  | 21900004 | application task queue full error. |
  | 21900005 | task mode error. |

**示例：**

  ```ts
  let attachments: Array<request.agent.FormItem> = [{
    name: "createTest",
    value: {
      filename: "createTest.avi",
      mimeType: "application/octet-stream",
      path: "./createTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1',
    title: 'createTest',
    description: 'Sample code for create task',
    mode: request.agent.Mode.BACKGROUND,
    overwrite: false,
    method: "PUT",
    data: attachments,
    saveas: "./",
    network: request.agent.Network.CELLULAR,
    metered: false,
    roaming: true,
    retry: true,
    redirect: true,
    index: 0,
    begins: 0,
    ends: -1,
    gauge: false,
    precise: false,
    token: "it is a secret"
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    console.info(`Succeeded in creating a download task. result: ${task.config}`);
  }).catch((err) => {
    console.error(`Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

## request.agent.remove<sup>10+</sup>

remove(id: string, callback: AsyncCallback&lt;void&gt;): void

移除属于调用方的指定任务，如果正在处理中，该任务将被迫停止。使用callback异步回调。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | string | 是 | 任务id。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，删除指定任务成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | task service ability error. |
  | 21900006 | task not found error. |

**示例：**

  ```ts
  request.agent.remove("123456", (err: BusinessError) => {
    if (err) {
      console.error(`Failed to removing a download task, Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in creating a download task.`);
  });
  ```


## request.agent.remove<sup>10+</sup>

remove(id: string): Promise&lt;void&gt;

移除属于调用方的指定任务，如果正在处理中，该任务将被迫停止，使用Promise异步回调。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | string | 是 | 任务id。 |

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | task service ability error. |
  | 21900006 | task not found error. |

**示例：**

  ```ts
  request.agent.remove("123456").then(() => {
    console.info(`Succeeded in removing a download task. `);
  }).catch((err: BusinessError) => {
    console.error(`Failed to remove a download task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

<!--no_check-->