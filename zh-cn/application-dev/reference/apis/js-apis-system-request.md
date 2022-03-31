# 上传下载

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 从API Version 6开始，该接口不再维护，推荐使用新接口[`@ohos.request`](js-apis-request.md)。
> 
> - 本模块首批接口从API version 4开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```
import request from '@system.request';
```

## 权限列表

ohos.permission.INTERNET。


## request.upload

upload(Object): void

上传文件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| url | string | 是 | 上传服务器地址。 |
| header | Object | 否 | 请求头。 |
| method | string | 否 | 请求方法：POST、PUT。缺省POST。 |
| files | Array&lt;File&gt; | 是 | 待上传文件列表。请使用multipart/form-data进行提交。 |
| data | Array&lt;RequestData&gt; | 否 | 请求的表单数据。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

**表1** File

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| filename | string | 否 | multipart&nbsp;提交时，请求头中的文件名。 |
| name | string | 否 | multipart&nbsp;提交时，表单项目的名称，缺省为file。 |
| uri | string | 是 | 文件的本地存储路径。 |
| type | string | 否 | 文件的内容类型，默认根据文件名或路径的后缀获取。 |

**表2** RequestData

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 表示form&nbsp;元素的名称。 |
| value | string | 是 | 表示form&nbsp;元素的值。 |

success返回值：

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| code | number | 服务器返回的HTTP状态码。 |
| data | string | 服务器返回的内容。根据返回头内容中的type决定该值的类型。 |
| headers | Object | 服务器返回的返回头内容。 |

fail返回值中的data中的code为HTTP状态码。

**示例：**

```
export default {    
  upLoad() {
    request.upload({
      url: 'http://www.path.com',
      files: [
        {
           uri: 'internal://cache/path/to/file.txt',
           name: 'file',
           filename: 'file.txt',
        },
      ],
      data:[
        {
          name: 'name1',
          value: 'value',
         },
       ],
       success: function(data) {
         console.log('upload success, code:' + data.code);
       },
       fail: function() {
         console.log('upload fail');
       },
     });
  }
}
```


## request.download

download(Object): void

下载文件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| url | string | 是 | 资源地址。 |
| header | Object | 否 | 请求头。 |
| description | string | 否 | 资源地址的下载描述，默认为文件名称。 |
| filename | string | 否 | 本次下载文件的名称。默认从本次请求或资源地址中获取。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

success返回值：

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| token | string | 表示下载的&nbsp;token，获取下载状态的依据。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 400 | 表示下载任务失败。 |

**示例：**

```
export default {    
  downLoad() {        
    request.download({            
      url: 'http://www.path.com',            
      success: function(data) {                
        console.log('call success callback success: ' + data.token);            
      },            
      fail: function(data, code) {                
        console.log('handling fail');            
      },        
    });    
  }
}
```


## request.onDownloadComplete

onDownloadComplete(Object): void

获取下载任务状态。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| token | string | 是 | download&nbsp;接口返回的结果&nbsp;token。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

success返回值：

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| uri | string | 表示下载文件的uri。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 400 | 表示下载任务失败。 |
| 401 | 表示不存在该下载任务。 |

**示例：**

```
export default {    
  onDownloadComplete() {        
    request.onDownloadComplete({            
      token: 'token-index',            
      success: function(data) {                
        console.log('download success, uri:' + data.uri);            
      },            
      fail: function(data, code) {                
        console.log('download fail');            
      },
    });    
  }
}
```