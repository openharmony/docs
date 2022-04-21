# Uploading and Downloading

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
> - The APIs of this module are no longer maintained since API version 6. It is recommended that you use [`@ohos.request`](js-apis-request.md) instead.
> 
> - The initial APIs of this module are supported since API version 4. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import request from '@system.request';
```

## Required Permissions

ohos.permission.INTERNET.


## request.upload

upload(Object): void

Uploads files.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| url | string | Yes | URL&nbsp;of&nbsp;the&nbsp;upload&nbsp;server. |
| header | Object | No | Request&nbsp;header. |
| method | string | No | Request&nbsp;methods&nbsp;available:&nbsp;**POST**&nbsp;and&nbsp;**PUT**.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**POST**. |
| files | Array&lt;File&gt; | Yes | List&nbsp;of&nbsp;files&nbsp;to&nbsp;upload,&nbsp;which&nbsp;is&nbsp;submitted&nbsp;through&nbsp;**multipart/form-data**. |
| data | Array&lt;RequestData&gt; | No | Form&nbsp;data&nbsp;in&nbsp;the&nbsp;request&nbsp;body. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;download&nbsp;task&nbsp;is&nbsp;complete. |
| fail | Function | No | Called&nbsp;when&nbsp;downloading&nbsp;fails&nbsp;or&nbsp;the&nbsp;task&nbsp;does&nbsp;not&nbsp;exist. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

**Table 1** File

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| filename | string | No | File&nbsp;name&nbsp;in&nbsp;the&nbsp;header&nbsp;when&nbsp;**multipart**&nbsp;is&nbsp;used. |
| name | string | No | Name&nbsp;of&nbsp;a&nbsp;form&nbsp;item&nbsp;when&nbsp;**multipart**&nbsp;is&nbsp;used.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**file**. |
| uri | string | Yes | Local&nbsp;storage&nbsp;path&nbsp;of&nbsp;a&nbsp;file. |
| type | string | No | Type&nbsp;of&nbsp;the&nbsp;file&nbsp;content.&nbsp;By&nbsp;default,&nbsp;the&nbsp;type&nbsp;is&nbsp;obtained&nbsp;based&nbsp;on&nbsp;the&nbsp;suffix&nbsp;of&nbsp;the&nbsp;file&nbsp;name&nbsp;or&nbsp;URI. |

**Table 2** RequestData

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| name | string | Yes | Name&nbsp;of&nbsp;the&nbsp;form&nbsp;element |
| value | string | Yes | Value&nbsp;of&nbsp;the&nbsp;form&nbsp;element |

When the files are successfully uploaded, the following values will be returned.

| Name | Type | Description |
| -------- | -------- | -------- |
| code | number | HTTP&nbsp;status&nbsp;code&nbsp;returned&nbsp;by&nbsp;the&nbsp;server. |
| data | string | Content&nbsp;returned&nbsp;by&nbsp;the&nbsp;server.&nbsp;The&nbsp;value&nbsp;type&nbsp;is&nbsp;determined&nbsp;by&nbsp;the&nbsp;type&nbsp;in&nbsp;the&nbsp;returned&nbsp;headers. |
| headers | Object | Headers&nbsp;returned&nbsp;by&nbsp;the&nbsp;server. |

When the files fail to be uploaded, an HTTP status code is returned in **code** of **data**.

**Example**

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

Downloads files.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| url | string | Yes | Resource&nbsp;URL. |
| header | Object | No | Request&nbsp;header. |
| description | string | No | Download&nbsp;description.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;the&nbsp;file&nbsp;name. |
| filename | string | No | Name&nbsp;of&nbsp;the&nbsp;file&nbsp;to&nbsp;download.&nbsp;The&nbsp;value&nbsp;is&nbsp;obtained&nbsp;from&nbsp;the&nbsp;current&nbsp;request&nbsp;or&nbsp;resource&nbsp;URL&nbsp;by&nbsp;default. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;download&nbsp;task&nbsp;is&nbsp;complete. |
| fail | Function | No | Called&nbsp;when&nbsp;downloading&nbsp;fails&nbsp;or&nbsp;the&nbsp;task&nbsp;does&nbsp;not&nbsp;exist. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

Return values of the **success** callback

| Name | Type | Description |
| -------- | -------- | -------- |
| token | string | Download&nbsp;token,&nbsp;which&nbsp;is&nbsp;used&nbsp;to&nbsp;obtain&nbsp;the&nbsp;download&nbsp;status. |

One of the following error codes will be returned if the operation fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 400 | Download&nbsp;task&nbsp;failed |

**Example**

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

Listens to download task status.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| token | string | Yes | Token&nbsp;of&nbsp;the&nbsp;result&nbsp;returned&nbsp;by&nbsp;the&nbsp;download&nbsp;method |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;download&nbsp;task&nbsp;is&nbsp;complete. |
| fail | Function | No | Called&nbsp;when&nbsp;downloading&nbsp;fails&nbsp;or&nbsp;the&nbsp;task&nbsp;does&nbsp;not&nbsp;exist. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

Return values of the **success** callback

| Name | Type | Description |
| -------- | -------- | -------- |
| uri | string | URI&nbsp;of&nbsp;the&nbsp;download&nbsp;file |

One of the following error codes will be returned if the listening fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 400 | Download&nbsp;task&nbsp;failed |
| 401 | Download&nbsp;task&nbsp;not&nbsp;exist |

**Example**

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