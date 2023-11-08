# @ohos.request (上传下载)

request部件主要给应用提供上传下载文件、后台传输代理的基础能力。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```js
import request from '@ohos.request';
```

## 常量

**需要权限**：ohos.permission.INTERNET

**系统能力**: 以下各项对应的系统能力均为SystemCapability.MiscServices.Download。

### 网络类型
下载支持自定义网络类型，可以在[DownloadConfig](#downloadconfig)中通过networkType配置成以下网络类型。

| 名称 | 参数类型 | 数值 | 说明 |
| -------- | -------- | -------- | -------- |
| NETWORK_MOBILE | number | 0x00000001 | 使用蜂窝网络时允许下载的位标志。 |
| NETWORK_WIFI | number | 0x00010000 | 使用WLAN时允许下载的位标志。 |

### 下载任务的错误码
下载[on('fail')<sup>7+</sup>](#onfail7)事件callback的错误参数、[getTaskInfo<sup>9+</sup>](#gettaskinfo9)返回值的failedReason字段取值。

| 名称 | 参数类型 | 数值 | 说明 |
| -------- | -------- | -------- | -------- |
| ERROR_CANNOT_RESUME<sup>7+</sup> | number |   0   | 网络原因导致恢复下载失败。 |
| ERROR_DEVICE_NOT_FOUND<sup>7+</sup> | number |   1   | 找不到SD卡等存储设备。 |
| ERROR_FILE_ALREADY_EXISTS<sup>7+</sup> | number |   2   | 要下载的文件已存在，下载会话不能覆盖现有文件。 |
| ERROR_FILE_ERROR<sup>7+</sup> | number |   3   | 文件操作失败。 |
| ERROR_HTTP_DATA_ERROR<sup>7+</sup> | number |   4   | HTTP传输失败。 |
| ERROR_INSUFFICIENT_SPACE<sup>7+</sup> | number |   5   | 存储空间不足。 |
| ERROR_TOO_MANY_REDIRECTS<sup>7+</sup> | number |   6   | 网络重定向过多导致的错误。 |
| ERROR_UNHANDLED_HTTP_CODE<sup>7+</sup> | number |   7   | 无法识别的HTTP代码。 |
| ERROR_UNKNOWN<sup>7+</sup> | number |   8   | 未知错误。 |
| ERROR_OFFLINE<sup>9+</sup> | number |   9   | 网络未连接。 |
| ERROR_UNSUPPORTED_NETWORK_TYPE<sup>9+</sup> | number |   10   | 网络类型不匹配。 |


### 下载任务暂停原因
下载相关[getTaskInfo<sup>9+</sup>](#gettaskinfo9)返回值的pausedReason字段取值。

| 名称 | 参数类型 | 数值 | 说明 |
| -------- | -------- | -------- | -------- |
| PAUSED_QUEUED_FOR_WIFI<sup>7+</sup> | number |   0   | 下载被暂停并等待WLAN连接，因为文件大小超过了使用蜂窝网络的会话允许的最大值。 |
| PAUSED_WAITING_FOR_NETWORK<sup>7+</sup> | number |   1   | 由于网络问题（例如网络断开）而暂停下载。 |
| PAUSED_WAITING_TO_RETRY<sup>7+</sup> | number |   2   | 发生网络错误，将重试下载会话。 |
| PAUSED_BY_USER<sup>9+</sup> | number |   3   | 用户暂停会话。 |
| PAUSED_UNKNOWN<sup>7+</sup> | number |   4   | 未知原因导致暂停下载。 |

### 下载任务状态码
下载相关[getTaskInfo<sup>9+</sup>](#gettaskinfo9)返回值的status字段取值。

| 名称 | 参数类型 | 数值 | 说明 |
| -------- | -------- | -------- | -------- |
| SESSION_SUCCESSFUL<sup>7+</sup> | number |   0   | 下载会话已完成。 |
| SESSION_RUNNING<sup>7+</sup> | number |   1   | 下载会话正在进行中。 |
| SESSION_PENDING<sup>7+</sup> | number |   2   | 正在调度下载会话。 |
| SESSION_PAUSED<sup>7+</sup> | number |   3   | 下载会话已暂停。 |
| SESSION_FAILED<sup>7+</sup> | number |   4   | 下载会话已失败，将不会重试。 |


## request.uploadFile<sup>9+</sup>

uploadFile(context: BaseContext, config: UploadConfig): Promise&lt;UploadTask&gt;

上传，异步方法，使用promise形式返回结果。通过[on('complete'|'fail')<sup>9+</sup>](#oncomplete--fail9)可获取任务上传时的错误信息。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [BaseContext](js-apis-inner-application-baseContext.md) | 是 | 基于应用程序的上下文。 |
  | config | [UploadConfig](#uploadconfig) | 是 | 上传的配置信息。 |


**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[UploadTask](#uploadtask)&gt; | 使用Promise方式，异步返回上传任务。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400002 | bad file path. |

**示例：**

  ```ts
  let uploadTask: request.UploadTask;
  let uploadConfig: request.UploadConfig = {
    url: 'http://www.example.com', //需要手动替换为真实服务器地址
    header: { 'Accept': '*/*' },
    method: "POST",
    files: [{ filename: "test", name: "test", uri: "internal://cache/test.jpg", type: "jpg" }],
    data: [{ name: "name123", value: "123" }],
  };
  try {
    request.uploadFile(getContext(), uploadConfig).then((data: request.UploadTask) => {
      uploadTask = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the upload. Code: ${err.code}, message: ${err.message}`);
    });
  } catch (err) {
    console.error(`Failed to request the upload. err: ${JSON.stringify(err)}`);
  }
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。


## request.uploadFile<sup>9+</sup>

uploadFile(context: BaseContext, config: UploadConfig, callback: AsyncCallback&lt;UploadTask&gt;): void

上传，异步方法，使用callback形式返回结果。通过[on('complete'|'fail')<sup>9+</sup>](#oncomplete--fail9)可获取任务上传时的错误信息。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [BaseContext](js-apis-inner-application-baseContext.md) | 是 | 基于应用程序的上下文。 |
  | config | [UploadConfig](#uploadconfig) | 是 | 上传的配置信息。 |
  | callback | AsyncCallback&lt;[UploadTask](#uploadtask)&gt; | 是 | 回调函数，异步返回UploadTask对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400002 | bad file path. |

**示例：**

  ```ts
  let uploadTask: request.UploadTask;
  let uploadConfig: request.UploadConfig = {
    url: 'http://www.example.com', //需要手动替换为真实服务器地址
    header: { 'Accept': '*/*' },
    method: "POST",
    files: [{ filename: "test", name: "test", uri: "internal://cache/test.jpg", type: "jpg" }],
    data: [{ name: "name123", value: "123" }],
  };
  try {
    request.uploadFile(getContext(), uploadConfig, (err: BusinessError, data: request.UploadTask) => {
      if (err) {
        console.error(`Failed to request the upload. Code: ${err.code}, message: ${err.message}`);
        return;
      }
      uploadTask = data;
    });
  } catch (err) {
    console.error(`Failed to request the upload. err: ${JSON.stringify(err)}`);
  }
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

## request.upload<sup>(deprecated)</sup>

upload(config: UploadConfig): Promise&lt;UploadTask&gt;

上传，异步方法，使用promise形式返回结果。

**模型约束**：此接口仅可在FA模型下使用

> **说明：**
>
> 从API Version 9开始不再维护，建议使用[request.uploadFile<sup>9+</sup>](#requestuploadfile9)替代。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | config | [UploadConfig](#uploadconfig) | 是 | 上传的配置信息。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[UploadTask](#uploadtask)&gt; | 使用Promise方式，异步返回上传任务。 |

**示例：**

  ```js
  let uploadTask;
  let uploadConfig = {
    url: 'http://www.example.com', //需要手动替换为真实服务器地址
    header: { 'Accept': '*/*' },
    method: "POST",
    files: [{ filename: "test", name: "test", uri: "internal://cache/test.jpg", type: "jpg" }],
    data: [{ name: "name123", value: "123" }],
  };
  request.upload(uploadConfig).then((data) => {
    uploadTask = data;
  }).catch((err) => {
    console.error(`Failed to request the upload. Code: ${err.code}, message: ${err.message}`);
  })
  ```


## request.upload<sup>(deprecated)</sup>

upload(config: UploadConfig, callback: AsyncCallback&lt;UploadTask&gt;): void

上传，异步方法，使用callback形式返回结果。

**模型约束**：此接口仅可在FA模型下使用

> **说明：**
>
> 从API Version 9开始不再维护，建议使用[request.uploadFile<sup>9+</sup>](#requestuploadfile9-1)替代。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | config | [UploadConfig](#uploadconfig) | 是 | 上传的配置信息。 |
  | callback | AsyncCallback&lt;[UploadTask](#uploadtask)&gt; | 是 | 回调函数，异步返回UploadTask对象。 |

**示例：**

  ```js
  let uploadTask;
  let uploadConfig = {
    url: 'http://www.example.com', //需要手动替换为真实服务器地址
    header: { 'Accept': '*/*' },
    method: "POST",
    files: [{ filename: "test", name: "test", uri: "internal://cache/test.jpg", type: "jpg" }],
    data: [{ name: "name123", value: "123" }],
  };
  request.upload(uploadConfig, (err, data) => {
    if (err) {
      console.error(`Failed to request the upload. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    uploadTask = data;
  });
  ```

## UploadTask

上传任务，使用下列方法前，需要先获取UploadTask对象，promise形式通过[request.uploadFile<sup>9+</sup>](#requestuploadfile9)获取，callback形式通过[request.uploadFile<sup>9+</sup>](#requestuploadfile9-1)获取。



### on('progress')

on(type: 'progress', callback:(uploadedSize: number, totalSize: number) =&gt; void): void

订阅上传任务进度事件，异步方法，使用callback形式返回结果。

> **说明：**
>
> 当应用处于后台时，为满足功耗性能要求，不支持调用此接口进行回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 订阅的事件类型，取值为'progress'（上传的进度信息）。 |
  | callback | function | 是 | 上传进度的回调函数。 |

  回调函数的参数

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uploadedSize | number | 是 | 当前已上传文件大小，单位为B。 |
| totalSize | number | 是 | 上传文件的总大小，单位为B。 |

**示例：**

  ```ts
  let upProgressCallback = (uploadedSize: number, totalSize: number) => {
    console.info("upload totalSize:" + totalSize + "  uploadedSize:" + uploadedSize);
  };
  uploadTask.on('progress', upProgressCallback);
  ```


### on('headerReceive')<sup>7+</sup>

on(type: 'headerReceive', callback:  (header: object) =&gt; void): void

订阅上传任务HTTP标头事件，异步方法，使用callback形式返回结果。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 订阅的事件类型，取值为'headerReceive'（接收响应头）。 |
  | callback | function | 是 | HTTP&nbsp;Response&nbsp;Header事件的回调函数。 |

  回调函数的参数：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| header | object | 是 | HTTP&nbsp;Response&nbsp;Header。 |

**示例：**

  ```ts
  let headerCallback = (headers: object) => {
    console.info("upOnHeader headers:" + JSON.stringify(headers));
  };
  uploadTask.on('headerReceive', headerCallback);
  ```


### on('complete' | 'fail')<sup>9+</sup>

 on(type:'complete' | 'fail', callback: Callback&lt;Array&lt;TaskState&gt;&gt;): void;

订阅上传任务完成或失败事件，异步方法，使用callback形式返回结果。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 订阅的事件类型，取值为'complete'，表示上传任务完成；取值为'fail'，表示上传任务失败。|
  | callback | Callback&lt;Array&lt;TaskState&gt;&gt; | 是 | 上传任务完成或失败的回调函数。 |

  回调函数的参数

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| taskstates | Array&lt;[TaskState](#taskstate9)&gt; | 是 | 上传任务返回结果 |

**示例：**

  ```ts
  let upCompleteCallback = (taskStates: Array<request.TaskState>) => {
    for (let i = 0; i < taskStates.length; i++) {
      console.info("upOnComplete taskState:" + JSON.stringify(taskStates[i]));
    }
  };
  uploadTask.on('complete', upCompleteCallback);

  let upFailCallback = (taskStates: Array<request.TaskState>) => {
    for (let i = 0; i < taskStates.length; i++) {
      console.info("upOnFail taskState:" + JSON.stringify(taskStates[i]));
    }
  };
  uploadTask.on('fail', upFailCallback);
  ```


### off('progress')

off(type:  'progress',  callback?: (uploadedSize: number, totalSize: number) =&gt;  void): void

取消订阅上传任务进度事件，异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消订阅的事件类型，取值为'progress'（上传的进度信息）。 |
  | callback | function | 否 | 需要删除的上传任务进度的回调函数。<br/>uploadedSize：当前已上传文件的大小，单位为B。<br/>totalSize：上传文件的总大小，单位为B。 |

**示例：**

  ```ts
  let upProgressCallback1 = (uploadedSize: number, totalSize: number) => {
    console.info('Upload delete progress notification.' + 'totalSize:' + totalSize + 'uploadedSize:' + uploadedSize);
  };
  let upProgressCallback2 = (uploadedSize: number, totalSize: number) => {
    console.info('Upload delete progress notification.' + 'totalSize:' + totalSize + 'uploadedSize:' + uploadedSize);
  };
  uploadTask.on('progress', upProgressCallback1);
  uploadTask.on('progress', upProgressCallback2);
  //表示取消upProgressCallback1的订阅
  uploadTask.off('progress', upProgressCallback1);
  //表示取消订阅上传任务进度事件的所有回调
  uploadTask.off('progress');
  ```


### off('headerReceive')<sup>7+</sup>

off(type: 'headerReceive', callback?: (header: object) =&gt; void): void

取消订阅上传任务HTTP标头事件，异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消订阅的事件类型，取值为'headerReceive'（接收响应头）。 |
  | callback | function | 否 | HTTP&nbsp;Response&nbsp;需要删除的Header事件的回调函数。<br/>header：HTTP&nbsp;Response&nbsp;Header。 |

**示例：**

  ```ts
  let headerCallback1 = (header: object) => {
    console.info(`Upload delete headerReceive notification. header: ${JSON.stringify(header)}`);
  };
  let headerCallback2 = (header: object) => {
    console.info(`Upload delete headerReceive notification. header: ${JSON.stringify(header)}`);
  };
  uploadTask.on('headerReceive', headerCallback1);
  uploadTask.on('headerReceive', headerCallback2);
  //表示取消headerCallback1的订阅
  uploadTask.off('headerReceive', headerCallback1);
  //表示取消订阅上传任务HTTP标头事件的所有回调
  uploadTask.off('headerReceive');
  ```

### off('complete' | 'fail')<sup>9+</sup>

 off(type:'complete' | 'fail', callback?: Callback&lt;Array&lt;TaskState&gt;&gt;): void;

取消订阅上传任务完成或失败事件，异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 订阅的事件类型，取值为'complete'，表示上传任务完成；取值为'fail'，表示上传任务失败。|
  | callback | Callback&lt;Array&lt;TaskState&gt;&gt; | 否 | 需要删除的上传任务完成或失败的回调函数。<br/>taskstates：上传任务返回结果 |

**示例：**

  ```ts
  let upCompleteCallback1 = (taskStates: Array<request.TaskState>) => {
    console.info('Upload delete complete notification.');
    for (let i = 0; i < taskStates.length; i++) {
      console.info('taskState:' + JSON.stringify(taskStates[i]));
    }
  };
  let upCompleteCallback2 = (taskStates: Array<request.TaskState>) => {
    console.info('Upload delete complete notification.');
    for (let i = 0; i < taskStates.length; i++) {
      console.info('taskState:' + JSON.stringify(taskStates[i]));
    }
  };
  uploadTask.on('complete', upCompleteCallback1);
  uploadTask.on('complete', upCompleteCallback2);
  //表示取消headerCallback1的订阅
  uploadTask.off('complete', upCompleteCallback1);
  //表示取消订阅上传任务完成的所有回调
  uploadTask.off('complete');

  let upFailCallback1 = (taskStates: Array<request.TaskState>) => {
    console.info('Upload delete fail notification.');
    for (let i = 0; i < taskStates.length; i++) {
      console.info('taskState:' + JSON.stringify(taskStates[i]));
    }
  };
  let upFailCallback2 = (taskStates: Array<request.TaskState>) => {
    console.info('Upload delete fail notification.');
    for (let i = 0; i < taskStates.length; i++) {
      console.info('taskState:' + JSON.stringify(taskStates[i]));
    }
  };
  uploadTask.on('fail', upFailCallback1);
  uploadTask.on('fail', upFailCallback2);
  //表示取消headerCallback1的订阅
  uploadTask.off('fail', upFailCallback1);
  //表示取消订阅上传任务失败的所有回调
  uploadTask.off('fail');
  ```

### delete<sup>9+</sup>
delete(): Promise&lt;boolean&gt;

移除上传的任务，异步方法，使用promise形式返回结果。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Upload

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 使用Promise方式，异步返回移除任务是否成功。true：成功，false：不成功。 |

**示例：**

  ```ts
  uploadTask.delete().then((result: boolean) => {
    console.info('Succeeded in deleting the upload task.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to delete the upload task. Code: ${err.code}, message: ${err.message}`);
  });
  ```


### delete<sup>9+</sup>

delete(callback: AsyncCallback&lt;boolean&gt;): void

移除上传的任务，异步方法，使用callback形式返回结果。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数，异步返回移除任务是否成功。true：成功，false：不成功。 |

**示例：**

  ```ts
  uploadTask.delete((err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to delete the upload task. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in deleting the upload task.');
  });
  ```


### remove<sup>(deprecated)</sup>

remove(): Promise&lt;boolean&gt;

移除上传的任务，异步方法，使用promise形式返回结果。

> **说明：**
>
> 从API Version 9开始不再维护，建议使用[delete<sup>9+</sup>](#delete9)替代。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Upload

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 使用Promise方式，异步返回移除任务是否成功。true：成功，false：不成功。 |

**示例：**

  ```js
  uploadTask.remove().then((result) => {
    console.info('Succeeded in removing the upload task.');
  }).catch((err) => {
    console.error(`Failed to remove the upload task. Code: ${err.code}, message: ${err.message}`);
  });
  ```


### remove<sup>(deprecated)</sup>

remove(callback: AsyncCallback&lt;boolean&gt;): void

移除上传的任务，异步方法，使用callback形式返回结果。

> **说明：**
>
> 从API Version 9开始不再维护，建议使用[delete<sup>9+</sup>](#delete9-1)替代。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数，异步返回移除任务是否成功。true：成功，false：不成功。 |

**示例：**

  ```js
  uploadTask.remove((err, result) => {
    if (err) {
      console.error(`Failed to remove the upload task. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    if (result) {
      console.info('Succeeded in removing the upload task.');
    } else {
      console.error(`Failed to remove the upload task. Code: ${err.code}, message: ${err.message}`);
    }
  });
  ```

## UploadConfig<sup>6+</sup>
上传任务的配置信息。

**需要权限**：ohos.permission.INTERNET

**系统能力**: 以下各项对应的系统能力均为SystemCapability.MiscServices.Upload。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| url | string | 是 | 资源地址。 |
| header | Object | 是 | 添加要包含在上传请求中的HTTP或HTTPS标志头。 |
| method | string | 是 | 请求方法：POST、PUT。缺省为POST。 |
| files | Array&lt;[File](#file)&gt; | 是 | 要上传的文件列表。请使用&nbsp;multipart/form-data提交。 |
| data | Array&lt;[RequestData](#requestdata)&gt; | 是 | 请求的表单数据。 |

## UploadConfig<sup>11+</sup>
上传任务的配置信息。

**需要权限**：ohos.permission.INTERNET

**系统能力**: 以下各项对应的系统能力均为SystemCapability.MiscServices.Upload。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 否 | 任务的路径索引，默认值为0。 |
| begins | number | 否 | 在上传开始时读取的文件起点。默认值为0，取值为闭区间。|
| ends | number | 否 | 在上传结束时读取的文件终点。默认值为-1，取值为闭区间。 |

## TaskState<sup>9+</sup>
上传任务信息，[on('complete' | 'fail')<sup>9+</sup>](#oncomplete--fail9)和[off('complete' | 'fail')<sup>9+</sup>](#offcomplete--fail9)接口的回调参数。

**需要权限**：ohos.permission.INTERNET

**系统能力**: 以下各项对应的系统能力均为SystemCapability.MiscServices.Upload。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| path | string | 是 | 文件路径 |
| responseCode | number | 是 | 上传任务返回值，0表示任务成功，其它返回码为失败，具体请查看message上传任务结果描述信息 |
| message | string | 是 | 上传任务结果描述信息 |

## File
[UploadConfig](#uploadconfig)中的文件列表。

**需要权限**：ohos.permission.INTERNET

**系统能力**: 以下各项对应的系统能力均为SystemCapability.MiscServices.Download。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| filename | string | 是 | multipart提交时，请求头中的文件名。 |
| name | string | 是 | multipart提交时，表单项目的名称，缺省为file。 |
| uri | string | 是 | 文件的本地存储路径。<br/>仅支持"internal"协议类型，"internal://cache/"为必填字段，示例：<br/>internal://cache/path/to/file.txt |
| type | string | 是 | 文件的内容类型，默认根据文件名或路径的后缀获取。 |


## RequestData
[UploadConfig](#uploadconfig)中的表单数据。

**需要权限**：ohos.permission.INTERNET

**系统能力**: 以下各项对应的系统能力均为SystemCapability.MiscServices.Download。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 表示表单元素的名称。 |
| value | string | 是 | 表示表单元素的值。 |

## request.downloadFile<sup>9+</sup>

downloadFile(context: BaseContext, config: DownloadConfig): Promise&lt;DownloadTask&gt;

下载，异步方法，使用promise形式返回结果。通过[on('complete'|'pause'|'remove')<sup>7+</sup>](#oncompletepauseremove7)可获取任务下载时的状态信息，包括任务完成、暂停或移除。通过[on('fail')<sup>7+</sup>](#onfail7)可获取任务下载时的错误信息。


**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [BaseContext](js-apis-inner-application-baseContext.md) | 是 | 基于应用程序的上下文。 |
  | config | [DownloadConfig](#downloadconfig) | 是 | 下载的配置信息。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[DownloadTask](#downloadtask)&gt; | 使用Promise方式，异步返回返回下载任务。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400001 | file operation error. |
  | 13400002 | bad file path. |
  | 13400003 | task service ability error. |

**示例：**

  ```ts
  let downloadTask: request.DownloadTask;
  try {
    request.downloadFile(getContext(), { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      downloadTask = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。


## request.downloadFile<sup>9+</sup>

downloadFile(context: BaseContext, config: DownloadConfig, callback: AsyncCallback&lt;DownloadTask&gt;): void;

下载，异步方法，使用callback形式返回结果。通过[on('complete'|'pause'|'remove')<sup>7+</sup>](#oncompletepauseremove7)可获取任务下载时的状态信息，包括任务完成、暂停或移除。通过[on('fail')<sup>7+</sup>](#onfail7)可获取任务下载时的错误信息。


**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [BaseContext](js-apis-inner-application-baseContext.md) | 是 | 基于应用程序的上下文。 |
  | config | [DownloadConfig](#downloadconfig) | 是 | 下载的配置信息。 |
  | callback | AsyncCallback&lt;[DownloadTask](#downloadtask)&gt; | 是 | 回调函数，异步返回下载任务。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400001 | file operation error. |
  | 13400002 | bad file path. |
  | 13400003 | task service ability error. |

**示例：**

  ```ts
  let downloadTask: request.DownloadTask;
  try {
    request.downloadFile(getContext(), {
      url: 'https://xxxx/xxxxx.hap',
      filePath: 'xxx/xxxxx.hap'
    }, (err: BusinessError, data: request.DownloadTask) => {
      if (err) {
        console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
        return;
      }
      downloadTask = data;
    });
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

## request.download<sup>(deprecated)</sup>

download(config: DownloadConfig): Promise&lt;DownloadTask&gt;

下载，异步方法，使用promise形式返回结果。

> **说明：**
>
> 从API Version 9开始不再维护，建议使用[request.downloadFile<sup>9+</sup>](#requestdownloadfile9)替代。

**模型约束**：此接口仅可在FA模型下使用

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | config | [DownloadConfig](#downloadconfig) | 是 | 下载的配置信息。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[DownloadTask](#downloadtask)&gt; | 使用Promise方式，异步返回返回下载任务。 |

**示例：**

  ```js
  let downloadTask;
  request.download({ url: 'https://xxxx/xxxx.hap' }).then((data) => {
    downloadTask = data;
  }).catch((err) => {
    console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
  })
  ```


## request.download<sup>(deprecated)</sup>

download(config: DownloadConfig, callback: AsyncCallback&lt;DownloadTask&gt;): void

下载，异步方法，使用callback形式返回结果。

> **说明：**
>
> 从API Version 9开始不再维护，建议使用[request.downloadFile<sup>9+</sup>](#requestdownloadfile9-1)替代。

**模型约束**：此接口仅可在FA模型下使用

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | config | [DownloadConfig](#downloadconfig) | 是 | 下载的配置信息。 |
  | callback | AsyncCallback&lt;[DownloadTask](#downloadtask)&gt; | 是 | 回调函数，异步返回下载任务。 |

**示例：**

  ```js
  let downloadTask;
  request.download({ url: 'https://xxxx/xxxxx.hap', 
  filePath: 'xxx/xxxxx.hap'}, (err, data) => {
    if (err) {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    downloadTask = data;
  });
  ```

## DownloadTask

下载任务，使用下列方法前，需要先获取DownloadTask对象，promise形式通过[request.downloadFile<sup>9+</sup>](#requestdownloadfile9)获取，callback形式通过[request.downloadFile<sup>9+</sup>](#requestdownloadfile9-1)获取。


### on('progress')

on(type: 'progress', callback:(receivedSize: number, totalSize: number) =&gt; void): void

订阅下载任务进度事件，异步方法，使用callback形式返回结果。

> **说明：**
>
> 当应用处于后台时，为满足功耗性能要求，不支持调用此接口进行回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 订阅的事件类型，取值为'progress'（下载的进度信息）。 |
  | callback | function | 是 | 下载任务进度的回调函数。 |

  回调函数的参数：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| receivedSize | number | 是 | 当前下载的进度，单位为B。 |
| totalSize | number | 是 | 下载文件的总大小，单位为B。 |

**示例：**

  ```ts
  let progressCallback = (receivedSize: number, totalSize: number) => {
    console.info("download receivedSize:" + receivedSize + " totalSize:" + totalSize);
  };
  downloadTask.on('progress', progressCallback);
  ```


### off('progress')

off(type: 'progress', callback?: (receivedSize: number, totalSize: number) =&gt; void): void

取消订阅下载任务进度事件，异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消订阅的事件类型，取值为'progress'（下载的进度信息）。 |
  | callback | function | 否 | 需要删除的下载任务进度的回调。 <br/>receivedSize：当前下载任务的进度；<br/>totalSize：下载文件的总大小。 |

**示例：**

  ```ts
  let progressCallback1 = (receivedSize: number, totalSize: number) => {
    console.info('Download delete progress notification.' + 'receivedSize:' + receivedSize + 'totalSize:' + totalSize);
  };
  let progressCallback2 = (receivedSize: number, totalSize: number) => {
    console.info('Download delete progress notification.' + 'receivedSize:' + receivedSize + 'totalSize:' + totalSize);
  };
  downloadTask.on('progress', progressCallback1);
  downloadTask.on('progress', progressCallback2);
  //表示取消progressCallback1的订阅
  downloadTask.off('progress', progressCallback1);
  //表示取消订阅下载任务进度事件的所有回调
  downloadTask.off('progress');
  ```


### on('complete'|'pause'|'remove')<sup>7+</sup>

on(type: 'complete'|'pause'|'remove', callback:() =&gt; void): void

订阅下载任务相关的事件，异步方法，使用callback形式返回。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 订阅的事件类型。<br>- 取值为'complete'，表示下载任务完成；<br/>- 取值为'pause'，表示下载任务暂停；<br/>- 取值为'remove'，表示下载任务移除。 |
  | callback | function | 是 | 下载任务相关的回调函数。|

**示例：**

  ```ts
  let completeCallback = () => {
    console.info('Download task completed.');
  };
  downloadTask.on('complete', completeCallback);

  let pauseCallback = () => {
    console.info('Download task pause.');
  };
  downloadTask.on('pause', pauseCallback);

  let removeCallback = () => {
    console.info('Download task remove.');
  };
  downloadTask.on('remove', removeCallback);
  ```


### off('complete'|'pause'|'remove')<sup>7+</sup>

off(type: 'complete'|'pause'|'remove', callback?:() =&gt; void): void

取消订阅下载任务相关的事件，异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消订阅的事件类型。<br/>- 取值为'complete'，表示下载任务完成；<br/>- 取值为'pause'，表示下载任务暂停；<br/>- 取值为'remove'，表示下载任务移除。 |
  | callback | function | 否 | 需要删除的下载任务相关的回调。 |

**示例：**

  ```ts
  let completeCallback1 = () => {
    console.info('Download delete complete notification.');
  };
  let completeCallback2 = () => {
    console.info('Download delete complete notification.');
  };
  downloadTask.on('complete', completeCallback1);
  downloadTask.on('complete', completeCallback2);
  //表示取消completeCallback1的订阅
  downloadTask.off('complete', completeCallback1);
  //表示取消订阅下载任务完成的所有回调
  downloadTask.off('complete');

  let pauseCallback1 = () => {
    console.info('Download delete pause notification.');
  };
  let pauseCallback2 = () => {
    console.info('Download delete pause notification.');
  };
  downloadTask.on('pause', pauseCallback1);
  downloadTask.on('pause', pauseCallback2);
  //表示取消pauseCallback1的订阅
  downloadTask.off('pause', pauseCallback1);
  //表示取消订阅下载任务暂停的所有回调
  downloadTask.off('pause');

  let removeCallback1 = () => {
    console.info('Download delete remove notification.');
  };
  let removeCallback2 = () => {
    console.info('Download delete remove notification.');
  };
  downloadTask.on('remove', removeCallback1);
  downloadTask.on('remove', removeCallback2);
  //表示取消removeCallback1的订阅
  downloadTask.off('remove', removeCallback1);
  //表示取消订阅下载任务移除的所有回调
  downloadTask.off('remove');
  ```


### on('fail')<sup>7+</sup>

on(type: 'fail', callback: (err: number) =&gt; void): void

订阅下载任务失败事件，异步方法，使用callback形式返回结果。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 订阅的事件类型，取值为'fail'（下载失败）。 |
  | callback | function | 是 | 下载失败的回调函数。 |

  回调函数的参数：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| err | number | 是 | 下载失败的错误码，错误原因见[下载任务的错误码](#下载任务的错误码)。 |

**示例：**

  ```ts
  let failCallback = (err: number) => {
    console.error(`Failed to download the task. Code: ${err}`);
  };
  downloadTask.on('fail', failCallback);
  ```


### off('fail')<sup>7+</sup>

off(type: 'fail', callback?: (err: number) =&gt; void): void

取消订阅下载任务失败事件，异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消订阅的事件类型，取值为'fail'（下载失败）。 |
  | callback | function | 否 | 需要删除的下载失败的回调函数。<br/>err：下载失败的错误码。 |

**示例：**

  ```ts
  let failCallback1 = (err: number) => {
    console.error(`Failed to download the task. Code: ${err}`);
  };
  let failCallback2 = (err: number) => {
    console.error(`Failed to download the task. Code: ${err}`);
  };
  downloadTask.on('fail', failCallback1);
  downloadTask.on('fail', failCallback2);
  //表示取消failCallback1的订阅
  downloadTask.off('fail', failCallback1);
  //表示取消订阅下载任务失败的所有回调
  downloadTask.off('fail');
  ```

### delete<sup>9+</sup>

delete(): Promise&lt;boolean&gt;

移除下载的任务，异步方法，使用promise形式返回结果。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 使用promise方式，异步返回移除任务是否成功。true：成功，false：不成功。 |

**示例：**

  ```ts
  downloadTask.delete().then((result: boolean) => {
    console.info('Succeeded in removing the download task.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to remove the download task. Code: ${err.code}, message: ${err.message}`);
  });
  ```


### delete<sup>9+</sup>

delete(callback: AsyncCallback&lt;boolean&gt;): void

移除下载的任务，异步方法，使用callback形式返回结果。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数，异步返回移除任务是否成功。true：成功，false：不成功。 |

**示例：**

  ```ts
  downloadTask.delete((err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to remove the download task. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in removing the download task.');
  });
  ```


### getTaskInfo<sup>9+</sup>

getTaskInfo(): Promise&lt;DownloadInfo&gt;

查询下载任务，异步方法，使用promise形式返回DownloadInfo里的信息。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[DownloadInfo](#downloadinfo7)&gt; |  使用promise方式，异步返回下载任务信息。 |

**示例：**

  ```ts
  downloadTask.getTaskInfo().then((downloadInfo: request.DownloadInfo) => {
    console.info('Succeeded in querying the download task')
  }).catch((err: BusinessError) => {
    console.error(`Failed to query the download task. Code: ${err.code}, message: ${err.message}`)
  });
  ```


### getTaskInfo<sup>9+</sup>

getTaskInfo(callback: AsyncCallback&lt;DownloadInfo&gt;): void

查询下载的任务，异步方法，使用callback形式返回结果。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[DownloadInfo](#downloadinfo7)&gt; | 是 | 回调函数，异步返回下载任务信息。 |

**示例：**

  ```ts
  downloadTask.getTaskInfo((err: BusinessError, downloadInfo: request.DownloadInfo) => {
    if (err) {
      console.error(`Failed to query the download mimeType. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('Succeeded in querying the download mimeType');
    }
  });
  ```


### getTaskMimeType<sup>9+</sup>

getTaskMimeType(): Promise&lt;string&gt;

查询下载的任务的 MimeType，异步方法，使用promise形式返回结果。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;string&gt; | 使用promise方式，异步返回下载任务的MimeType。 |

**示例：**

  ```ts
  downloadTask.getTaskMimeType().then((data: string) => {
    console.info('Succeeded in querying the download MimeType');
  }).catch((err: BusinessError) => {
    console.error(`Failed to query the download MimeType. Code: ${err.code}, message: ${err.message}`)
  });
  ```


### getTaskMimeType<sup>9+</sup>

getTaskMimeType(callback: AsyncCallback&lt;string&gt;): void;

查询下载的任务的 MimeType，异步方法，使用callback形式返回结果。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;string&gt; | 是 | 回调函数，异步返回下载任务的MimeType。 |

**示例：**

  ```ts
  downloadTask.getTaskMimeType((err: BusinessError, data: string) => {
    if (err) {
      console.error(`Failed to query the download mimeType. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('Succeeded in querying the download mimeType');
    }
  });
  ```


### suspend<sup>9+</sup>

suspend(): Promise&lt;boolean&gt;

暂停下载任务，异步方法，使用promise形式返回结果。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 使用promise方式，异步返回暂停下载任务是否成功。 |

**示例：**

  ```ts
  downloadTask.suspend().then((result: boolean) => {
    console.info('Succeeded in pausing the download task.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to pause the download task. Code: ${err.code}, message: ${err.message}`);
  });
  ```


### suspend<sup>9+</sup>

suspend(callback: AsyncCallback&lt;boolean&gt;): void

暂停下载任务，异步方法，使用callback形式返回结果。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数，异步返回暂停下载任务是否成功。 |

**示例：**

  ```ts
  downloadTask.suspend((err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to pause the download task. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in pausing the download task.');
  });
  ```


### restore<sup>9+</sup>

restore(): Promise&lt;boolean&gt;

重新启动暂停的下载任务，异步方法，使用promise形式返回结果。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 使用promise方式，异步返回重新启动暂停的下载任务是否成功。 |

**示例：**

  ```ts
  downloadTask.restore().then((result: boolean) => {
    console.info('Succeeded in resuming the download task.')
  }).catch((err: BusinessError) => {
    console.error(`Failed to resume the download task. Code: ${err.code}, message: ${err.message}`);
  });
  ```


### restore<sup>9+</sup>

restore(callback: AsyncCallback&lt;boolean&gt;): void

重新启动暂停的下载任务，异步方法，使用callback形式返回结果。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数，异步返回重新启动暂停的下载任务是否成功。 |

**示例：**

  ```ts
  downloadTask.restore((err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to resume the download task. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in resuming the download task.');
  });
  ```


### remove<sup>(deprecated)</sup>

remove(): Promise&lt;boolean&gt;

移除下载的任务，异步方法，使用promise形式返回结果。

> **说明：**
>
> 从API Version 9开始不再维护，建议使用[delete<sup>9+</sup>](#delete9-2)替代。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 使用promise方式，异步返回移除任务是否成功。 |

**示例：**

  ```js
  downloadTask.remove().then((result) => {
    console.info('Succeeded in removing the download task.');
  }).catch ((err) => {
    console.error(`Failed to remove the download task. Code: ${err.code}, message: ${err.message}`);
  });
  ```


### remove<sup>(deprecated)</sup>

remove(callback: AsyncCallback&lt;boolean&gt;): void

移除下载的任务，异步方法，使用callback形式返回结果。

> **说明：**
>
> 从API Version 9开始不再维护，建议使用[delete<sup>9+</sup>](#delete9-3)替代。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数，异步返回移除任务是否成功。 |

**示例：**

  ```js
  downloadTask.remove((err, result)=>{
    if(err) {
      console.error(`Failed to remove the download task. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in removing the download task.');
  });
  ```


### query<sup>(deprecated)</sup>

query(): Promise&lt;DownloadInfo&gt;

查询下载任务，异步方法，使用promise形式返回DownloadInfo里的信息。

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始不再维护，建议使用[getTaskInfo<sup>9+</sup>](#gettaskinfo9)替代。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[DownloadInfo](#downloadinfo7)&gt; | 使用promise方式，异步返回下载任务信息。 |

**示例：**

  ```js
  downloadTask.query().then((downloadInfo) => {    
    console.info('Succeeded in querying the download task.')
  }) .catch((err) => {
    console.error(`Failed to query the download task. Code: ${err.code}, message: ${err.message}`)
  });
  ```


### query<sup>(deprecated)</sup>

query(callback: AsyncCallback&lt;DownloadInfo&gt;): void

查询下载的任务，异步方法，使用callback形式返回结果。

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始不再维护，建议使用[getTaskInfo<sup>9+</sup>](#gettaskinfo9-1)替代。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[DownloadInfo](#downloadinfo7)&gt; | 是 | 回调函数，异步返回下载任务信息。 |

**示例：**

  ```js
  downloadTask.query((err, downloadInfo)=>{
    if(err) {
      console.error(`Failed to query the download mimeType. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('Succeeded in querying the download task.');
    }
  });
  ```


### queryMimeType<sup>(deprecated)</sup>

queryMimeType(): Promise&lt;string&gt;

查询下载的任务的 MimeType，异步方法，使用promise形式返回结果。

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始不再维护，建议使用[getTaskMimeType<sup>9+</sup>](#gettaskmimetype9)替代。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;string&gt; | 使用promise方式，异步返回下载任务的MimeType。 |

**示例：**

  ```js
  downloadTask.queryMimeType().then((data) => {    
    console.info('Succeeded in querying the download MimeType.');
  }).catch((err) => {
    console.error(`Failed to query the download MimeType. Code: ${err.code}, message: ${err.message}`)
  });
  ```


### queryMimeType<sup>(deprecated)</sup>

queryMimeType(callback: AsyncCallback&lt;string&gt;): void;

查询下载的任务的 MimeType，异步方法，使用callback形式返回结果。

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始不再维护，建议使用[getTaskMimeType<sup>9+</sup>](#gettaskmimetype9-1)替代。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;string&gt; | 是 | 回调函数，异步返回下载任务的MimeType。 |

**示例：**

  ```js
  downloadTask.queryMimeType((err, data)=>{
    if(err) {
      console.error(`Failed to query the download mimeType. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('Succeeded in querying the download mimeType.');
    }
  });
  ```


### pause<sup>(deprecated)</sup>

pause(): Promise&lt;void&gt;

暂停下载任务，异步方法，使用promise形式返回结果。

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始不再维护，建议使用[suspend<sup>9+</sup>](#suspend9)替代。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | 使用promise方式，异步返回暂停下载任务是否成功。 |

**示例：**

  ```js
  downloadTask.pause().then((result) => {    
    console.info('Succeeded in pausing the download task.');
  }).catch((err) => {
    console.error(`Failed to pause the download task. Code: ${err.code}, message: ${err.message}`);
  });
  ```


### pause<sup>(deprecated)</sup>

pause(callback: AsyncCallback&lt;void&gt;): void

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始不再维护，建议使用[suspend<sup>9+</sup>](#suspend9-1)替代。

暂停下载任务，异步方法，使用callback形式返回结果。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，异步返回暂停下载任务是否成功。 |

**示例：**

  ```js
  downloadTask.pause((err, result)=>{
    if(err) {
      console.error(`Failed to pause the download task. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in pausing the download task.');
  });
  ```


### resume<sup>(deprecated)</sup>

resume(): Promise&lt;void&gt;

重新启动暂停的下载任务，异步方法，使用promise形式返回结果。

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始不再维护，建议使用[restore<sup>9+</sup>](#restore9)替代。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | 使用promise方式，异步返回重新启动暂停的下载任务是否成功。 |

**示例：**

  ```js
  downloadTask.resume().then((result) => {
    console.info('Succeeded in resuming the download task.')
  }).catch((err) => {
    console.error(`Failed to resume the download task. Code: ${err.code}, message: ${err.message}`);
  });
  ```


### resume<sup>(deprecated)</sup>

resume(callback: AsyncCallback&lt;void&gt;): void

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始不再维护，建议使用[restore<sup>9+</sup>](#restore9-1)替代。

重新启动暂停的下载任务，异步方法，使用callback形式返回结果。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，异步返回重新启动暂停的下载任务是否成功。 |

**示例：**

  ```js
  downloadTask.resume((err, result)=>{
    if (err) {
      console.error(`Failed to resume the download task. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in resuming the download task.');
  });
  ```


## DownloadConfig
下载任务的配置信息。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| url | string | 是 | 资源地址。 |
| header | Object | 否 | 添加要包含在下载请求中的HTTPS标志头。<br/>开发者可以通过header的X-TLS-Version参数指定需要使用的TLS版本(如果不指定，则默认使用CURL_SSLVERSION_TLSv1_2版本，指定则使用指定版本。)<br/>CURL_SSLVERSION_TLSv1_0<br/>CURL_SSLVERSION_TLSv1_1<br/>CURL_SSLVERSION_TLSv1_2<br/>CURL_SSLVERSION_TLSv1_3<br/>通过header的X-Cipher-List参数指定需要使用的密码套件(如果不指定，则默认使用安全密码套件，指定则使用指定密码套件。)<br/>-1.2允许使用的密码套件白名单：<br/>TLS_DHE_RSA_WITH_AES_128_GCM_SHA256,TLS_DHE_RSA_WITH_AES_256_GCM_SHA384,<br/>TLS_DHE_DSS_WITH_AES_128_GCM_SHA256,TLS_DSS_RSA_WITH_AES_256_GCM_SHA384,<br/>TLS_PSK_WITH_AES_256_GCM_SHA384,TLS_DHE_PSK_WITH_AES_128_GCM_SHA256,<br/>TLS_DHE_PSK_WITH_AES_256_GCM_SHA384,TLS_DHE_PSK_WITH_CHACHA20_POLY1305_SHA256,<br/>TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256,TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384,<br/>TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256,TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384,<br/>TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256,TLS_ECDHE_PSK_WITH_CHACHA20_POLY1305_SHA256,<br/>TLS_ECDHE_PSK_WITH_AES_128_GCM_SHA256,TLS_ECDHE_PSK_WITH_AES_256_GCM_SHA384,<br/>TLS_ECDHE_PSK_WITH_AES_128_GCM_SHA256,TLS_DHE_RSA_WITH_AES_128_CCM,<br/>TLS_DHE_RSA_WITH_AES_256_CCM,TLS_DHE_RSA_WITH_CHACHA20_POLY1305_SHA256,<br/>TLS_PSK_WITH_AES_256_CCM,TLS_DHE_PSK_WITH_AES_128_CCM,<br/>TLS_DHE_PSK_WITH_AES_256_CCM,TLS_ECDHE_ECDSA_WITH_AES_128_CCM,<br/>TLS_ECDHE_ECDSA_WITH_AES_256_CCM,TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256<br/>-1.3允许使用的密码套件白名单：<br/>TLS_AES_128_GCM_SHA256,TLS_AES_256_GCM_SHA384,TLS_CHACHA20_POLY1305_SHA256,TLS_AES_128_CCM_SHA256<br/>-1.3新增国密算法套：<br/>TLS_SM4_GCM_SM3,TLS_SM4_CCM_SM3 |
| enableMetered | boolean | 否 | 设置是否允许在按流量计费的连接下下载(默认使用false)。Wi-Fi为非计费网络，数据流量为计费网络。<br/>-&nbsp;true：是<br/>-&nbsp;false：否 |
| enableRoaming | boolean | 否 | 设置是否允许在漫游网络中下载(默认使用false)。 <br/>-&nbsp;true：是<br/>-&nbsp;false：否|
| description | string | 否 | 设置下载会话的描述。 |
| filePath<sup>7+</sup> | string | 否 | 设置下载路径。<br/>-&nbsp;FA模型下使用[context](js-apis-inner-app-context.md#contextgetcachedir) 获取应用存储路径，比如：\`${featureAbility.getContext().getFilesDir()}/test.txt\`，并将文件存储在此路径下。<br/>-&nbsp;Stage模型下使用[AbilityContext](js-apis-inner-application-context.md) 类获取文件路径，比如：\`${globalThis.abilityContext.tempDir}/test.txt\`，并将文件存储在此路径下。|
| networkType | number | 否 | 设置允许下载的网络类型(默认使用NETWORK_MOBILE&NETWORK_WIFI)。<br/>-&nbsp;NETWORK_MOBILE：0x00000001<br/>-&nbsp;NETWORK_WIFI：0x00010000|
| title | string | 否 | 设置下载任务名称。 |
| background<sup>9+</sup> | boolean | 否 | 后台任务通知开关，开启后可在通知中显示下载状态(默认使用false)。 |


## DownloadInfo<sup>7+</sup>
下载任务信息，[getTaskInfo<sup>9+</sup>](#gettaskinfo9)接口的回调参数。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.MiscServices.Download

| 名称 | 类型 |必填 |  说明 |
| -------- | -------- | -------- | -------- |
| downloadId | number |是 | 下载任务ID。 |
| failedReason | number|是 | 下载失败原因，可以是任何[下载任务的错误码](#下载任务的错误码)常量。 |
| fileName | string |是| 下载的文件名。 |
| filePath | string |是| 存储文件的URI。 |
| pausedReason | number |是| 会话暂停的原因，可以是任何[下载任务暂停原因](#下载任务暂停原因)常量。 |
| status | number |是| 下载状态码，可以是任何[下载任务状态码](#下载任务状态码)常量。 |
| targetURI | string |是| 下载文件的URI。 |
| downloadTitle | string |是| 下载任务名称。 |
| downloadTotalBytes | number |是| 下载的文件的总大小（int&nbsp;bytes）。 |
| description | string |是| 待下载任务的描述信息。 |
| downloadedBytes | number |是| 实时下载大小（int&nbsp;&nbsp;bytes）。 |

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

## BroadcastEvent<sup>11+</sup>

定义自定义系统事件。用户可以使用公共事件接口获取该事件。
上传下载 SA 具有 'ohos.permission.SEND_TASK_COMPLETE_EVENT' 该权限，用户可以配置事件的 metadata 指向的二级配置文件来拦截其他事件发送者。

事件配置信息请参考[静态订阅公共事件](../../application-models/common-event-static-subscription.md)。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 值 | 说明        |
| -------- | ------- |-----------|
| COMPLETE | 'ohos.request.event.COMPLETE' | 表示任务完成事件。 |

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
| title | string | 否 | 任务标题，其最大长度为256个字符，默认值为空。 |
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
| mode | [Mode](#mode10) | 否 | 任务模式。<br/>-FOREGROUND表示前端任务。<br/>-BACKGROUND表示后台任务。 |

## TaskInfo<sup>10+</sup> 
查询结果的任务信息数据结构，提供普通查询和系统查询，两种字段的可见范围不同。

**系统能力**: SystemCapability.Request.FileTransferAgent

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uid | string | 否 | 应用程序的UID，仅用于系统查询。<br/>**系统接口**：此接口为系统接口。|
| bundle | string | 否 | 应用程序的包名，仅用于系统查询。<br/>**系统接口**：此接口为系统接口。|
| saveas | string | 否 | 保存下载文件的路径，包括如下两种：<br/>-相对路径，如"./xxx/yyy/zzz.html"、"xxx/yyy/zzz.html"，位于调用方的缓存路径下。<br/>-uri路径，如"datashare://bundle/xxx/yyy/zzz.html"，仅对具有访问url路径权限的应用开放。该功能暂不支持。<br/>默认为相对路径，即下载至应用当前缓存路径下。|
| url | string | 否 | 任务的url。<br/>- 通过[request.agent.show<sup>10+</sup>](#requestagentshow10-1)、[request.agent.touch<sup>10+</sup>](#requestagenttouch10-1)、[request.agent.query<sup>10+</sup>](#requestagentquery10-1)进行查询。其中，使用[request.agent.query<sup>10+</sup>](#requestagentquery10-1)进行查询时会返回空字符串。 |
| data | string \| Array&lt;[FormItem](#formitem10)&gt; | 否 | 任务值。<br/>- 通过[request.agent.show<sup>10+</sup>](#requestagentshow10-1)、[request.agent.touch<sup>10+</sup>](#requestagenttouch10-1)、[request.agent.query<sup>10+</sup>](#requestagentquery10-1)进行查询。其中，使用[request.agent.query<sup>10+</sup>](#requestagentquery10-1)进行查询时会返回空字符串。 |
| tid | string | 是 | 任务id。 |
| title | string | 是 | 任务标题。 |
| description | string | 是 | 任务描述。 |
| action | [Action](#action10) | 是 | 任务操作选项。<br/>-UPLOAD表示上传任务。<br/>-DOWNLOAD表示下载任务。 |
| mode | [Mode](#mode10) | 是 | 指定任务模式。<br/>-FOREGROUND表示前端任务。<br/>-BACKGROUND表示后台任务。 |
| mimeType | string | 是 | 任务配置中的mimetype。 |
| progress | [Progress](#progress10) | 是 | 任务的过程进度。 |
| gauge | boolean | 是 | 后台任务的进度通知策略。 |
| ctime | number | 是 | 创建任务的Unix时间戳（毫秒），由当前设备的系统生成。<br/>说明：使用[request.agent.search<sup>10+</sup>](#requestagentsearch10-1)进行查询时，该值需处于[after,before]区间内才可正常查询到任务id，before和after信息详见[Filter](#filter10)。
| mtime | number | 是 | 任务状态改变时的Unix时间戳（毫秒），由当前设备的系统生成。|
| retry | boolean | 是 | 任务的重试开关，仅应用于后台任务。 |
| tries | number | 是 | 任务的尝试次数。 |
| faults | [Faults](#faults10) | 是 | 任务的失败原因。<br/>-OTHERS表示其他故障。<br/>-DISCONNECT表示网络断开连接。<br/>-TIMEOUT表示任务超时。<br/>-PROTOCOL表示协议错误。<br/>-FSIO表示文件系统io错误。|
| reason | string | 是 | 等待/失败/停止/暂停任务的原因。|
| extras | string | 否 | 任务的额外部分。|


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

### on('pause')<sup>11+</sup>

on(event: 'pause', callback: (progress: Progress) =&gt; void): void

订阅任务暂停事件，异步方法，使用callback形式返回结果。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'pause'，表示任务暂停。 |
  | callback | function | 是 | 发生相关的事件时触发该回调方法，返回任务进度的数据结构。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

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
    console.info('upload task pause.');
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    task.on('pause', createOnCallback);
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

### on('resume')<sup>11+</sup>

on(event: 'resume', callback: (progress: Progress) =&gt; void): void

订阅任务恢复事件，异步方法，使用callback形式返回结果。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'resume'，表示任务恢复。 |
  | callback | function | 是 | 发生相关的事件时触发该回调方法，返回任务进度的数据结构。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

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
    console.info('upload task resume.');
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    task.on('resume', createOnCallback);
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

### on('remove')<sup>11+</sup>

on(event: 'remove', callback: (progress: Progress) =&gt; void): void

订阅任务删除事件，异步方法，使用callback形式返回结果。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'remove'，表示任务删除。 |
  | callback | function | 是 | 发生相关的事件时触发该回调方法，返回任务进度的数据结构。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

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
    console.info('upload task remove.');
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    task.on('remove', createOnCallback);
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

取消订阅前端任务进度事件，异步方法。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'progress'，表示任务进度。 |
  | callback | function | 否 | 发生相关的事件时触发该回调方法，返回任务进度的数据结构。 |

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

取消订阅前端任务完成事件，异步方法。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'completed'，表示任务完成。 |
  | callback | function | 否 | 发生相关的事件时触发该回调方法，返回任务进度的数据结构。 |

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

取消订阅前端任务失败事件，异步方法。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'failed'，表示任务失败。 |
  | callback | function | 否 | 发生相关的事件时触发该回调方法，返回任务进度的数据结构。 |

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

### off('pause')<sup>11+</sup>

off(event: 'pause', callback?: (progress: Progress) =&gt; void): void

取消订阅任务暂停事件，异步方法。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'pause'，表示任务暂停。 |
  | callback | function | 否 | 发生相关的事件时触发该回调方法，返回任务进度的数据结构。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

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
    console.info('upload task pause.');
  };
  let createOffCallback2 = (progress: request.agent.Progress) => {
    console.info('upload task pause.');
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    task.on('pause', createOffCallback1);
    task.on('pause', createOffCallback2);
    //表示取消createOffCallback1的订阅
    task.off('pause', createOffCallback1);
    //表示取消订阅任务暂停的所有回调
    task.off('pause');
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

### off('resume')<sup>11+</sup>

off(event: 'resume', callback?: (progress: Progress) =&gt; void): void

取消订阅任务恢复事件，异步方法。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'resume'，表示任务恢复。 |
  | callback | function | 否 | 发生相关的事件时触发该回调方法，返回任务进度的数据结构。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

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
    console.info('upload task resume.');
  };
  let createOffCallback2 = (progress: request.agent.Progress) => {
    console.info('upload task resume.');
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    task.on('resume', createOffCallback1);
    task.on('resume', createOffCallback2);
    //表示取消createOffCallback1的订阅
    task.off('resume', createOffCallback1);
    //表示取消订阅任务恢复的所有回调
    task.off('resume');
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

### off('remove')<sup>11+</sup>

off(event: 'remove', callback?: (progress: Progress) =&gt; void): void

取消订阅任务删除事件，异步方法。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'remove'，表示任务删除。 |
  | callback | function | 否 | 发生相关的事件时触发该回调方法，返回任务进度的数据结构。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

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
    console.info('upload task remove.');
  };
  let createOffCallback2 = (progress: request.agent.Progress) => {
    console.info('upload task remove.');
  };
  request.agent.create(getContext(), config).then((task: request.agent.Task) => {
    task.on('remove', createOffCallback1);
    task.on('remove', createOffCallback2);
    //表示取消createOffCallback1的订阅
    task.off('remove', createOffCallback1);
    //表示取消订阅任务移除的所有回调
    task.off('remove');
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

### pause<sup>10+</sup>

pause(callback: AsyncCallback&lt;void&gt;): void

暂停任务，可以暂停正在等待/正在运行/正在重试的后台任务。使用callback异步回调。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | function | 是 | 回调函数，暂停任务成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | task service ability error. |
  | 21900005 | task mode error. |
  | 21900007 | task state error. |

**示例：**

  ```ts
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1',
    title: 'taskPauseTest',
    description: 'Sample code for pause the download task',
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
    task.pause((err: BusinessError) => {
      if (err) {
        console.error(`Failed to pause the download task, Code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info(`Succeeded in pausing a download task. `);
    });
    console.info(`Succeeded in creating a download task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 在 api11 中 `21900005 task mode error` 这个错误码被移除。

### pause<sup>10+</sup>

pause(): Promise&lt;void&gt;

暂停任务，可以暂停正在等待/正在运行/正在重试的后台任务。使用Promise异步回调。

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
  | 21900005 | task mode error. |
  | 21900007 | task state error. |

**示例：**

  ```ts
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1',
    title: 'taskPauseTest',
    description: 'Sample code for pause the download task',
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
    task.pause().then(() => {
      console.info(`Succeeded in pausing a download task. `);
    }).catch((err: BusinessError) => {
      console.error(`Failed to pause the upload task, Code: ${err.code}, message: ${err.message}`);
    });
    console.info(`Succeeded in creating a download task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 在 api11 中 `21900005 task mode error` 这个错误码被移除。

### resume<sup>10+</sup>

resume(callback: AsyncCallback&lt;void&gt;): void

重新启动任务，可以恢复暂停的后台任务。使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | function | 是 | 回调函数，重新启动任务成功，err为undefined，否则为错误对象 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | task service ability error. |
  | 21900005 | task mode error. |
  | 21900007 | task state error. |

**示例：**

  ```ts
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1',
    title: 'taskResumeTest',
    description: 'Sample code for resume the download task',
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
    task.resume((err: BusinessError) => {
      if (err) {
        console.error(`Failed to resume the download task, Code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info(`Succeeded in resuming a download task. `);
    });
    console.info(`Succeeded in creating a download task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 在 api11 中 `21900005 task mode error` 这个错误码被移除。


### resume<sup>10+</sup>

resume(): Promise&lt;void&gt;

重新启动任务，可以恢复暂停的后台任务。使用Promise异步回调。

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
  | 21900005 | task mode error. |
  | 21900007 | task state error. |

**示例：**

  ```ts
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1',
    title: 'taskResumeTest',
    description: 'Sample code for resume the download task',
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
    task.resume().then(() => {
      console.info(`Succeeded in resuming a download task. `);
    }).catch((err: BusinessError) => {
      console.error(`Failed to resume the download task, Code: ${err.code}, message: ${err.message}`);
    });
    console.info(`Succeeded in creating a download task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

> **说明：**
>
> 在 api11 中 `21900005 task mode error` 这个错误码被移除。


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
  | config | [Config](#config10) | 是 | 上传/下载任务的配置信息。 |
  | context | [BaseContext](js-apis-inner-application-baseContext.md) | 是 | 基于应用程序的上下文。 |
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


## request.agent.show<sup>10+</sup>

show(id: string, callback: AsyncCallback&lt;TaskInfo&gt;): void

根据任务id查询任务的详细信息。使用callback异步回调。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | string | 是 | 任务id。 |
  | callback | AsyncCallback&lt;[TaskInfo](#taskinfo10)&gt; | 是 | 回调函数，返回任务详细信息。 |

**错误码：**
以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | task service ability error. |
  | 21900006 | task not found error. |

**示例：**

  ```ts
  request.agent.show("123456", (err: BusinessError, taskInfo: request.agent.TaskInfo) => {
    if (err) {
      console.error(`Failed to show a upload task, Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in showing a upload task.`);
  });
  ```


## request.agent.show<sup>10+</sup>

show(id: string): Promise&lt;TaskInfo&gt;

根据任务id查询任务的详细信息。使用Promise异步回调。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | string | 是 | 任务id。 |

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[TaskInfo](#taskinfo10)&gt; | Promise对象。返回任务详细信息的Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | task service ability error. |
  | 21900006 | task not found error. |

**示例：**

  ```ts
  request.agent.show("123456").then((taskInfo: request.agent.TaskInfo) => {
    console.info(`Succeeded in showing a upload task.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to show a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```


## request.agent.touch<sup>10+</sup>

touch(id: string, token: string, callback: AsyncCallback&lt;TaskInfo&gt;): void

根据任务id和token查询任务的详细信息。使用callback异步回调。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | string | 是 | 任务id。 |
  | token | string | 是 | 任务查询token。 |
  | callback | AsyncCallback&lt;[TaskInfo](#taskinfo10)&gt; | 是 | 回调函数，返回任务详细信息。 |

**错误码：**
以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | task service ability error. |
  | 21900006 | task not found error. |

**示例：**

  ```ts
  request.agent.touch("123456", "token", (err: BusinessError, taskInfo: request.agent.TaskInfo) => {
    if (err) {
      console.error(`Failed to touch a upload task, Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in touching a upload task.`);
  });
  ```


## request.agent.touch<sup>10+</sup>

touch(id: string, token: string): Promise&lt;TaskInfo&gt;

根据任务id和token查询任务的详细信息。使用Promise异步回调。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | string | 是 | 任务id。 |
  | token | string | 是 | 任务查询token。 |

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[TaskInfo](#taskinfo10)&gt; | Promise对象。返回任务详细信息的Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | task service ability error. |
  | 21900006 | task not found error. |

**示例：**

  ```ts
  request.agent.touch("123456", "token").then((taskInfo: request.agent.TaskInfo) => {
    console.info(`Succeeded in touching a upload task. `);
  }).catch((err: BusinessError) => {
    console.error(`Failed to touch a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

## request.agent.search<sup>10+</sup>

search(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

根据默认[Filter](#filter10)过滤条件查找任务id。使用callback异步回调。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是 | 回调函数，返回满足条件任务id。 |

**错误码：**
以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | task service ability error. |

**示例：**

  ```ts
  request.agent.search((err: BusinessError, data: Array<string>) => {
    if (err) {
      console.error(`Failed to search a upload task, Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in searching a upload task. `);
  });
  ```

## request.agent.search<sup>10+</sup>

search(filter: Filter, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

根据[Filter](#filter10)过滤条件查找任务id。使用callback异步回调。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | filter | [Filter](#filter10) | 是 | 过滤条件。 |
  | callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是 | 回调函数，返回满足条件任务id。 |

**错误码：**
以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | task service ability error. |

**示例：**

  ```ts
  let filter: request.agent.Filter = {
    bundle: "com.example.myapplication",
    action: request.agent.Action.UPLOAD,
    mode: request.agent.Mode.BACKGROUND
  }
  request.agent.search(filter, (err: BusinessError, data: Array<string>) => {
    if (err) {
      console.error(`Failed to search a upload task, Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in searching a upload task. `);
  });
  ```


## request.agent.search<sup>10+</sup>

search(filter?: Filter): Promise&lt;Array&lt;string&gt;&gt;

根据[Filter](#filter10)过滤条件查找任务id。使用Promise异步回调。

**系统能力**: SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | filter | [Filter](#filter10) | 否 | 过滤条件。 |

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象。返回满足条件任务id的Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | task service ability error. |

**示例：**

  ```ts
  let filter: request.agent.Filter = {
    bundle: "com.example.myapplication",
    action: request.agent.Action.UPLOAD,
    mode: request.agent.Mode.BACKGROUND
  }
  request.agent.search(filter).then((data: Array<string>) => {
    console.info(`Succeeded in searching a upload task. `);
  }).catch((err: BusinessError) => {
    console.error(`Failed to search a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```


## request.agent.query<sup>10+</sup>

query(id: string, callback: AsyncCallback&lt;TaskInfo&gt;): void

根据任务id查询任务的详细信息。使用callback异步回调。

**需要权限**：ohos.permission.DOWNLOAD_SESSION_MANAGER 或 ohos.permission.UPLOAD_SESSION_MANAGER

**系统能力**: SystemCapability.Request.FileTransferAgent

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | string | 是 | 任务id。 |
  | callback | AsyncCallback&lt;[TaskInfo](#taskinfo10)&gt; | 是 | 回调函数，返回任务详细信息。 |

**错误码：**
以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

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

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[TaskInfo](#taskinfo10)&gt; | Promise对象。返回任务详细信息的Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[上传下载错误码](../errorcodes/errorcode-request.md)。

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