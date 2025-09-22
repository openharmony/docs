# @ohos.request (上传下载)
<!--Kit: Basic Services Kit-->
<!--Subsystem: Request-->
<!--Owner: @huaxin05-->
<!--Designer: @hu-kai45-->
<!--Tester: @murphy1984-->
<!--Adviser: @zhang_yixin13-->

request模块给应用提供上传下载文件、后台代理传输的基础功能。

- request暂不支持在Extension中调用。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```js
import { request } from '@kit.BasicServicesKit';
```

## 常量

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> **网络类型**：下载支持自定义网络类型，可以在[DownloadConfig](#downloadconfig)中通过networkType配置成以下网络类型。<br/>
>
> **下载任务错误码**：下载[on('fail')](#onfail7)事件callback的错误参数、[getTaskInfo](#gettaskinfo9)返回值的failedReason字段取值。<br/>
>
> **下载任务暂停原因**：下载相关[getTaskInfo](#gettaskinfo9)返回值的pausedReason字段取值。<br/>
>
> **下载任务状态码**：下载相关[getTaskInfo](#gettaskinfo9)返回值的status字段取值。

| 名称 | 参数类型 | 数值 | 说明 |
| -------- | -------- | -------- | -------- |
| EXCEPTION_PERMISSION<sup>9+</sup> | number |   201   | 通用错误码：权限校验失败。 |
| EXCEPTION_PARAMCHECK<sup>9+</sup> | number |   401   | 通用错误码：参数检查失败。 |
| EXCEPTION_UNSUPPORTED<sup>9+</sup> | number |   801   | 通用错误码：该设备不支持此API。 |
| EXCEPTION_FILEIO<sup>9+</sup> | number |   13400001   | 特有错误码：文件操作异常。 |
| EXCEPTION_FILEPATH<sup>9+</sup> | number |   13400002   | 特有错误码：文件路径异常。 |
| EXCEPTION_SERVICE<sup>9+</sup> | number |   13400003   | 特有错误码：服务异常。 |
| EXCEPTION_OTHERS<sup>9+</sup> | number |   13499999   | 特有错误码：其他错误。 |
| NETWORK_MOBILE<sup>6+</sup> | number | 0x00000001 | 网络类型：使用蜂窝网络时允许下载的位标志。 |
| NETWORK_WIFI<sup>6+</sup> | number | 0x00010000 | 网络类型：使用WLAN时允许下载的位标志。 |
| ERROR_CANNOT_RESUME<sup>7+</sup> | number |   0   | 下载任务错误码：网络原因导致恢复下载失败。 |
| ERROR_DEVICE_NOT_FOUND<sup>7+</sup> | number |   1   | 下载任务错误码：找不到SD卡等存储设备。 |
| ERROR_FILE_ALREADY_EXISTS<sup>7+</sup> | number |   2   | 下载任务错误码：要下载的文件已存在，下载会话无法覆盖现有文件。 |
| ERROR_FILE_ERROR<sup>7+</sup> | number |   3   | 下载任务错误码：文件操作失败。 |
| ERROR_HTTP_DATA_ERROR<sup>7+</sup> | number |   4   | 下载任务错误码：HTTP传输失败。 |
| ERROR_INSUFFICIENT_SPACE<sup>7+</sup> | number |   5   | 下载任务错误码：存储空间不足。 |
| ERROR_TOO_MANY_REDIRECTS<sup>7+</sup> | number |   6   | 下载任务错误码：网络重定向过多导致的错误。 |
| ERROR_UNHANDLED_HTTP_CODE<sup>7+</sup> | number |   7   | 下载任务错误码：无法识别的HTTP代码。 |
| ERROR_UNKNOWN<sup>7+</sup> | number |   8   | 下载任务错误码：未知错误。<br/>例如：API version 12及以下版本，系统仅支持串行地尝试连接域名相关IP，不支持单个IP的连接时间控制。若DNS返回的首个IP被阻塞，可能会由于握手超时导致ERROR_UNKNOWN错误。 |
| ERROR_OFFLINE<sup>9+</sup> | number |   9   | 下载任务错误码：网络未连接。 |
| ERROR_UNSUPPORTED_NETWORK_TYPE<sup>9+</sup> | number |   10   | 下载任务错误码：网络类型不匹配。 |
| PAUSED_QUEUED_FOR_WIFI<sup>7+</sup> | number |   0   | 下载任务暂停原因：文件大小超过了使用蜂窝网络会话允许的最大值，下载被暂停并等待WLAN连接。 |
| PAUSED_WAITING_FOR_NETWORK<sup>7+</sup> | number |   1   | 下载任务暂停原因：网络问题导致下载暂停。<br/>例如：网络断开。 |
| PAUSED_WAITING_TO_RETRY<sup>7+</sup> | number |   2   | 下载任务暂停原因：网络错误导致下载会话将被重试。 |
| PAUSED_BY_USER<sup>9+</sup> | number |   3   | 下载任务暂停原因：用户暂停会话。 |
| PAUSED_UNKNOWN<sup>7+</sup> | number |   4   | 下载任务暂停原因：未知原因导致暂停下载。 |
| SESSION_SUCCESSFUL<sup>7+</sup> | number |   0   | 下载任务状态码：下载会话已完成。 |
| SESSION_RUNNING<sup>7+</sup> | number |   1   | 下载任务状态码：下载会话正在进行中。 |
| SESSION_PENDING<sup>7+</sup> | number |   2   | 下载任务状态码：下载会话正在被调度中。 |
| SESSION_PAUSED<sup>7+</sup> | number |   3   | 下载任务状态码：下载会话已暂停。 |
| SESSION_FAILED<sup>7+</sup> | number |   4   | 下载任务状态码：下载会话已失败，将不会重试。 |


## request.uploadFile<sup>9+</sup>

uploadFile(context: BaseContext, config: UploadConfig): Promise&lt;UploadTask&gt;

创建并启动一个上传任务，使用Promise异步回调，支持HTTP协议。通过[on('complete'|'fail')](#oncomplete--fail9)可获取任务上传时的成功信息或错误信息。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Upload

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是 | 基于应用程序的上下文。 |
  | config | [UploadConfig](#uploadconfig6) | 是 | 上传的配置信息。 |


**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[UploadTask](#uploadtask)&gt; | 使用Promise方式，异步返回上传任务UploadTask的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |
  | 401 | The parameters check fails. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |
  | 13400002 | File path not supported or invalid. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';
  
  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let uploadTask: request.UploadTask;
  let uploadConfig: request.UploadConfig = {
    url: 'http://www.example.com', // 需要手动将url替换为真实服务器的HTTP协议地址
    header: { 'Accept': '*/*' },
    method: "POST",
    files: [{ filename: "test", name: "test", uri: "internal://cache/test.jpg", type: "image/jpeg" }], // 建议type填写HTTP协议规范的MIME类型
    data: [{ name: "name123", value: "123" }],
  };
  try {
    request.uploadFile(context, uploadConfig).then((data: request.UploadTask) => {
      uploadTask = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the upload. Code: ${err.code}, message: ${err.message}`);
    });
  } catch (err) {
    console.error(`Failed to request the upload. err: ${JSON.stringify(err)}`);
  }
  ```


## request.uploadFile<sup>9+</sup>

uploadFile(context: BaseContext, config: UploadConfig, callback: AsyncCallback&lt;UploadTask&gt;): void

创建并启动一个上传任务，使用callback异步回调，支持HTTP协议。通过[on('complete'|'fail')](#oncomplete--fail9)可获取任务上传时的成功信息或错误信息。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Upload

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是 | 基于应用程序的上下文。 |
  | config | [UploadConfig](#uploadconfig6) | 是 | 上传的配置信息。 |
  | callback | AsyncCallback&lt;[UploadTask](#uploadtask)&gt; | 是 | 回调函数，异步返回UploadTask对象。当上传成功，err为undefined，data为获取到的UploadTask对象；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |
  | 401 | The parameters check fails. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |
  | 13400002 | File path not supported or invalid. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let uploadTask: request.UploadTask;
  let uploadConfig: request.UploadConfig = {
    url: 'http://www.example.com', // 需要手动将url替换为真实服务器的HTTP协议地址
    header: { 'Accept': '*/*' },
    method: "POST",
    files: [{ filename: "test", name: "test", uri: "internal://cache/test.jpg", type: "image/jpeg" }], // 建议type填写HTTP协议规范的MIME类型
    data: [{ name: "name123", value: "123" }],
  };
  try {
    request.uploadFile(context, uploadConfig, (err: BusinessError, data: request.UploadTask) => {
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

## request.upload<sup>(deprecated)</sup>

upload(config: UploadConfig): Promise&lt;UploadTask&gt;

创建并启动一个上传任务，使用Promise异步回调。

**模型约束**：此接口仅可在FA模型下使用。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Upload

> **说明：**
>
> 从API version 6 开始支持，从API version 9 开始废弃，建议使用[request.uploadFile](#requestuploadfile9)替代。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | config | [UploadConfig](#uploadconfig6) | 是 | 上传的配置信息。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[UploadTask](#uploadtask)&gt; | 使用Promise方式，异步返回上传任务UploadTask的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**

  ```js
  let uploadTask: request.UploadTask;
  let uploadConfig: request.UploadConfig = {
    url: 'http://www.example.com', // 需要手动将url替换为真实服务器的HTTP协议地址
    header: { 'Accept': '*/*' },
    method: "POST",
    files: [{ filename: "test", name: "test", uri: "internal://cache/test.jpg", type: "image/jpeg" }], // 建议type填写HTTP协议规范的MIME类型
    data: [{ name: "name123", value: "123" }],
  };
  request.upload(uploadConfig).then((data: request.UploadTask) => {
    uploadTask = data;
  }).catch((err: BusinessError) => {
    console.error(`Failed to request the upload. Code: ${err.code}, message: ${err.message}`);
  })
  ```


## request.upload<sup>(deprecated)</sup>

upload(config: UploadConfig, callback: AsyncCallback&lt;UploadTask&gt;): void

创建并启动一个上传任务，使用callback异步回调。

**模型约束**：此接口仅可在FA模型下使用。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Upload

> **说明：**
>
> 从API version 6 开始支持，从API version 9 开始废弃，建议使用[request.uploadFile](#requestuploadfile9)替代。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | config | [UploadConfig](#uploadconfig6) | 是 | 上传的配置信息。 |
  | callback | AsyncCallback&lt;[UploadTask](#uploadtask)&gt; | 是 | 回调函数，异步返回UploadTask对象。当上传成功，err为undefined，data为获取到的UploadTask对象；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**

  ```js
  let uploadTask: request.UploadTask;
  let uploadConfig: request.UploadConfig = {
    url: 'http://www.example.com', // 需要手动将url替换为真实服务器的HTTP协议地址
    header: { 'Accept': '*/*' },
    method: "POST",
    files: [{ filename: "test", name: "test", uri: "internal://cache/test.jpg", type: "image/jpeg" }], // 建议type填写HTTP协议规范的MIME类型
    data: [{ name: "name123", value: "123" }],
  };
  request.upload(uploadConfig, (err: BusinessError, data: request.UploadTask) => {
    if (err) {
      console.error(`Failed to request the upload. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    uploadTask = data;
  });
  ```

## UploadTask

上传任务，使用下列方法前，需要先获取UploadTask对象，promise形式通过[request.uploadFile](#requestuploadfile9)获取，callback形式通过[request.uploadFile](#requestuploadfile9-1)获取。



### on('progress')

on(type: 'progress', callback: (uploadedSize: number, totalSize: number) =&gt; void): void

订阅上传任务进度事件，使用callback异步回调。

**系统能力**：SystemCapability.MiscServices.Upload

> **说明：**
>
> 应用处于后台时，为满足功耗性能要求，不支持调用此接口进行回调。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 订阅的事件类型。取值为'progress'，表示上传的进度信息，任务进度有进展时触发该事件。 |
| callback | function | 是 | 上传任务进度的回调函数，返回已上传文件大小和上传文件总大小。 |

  回调函数的参数：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uploadedSize | number | 是 | 当前已上传文件大小，单位为字节（B）。 |
| totalSize | number | 是 | 上传文件的总大小，单位为字节（B）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | The parameters check fails. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**

<!--code_no_check-->
  ```ts
  let upProgressCallback = (uploadedSize: number, totalSize: number) => {
    console.info("upload totalSize:" + totalSize + "  uploadedSize:" + uploadedSize);
  };
  uploadTask.on('progress', upProgressCallback);
  ```


### on('headerReceive')<sup>7+</sup>

on(type: 'headerReceive', callback:  (header: object) =&gt; void): void

订阅上传任务HTTP响应事件，使用callback异步回调。

**系统能力**：SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 订阅的事件类型。<br>- 取值为'headerReceive'，HTTP请求接收到响应时触发该事件。 |
  | callback | function | 是 | HTTP&nbsp;Response事件的回调函数，返回响应请求内容。 |

  回调函数的参数：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| header | object | 是 | HTTP响应。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | The parameters check fails. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**

<!--code_no_check-->
  ```ts
  let headerCallback = (headers: object) => {
    console.info("upOnHeader headers:" + JSON.stringify(headers));
  };
  uploadTask.on('headerReceive', headerCallback);
  ```


### on('complete' | 'fail')<sup>9+</sup>

 on(type: 'complete' | 'fail', callback: Callback&lt;Array&lt;TaskState&gt;&gt;): void

订阅上传任务完成或失败事件，使用callback异步回调。

**系统能力**：SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 订阅的事件类型，支持的事件包括：`'complete'`\|`'fail'`。<br/>\- `'complete'`：表示上传任务完成，任务完成时触发该事件。 <br/>\- `'fail'`：表示上传任务失败，任务失败时触发该事件。 
  | callback | Callback&lt;Array&lt;[TaskState](#taskstate9)&gt;&gt; | 是 | 上传任务完成或失败的回调函数。返回上传任务的任务状态信息。 |


**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | The parameters check fails. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**

<!--code_no_check-->
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

取消订阅上传任务进度事件。

**系统能力**：SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消订阅的事件类型。<br>- 取值为'progress'，表示上传的进度信息。 |
  | callback | function | 否 | 需要取消订阅的回调函数。若无此参数，则取消订阅当前类型的所有回调函数。 |

回调函数的参数

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uploadedSize | number | 是 | 当前已上传文件大小，单位为字节（B）。 |
| totalSize | number | 是 | 上传文件的总大小，单位为字节（B）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | The parameters check fails. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**

<!--code_no_check-->
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

取消订阅上传任务HTTP响应事件。

**系统能力**：SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消订阅的事件类型。<br>- 取值为'headerReceive'，表示HTTP请求接收到响应。 |
  | callback | function | 否 | 需要取消订阅的回调函数。若无此参数，则取消订阅当前类型的所有回调函数。 |

  回调函数的参数：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| header | object | 是 | HTTP响应。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | The parameters check fails. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**

<!--code_no_check-->
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

 off(type: 'complete' | 'fail', callback?: Callback&lt;Array&lt;TaskState&gt;&gt;): void

取消订阅上传任务的完成或失败事件。

**系统能力**：SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消订阅的事件类型。<br>- 取值为'complete'，表示上传任务完成。<br>- 取值为'fail'，表示上传任务失败。|
  | callback | Callback&lt;Array&lt;[TaskState](#taskstate9)&gt;&gt; | 否 | 需要取消订阅的回调函数。若无此参数，则取消订阅当前类型的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | The parameters check fails. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**

<!--code_no_check-->
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

移除上传的任务，使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Upload

> **说明：**
>
> 由于不存在401报错场景，在api12中 `401 the parameters check fails` 这个错误码被移除。

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise对象。返回true表示移除上传任务成功；返回false表示移除上传任务失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**

<!--code_no_check-->
  ```ts
  uploadTask.delete().then((result: boolean) => {
    console.info('Succeeded in deleting the upload task.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to delete the upload task. Code: ${err.code}, message: ${err.message}`);
  });
  ```


### delete<sup>9+</sup>

delete(callback: AsyncCallback&lt;boolean&gt;): void

移除上传的任务，使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Upload

> **说明：**
>
> 由于不存在401报错场景，在api12中 `401 the parameters check fails` 这个错误码被移除。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回true表示移除上传任务成功；返回false表示移除上传任务失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**

<!--code_no_check-->
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

移除上传的任务，使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Upload

> **说明：**
>
> 从API Version 9开始不再维护，建议使用[delete](#delete9)替代。

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 使用Promise方式异步回调，返回true表示移除上传任务成功；返回false表示移除上传任务失败。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**

  ```js
  uploadTask.remove().then((result: boolean) => {
    console.info('Succeeded in removing the upload task.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to remove the upload task. Code: ${err.code}, message: ${err.message}`);
  });
  ```


### remove<sup>(deprecated)</sup>

remove(callback: AsyncCallback&lt;boolean&gt;): void

移除上传的任务，使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Upload

> **说明：**
>
> 从API Version 9开始不再维护，建议使用[delete](#delete9-1)替代。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回true表示移除上传任务成功；返回false表示移除上传任务失败。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**

  ```js
  uploadTask.remove((err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to remove the upload task. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    if (result) {
      console.info('Succeeded in removing the upload task.');
    }
  });
  ```

## UploadConfig<sup>6+</sup>
上传任务的配置信息。

**系统能力**：SystemCapability.MiscServices.Upload

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| url | string | 否 | 否 | 资源地址。从API 6到API 14，最大长度为2048个字符；从API 15开始，最大长度为8192个字符。支持[HTTP拦截](../../basic-services/request/app-file-upload-download.md#http拦截)功能。 |
| header | Object | 否 | 否 | 添加要包含在上传请求中的HTTP或HTTPS标志头。 |
| method | string | 否 | 否 |  HTTP请求方法：POST、PUT，缺省为POST。使用POST新增资源，使用PUT修改资源。 |
| index<sup>11+</sup> | number | 否 | 是 | 任务的路径索引，默认值为0。 |
| begins<sup>11+</sup> | number | 否 | 是 | 上传任务开始时读取的文件起点。默认值为0，取值范围为闭区间，表示从头开始传输。|
| ends<sup>11+</sup> | number | 否 | 是 | 上传任务结束时读取的文件终点。默认值为-1，取值范围为闭区间，表示传输到整个文件末尾结束。 |
| files | Array&lt;[File](#file)&gt; | 否 | 否 | 要上传的文件列表。文件以HTTP的multipart/form-data格式提交。 |
| data | Array&lt;[RequestData](#requestdata)&gt; | 否 | 否 | 请求的表单数据。 |

## TaskState<sup>9+</sup>
上传任务的任务信息，是[on('complete' | 'fail')](#oncomplete--fail9)和[off('complete' | 'fail')](#offcomplete--fail9)接口的回调参数。

**系统能力**：SystemCapability.MiscServices.Upload

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| path | string | 否 | 否 | 文件路径。                                         |
| responseCode | number | 否 | 否 | 上传任务返回码。返回0表示上传任务成功，返回其它值表示上传任务失败，具体请参见message参数中的上传任务结果描述信息。<br/>此处推荐使用[request.agent.create](#requestagentcreate10-1)创建上传任务，并获取标准错误码处理异常分支。 |
| message | string | 否 | 否 | 上传任务结果描述信息。                           |

其中，responseCode包含的返回码值如下。

| 返回码 | 具体信息                               |
|-----|------------------------------------|
| 0   | 上传成功。                               |
| 5   | 任务被主动暂停或被动停止。                         |
| 6   | 任务所属应用被切换到后台或终止，导致前台任务被停止，请检查应用状态。  |
| 7   | 无网络，请检查设备是否处于联网状态。                  |
| 8   | 网络类型不匹配，请检查当前网络类型和任务所需网络类型是否匹配。     |
| 10  | 创建HTTP请求失败，请检查参数是否正确或重试任务。          |
| 12  | 超时，请检查参数是否正确、检查网络状况是否允许，或重试任务。          |
| 13  | 连接失败，请检查参数是否正确、检查网络状况是否允许，或重试任务。        |
| 14  | 请求失败，请检查参数是否正确、检查网络状况是否允许，或重试任务。        |
| 15  | 上传失败，请检查参数是否正确、检查网络状况是否允许，或重试任务。        |
| 16  | 重定向失败，请检查参数是否正确、检查网络状况是否允许，或重试任务。       |
| 17  | 协议错误，服务器返回 4XX 或 5XX 状态码，请检查参数是否正确。 |
| 20  | 其他错误，请检查参数是否正确、检查网络状况是否允许，或重试任务。        |

## File
[UploadConfig](#uploadconfig6)中的文件列表。

**系统能力**：SystemCapability.MiscServices.Download

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| filename | string | 否 | 否 | multipart提交时，请求头中的文件名。 |
| name | string | 否 | 否 | multipart提交时，表单项目的名称，缺省为file。 |
| uri | string | 否 | 否 | 文件的本地存储路径。<br/>仅支持"internal://cache/"，即调用方（传入的context）对应的缓存路径context.cacheDir。<br/>示例：internal://cache/path/to/file.txt |
| type | string | 否 | 否 | 文件的内容类型，默认根据文件名或路径的后缀获取。 |


## RequestData
[UploadConfig](#uploadconfig6)中的表单数据。

**系统能力**：SystemCapability.MiscServices.Download

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| name | string | 否 | 否 | 表示表单元素的名称。 |
| value | string | 否 | 否 | 表示表单元素的值。 |

## request.downloadFile<sup>9+</sup>

downloadFile(context: BaseContext, config: DownloadConfig): Promise&lt;DownloadTask&gt;

创建并启动一个下载任务，使用Promise异步回调，支持HTTP协议。通过[on('complete'|'pause'|'remove')](#oncompletepauseremove7)可以获取任务下载时的状态信息，包括任务完成、暂停或移除。通过[on('fail')](#onfail7)可以获取任务下载时的错误信息。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是 | 基于应用程序的上下文。 |
  | config | [DownloadConfig](#downloadconfig) | 是 | 下载的配置信息。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[DownloadTask](#downloadtask)&gt; | 使用Promise方式，异步返回下载任务DownloadTask的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |
  | 401 | The parameters check fails. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |
  | 13400001 | Invalid file or file system error. |
  | 13400002 | File path not supported or invalid. |
  | 13400003 | Task service ability error. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
       let downloadTask: request.DownloadTask = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```


## request.downloadFile<sup>9+</sup>

downloadFile(context: BaseContext, config: DownloadConfig, callback: AsyncCallback&lt;DownloadTask&gt;): void

创建并启动一个下载任务，使用callback异步回调，支持HTTP协议。通过[on('complete'|'pause'|'remove')](#oncompletepauseremove7)可获取任务下载时的状态信息，包括任务完成、暂停或移除。通过[on('fail')](#onfail7)可获取任务下载时的错误信息。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是 | 基于应用程序的上下文。 |
  | config | [DownloadConfig](#downloadconfig) | 是 | 下载的配置信息。 |
  | callback | AsyncCallback&lt;[DownloadTask](#downloadtask)&gt; | 是 | 回调函数。当下载任务成功，err为undefined，data为获取到的DownloadTask对象；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |
  | 401 | The parameters check fails. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |
  | 13400001 | Invalid file or file system error. |
  | 13400002 | File path not supported or invalid. |
  | 13400003 | Task service ability error. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, {
      url: 'https://xxxx/xxxxx.hap',
      filePath: 'xxx/xxxxx.hap'
    }, (err: BusinessError, data: request.DownloadTask) => {
      if (err) {
        console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
        return;
      }
    });
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```

## request.download<sup>(deprecated)</sup>

download(config: DownloadConfig): Promise&lt;DownloadTask&gt;

创建并启动一个下载任务，使用Promise异步回调。

**模型约束**：此接口仅可在FA模型下使用。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 从API version 6 开始支持，从API version 9 开始废弃，建议使用[request.downloadFile](#requestdownloadfile9)替代。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | config | [DownloadConfig](#downloadconfig) | 是 | 下载的配置信息。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[DownloadTask](#downloadtask)&gt; | 使用Promise方式，异步返回下载任务DownloadTask的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**

  ```js
  let downloadTask: request.DownloadTask;
  // 需要手动将url替换为真实服务器的HTTP协议地址
  request.download({ url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
    downloadTask = data;
  }).catch((err: BusinessError) => {
    console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
  })
  ```


## request.download<sup>(deprecated)</sup>

download(config: DownloadConfig, callback: AsyncCallback&lt;DownloadTask&gt;): void

创建并启动一个下载任务，使用callback异步回调。

**模型约束**：此接口仅可在FA模型下使用。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 从API version 6 开始支持，从API version 9 开始废弃，建议使用[request.downloadFile](#requestdownloadfile9-1)替代。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | config | [DownloadConfig](#downloadconfig) | 是 | 下载的配置信息。 |
  | callback | AsyncCallback&lt;[DownloadTask](#downloadtask)&gt; | 是 | 回调函数。当下载任务成功，err为undefined，data为获取到的DownloadTask对象；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
  | -------- | -------- |
| 201 | The permissions check fails. |

**示例：**

  ```js
  let downloadTask: request.DownloadTask;
  // 需要手动将url替换为真实服务器的HTTP协议地址
  request.download({ url: 'https://xxxx/xxxxx.hap', 
  filePath: 'xxx/xxxxx.hap'}, (err: BusinessError, data: request.DownloadTask) => {
    if (err) {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    downloadTask = data;
  });
  ```

## DownloadTask

下载任务，使用下列方法前，需要先获取DownloadTask对象，promise形式通过[request.downloadFile](#requestdownloadfile9)获取，callback形式通过[request.downloadFile](#requestdownloadfile9-1)获取。


### on('progress')

on(type: 'progress', callback: (receivedSize: number, totalSize: number) =&gt; void): void

订阅下载任务进度事件，使用callback异步回调。

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 应用处于后台时，为满足功耗性能要求，不支持调用此接口进行回调。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 订阅的事件类型。<br>- 取值为'progress'，表示下载的进度信息，当任务进度有进展时触发该事件。 |
  | callback | function | 是 | 下载任务进度的回调函数，返回已上传文件大小和上传文件大小总和。 |

  回调函数的参数：

| 参数名 | 类型 | 必填 | 说明                                                                      |
| -------- | -------- | -------- |----------------------------------|
| receivedSize | number | 是 | 当前下载的进度，单位为字节（B）。                |
| totalSize | number | 是 | 下载文件的总大小，单位为字节（B）。在下载过程中，若服务器使用chunk方式传输导致无法从请求头中获取文件总大小时，totalSize为 -1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | The parameters check fails. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      let downloadTask: request.DownloadTask = data;
      let progressCallback = (receivedSize: number, totalSize: number) => {
        console.info("download receivedSize:" + receivedSize + " totalSize:" + totalSize);
      };
      downloadTask.on('progress', progressCallback);
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```


### off('progress')

off(type: 'progress', callback?: (receivedSize: number, totalSize: number) =&gt; void): void

取消订阅下载任务进度事件。

**系统能力**：SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消订阅的事件类型。<br>- 取值为'progress'，表示下载的进度信息。 |
  | callback | function | 否 | 需要取消订阅的回调函数。若无此参数，则取消订阅当前类型的所有回调函数。 |
  
  回调函数的参数：

| 参数名 | 类型 | 必填 | 说明                                                                      |
| -------- | -------- | -------- |------------------------------------|
| receivedSize | number | 是 | 当前下载的进度，单位为字节（B）。           |
| totalSize | number | 是 | 下载文件的总大小，单位为字节（B）。在下载过程中，若服务器使用chunk方式传输导致无法从请求头中获取文件总大小时，totalSize为 -1。 |


**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | The parameters check fails. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      let downloadTask: request.DownloadTask = data;
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
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```


### on('complete'|'pause'|'remove')<sup>7+</sup>

on(type: 'complete'|'pause'|'remove', callback: () =&gt; void): void

订阅下载任务相关的事件，使用callback异步回调。

**系统能力**：SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 订阅的事件类型。<br>- 取值为'complete'，表示下载任务完成，任务完成时触发该事件。<br/>- 取值为'pause'，表示下载任务暂停，任务暂停时触发该事件。<br/>- 取值为'remove'，表示下载任务移除，任务移除时触发该事件。 |
  | callback | function | 是 | 下载任务相关的回调函数。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | The parameters check fails. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      let downloadTask: request.DownloadTask = data;
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
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```


### off('complete'|'pause'|'remove')<sup>7+</sup>

off(type: 'complete'|'pause'|'remove', callback?: () =&gt; void): void

取消订阅下载任务相关的事件。

**系统能力**：SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消订阅的事件类型。<br/>- 取值为'complete'，表示下载任务完成。<br/>- 取值为'pause'，表示下载任务暂停。<br/>- 取值为'remove'，表示下载任务移除。 |
  | callback | function | 否 | 需要取消订阅的回调函数。若无此参数，则取消订阅当前类型的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | The parameters check fails. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      let downloadTask: request.DownloadTask = data;
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
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }  
  ```


### on('fail')<sup>7+</sup>

on(type: 'fail', callback: (err: number) =&gt; void): void

订阅下载任务失败事件，使用callback异步回调。

**系统能力**：SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 订阅的事件类型。<br>- 取值为'fail'，表示下载失败，任务失败时触发该事件。 |
  | callback | function | 是 | 下载失败的回调函数。 |

  回调函数的参数：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| err | number | 是 | 下载失败的错误码，错误原因见[下载任务的错误码](#常量)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | The parameters check fails. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      let downloadTask: request.DownloadTask = data;
      let failCallback = (err: number) => {
        console.error(`Failed to download the task. Code: ${err}`);
      };
      downloadTask.on('fail', failCallback);
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```


### off('fail')<sup>7+</sup>

off(type: 'fail', callback?: (err: number) =&gt; void): void

取消订阅下载任务失败事件。

**系统能力**：SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消订阅的事件类型。<br>- 取值为'fail'，表示下载失败。 |
  | callback | function | 否 | 需要取消订阅的回调函数。若无此参数，则取消订阅当前类型的所有回调函数。 |

  回调函数的参数：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| err | number | 是 | 下载失败的错误码，错误原因见[下载任务的错误码](#常量)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | The parameters check fails. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      let downloadTask: request.DownloadTask = data;
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
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```

### delete<sup>9+</sup>

delete(): Promise&lt;boolean&gt;

移除下载的任务，使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download
  
> **说明：**
>
> 由于不存在401报错场景，在api12中 `401 the parameters check fails` 这个错误码被移除。

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise对象。返回true表示移除下载任务成功；返回false表示移除下载任务失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      data.delete().then((result: boolean) => {
        console.info('Succeeded in removing the download task.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to remove the download task. Code: ${err.code}, message: ${err.message}`);
      });
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```

### delete<sup>9+</sup>

delete(callback: AsyncCallback&lt;boolean&gt;): void

移除下载的任务，使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 由于不存在401报错场景，在api12中 `401 the parameters check fails` 这个错误码被移除。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回true表示移除下载任务成功；返回false表示移除下载任务失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |


**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      let downloadTask: request.DownloadTask = data;
      downloadTask.delete((err: BusinessError, result: boolean) => {
        if (err) {
          console.error(`Failed to remove the download task. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in removing the download task.');
      });
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```

### getTaskInfo<sup>9+</sup>

getTaskInfo(): Promise&lt;DownloadInfo&gt;

查询下载任务的信息，使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 由于不存在401报错场景，在api12中 `401 the parameters check fails` 这个错误码被移除。

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[DownloadInfo](#downloadinfo7)&gt; |  Promise对象，返回DownloadInfo对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |


**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      let downloadTask: request.DownloadTask = data;
      downloadTask.getTaskInfo().then((downloadInfo: request.DownloadInfo) => {
        console.info('Succeeded in querying the download task')
      }).catch((err: BusinessError) => {
        console.error(`Failed to query the download task. Code: ${err.code}, message: ${err.message}`)
      });
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  } 
  ```

### getTaskInfo<sup>9+</sup>

getTaskInfo(callback: AsyncCallback&lt;DownloadInfo&gt;): void

查询下载的任务，使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 由于不存在401报错场景，在api12中 `401 the parameters check fails` 这个错误码被移除。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[DownloadInfo](#downloadinfo7)&gt; | 是 | 回调函数。当查询下载任务操作成功，err为undefined，data为获取到的DownloadInfo对象；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      let downloadTask: request.DownloadTask = data;
      downloadTask.getTaskInfo((err: BusinessError, downloadInfo: request.DownloadInfo) => {
        if (err) {
          console.error(`Failed to query the download mimeType. Code: ${err.code}, message: ${err.message}`);
        } else {
          console.info('Succeeded in querying the download mimeType');
        }
      });
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```

### getTaskMimeType<sup>9+</sup>

getTaskMimeType(): Promise&lt;string&gt;

查询下载的任务的MimeType(HTTP中表示资源的媒体类型)，使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 由于不存在401报错场景，在api12中 `401 the parameters check fails` 这个错误码被移除。

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;string&gt; | Promise对象。返回下载任务的MimeType。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      let downloadTask: request.DownloadTask = data;
      downloadTask.getTaskMimeType().then((data: string) => {
        console.info('Succeeded in querying the download MimeType');
      }).catch((err: BusinessError) => {
        console.error(`Failed to query the download MimeType. Code: ${err.code}, message: ${err.message}`)
      });
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```

### getTaskMimeType<sup>9+</sup>

getTaskMimeType(callback: AsyncCallback&lt;string&gt;): void

查询下载任务的 MimeType（HTTP中表示资源的媒体类型），使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 由于不存在401报错场景，在api12中 `401 the parameters check fails` 这个错误码被移除。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。当查询下载任务MimeType成功，err为undefined，data为获取到的下载任务的MimeType的对象；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      let downloadTask: request.DownloadTask = data;
      downloadTask.getTaskMimeType((err: BusinessError, data: string) => {
        if (err) {
          console.error(`Failed to query the download mimeType. Code: ${err.code}, message: ${err.message}`);
        } else {
          console.info('Succeeded in querying the download mimeType');
        }
      });
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```

### suspend<sup>9+</sup>

suspend(): Promise&lt;boolean&gt;

暂停下载正在运行中的任务，已暂停的任务可被[restore](#restore9)恢复，使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 由于不存在401报错场景，在api12中 `401 the parameters check fails` 这个错误码被移除。

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise对象。返回true表示暂停下载正在运行中的任务成功；返回false表示暂停下载正在运行中的任务失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      let downloadTask: request.DownloadTask = data;
      downloadTask.suspend().then((result: boolean) => {
        console.info('Succeeded in pausing the download task.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to pause the download task. Code: ${err.code}, message: ${err.message}`);
      });
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```

### suspend<sup>9+</sup>

suspend(callback: AsyncCallback&lt;boolean&gt;): void

暂停下载正在运行中的任务，已暂停的任务可被[restore](#restore9)恢复，使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 由于不存在401报错场景，在api12中 `401 the parameters check fails` 这个错误码被移除。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回true表示暂停下载任务成功；返回false表示暂停下载任务失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      let downloadTask: request.DownloadTask = data;
      downloadTask.suspend((err: BusinessError, result: boolean) => {
        if (err) {
          console.error(`Failed to pause the download task. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in pausing the download task.');
      });
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```

### restore<sup>9+</sup>

restore(): Promise&lt;boolean&gt;

重新启动被暂停的下载任务，使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 由于不存在401报错场景，在api12中 `401 the parameters check fails` 这个错误码被移除。

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise对象。返回true表示重新启动被暂停的下载任务成功；返回false表示重新启动被暂停的下载任务失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      let downloadTask: request.DownloadTask = data;
      downloadTask.restore().then((result: boolean) => {
        console.info('Succeeded in resuming the download task.')
      }).catch((err: BusinessError) => {
        console.error(`Failed to resume the download task. Code: ${err.code}, message: ${err.message}`);
      });
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```

### restore<sup>9+</sup>

restore(callback: AsyncCallback&lt;boolean&gt;): void

重新启动被暂停的下载任务，使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 由于不存在401报错场景，在api12中 `401 the parameters check fails` 这个错误码被移除。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回true表示重新启动已暂停的下载任务成功；返回false表示重新启动下载任务失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  try {
    // 需要手动将url替换为真实服务器的HTTP协议地址
    request.downloadFile(context, { url: 'https://xxxx/xxxx.hap' }).then((data: request.DownloadTask) => {
      let downloadTask: request.DownloadTask = data;
      downloadTask.restore((err: BusinessError, result: boolean) => {
        if (err) {
          console.error(`Failed to resume the download task. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in resuming the download task.');
      });
    }).catch((err: BusinessError) => {
      console.error(`Failed to request the download. Code: ${err.code}, message: ${err.message}`);
    })
  } catch (err) {
    console.error(`Failed to request the download. err: ${JSON.stringify(err)}`);
  }
  ```

### remove<sup>(deprecated)</sup>

remove(): Promise&lt;boolean&gt;

移除下载的任务，使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 从API Version 9开始不再维护，建议使用[delete](#delete9-2)替代。

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise对象。返回true表示移除下载任务成功；返回false表示移除下载任务失败。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**

  ```js
  downloadTask.remove().then((result) => {
    console.info('Succeeded in removing the download task.');
  }).catch ((err: BusinessError) => {
    console.error(`Failed to remove the download task. Code: ${err.code}, message: ${err.message}`);
  });
  ```


### remove<sup>(deprecated)</sup>

remove(callback: AsyncCallback&lt;boolean&gt;): void

移除下载的任务，使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 从API Version 9开始不再维护，建议使用[delete](#delete9-3)替代。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回true表示移除下载任务成功；返回false表示移除下载任务失败。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

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

查询下载任务，返回下载任务的信息，使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始不再维护，建议使用[getTaskInfo](#gettaskinfo9)替代。

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[DownloadInfo](#downloadinfo7)&gt; | Promise对象。返回DownloadInfo。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**

  ```js
  downloadTask.query().then((downloadInfo) => {    
    console.info('Succeeded in querying the download task.')
  }).catch((err: BusinessError) => {
    console.error(`Failed to query the download task. Code: ${err.code}, message: ${err.message}`)
  });
  ```


### query<sup>(deprecated)</sup>

query(callback: AsyncCallback&lt;DownloadInfo&gt;): void

查询下载任务，返回下载任务的信息，使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始不再维护，建议使用[getTaskInfo](#gettaskinfo9-1)替代。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[DownloadInfo](#downloadinfo7)&gt; | 是 | 回调函数。当查询下载任务成功，err为undefined，data为获取到的DownloadInfo对象；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**

  ```js
  downloadTask.query((err: BusinessError, downloadInfo: request.DownloadInfo)=>{
    if(err) {
      console.error(`Failed to query the download mimeType. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('Succeeded in querying the download task.');
    }
  });
  ```


### queryMimeType<sup>(deprecated)</sup>

queryMimeType(): Promise&lt;string&gt;

查询下载任务的MimeType，使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始不再维护，建议使用[getTaskMimeType](#gettaskmimetype9)替代。

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;string&gt; | Promise对象。返回下载任务的MimeType。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**

  ```js
  downloadTask.queryMimeType().then((data: string) => {    
    console.info('Succeeded in querying the download MimeType.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to query the download MimeType. Code: ${err.code}, message: ${err.message}`)
  });
  ```


### queryMimeType<sup>(deprecated)</sup>

queryMimeType(callback: AsyncCallback&lt;string&gt;): void

查询下载的任务的MimeType，使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始不再维护，建议使用[getTaskMimeType](#gettaskmimetype9-1)替代。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。当查询下载任务的MimeType成功，err为undefined，data为获取到的任务的MimeType对象；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**

  ```js
  downloadTask.queryMimeType((err: BusinessError, data: string)=>{
    if(err) {
      console.error(`Failed to query the download mimeType. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('Succeeded in querying the download mimeType.');
    }
  });
  ```


### pause<sup>(deprecated)</sup>

pause(): Promise&lt;void&gt;

暂停下载正在运行中的任务，使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始不再维护，建议使用[suspend](#suspend9)替代。

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**

  ```js
  downloadTask.pause().then((result: boolean) => {    
    console.info('Succeeded in pausing the download task.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to pause the download task. Code: ${err.code}, message: ${err.message}`);
  });
  ```


### pause<sup>(deprecated)</sup>

pause(callback: AsyncCallback&lt;void&gt;): void

暂停下载正在运行中的任务，使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[suspend](#suspend9-1)替代。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当暂停下载任务成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**

  ```js
  downloadTask.pause((err: BusinessError, result: boolean)=>{
    if(err) {
      console.error(`Failed to pause the download task. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in pausing the download task.');
  });
  ```


### resume<sup>(deprecated)</sup>

resume(): Promise&lt;void&gt;

重新启动被暂停的下载任务，使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始不再维护，建议使用[restore](#restore9)替代。

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**

  ```js
  downloadTask.resume().then((result: boolean) => {
    console.info('Succeeded in resuming the download task.')
  }).catch((err: BusinessError) => {
    console.error(`Failed to resume the download task. Code: ${err.code}, message: ${err.message}`);
  });
  ```


### resume<sup>(deprecated)</sup>

resume(callback: AsyncCallback&lt;void&gt;): void

重新启动被暂停的下载任务，使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始不再维护，建议使用[restore](#restore9-1)替代。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当重新启动已暂停的下载任务成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | The permissions check fails. |

**示例：**

  ```js
  downloadTask.resume((err: BusinessError, result: boolean)=>{
    if (err) {
      console.error(`Failed to resume the download task. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in resuming the download task.');
  });
  ```


## DownloadConfig
下载任务的配置信息。

**系统能力**：SystemCapability.MiscServices.Download

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| url | string | 否 | 否 | 资源地址。从API 6到API 14，最大长度为2048个字符；从API 15开始，最大长度为8192个字符。支持[HTTP拦截](../../basic-services/request/app-file-upload-download.md#http拦截)功能。 |
| header | Object | 否 | 是 | 添加要包含在下载请求中的HTTPS标志头。|
| enableMetered | boolean | 否 | 是 | 表示设置是否允许在按流量计费的连接下下载任务的配置信息。true表示允许，false表示不允许。默认值为false。<br/>**说明：** Wi-Fi为非计费网络，数据流量为计费网络。 |
| enableRoaming | boolean | 否 | 是 | 表示设置是否允许在漫游网络中下载任务的配置信息。true表示允许，false表示不允许。默认值为false。|
| description | string | 否 | 是 | 设置下载会话的描述。默认值为空字符串。 |
| filePath<sup>7+</sup> | string | 否 | 是 | 设置下载路径。默认为调用方（即传入的context）对应的缓存路径。默认文件名从url的最后一个"/"后截取。<br/>-&nbsp;FA模型下使用[context](../apis-ability-kit/js-apis-inner-app-context.md#contextgetcachedir)获取应用存储路径。<br/>-&nbsp;Stage模型下使用[AbilityContext](../apis-ability-kit/js-apis-inner-application-context.md)类获取文件路径。|
| networkType | number | 否 | 是 | 设置允许下载的网络类型。默认值为NETWORK_MOBILE&NETWORK_WIFI。<br/>-&nbsp;NETWORK_MOBILE：0x00000001<br/>-&nbsp;NETWORK_WIFI：0x00010000|
| title | string | 否 | 是 | 设置下载任务名称。 |
| background<sup>9+</sup> | boolean | 否 | 是 | 后台任务通知开关，启用后可在通知中显示下载状态。true表示启用，false表示禁用。默认值为false。 |


## DownloadInfo<sup>7+</sup>
下载任务信息，[getTaskInfo](#gettaskinfo9)接口的回调参数。

**系统能力**：SystemCapability.MiscServices.Download

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| downloadId | number | 否 | 否 | 下载任务id。 |
| failedReason | number| 否 | 否 | 下载失败原因，可以是任何[下载任务的错误码](#常量)常量。 |
| fileName | string | 否 | 否 | 下载的文件名。 |
| filePath | string | 否 | 否 | 存储文件的URI。 |
| pausedReason | number | 否 | 否 | 会话暂停的原因，可以是任何[下载任务暂停原因](#常量)常量。 |
| status | number | 否 | 否 | 下载状态码，可以是任何[下载任务状态码](#常量)常量。 |
| targetURI | string | 否 | 否 | 下载文件的URI。 |
| downloadTitle | string | 否 | 否 | 下载任务名称。 |
| downloadTotalBytes | number | 否 | 否 | 下载的文件的总大小，单位为字节（B）。 |
| description | string | 否 | 否 | 待下载任务的描述信息。 |
| downloadedBytes | number | 否 | 否 | 实时下载大小，单位为字节（B）。 |

## Action<sup>10+</sup>  

定义操作选项。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| DOWNLOAD | 0 |表示下载任务。 |
| UPLOAD | 1 |表示上传任务。 |


## Mode<sup>10+</sup>  
定义模式选项。<br>
当应用的前台任务切换到后台一段时间后会显示运行失败或暂停，而后台任务不受此操作影响。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| BACKGROUND | 0 |表示后台任务。 |
| FOREGROUND | 1 |表示前台任务。 |

## Network<sup>10+</sup>  

定义网络选项。<br>
网络不满足设置条件时，未执行的任务会等待执行，执行中的任务将失败或暂停。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| ANY | 0 |表示不限网络类型。 |
| WIFI | 1 |表示无线网络。 |
| CELLULAR | 2 |表示蜂窝数据网络。 |

## BroadcastEvent<sup>11+</sup>

定义自定义系统事件。用户可以使用公共事件接口获取该事件。
上传下载 SA 具有 'ohos.permission.SEND_TASK_COMPLETE_EVENT' 该权限，用户可以配置事件的metadata指向的二级配置文件来拦截其他事件发送者。

调用CommonEventData类型传输公共事件相关数据，成员的内容填写和 [CommonEventData](js-apis-inner-commonEvent-commonEventData.md) 介绍的有所区别，其中CommonEventData.code表示任务的状态，目前为0x40 COMPLETE或0x41 FAILED；CommonEventData.data表示任务的taskId。

<!--Del-->
请参考[静态订阅公共事件](../../basic-services/common-event/common-event-static-subscription.md)以获取事件配置信息和二级配置文件的配置方式。<!--DelEnd-->

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称 | 值 | 说明        |
| -------- | ------- |-----------|
| COMPLETE | ohos.request.event.COMPLETE | 表示自定义系统事件完成。在任务结束后会触发该事件，根据任务的成功或失败，事件的code返回0x40或者0x41。 |

## FileSpec<sup>10+</sup> 
表单项的文件信息。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| path | string | 否 | 否 | 文件路径。<br/>- 相对路径，位于调用方的缓存路径下。<br/>例如："./xxx/yyy/zzz.html"、"xxx/yyy/zzz.html"。<br/>- internal协议路径，支持"internal://"及其子路径。internal为调用方（即传入的context）对应路径，"internal://cache"对应context.cacheDir。<br/>例如："internal://cache/path/to/file.txt"。<br/>- 应用沙箱目录，只支持到base及其子目录下。<br/>例如："/data/storage/el1/base/path/to/file.txt"。<br/>- file协议路径，必须匹配应用包名，只支持到base及其子目录下。<br/>例如："file://com.example.test/data/storage/el2/base/file.txt"。<br/>- 用户公共文件，仅支持上传任务。<br/>例如："file://media/Photo/path/to/file.img"。仅支持前台任务。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| mimeType<sup>(deprecated)</sup> | string | 否 | 是 | 文件的mimeType，通过文件名获取，默认值为文件名后缀。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br/> 从 API version 18 开始废弃，建议使用contentType替代。 |
| contentType<sup>18+</sup> | string | 否 | 是 | 文件内容类型，默认值为文件名后缀。该选项会被填写到HTTP表单指定的Content-Type字段中。 |
| filename | string | 否 | 是 | 文件名，默认值通过路径获取。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| extras | object | 否 | 是 | 文件信息的附加内容，该参数不会体现在HTTP请求中。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |


## FormItem<sup>10+</sup> 
任务的表单项信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| name | string | 否 | 否 | 表单参数名。 |
| value | string \| [FileSpec](#filespec10) \| Array&lt;[FileSpec](#filespec10)&gt; | 否 | 否 | 表单参数值。 |


## Config<sup>10+</sup> 
上传/下载任务的配置信息。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| action | [Action](#action10) | 否 | 否 | 任务操作选项。<br/>- UPLOAD表示上传任务。<br/>- DOWNLOAD表示下载任务。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| url | string | 否 | 否 | 资源地址。从API 6到API 14，最大长度为2048个字符；从API 15开始，最大长度为8192个字符。支持[HTTP拦截](../../basic-services/request/app-file-upload-download.md#http拦截)功能。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| title | string | 否 | 是 | 任务标题，其最大长度为256个字符，默认值为小写的 upload 或 download，与上面的 action 保持一致。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| description | string | 否 | 是 | 任务的详细信息，其最大长度为1024个字符，默认值为空字符串。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| mode | [Mode](#mode10) | 否 | 是 | 任务模式，默认为后台任务。从API version 20开始，下载到用户文件场景必须为request.agent.Mode.FOREGROUND。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| overwrite | boolean | 否 | 是 | 下载过程中路径已存在时的解决方案选择，默认为false。<br/>- true，覆盖已存在的文件。<br/>- false，下载失败。<br/>从API version 20开始，下载到用户文件场景必须为true。<br/>设置为 `true` 时，不建议创建多个任务同时往同一个文件下载内容，会导致文件内容混乱。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| method | string | 否 | 是 | 上传或下载HTTP的标准方法，包括GET、POST和PUT，不区分大小写。<br/>- 上传时，使用PUT或POST，默认值为PUT。<br/>- 下载时，使用GET或POST，默认值为GET。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| headers | object | 否 | 是 | 添加要包含在任务中的HTTP协议标志头。<br/>- 上传请求，默认的Content-Type为"multipart/form-data"。<br/>- 下载请求，默认的Content-Type为"application/json"。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| data | string \| Array&lt;[FormItem](#formitem10)&gt; | 否 | 是 | - 下载时，data为字符串类型，通常情况下使用json格式（object将被转换为json文本），默认为空。<br/>- 上传时，data是表单项数组Array&lt;[FormItem](#formitem10)&gt;。从API version 15开始，创建单个任务可以上传最多100个文件。默认为空。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| saveas | string | 否 | 是 | 保存下载文件的路径，包括如下几种：<br/>- 相对路径，位于调用方的缓存路径下，如"./xxx/yyy/zzz.html"、"xxx/yyy/zzz.html"。<br/>- internal协议路径，支持"internal://"及其子路径，internal为调用方（传入的context）对应路径，"internal://cache"对应context.cacheDir。如"internal://cache/path/to/file.txt"。<br/>- 应用沙箱目录，只支持到base及其子目录下，如"/data/storage/el1/base/path/to/file.txt"。<br/>- file协议路径，支持应用文件和用户文件，应用文件必须匹配应用包名，只支持到base及其子目录下，如"file://com.example.test/data/storage/el2/base/file.txt"。用户文件必须为调用方创建好的用户文件uri。<br/>从API version 20开始，除[下载到用户文件](../../basic-services/request/app-file-upload-download.md#下载网络资源文件至用户文件)外，其他可默认为调用方（即传入的context）对应的缓存路径。默认文件名从url的最后一个"/"后截取。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| network | [Network](#network10) | 否 | 是 | 网络选项，当前支持无线网络WIFI和蜂窝数据网络CELLULAR，默认为ANY（WIFI或CELLULAR）。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| metered | boolean | 否 | 是 | 是否允许在按流量计费的网络中工作，默认为false。<br/>- true：是 <br/>- false：否<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| roaming | boolean | 否 | 是 | 是否允许在漫游网络中工作，默认为true。<br/>- true：是 <br/>- false：否<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| retry | boolean | 否 | 是 | 是否为后台任务启用自动重试，仅应用于后台任务，默认为true。<br/>- true：是 <br/>- false：否<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| redirect | boolean | 否 | 是 | 是否允许重定向，默认为true。<br/>- true：是 <br/>- false：否<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| proxy<sup>12+</sup> | string | 否 | 是 | 设置代理地址，其最大长度为512个字符，默认为空。<br/>代理地址格式:"http://\<domain or address\>:\<port\>" |
| index | number | 否 | 是 | 任务的路径索引，通常情况下用于任务断点续传，默认为0。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| begins | number | 否 | 是 | 文件起点，通常情况下用于断点续传。默认值为0，取值为闭区间，表示从头开始传输。<br/>- 下载时，请求读取服务器开始下载文件时的起点位置（HTTP协议中设置"Range"选项）。<br/>- 上传时，读取需上传的文件的起点位置。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| ends | number | 否 | 是 | 文件终点，通常情况下用于断点续传。默认值为-1，取值为闭区间，表示传输到整个文件末尾结束。<br/>- 下载时，请求读取服务器开始下载文件时的结束位置（HTTP协议中设置"Range"选项）。<br/>- 上传时，读取需上传的文件的结束位置。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| gauge | boolean | 否 | 是 | 后台任务的过程进度通知策略，仅应用于后台任务，默认值为false。<br/>- false：代表仅完成或失败的通知。<br/>- true：发出每个进度已完成或失败的通知。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| precise | boolean | 否 | 是 | - 如果设置为true，在上传/下载无法获取文件大小时任务失败。<br/>- 如果设置为false，将文件大小设置为-1时任务继续。<br/>默认值为false。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| token | string | 否 | 是 | 任务令牌。查询带有token的任务需提供token并通过[request.agent.touch](#requestagenttouch10)查询，否则无法查询到指定任务。其最小为8个字节，最大为2048个字节。默认为空。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| priority<sup>11+</sup> | number | 否 | 是 | 任务的优先级。前台任务的优先级比后台任务高。任务模式相同的情况下，该配置项的数字越小优先级越高，默认值为0。 |
| extras | object | 否 | 是 | 配置的附加功能，默认为空。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| multipart<sup>15+</sup> | boolean | 否 | 是 | 是否使用单个请求进行上传，单个请求上传时必定使用multipart/form-data。<br/>- false：每个文件使用一个请求传输。 <br/>- true：使用多文件单请求上传。 <br/>默认值为false。 |
| notification<sup>15+</sup> | [Notification](#notification15) | 否 | 是 | 通知栏自定义设置。默认值为`{}`。|
| minSpeed<sup>20+</sup> | [MinSpeed](#minspeed20) | 否 | 是 | 最低限速自定义设置，默认不启用最低限速。|
| timeout<sup>20+</sup> | [Timeout](#timeout20) | 否 | 是 | 超时时间自定义设置，连接超时时间默认60秒，总超时时间默认604800秒（1周）。当retry参数为true时，[timeout](#timeout20)事件会触发立即重试，导致[timeout](#timeout20)在外部观察中被重试动作所掩盖，但内部[timeout](#timeout20)条件已实际触发。若需显性观察[timeout](#timeout20)事件，需关闭retry参数。|

## State<sup>10+</sup>  

定义任务当前的状态。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| INITIALIZED | 0x00 |表示通过配置信息（[Config](#config10)）创建的任务已初始化。 |
| WAITING | 0x10 |表示任务缺少运行或重试的资源，又或是网络状态不匹配。 |
| RUNNING | 0x20 |表示任务正在运行中。 |
| RETRYING | 0x21 |表示任务至少失败一次，现在正在再次处理中。 |
| PAUSED | 0x30 |表示任务暂停，通常后续会恢复任务。 |
| STOPPED | 0x31 |表示任务停止。 |
| COMPLETED | 0x40 |表示任务完成。 |
| FAILED | 0x41 |表示任务失败。 |
| REMOVED | 0x50 |表示任务移除。 |


## Progress<sup>10+</sup> 
任务进度的数据结构。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| state | [State](#state10) | 是 | 否 | 任务当前的状态。                                                            |
| index | number | 是 | 否 | 任务中当前正在处理的文件索引。                                                     |
| processed | number | 是 | 否 | 任务中当前文件的已处理数据大小，单位为字节（B）。                                               |
| sizes | Array&lt;number&gt; | 是 | 否 | 任务中文件的大小，单位为字节（B）。在下载过程中，若服务器使用chunk方式传输导致无法从请求头中获取文件总大小时，sizes为 -1。 |
| extras | object | 是 | 是 | 交互的额外内容，例如：来自服务器的响应的header和body。                                     |


## Faults<sup>10+</sup>  

定义任务失败的原因。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> API version 12及以下版本，只支持串行的尝试连接域名相关ip，且不支持单个ip的连接时间控制，如果DNS返回的首个ip是阻塞的，可能会导致握手超时，进而引发TIMEOUT错误。

| 名称 | 值 | 说明                                                                             |
| -------- | -------- |--------------------------------------------------------------------------------|
| OTHERS | 0xFF | 表示其他故障。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                        |
| DISCONNECTED | 0x00 | 表示网络断开连接。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                      |
| TIMEOUT | 0x10 | 表示任务超时。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                        |
| PROTOCOL | 0x20 | 表示协议错误，例如：服务器内部错误（500）、无法处理的数据区间（416）等。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                        |
| PARAM<sup>12+</sup> | 0x30 | 表示参数错误，例如：url格式错误等。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。          |
| FSIO | 0x40 | 表示文件系统io错误，例如：打开/查找/读取/写入/关闭。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                   |
| DNS<sup>12+</sup> | 0x50 | 表示DNS解析错误。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                  |
| TCP<sup>12+</sup> | 0x60 | 表示TCP连接错误。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。              |
| SSL<sup>12+</sup> | 0x70 | 表示SSL连接错误，例如：证书错误、证书校验失败错误等。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| REDIRECT<sup>12+</sup> | 0x80 | 表示重定向错误。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                    |
| LOW_SPEED<sup>20+</sup>  | 0x90 | 表示任务速度过低。                    |

## Filter<sup>10+</sup>
过滤条件。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| before | number | 否 | 是 | 结束的Unix时间戳（毫秒），默认为调用时刻。 |
| after | number | 否 | 是 | 开始的Unix时间戳（毫秒），默认值为调用时刻减24小时。 |
| state | [State](#state10) | 否 | 是 | 指定任务的状态。如果未填写，则查询所有任务。 |
| action | [Action](#action10) | 否 | 是 | 任务操作选项。<br/>- UPLOAD表示上传任务。<br/>- DOWNLOAD表示下载任务。<br/>- 如果未填写，则查询所有任务。 |
| mode | [Mode](#mode10) | 否 | 是 | 任务模式。<br/>- FOREGROUND表示前台任务。<br/>- BACKGROUND表示后台任务。<br/>- 如果未填写，则查询所有任务。 |

## TaskInfo<sup>10+</sup> 
查询结果的任务信息数据结构，提供普通查询和系统查询，两种字段的可见范围不同。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| saveas | string | 是 | 是 | 保存下载文件的路径。 |
| url | string | 是 | 是 | 任务的url。<br/>- 通过[request.agent.show](#requestagentshow10-1)、[request.agent.touch](#requestagenttouch10-1)进行查询。 |
| data | string \| Array&lt;[FormItem](#formitem10)&gt; | 是 | 是 | 任务值。<br/>- 通过[request.agent.show](#requestagentshow10-1)、[request.agent.touch](#requestagenttouch10-1)进行查询。 |
| tid | string | 是 | 否 | 任务id。 |
| title | string | 是 | 否 | 任务标题。 |
| description | string | 是 | 否 | 任务描述。 |
| action | [Action](#action10) | 是 | 否 | 任务操作选项。<br/>- UPLOAD表示上传任务。<br/>- DOWNLOAD表示下载任务。 |
| mode | [Mode](#mode10) | 是 | 否 | 任务模式。<br/>- FOREGROUND表示前台任务。<br/>- BACKGROUND表示后台任务。 |
| priority<sup>11+</sup> | number | 是 | 否 | 任务配置中的优先级。前台任务的优先级比后台任务高。相同模式的任务，数字越小优先级越高。 |
| mimeType | string | 是 | 否 | 任务配置中的mimetype。 |
| progress | [Progress](#progress10) | 是 | 否 | 任务的过程进度。 |
| gauge | boolean | 是 | 否 | 后台任务的进度通知策略。<br/>- false：代表仅完成或失败的通知。<br/>- true，发出每个进度已完成或失败的通知。 |
| ctime | number | 是 | 否 | 创建任务的Unix时间戳（毫秒），由当前设备的系统生成。<br/>说明：使用[request.agent.search](#requestagentsearch10-1)进行查询时，该值需处于[after,before]区间内才可正常查询到任务id，before和after信息详见[Filter](#filter10)。|
| mtime | number | 是 | 否 | 任务状态改变时的Unix时间戳（毫秒），由当前设备的系统生成。|
| retry | boolean | 是 | 否 | 任务的重试开关，仅应用于后台任务。<br/>- true：是 <br/>- false：否 |
| tries | number | 是 | 否 | 任务的尝试次数。 |
| faults | [Faults](#faults10) | 是 | 否 | 任务的失败原因。|
| reason | string | 是 | 否 | 等待/失败/停止/暂停任务的原因。|
| extras | object | 是 | 是 | 任务的额外部分。|

## HttpResponse<sup>12+</sup> 
任务响应头的数据结构。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| version | string | 是 | 否 | Http版本。 |
| statusCode | number | 是 | 否 | Http响应状态码。 |
| reason | string | 是 | 否 | Http响应原因。|
| headers | Map&lt;string, Array&lt;string&gt;&gt; | 是 | 否 | Http响应头部。 |

## Notification<sup>15+</sup>

通知栏自定义信息。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| title   | string | 否 | 是 | 通知栏自定义标题。若不设置则使用默认显示方式。title长度上限为1024B。 |
| text    | string | 否 | 是 | 通知栏自定义正文。若不设置则使用默认显示方式。text长度上限为3072B。  |

## GroupConfig<sup>15+</sup>

下载任务分组配置选项。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| gauge        | boolean                                       | 否 | 是  | 后台任务的进度通知策略。 <br/>- true，显示进度、成功、失败通知。 <br/>- false，仅显示成功、失败通知。<br/>默认为false。 |
| notification<sup>15+</sup> | [Notification](#notification15) | 否 | 否  | 通知栏自定义设置。默认值为`{}`                     |

## WaitingReason<sup>20+</sup>

枚举，定义任务等待的原因。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称 | 值    | 说明                       |
| -------- |------|--------------------------|
| TASK_QUEUE_FULL | 0x00 | 表示任务因任务队列已满而进入等待状态。      |
| NETWORK_NOT_MATCH | 0x01 | 表示任务因所需网络条件不满足而进入等待状态。   |
| APP_BACKGROUND | 0x02 | 表示任务因应用长时间处于后台而进入等待状态。   |
| USER_INACTIVATED | 0x03 | 表示任务因所属用户处于非激活状态而进入等待状态。 |

## MinSpeed<sup>20+</sup>

任务的最低限速配置。若任务速度持续低于设定值并达到指定时长，则任务失败，失败原因为[LOW_SPEED](#faults10)。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称      | 类型   | 只读 | 可选 | 说明                                                           |
|---------|----------|----|----|--------------------------------------------------------------|
| speed   | number   | 否  | 否  | 任务最低速度，单位为字节每秒（B/s）。若任务速度持续低于该值达到指定时长，则任务失败。设置为0表示不启用最低速度限制。 |
| duration    | number   | 否  | 否  | 允许低于最低速度的持续时间，单位为秒。若任务速度持续低于设定值达到该时长，则任务失败。设置为0表示不启用最低速度限制。  |

## Timeout<sup>20+</sup>

任务的超时配置。任务处于等待状态的时间不参与计算，上传下载任务会存在以下任务等待的原因:[WaitingReason<sup>20+</sup>](#waitingreason20)。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称      | 类型     | 只读 | 可选 | 说明                                      |
|---------|--------|----|----|-----------------------------------------|
| connectionTimeout   | number | 否  | 是  | 任务连接超时时间，单位为秒。连接超时是指客户端与服务器建立连接的最大耗时。若不设置则使用默认值60秒，允许设置的最小值为1秒。 |
| totalTimeout    | number | 否  | 是  |任务总超时时间，单位为秒。总超时包括建立连接、发送请求和接收响应的全部时间。未指定时使用默认值604800秒（1周）。允许设置的最小值为1秒，最大值为604800秒（1周）。  |


## Task<sup>10+</sup> 
上传或下载任务。使用该方法前需要先获取Task对象，promise形式通过[request.agent.create](#requestagentcreate10-1)获取，callback形式通过[request.agent.create](#requestagentcreate10)获取。

### 属性
包括任务id和任务的配置信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> Task对象及其挂载回调函数会在调用remove方法后释放并被系统自动回收。

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| tid | string | 是 | 否 | 任务id，由系统自动生成且唯一。 |
| config | [Config](#config10) | 否 | 否 | 任务的配置信息。 |

### on('progress')<sup>10+</sup>

on(event: 'progress', callback: (progress: [Progress](#progress10)) =&gt; void): void

订阅任务进度的事件，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'progress'，表示任务进度，任务进度有进展时触发该事件。 |
  | callback | function | 是 | 回调函数，发生相关的事件时触发该回调方法。 |

回调函数的参数：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | progress | [Progress](#progress10) | 是 | 表示任务的进度信息。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOnTest",
    value: {
      filename: "taskOnTest.avi",
      path: "./taskOnTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then((task: request.agent.Task) => {
    task.on('progress', createOnCallback);
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### on('completed')<sup>10+</sup>

on(event: 'completed', callback: (progress: [Progress](#progress10)) =&gt; void): void

订阅任务完成事件，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'completed'，表示任务完成，任务完成时触发该事件。 |
  | callback | function | 是 | 回调函数，发生相关的事件时触发该回调方法。 |

回调函数的参数：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | progress | [Progress](#progress10) | 是 | 表示任务的进度信息。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOnTest",
    value: {
      filename: "taskOnTest.avi",
      path: "./taskOnTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then((task: request.agent.Task) => {
    task.on('completed', createOnCallback);
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### on('failed')<sup>10+</sup>

on(event: 'failed', callback: (progress: [Progress](#progress10)) =&gt; void): void

订阅任务失败事件，使用callback异步回调。可通过调用[request.agent.show](#requestagentshow10-1)查看错误原因。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'failed'，表示任务失败，任务失败时触发该事件。 |
  | callback | function | 是 | 回调函数，发生相关的事件时触发该回调方法。 |

回调函数的参数：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | progress | [Progress](#progress10) | 是 | 表示任务的进度信息。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOnTest",
    value: {
      filename: "taskOnTest.avi",
      path: "./taskOnTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then((task: request.agent.Task) => {
    task.on('failed', createOnCallback);
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### on('pause')<sup>11+</sup>

on(event: 'pause', callback: (progress: [Progress](#progress10)) =&gt; void): void

订阅任务暂停事件，使用callback异步回调。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'pause'，表示任务已暂停，任务暂停时触发该事件。 |
  | callback | function | 是 | 回调函数，发生相关的事件时触发该回调方法。 |

回调函数的参数：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | progress | [Progress](#progress10) | 是 | 表示任务的进度信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOnTest",
    value: {
      filename: "taskOnTest.avi",
      path: "./taskOnTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
    title: 'taskOnTest',
    description: 'Sample code for event listening',
    mode: request.agent.Mode.FOREGROUND,
    overwrite: false,
    method: "POST",
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
  request.agent.create(context, config).then(async (task: request.agent.Task) => {
    task.on('pause', createOnCallback);
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
    // 等待1秒再执行下一步操作，以防异步乱序
    await new Promise<void>((resolve) => {
      setTimeout(() => resolve(),1000)
    })
    task.pause();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### on('resume')<sup>11+</sup>

on(event: 'resume', callback: (progress: [Progress](#progress10)) =&gt; void): void

订阅任务恢复事件，使用callback异步回调。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'resume'，表示任务恢复，任务恢复时触发该事件。 |
  | callback | function | 是 | 回调函数，发生相关的事件时触发该回调方法。 |

回调函数的参数：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | progress | [Progress](#progress10) | 是 | 表示任务的进度信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOnTest",
    value: {
      filename: "taskOnTest.avi",
      path: "./taskOnTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then(async (task: request.agent.Task) => {
    task.on('resume', createOnCallback);
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
    // 等待1秒再执行下一步操作，以防异步乱序
    await new Promise<void>((resolve) => {
      setTimeout(() => resolve(),1000)
    })
    task.pause();
    // 等待1秒再执行下一步操作，以防异步乱序
    await new Promise<void>((resolve) => {
      setTimeout(() => resolve(),1000)
    })
    task.resume();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### on('remove')<sup>11+</sup>

on(event: 'remove', callback: (progress: [Progress](#progress10)) =&gt; void): void

订阅任务移除事件，使用callback异步回调。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'remove'，表示任务被移除，任务移除时触发该事件。 |
  | callback | function | 是 | 回调函数，发生相关的事件时触发该回调方法。 |

回调函数的参数：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | progress | [Progress](#progress10) | 是 | 表示任务的进度信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOnTest",
    value: {
      filename: "taskOnTest.avi",
      path: "./taskOnTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then(async (task: request.agent.Task) => {
    task.on('remove', createOnCallback);
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
    // 等待1秒再执行下一步操作，以防异步乱序
    await new Promise<void>((resolve) => {
      setTimeout(() => resolve(),1000)
    })
    request.agent.remove(task.tid);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### on('response')<sup>12+</sup>

on(event: 'response', callback: Callback&lt;HttpResponse&gt;): void

订阅任务响应头，使用callback异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 订阅的事件类型。<br>- 取值为'response'，表示任务响应，请求接收到响应时触发该事件。 |
  | callback | Callback&lt;[HttpResponse](#httpresponse12)&gt; | 是 | 回调函数，发生相关的事件时触发该回调方法，返回任务响应头的数据结构。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOnTest",
    value: {
      filename: "taskOnTest.avi",
      path: "./taskOnTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  let createOnCallback = (response: request.agent.HttpResponse) => {
    console.info('upload task response.');
  };
  request.agent.create(context, config).then((task: request.agent.Task) => {
    task.on('response', createOnCallback);
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### on('faultOccur')<sup>20+</sup>

on(event: 'faultOccur', callback: Callback&lt;Faults&gt;): void

订阅任务失败原因，使用callback形式返回结果。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

| 参数名 | 类型                                  | 必填 | 说明                         |
| -------- |-------------------------------------| -------- |----------------------------|
| event | string                              | 是 | 订阅的事件类型。<br>- 取值为'faultOccur'，表示任务失败。 |
| callback | Callback&lt;[Faults](#faults10)&gt; | 是 | 发生相关的事件时触发该回调方法，返回任务失败的原因。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';
  
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
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
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  let faultOnCallback = (faults: request.agent.Faults) => {
    console.info('upload task failed.');
  };
  request.agent.create(context, config).then((task: request.agent.Task) => {
    task.on('faultOccur', faultOnCallback);
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### on('wait')<sup>20+</sup>

on(event: 'wait', callback: Callback&lt;WaitingReason&gt;): void

订阅任务等待原因，使用callback形式返回结果。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

| 参数名 | 类型                                                | 必填 | 说明                              |
| -------- |---------------------------------------------------| -------- |---------------------------------|
| event | string                                            | 是 | 订阅的事件类型。<br>- 取值为'wait'，表示任务等待。 |
| callback | Callback&lt;[WaitingReason](#waitingreason20)&gt; | 是 | 发生相关的事件时触发该回调方法，返回任务等待的原因。      |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';
  
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
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
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  let waitOnCallback = (reason: request.agent.WaitingReason) => {
    console.info('upload task waiting.');
  };
  request.agent.create(context, config).then((task: request.agent.Task) => {
    task.on('wait', waitOnCallback);
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### off('progress')<sup>10+</sup>

off(event: 'progress', callback?: (progress: [Progress](#progress10)) =&gt; void): void

取消订阅任务进度事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 取消订阅的事件类型。<br>- 取值为'progress'，表示任务进度。 |
  | callback | function | 否 | 回调函数，发生相关的事件时触发该回调方法。 |

回调函数的参数：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | progress | [Progress](#progress10) | 是 | 表示任务的进度信息。 |


**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOffTest",
    value: {
      filename: "taskOffTest.avi",
      path: "./taskOffTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then((task: request.agent.Task) => {
    task.on('progress', createOffCallback1);
    task.on('progress', createOffCallback2);
    //表示取消createOffCallback1的订阅
    task.off('progress', createOffCallback1);
    //表示取消订阅任务进度的所有回调
    task.off('progress');
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### off('completed')<sup>10+</sup>

off(event: 'completed', callback?: (progress: [Progress](#progress10)) =&gt; void): void

取消订阅任务完成事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 取消订阅的事件类型。<br>- 取值为'completed'，表示任务完成。 |
  | callback | function | 否 | 回调函数，发生相关的事件时触发该回调方法。 |

回调函数的参数：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | progress | [Progress](#progress10) | 是 | 表示任务的进度信息。 |


**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOffTest",
    value: {
      filename: "taskOffTest.avi",
      path: "./taskOffTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then((task: request.agent.Task) => {
    task.on('completed', createOffCallback1);
    task.on('completed', createOffCallback2);
    //表示取消createOffCallback1的订阅
    task.off('completed', createOffCallback1);
    //表示取消订阅任务完成的所有回调
    task.off('completed');
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### off('failed')<sup>10+</sup>

off(event: 'failed', callback?: (progress: [Progress](#progress10)) =&gt; void): void

取消订阅任务失败事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 取消订阅的事件类型。<br>- 取值为'failed'，表示任务失败。 |
  | callback | function | 否 | 回调函数，发生相关的事件时触发该回调方法。 |

回调函数的参数：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | progress | [Progress](#progress10) | 是 | 表示任务的进度信息 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOffTest",
    value: {
      filename: "taskOffTest.avi",
      path: "./taskOffTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then((task: request.agent.Task) => {
    task.on('failed', createOffCallback1);
    task.on('failed', createOffCallback2);
    //表示取消createOffCallback1的订阅
    task.off('failed', createOffCallback1);
    //表示取消订阅任务失败的所有回调
    task.off('failed');
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### off('pause')<sup>11+</sup>

off(event: 'pause', callback?: (progress: [Progress](#progress10)) =&gt; void): void

取消订阅任务暂停事件。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 取消订阅的事件类型。<br>- 取值为'pause'，表示任务暂停。 |
  | callback | function | 否 | 回调函数，发生相关的事件时触发该回调方法。 |

回调函数的参数：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | progress | [Progress](#progress10) | 是 | 表示任务的进度信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOffTest",
    value: {
      filename: "taskOffTest.avi",
      path: "./taskOffTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then((task: request.agent.Task) => {
    task.on('pause', createOffCallback1);
    task.on('pause', createOffCallback2);
    //表示取消createOffCallback1的订阅
    task.off('pause', createOffCallback1);
    //表示取消订阅任务暂停的所有回调
    task.off('pause');
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### off('resume')<sup>11+</sup>

off(event: 'resume', callback?: (progress: [Progress](#progress10)) =&gt; void): void

取消订阅任务恢复事件。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 取消订阅的事件类型。<br>- 取值为'resume'，表示任务恢复。 |
  | callback | function | 否 | 回调函数，发生相关的事件时触发该回调方法。 |

回调函数的参数：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | progress | [Progress](#progress10) | 是 | 表示任务的进度信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOffTest",
    value: {
      filename: "taskOffTest.avi",
      path: "./taskOffTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then((task: request.agent.Task) => {
    task.on('resume', createOffCallback1);
    task.on('resume', createOffCallback2);
    //表示取消createOffCallback1的订阅
    task.off('resume', createOffCallback1);
    //表示取消订阅任务恢复的所有回调
    task.off('resume');
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### off('remove')<sup>11+</sup>

off(event: 'remove', callback?: (progress: [Progress](#progress10)) =&gt; void): void

取消订阅任务移除事件。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 取消订阅的事件类型。<br>- 取值为'remove'，表示任务被移除。 |
  | callback | function | 否 | 回调函数，发生相关的事件时触发该回调方法。 |

回调函数的参数：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | progress | [Progress](#progress10) | 是 | 表示任务的进度信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOffTest",
    value: {
      filename: "taskOffTest.avi",
      path: "./taskOffTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then((task: request.agent.Task) => {
    task.on('remove', createOffCallback1);
    task.on('remove', createOffCallback2);
    //表示取消createOffCallback1的订阅
    task.off('remove', createOffCallback1);
    //表示取消订阅任务移除的所有回调
    task.off('remove');
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### off('response')<sup>12+</sup>

off(event: 'response', callback?: Callback&lt;HttpResponse&gt;): void

取消订阅任务响应事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | string | 是 | 取消订阅的事件类型。<br>- 取值为'response'，表示任务响应。 |
  | callback | Callback&lt;[HttpResponse](#httpresponse12)&gt; | 否 | 需要取消订阅的回调函数。若无此参数，则取消订阅当前类型的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let attachments: Array<request.agent.FormItem> = [{
    name: "taskOffTest",
    value: {
      filename: "taskOffTest.avi",
      path: "./taskOffTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  let createOffCallback1 = (progress: request.agent.HttpResponse) => {
    console.info('upload task response.');
  };
  let createOffCallback2 = (progress: request.agent.HttpResponse) => {
    console.info('upload task response.');
  };
  request.agent.create(context, config).then((task: request.agent.Task) => {
    task.on('response', createOffCallback1);
    task.on('response', createOffCallback2);
    //表示取消createOffCallback1的订阅
    task.off('response', createOffCallback1);
    //表示取消订阅任务移除的所有回调
    task.off('response');
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### off('faultOccur')<sup>20+</sup>

off(event: 'faultOccur', callback?: Callback&lt;Faults&gt;): void

取消订阅任务响应头。


**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

| 参数名 | 类型                         | 必填 | 说明                                    |
| -------- |----------------------------| -------- |---------------------------------------|
| event | string                     | 是 | 订阅的事件类型。<br>- 取值为'faultOccur'，表示任务失败。      |
| callback | Callback&lt;[Faults](#faults10)&gt; | 否 | 需要取消订阅的回调函数。若无此参数，则默认取消订阅当前类型的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';
  
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
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
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  let faultOffCallback1 = (faults: request.agent.Faults) => {
    console.info('upload task failed.');
  };
  let faultOffCallback2 = (faults: request.agent.Faults) => {
    console.info('upload task failed.');
  };
  request.agent.create(context, config).then((task: request.agent.Task) => {
    task.on('faultOccur', faultOffCallback1);
    task.on('faultOccur', faultOffCallback2);
    // 表示取消faultOffCallback1的订阅
    task.off('faultOccur', faultOffCallback1);
    // 表示取消订阅任务移除的所有回调
    task.off('faultOccur');
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### off('wait')<sup>20+</sup>

off(event: 'wait', callback?: Callback&lt;WaitingReason&gt;): void

取消订阅任务响应头。


**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

| 参数名 | 类型                                | 必填 | 说明                                    |
| -------- |-----------------------------------| -------- |---------------------------------------|
| event | string                            | 是 | 订阅的事件类型。<br>- 取值为'wait'，表示任务等待。       |
| callback | Callback&lt;[WaitingReason](#waitingreason20)&gt; | 否 | 需要取消订阅的回调函数。若无此参数，则默认取消订阅当前类型的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';
  
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
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
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  let waitOffCallback1 = (reason: request.agent.WaitingReason) => {
    console.info('upload task waiting.');
  };
  let waitOffCallback2 = (reason: request.agent.WaitingReason) => {
    console.info('upload task waiting.');
  };
  request.agent.create(context, config).then((task: request.agent.Task) => {
    task.on('wait', waitOffCallback1);
    task.on('wait', waitOffCallback2);
    // 表示取消waitOffCallback1的订阅
    task.off('wait', waitOffCallback1);
    // 表示取消订阅任务移除的所有回调
    task.off('wait');
    console.info(`Succeeded in creating a upload task. result: ${task.tid}`);
    task.start();
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### start<sup>10+</sup>

start(callback: AsyncCallback&lt;void&gt;): void

启动一个任务，使用callback异步回调。<br>
以下状态的任务可以被启动：
1. 刚被request.agent.create接口创建的任务。
2. 使用request.agent.create接口创建的已经失败或者停止的下载任务。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当开启任务成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | Permission denied. |
  | 13400003 | Task service ability error. |
  | 21900007 | Operation with wrong task state. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then((task: request.agent.Task) => {
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

### start<sup>10+</sup>

start(): Promise&lt;void&gt;

启动一个任务，使用Promise异步回调。<br>
以下状态的任务可以被启动：
1. 刚被request.agent.create接口创建的任务。
2. 使用request.agent.create接口创建的已经失败或者停止的下载任务。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | Permission denied. |
  | 13400003 | Task service ability error. |
  | 21900007 | Operation with wrong task state. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then((task: request.agent.Task) => {
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

### pause<sup>10+</sup>

pause(callback: AsyncCallback&lt;void&gt;): void

暂停任务，可以暂停正在等待/正在运行/正在重试的任务，已暂停的任务可被[resume](#resume10)恢复。使用callback异步回调。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当暂停任务成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | Task service ability error. |
  | 21900007 | Operation with wrong task state. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then(async (task: request.agent.Task) => {
    task.start();
    // 等待1秒再执行下一步操作，以防异步乱序
    await new Promise<void>((resolve) => {
      setTimeout(() => resolve(),1000)
    })
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

### pause<sup>10+</sup>

pause(): Promise&lt;void&gt;

暂停任务，可以暂停正在等待/正在运行/正在重试的任务，已暂停的任务可被[resume](#resume10)恢复。使用Promise异步回调。

**系统能力**：SystemCapability.Request.FileTransferAgent

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | Task service ability error. |
  | 21900007 | Operation with wrong task state. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then(async (task: request.agent.Task) => {
    task.start();
    // 等待1秒再执行下一步操作，以防异步乱序
    await new Promise<void>((resolve) => {
      setTimeout(() => resolve(),1000)
    })
    task.pause().then(() => {
      console.info(`Succeeded in pausing a download task. `);
    }).catch((err: BusinessError) => {
      console.error(`Failed to pause the download task, Code: ${err.code}, message: ${err.message}`);
    });
    console.info(`Succeeded in creating a download task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

### resume<sup>10+</sup>

resume(callback: AsyncCallback&lt;void&gt;): void

重新启动任务，可以恢复被暂停的任务。使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当重新启动任务成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | Permission denied. |
  | 13400003 | Task service ability error. |
  | 21900007 | Operation with wrong task state. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then(async (task: request.agent.Task) => {
    task.start();
    // 等待1秒再执行下一步操作，以防异步乱序
    await new Promise<void>((resolve) => {
      setTimeout(() => resolve(),1000)
    })
    task.pause();
    // 等待1秒再执行下一步操作，以防异步乱序
    await new Promise<void>((resolve) => {
      setTimeout(() => resolve(),1000)
    })
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

### resume<sup>10+</sup>

resume(): Promise&lt;void&gt;

重新启动任务，可以恢复被暂停的任务。使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Request.FileTransferAgent

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | Permission denied. |
  | 13400003 | Task service ability error. |
  | 21900007 | Operation with wrong task state. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then(async (task: request.agent.Task) => {
    task.start();
    // 等待1秒再执行下一步操作，以防异步乱序
    await new Promise<void>((resolve) => {
      setTimeout(() => resolve(),1000)
    })
    task.pause();
    // 等待1秒再执行下一步操作，以防异步乱序
    await new Promise<void>((resolve) => {
      setTimeout(() => resolve(),1000)
    })
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

### stop<sup>10+</sup>

stop(callback: AsyncCallback&lt;void&gt;): void

停止任务，可以停止正在运行/正在等待/正在重试的任务，已停止的任务可被[start](#start10)恢复。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当停止任务成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | Task service ability error. |
  | 21900007 | Operation with wrong task state. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then(async (task: request.agent.Task) => {
    task.start();
    // 等待1秒再执行下一步操作，以防异步乱序
    await new Promise<void>((resolve) => {
      setTimeout(() => resolve(),1000)
    })
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

停止任务，可以停止正在运行/正在等待/正在重试的任务，已停止的任务可被[start](#start10)恢复。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 13400003 | Task service ability error. |
  | 21900007 | Operation with wrong task state. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then(async (task: request.agent.Task) => {
    task.start();
    // 等待1秒再执行下一步操作，以防异步乱序
    await new Promise<void>((resolve) => {
      setTimeout(() => resolve(),1000)
    })
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

### setMaxSpeed<sup>18+</sup>

setMaxSpeed(speed: number): Promise\<void\>

设置任务每秒能传输的字节数上限。使用Promise异步回调。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                                           |
|-------|--------|----|------------------------------------------------------------------------------|
| speed | number | 是  | 设置任务每秒能传输的字节数上限，单位为字节（B），最小值为16384字节，同时该值不得低于[MinSpeed](#minspeed20)设置的最低速度。 |

**返回值：**

| 类型              | 说明                         |
|-----------------|----------------------------|
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID    | 错误信息                 |
|----------|------------------------------------------------------------------------------------------------------|
| 401      | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |
| 13400003 | Task service ability error.     |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
    saveas: "./",
  };
  request.agent.create(context, config).then((task: request.agent.Task) => {
    // 设置任务速度上限。
    task.setMaxSpeed(10 * 1024 * 1024).then(() => {
      console.info(`Succeeded in setting the max speed of the task. result: ${task.tid}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to set the max speed of the task. result: ${task.tid}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

## request.agent.create<sup>10+</sup>

create(context: BaseContext, config: Config, callback: AsyncCallback&lt;Task&gt;): void

创建需要上传或下载的任务，并将其排入队列。支持HTTP/HTTPS协议，使用callback异步回调。


**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是 | 基于应用程序的上下文。 |
  | config | [Config](#config10) | 是 | 上传/下载任务的配置信息。 |
  | callback | AsyncCallback&lt;[Task](#task10)&gt; | 是 | 回调函数。当创建上传或下载任务成功，err为undefined，data为获取到的Task对象；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | Permission denied. |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |
  | 13400001 | Invalid file or file system error. |
  | 13400003 | Task service ability error.    |
  | 21900004 | The application task queue is full. |
  | 21900005 | Operation with wrong task mode. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let attachments: Array<request.agent.FormItem> = [{
    name: "createTest",
    value: {
      filename: "createTest.avi",
      path: "./createTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config, async (err: BusinessError, task: request.agent.Task) => {
    if (err) {
      console.error(`Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in creating a download task. result: ${task.config}`);
    await task.start();
    //用户需要手动调用remove从而结束task对象的生命周期
    request.agent.remove(task.tid);
  });
  ```

## request.agent.create<sup>10+</sup>

create(context: BaseContext, config: Config): Promise&lt;Task&gt;

创建需要上传或下载的任务，并将其排入队列。支持HTTP/HTTPS协议，使用Promise异步回调。


**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

> **说明：**
>
> 示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是 | 基于应用程序的上下文。 |
  | config | [Config](#config10) | 是 | 上传/下载任务的配置信息。 |

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Task](#task10)&gt; | Promise对象。返回任务配置信息的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | Permission denied. |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |
  | 13400001 | Invalid file or file system error. |
  | 13400003 | Task service ability error. |
  | 21900004 | The application task queue is full. |
  | 21900005 | Operation with wrong task mode. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let attachments: Array<request.agent.FormItem> = [{
    name: "createTest",
    value: {
      filename: "createTest.avi",
      path: "./createTest.avi",
    }
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: 'http://127.0.0.1', // 需要手动将url替换为真实服务器的HTTP协议地址
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
  request.agent.create(context, config).then(async (task: request.agent.Task) => {
    console.info(`Succeeded in creating a download task. result: ${task.config}`);
    await task.start();
    //用户需要手动调用remove从而结束task对象的生命周期
    request.agent.remove(task.tid);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

## request.agent.getTask<sup>11+</sup>

getTask(context: BaseContext, id: string, token?: string): Promise&lt;Task&gt;

根据任务id查询任务。使用Promise异步回调。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | context | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是 | 基于应用程序的上下文。 |
  | id | string | 是 | 任务id。 |
  | token | string | 否 | 任务查询token。 |

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Task](#task10)&gt; | Promise对象。返回任务配置信息的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |
  | 13400003 | Task service ability error. |
  | 21900006 | Task removed or not found. |

**示例：**
  <!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  request.agent.getTask(context, "123456").then((task: request.agent.Task) => {
    console.info(`Succeeded in querying a task. result: ${task.tid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to query a task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

## request.agent.remove<sup>10+</sup>

remove(id: string, callback: AsyncCallback&lt;void&gt;): void

移除属于调用方的指定任务，如果正在处理中，该任务将被迫停止。使用callback异步回调。在调用后任务对象和其回调函数会被释放。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | string | 是 | 任务id。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当移除指定任务成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. |
  | 13400003 | Task service ability error. |
  | 21900006 | Task removed or not found. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  request.agent.remove("123456", (err: BusinessError) => {
    if (err) {
      console.error(`Failed to remove a download task, Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in removing a download task.`);
  });
  ```


## request.agent.remove<sup>10+</sup>

remove(id: string): Promise&lt;void&gt;

移除属于调用方的指定任务，如果正在处理中，该任务将被迫停止。使用Promise异步回调。在调用后任务对象和其回调函数会被释放。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | string | 是 | 任务id。 |

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. |
  | 13400003 | Task service ability error. |
  | 21900006 | Task removed or not found. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  request.agent.remove("123456").then(() => {
    console.info(`Succeeded in removing a download task. `);
  }).catch((err: BusinessError) => {
    console.error(`Failed to remove a download task, Code: ${err.code}, message: ${err.message}`);
  });
  ```


## request.agent.show<sup>10+</sup>

show(id: string, callback: AsyncCallback&lt;TaskInfo&gt;): void

根据任务id查询任务的详细信息。使用callback异步回调。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | string | 是 | 任务id。 |
  | callback | AsyncCallback&lt;[TaskInfo](#taskinfo10)&gt; | 是 | 回调函数。当查询任务操作成功，err为undefined，data为查询到的任务TaskInfo信息；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. |
  | 13400003 | Task service ability error. |
  | 21900006 | Task removed or not found. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

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

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | string | 是 | 任务id。 |

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[TaskInfo](#taskinfo10)&gt; | Promise对象。返回任务详细信息TaskInfo的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. |
  | 13400003 | Task service ability error. |
  | 21900006 | Task removed or not found. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  request.agent.show("123456").then((taskInfo: request.agent.TaskInfo) => {
    console.info(`Succeeded in showing a upload task.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to show a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```


## request.agent.touch<sup>10+</sup>

touch(id: string, token: string, callback: AsyncCallback&lt;TaskInfo&gt;): void

根据任务id和token查询任务的详细信息。使用callback异步回调。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | string | 是 | 任务id。 |
  | token | string | 是 | 任务查询token。 |
  | callback | AsyncCallback&lt;[TaskInfo](#taskinfo10)&gt; | 是 | 回调函数。当查询任务操作成功，err为undefined，data为查询到的任务TaskInfo信息；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |
  | 13400003 | Task service ability error. |
  | 21900006 | Task removed or not found.  |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

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

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | string | 是 | 任务id。 |
  | token | string | 是 | 任务查询token。 |

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[TaskInfo](#taskinfo10)&gt; | Promise对象。返回任务详细信息TaskInfo的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |
  | 13400003 | Task service ability error. |
  | 21900006 | Task removed or not found. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  request.agent.touch("123456", "token").then((taskInfo: request.agent.TaskInfo) => {
    console.info(`Succeeded in touching a upload task. `);
  }).catch((err: BusinessError) => {
    console.error(`Failed to touch a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

## request.agent.search<sup>10+</sup>

search(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

根据默认[Filter](#filter10)过滤条件查找任务id，即查询调用时刻至24小时前的所有任务的任务id。使用callback异步回调。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是 | 回调函数。当根据过滤条件查找任务成功，err为undefined，data为满足条件的任务id；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Incorrect parameter type. 2. Parameter verification failed. |
  | 13400003 | Task service ability error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

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

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | filter | [Filter](#filter10) | 是 | 过滤条件。 |
  | callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是 | 回调函数。当根据过滤条件查找任务成功，err为undefined，data为满足条件的任务id；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Incorrect parameter type. 2. Parameter verification failed. |
  | 13400003 | Task service ability error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filter: request.agent.Filter = {
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

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | filter | [Filter](#filter10) | 否 | 过滤条件。 |

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象。返回满足条件任务id的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401 | Parameter error. Possible causes: 1. Incorrect parameter type. 2. Parameter verification failed. |
  | 13400003 | Task service ability error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filter: request.agent.Filter = {
    action: request.agent.Action.UPLOAD,
    mode: request.agent.Mode.BACKGROUND
  }
  request.agent.search(filter).then((data: Array<string>) => {
    console.info(`Succeeded in searching a upload task. `);
  }).catch((err: BusinessError) => {
    console.error(`Failed to search a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```

## request.agent.createGroup<sup>15+</sup>

createGroup(config: GroupConfig): Promise\<string\>

根据[GroupConfig](#groupconfig15)分组条件创建分组，并返回分组id。使用Promise异步回调。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

| 参数名    | 类型                                          | 必填 | 说明        |
|--------|---------------------------------------------|----|-----------|
| config | [GroupConfig<sup>15+</sup>](#groupconfig15) | 是  | 下载任务分组选项。 |

**返回值：**

| 类型                | 说明                               |
|-------------------|----------------------------------|
| Promise\<string\> | Promise对象。返回创建完成的分组id。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID    | 错误信息                                                                                           |
|----------|------------------------------------------------------------------------------------------------|
| 401      | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |
| 13400003 | Task service ability error.             |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // 准备分组配置选项 GroupConfig 对象。
  let config: request.agent.GroupConfig = {
      notification: {},
  };
  // 调用 createGroup 接口创建分组。
  request.agent.createGroup(config).then((gid: string) => {
    console.info(`Succeeded in creating a download task group. `);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create a download group, Code: ${err.code}, message: ${err.message}`);
  });
  ```

## request.agent.attachGroup<sup>15+</sup>

attachGroup(gid: string, tids: string[]): Promise\<void\>

向指定分组id中绑定多个下载任务id。使用Promise异步回调。

如果任意一个任务id不满足添加条件，则所有列表中的任务都不会添加到分组中。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

| 参数名  | 类型       | 必填 | 说明                  |
|------|----------|----|---------------------|
| gid  | string   | 是  | 目标分组id。             |
| tids | string[] | 是  | 待绑定的任务id列表。 |

**返回值：**

| 类型              | 说明         |
|-----------------|------------|
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID    | 错误信息                                                                                           |
|----------|------------------------------------------------------------------------------------------------|
| 401      | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |
| 13400003 | Task service ability error.               |
| 21900005 | Operation with wrong task mode.           |
| 21900006 | Task removed or not found.                |
| 21900007 | Operation with wrong task state.          |
| 21900008 | Group deleted or not found.               |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // 准备分组id和任务id列表。
  let groupId: string = "123456789";
  let taskIds: string[] = ["1111", "2222", "3333", "4444"];
  // 调用 attachGroup 接口向分组中添加任务id列表。
  request.agent.attachGroup(groupId, taskIds).then(() => {
    console.info(`Succeeded in attaching tasks to the download task group.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to attach tasks to the download group, Code: ${err.code}, message: ${err.message}`);
  });
  ```

## request.agent.deleteGroup<sup>15+</sup>

deleteGroup(gid: string): Promise\<void\>

移除指定分组，后续不能再往该分组中添加任务id。使用Promise异步回调。

当分组中的所有任务处于完成、失败或移除状态，并且分组被移除时，显示该分组的完成或失败通知。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

| 参数名  | 类型       | 必填 | 说明      |
|------|----------|----|---------|
| gid  | string   | 是  | 目标分组id。 |

**返回值：**

| 类型              | 说明         |
|-----------------|------------|
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[上传下载错误码](errorcode-request.md)与[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID    | 错误信息                                                                                           |
|----------|------------------------------------------------------------------------------------------------|
| 401      | Parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |
| 13400003 | Task service ability error.           |
| 21900008 | Group deleted or not found.           |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // 准备分组id。
  let groupId: string = "123456789";
  
  // 调用 deleteGroup 接口移除分组。
  request.agent.deleteGroup(groupId).then(() => {
    console.info(`Succeeded in deleting the download task group.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to delete the download group, Code: ${err.code}, message: ${err.message}`);
  });
  ```