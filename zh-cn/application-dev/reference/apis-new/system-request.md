# @system.request    
system.request部件主要给应用提供上传下载文件的基础能力。  
> **说明**   
>本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import request from '@system.request';  
    
```  
    
## UploadResponse<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 9 开始废弃。建议使用ohos.request替代。  
 **系统能力:**  SystemCapability.MiscServices.Upload    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.Upload    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| code<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 9 开始废弃。<br>服务器返回的HTTP状态码。 |  
| data<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 9 开始废弃。<br>服务器返回的内容。根据返回头内容中的type决定该值的类型。 |  
| headers<sup>(deprecated)</sup> | Object | false | true | 从API version 3 开始支持，从API version 9 开始废弃。<br>服务器返回的返回头内容。 |  
    
## DownloadResponse<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Download    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.Download    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| token<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 9 开始废弃。<br>表示下载的token，获取下载状态的依据。 |  
    
## OnDownloadCompleteResponse<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Download    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.Download    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 9 开始废弃。<br>表示下载文件的uri。 |  
    
## RequestFile<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Upload    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.Upload    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| filename<sup>(deprecated)</sup> | string | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>multipart提交时，请求头中的文件名。 |  
| name<sup>(deprecated)</sup> | string | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>multipart提交时，表单项目的名称，缺省为file。 |  
| uri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 9 开始废弃。<br>文件的本地存储路径。 |  
| type<sup>(deprecated)</sup> | string | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>文件的内容类型，默认根据文件名或路径的后缀获取。 |  
    
## RequestData<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Upload    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.Upload    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 9 开始废弃。<br>表示form元素的名称。 |  
| value<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 9 开始废弃。<br>表示form元素的值。 |  
    
## UploadRequestOptions<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Upload    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.Upload    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| url<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 9 开始废弃。<br>上传服务器地址。 |  
| data<sup>(deprecated)</sup> | Array<RequestData> | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>请求的表单数据。 |  
| files<sup>(deprecated)</sup> | Array<RequestFile> | false | true | 从API version 3 开始支持，从API version 9 开始废弃。<br>待上传文件列表。请使用multipart/form-data进行提交。 |  
| header<sup>(deprecated)</sup> | Object | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>请求头。 |  
| method<sup>(deprecated)</sup> | string | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>请求方法：POST、PUT。缺省POST。 |  
| success<sup>(deprecated)</sup> | (data: UploadResponse) => void | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>接口调用成功的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: any, code: number) => void | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>接口调用失败的回调函数。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>接口调用结束的回调函数。 |  
    
## DownloadRequestOptions<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Download    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.Download    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| url<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 9 开始废弃。<br>资源地址。 |  
| filename<sup>(deprecated)</sup> | string | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>本次下载文件的名称。默认从本次请求或资源地址中获取。 |  
| header<sup>(deprecated)</sup> | string | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>请求头。 |  
| description<sup>(deprecated)</sup> | string | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>资源地址的下载描述，默认为文件名称。 |  
| success<sup>(deprecated)</sup> | (data: DownloadResponse) => void | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>接口调用成功的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: any, code: number) => void | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>接口调用失败的回调函数。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>接口调用结束的回调函数。 |  
    
## OnDownloadCompleteOptions<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Download    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.Download    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| token<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 9 开始废弃。<br>download接口返回的结果token。 |  
| success<sup>(deprecated)</sup> | (data: OnDownloadCompleteResponse) => void | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>接口调用成功的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: any, code: number) => void | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>接口调用失败的回调函数。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>接口调用结束的回调函数。 |  
    
## Request<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 9 开始废弃。    
### upload<sup>(deprecated)</sup>    
上传文件，无返回值。  
 **调用形式：**     
- static upload(options: UploadRequestOptions): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Upload    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | UploadRequestOptions | true | 上传的配置信息。 |  
    
 **示例代码：**   
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
  
    
### download<sup>(deprecated)</sup>    
下载文件，无返回值。  
 **调用形式：**     
- static download(options: DownloadRequestOptions): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Download    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | DownloadRequestOptions | true | 下载的配置信息。 |  
    
 **示例代码：**   
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
  
    
### onDownloadComplete<sup>(deprecated)</sup>    
获取下载任务状态，无返回值。  
 **调用形式：**     
- static onDownloadComplete(options: OnDownloadCompleteOptions): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Download    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | OnDownloadCompleteOptions | true | 监听下载任务的配置信息。 |  
    
 **示例代码：**   
```js    
 import request, { OnDownloadCompleteOptions } from '@system.request';  
 let onDownloadCompleteOptions: OnDownloadCompleteOptions = {  token: 'token-index',  success: (data:object) => {   console.info(' download success, code:' + JSON.stringify(data));  },  fail: (data:string, code:number) => {   console.info(' download fail data: ' + data + 'code: ' + code);  },  complete: () => {   console.info(' download complete');  } } request.onDownloadComplete(onDownloadCompleteOptions);    
```    
  
