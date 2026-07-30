# @system.request (上传下载)
<!--Kit: Basic Services Kit-->
<!--Subsystem: Request-->
<!--Owner: @huaxin05-->
<!--Designer: @hu-kai45-->
<!--Tester: @liuhaonan2-->
<!--Adviser: @fang-jinxu-->

system.request部件主要给应用提供上传下载文件的基础能力。

> **说明：**
> - 从API Version 9开始所有接口不再维护，推荐使用新接口[@ohos.request](js-apis-request.md)。
> 
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```js
import { Request } from '@kit.BasicServicesKit';
```

## request.upload<sup>(deprecated)</sup>

upload(options: UploadRequestOptions): void

上传文件，无返回值。

**系统能力**：SystemCapability.MiscServices.Upload

> **说明：**
>
> 从API version 3开始支持，从API version 9开始废弃。建议使用[request.uploadFile](js-apis-request.md#requestuploadfile9)替代。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | options | [UploadRequestOptions](#uploadrequestoptionsdeprecated) | 是 | 上传的配置信息。 |

**示例：**

  ```js
  import  { Request, UploadRequestOptions, UploadResponse } from '@kit.BasicServicesKit';

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
    success: (data: UploadResponse) => {
      console.info('Succeeded in uploading, code:' + JSON.stringify(data.code));
    },
    fail: (data: string, code: number) => {
      console.info('Failed to upload, data: ' + data + 'code: ' + code);
    },
    complete: () => {
      console.info('Upload complete');
    }
  }

  try {
    Request.upload(uploadRequestOptions);
    console.info('Start Upload');
  } catch (err) {
    console.error('Failed to upload, err:' + err);
  }
  ```


## UploadRequestOptions<sup>(deprecated)</sup>

**系统能力**：SystemCapability.MiscServices.Upload

> **说明：**
>
> 从API version 3开始支持，从API version 9开始废弃。建议使用[UploadConfig](js-apis-request.md#uploadconfig)替代。

  | 名称 | 类型 | 只读 | 可选 | 说明 |
  | -------- | -------- | -------- | -------- | -------- |
  | url | string | 否 | 否 | 上传服务器地址。 |
  | data | Array&lt;[RequestData](#requestdatadeprecated)&gt; | 否 | 是 | 请求的表单数据。 |
  | files | Array&lt;[RequestFile](#requestfiledeprecated)&gt; | 否 | 否 | 待上传文件列表。请使用multipart/form-data进行提交。 |
  | header | Object | 否 | 是 | 请求头。 |
  | method | string | 否 | 是 | 请求方法：POST、PUT。缺省POST。 |
  | success | (data: [UploadResponse](#uploadresponsedeprecated)) => void | 否 | 是 | 接口调用成功的回调函数。 |
  | fail | (data: any, code: number) => void | 否 | 是 | 接口调用失败的回调函数。返回响应头信息与HTTP状态码。|
  | complete | () => void | 否 | 是 | 接口调用结束的回调函数。 |



## UploadResponse<sup>(deprecated)</sup>

**系统能力**：SystemCapability.MiscServices.Upload

  | 名称 | 类型 | 只读 | 可选 | 说明 |
  | -------- | -------- | -------- | -------- | -------- |
  | code | number | 否 | 否 | 服务器返回的HTTP状态码。 |
  | data | string | 否 | 否 | 服务器返回的内容。根据响应头内容中的type决定该值的类型。 |
  | headers | Object | 否 | 否 | 服务器返回的响应头内容。 |


## RequestFile<sup>(deprecated)</sup>

**系统能力**：SystemCapability.MiscServices.Upload

  | 名称 | 类型 | 只读 | 可选 | 说明 |
  | -------- | -------- | -------- | -------- | -------- |
  | filename | string | 否 | 是 | multipart&nbsp;提交时，请求头中的文件名。 |
  | name | string | 否 | 是 | multipart&nbsp;提交时，表单项目的名称，缺省为file。 |
  | uri | string | 否 | 否 | 文件的本地存储路径。 |
  | type | string | 否 | 是 | 文件的内容类型，默认根据文件名或路径的后缀获取。 |


## RequestData<sup>(deprecated)</sup>

**系统能力**：SystemCapability.MiscServices.Upload

  | 名称 | 类型 | 只读 | 可选 | 说明 |
  | -------- | -------- | -------- | -------- | -------- |
  | name | string | 否 | 否 | 表示form&nbsp;元素的名称。 |
  | value | string | 否 | 否 | 表示form&nbsp;元素的值。 |



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
  import  { Request, DownloadResponse, DownloadRequestOptions } from '@kit.BasicServicesKit';

  let downloadRequestOptions: DownloadRequestOptions = {
    url: 'http://www.path.com',
    filename: 'requestSystemTest',
    header: "",
    description: 'this is requestSystem download response',
    success: (data: DownloadResponse) => {
      console.info('Succeeded in downloading, code:' + JSON.stringify(data));
    },
    fail: (data: string, code: number) => {
      console.info('Failed to download, data: ' + data + 'code: ' + code);
    },
    complete: () => {
      console.info('Download complete');
    }
  }

  try {
    Request.download(downloadRequestOptions);
    console.info('Start download');
  } catch (err) {
    console.error('Failed to download, err:' + err);
  }
  ```


## DownloadRequestOptions<sup>(deprecated)</sup>

**系统能力**：SystemCapability.MiscServices.Download

> **说明：**
>
> 从API version 3开始支持，从API version 9开始废弃。建议使用[UploadConfig](js-apis-request.md#uploadconfig)替代。

**参数：**
  | 名称 | 类型 | 只读 | 可选 | 说明 |
  | -------- | -------- | -------- | -------- | -------- |
  | url | string | 否 | 否 | 资源地址。 |
  | filename | string | 否 | 是 | 本次下载文件的名称。默认从本次请求或资源地址中获取。 |
  | header | Object | 否 | 是 | 请求头。 |
  | description | string | 否 | 是 | 资源地址的下载描述，默认为文件名称。 |
  | success | (data: [DownloadResponse](#downloadresponsedeprecated)) => void | 否 | 是 | 接口调用成功的回调函数。 |
  | fail | (data: any, code: number) => void | 否 | 是 | 接口调用失败的回调函数。返回响应头信息与HTTP状态码。 |
  | complete | () => void | 否 | 是 | 接口调用结束的回调函数。 |

## DownloadResponse<sup>(deprecated)</sup>

**系统能力**：SystemCapability.MiscServices.Download

  | 名称 | 类型 | 只读 | 可选 | 说明 |
  | -------- | -------- | -------- | -------- | -------- |
  | token | string | 否 | 否 | 表示下载的token，获取下载状态的依据。 |


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
  import  { Request, OnDownloadCompleteOptions, OnDownloadCompleteResponse } from '@kit.BasicServicesKit';

  let onDownloadCompleteOptions: OnDownloadCompleteOptions = {
    token: 'token-index',
    success: (data: OnDownloadCompleteResponse) => {
      console.info('Succeeded in downloading, uri:' + JSON.stringify(data.uri));
    },
    fail: (data: string, code: number) => {
      console.info('Failed to download, data: ' + data + 'code: ' + code);
    },
    complete: () => {
      console.info('Download complete');
    }
  }

  Request.onDownloadComplete(onDownloadCompleteOptions);
  ```


## OnDownloadCompleteOptions<sup>(deprecated)</sup>

**系统能力**：SystemCapability.MiscServices.Download

  | 名称 | 类型 | 只读 | 可选 | 说明 |
  | -------- | -------- | -------- | -------- | -------- |
  | token | string | 否 | 否 | download&nbsp;接口返回的结果&nbsp;token。 |
  | success | (data: [OnDownloadCompleteResponse](#ondownloadcompleteresponsedeprecated)) => void | 否 | 是 | 接口调用成功的回调函数。 |
  | fail | (data: any, code: number) => void | 否 | 是 | 接口调用失败的回调函数。返回响应头信息与HTTP状态码。 |
  | complete | () => void | 否 | 是 | 接口调用结束的回调函数。 |


## OnDownloadCompleteResponse<sup>(deprecated)</sup>

**系统能力**：SystemCapability.MiscServices.Download

  | 名称 | 类型 | 只读 | 可选 | 说明 |
  | -------- | -------- | -------- | -------- | -------- |
  | uri | string | 否 | 否 | 表示下载文件的uri。 |