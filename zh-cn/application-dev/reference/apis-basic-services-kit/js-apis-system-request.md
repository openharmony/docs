# @system.request (上传下载)

system.request部件主要给应用提供上传下载文件的基础能力。

> **说明：**
> - 从API Version 9开始所有接口不再维护，推荐使用新接口[`@ohos.request`](js-apis-request.md)。
> 
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```
import request from '@system.request';
```

## request.upload<sup>(deprecated)</sup>

upload(options: UploadRequestOptions): void

上传文件，无返回值。

**系统能力**：SystemCapability.MiscServices.Upload

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | options | [UploadRequestOptions](#uploadrequestoptionsdeprecated) | 是 | 上传的配置信息。 |

**示例：**

  ```js
  import request, { UploadRequestOptions } from '@system.request';

  let uploadRequestOptions: UploadRequestOptions = {
    url: 'http://www.path.com',
    method: 'POST',
    files: [{
      filename: "test",
      name: "test",
      uri: "internal://cache/test.jpg",
      type: "jpg"
    }],
    data: [{
      name: "name123",
      value: "123"
    }],
    success: (data: object) => {
      console.info(' upload success, code:' + JSON.stringify(data));
    },
    fail: (data:string, code:number) => {
      console.info(' upload fail data: ' + data + 'code: ' + code);
    },
    complete: () => {
      console.info(' upload complete');
    }
  }

  try {
    request.upload(uploadRequestOptions);
    console.info('upload start ');
  } catch (err) {
    console.info(' upload err:' + err);
  }
  ```


## UploadRequestOptions<sup>(deprecated)</sup>

**系统能力**：SystemCapability.MiscServices.Upload


  | 名称 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | url | string | 是 | 上传服务器地址。 |
  | data | Array&lt;[RequestData](#requestdatadeprecated)&gt; | 否 | 请求的表单数据。 |
  | files | Array&lt;[RequestFile](#requestfiledeprecated)&gt; | 是 | 待上传文件列表。请使用multipart/form-data进行提交。 |
  | header | Object | 否 | 请求头。 |
  | method | string | 否 | 请求方法：POST、PUT。缺省POST。 |
  | success | Function | 否 | 接口调用成功的回调函数。 |
  | fail | Function | 否 | 接口调用失败的回调函数。 |
  | complete | Function | 否 | 接口调用结束的回调函数。 |

**success参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | data | [UploadResponse](#uploadresponsedeprecated) | 是 | 上传任务成功返回信息。 |

**fail参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | data | any | 是 | 上传任务失败返回header信息。 |
  | code | number | 是 | 上传任务失败返回HTTP状态码。 |



## UploadResponse<sup>(deprecated)</sup>

**系统能力**：SystemCapability.MiscServices.Upload

  | 名称 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | code | number | 是 | 服务器返回的HTTP状态码。 |
  | data | string | 是 | 服务器返回的内容。根据返回头内容中的type决定该值的类型。 |
  | headers | Object | 是 | 服务器返回的返回头内容。 |


## RequestFile<sup>(deprecated)</sup>

**系统能力**：SystemCapability.MiscServices.Upload

  | 名称 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | filename | string | 否 | multipart&nbsp;提交时，请求头中的文件名。 |
  | name | string | 否 | multipart&nbsp;提交时，表单项目的名称，缺省为file。 |
  | uri | string | 是 | 文件的本地存储路径。 |
  | type | string | 否 | 文件的内容类型，默认根据文件名或路径的后缀获取。 |


## RequestData<sup>(deprecated)</sup>

**系统能力**：SystemCapability.MiscServices.Upload

  | 名称 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | name | string | 是 | 表示form&nbsp;元素的名称。 |
  | value | string | 是 | 表示form&nbsp;元素的值。 |



## request.download<sup>(deprecated)</sup>

download(options: DownloadRequestOptions): void

下载文件，无返回值。

**系统能力**：SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | options | [DownloadRequestOptions](#downloadrequestoptionsdeprecated) | 是 | 下载的配置信息。 |

**示例：**

  ```js
  import request, { DownloadRequestOptions } from '@system.request';

  let downloadRequestOptions: DownloadRequestOptions = {
    url: 'http://www.path.com',
    filename: 'requestSystenTest',
    header: "",
    description: 'this is requeSystem download response',
    success: (data:object) => {
      console.info(' download success, code:' + JSON.stringify(data));
    },
    fail: (data:string, code:number) => {
      console.info(' download fail data: ' + data + 'code: ' + code);
    },
    complete: () => {
      console.info(' download complete');
    }
  }

  try {
    request.download(downloadRequestOptions);
    console.info('download start ');
  } catch(err) {
    console.info(' download err:' + err);
  }
  ```


## DownloadRequestOptions<sup>(deprecated)</sup>

**系统能力**：SystemCapability.MiscServices.Download

  | 名称 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | url | string | 是 | 资源地址。 |
  | filename | string | 否 | 本次下载文件的名称。默认从本次请求或资源地址中获取。 |
  | header | Object | 否 | 请求头。 |
  | description | string | 否 | 资源地址的下载描述，默认为文件名称。 |
  | success | Function | 否 | 接口调用成功的回调函数。 |
  | fail | Function | 否 | 接口调用失败的回调函数。 |
  | complete | Function | 否 | 接口调用结束的回调函数。 |

**success参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | data | [DownloadResponse](#downloadresponsedeprecated) | 是 | 下载任务成功返回信息。 |

**fail参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | data | any | 是 | 下载任务失败返回header信息。 |
  | code | number | 是 | 下载任务失败返回HTTP状态码。 |

## DownloadResponse<sup>(deprecated)</sup>

**系统能力**：SystemCapability.MiscServices.Download

  | 名称 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | token | string | 是 | 表示下载的token，获取下载状态的依据。 |


## request.onDownloadComplete<sup>(deprecated)</sup>

onDownloadComplete(options: OnDownloadCompleteOptions): void

获取下载任务状态，无返回值。

**系统能力**：SystemCapability.MiscServices.Download

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | options | [OnDownloadCompleteOptions](#ondownloadcompleteoptionsdeprecated) | 是 | 监听下载任务的配置信息。 |

**示例：**

  ```js
  import request, { OnDownloadCompleteOptions } from '@system.request';

  let onDownloadCompleteOptions: OnDownloadCompleteOptions = {
    token: 'token-index',
    success: (data:object) => {
      console.info(' download success, code:' + JSON.stringify(data));
    },
    fail: (data:string, code:number) => {
      console.info(' download fail data: ' + data + 'code: ' + code);
    },
    complete: () => {
      console.info(' download complete');
    }
  }

  request.onDownloadComplete(onDownloadCompleteOptions);
  ```


## OnDownloadCompleteOptions<sup>(deprecated)</sup>

**系统能力**：SystemCapability.MiscServices.Download

  | 名称 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | token | string | 是 | download&nbsp;接口返回的结果&nbsp;token。 |
  | success | Function | 否 | 接口调用成功的回调函数。 |
  | fail | Function | 否 | 接口调用失败的回调函数。 |
  | complete | Function | 否 | 接口调用结束的回调函数。 |

**success参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | data | [OnDownloadCompleteResponse](#ondownloadcompleteresponsedeprecated) | 是 | 下载任务成功返回信息。 |

**fail参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | data | any | 是 | 下载任务失败返回header信息。 |
  | code | number | 是 | 下载任务失败返回HTTP状态码。 |


## OnDownloadCompleteResponse<sup>(deprecated)</sup>

**系统能力**：SystemCapability.MiscServices.Download

  | 名称 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 表示下载文件的uri。 |