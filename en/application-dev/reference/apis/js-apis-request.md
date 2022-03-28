# Upload and Download


> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import request from '@ohos.request';
```


## Constraints

- HTTPS is supported by default. To support HTTP, you need to add **network** to the **config.json** file and set the **cleartextTraffic** attribute to **true**.
  
  ```
    "deviceConfig": {
      "default": {
        "network": {
          "cleartextTraffic": true
        }
        ...
      }
    }
  ```


## Constants

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| NETWORK_MOBILE | number | Yes | No | Whether&nbsp;download&nbsp;is&nbsp;allowed&nbsp;when&nbsp;the&nbsp;cellular&nbsp;network&nbsp;is&nbsp;used. |
| NETWORK_WIFI | number | Yes | No | Whether&nbsp;download&nbsp;is&nbsp;allowed&nbsp;when&nbsp;the&nbsp;WLAN&nbsp;is&nbsp;used. |
| ERROR_CANNOT_RESUME<sup>7+</sup> | number | Yes | No | Failure&nbsp;to&nbsp;resume&nbsp;the&nbsp;download&nbsp;due&nbsp;to&nbsp;an&nbsp;error. |
| ERROR_DEVICE_NOT_FOUND<sup>7+</sup> | number | Yes | No | Failure&nbsp;to&nbsp;find&nbsp;a&nbsp;storage&nbsp;device&nbsp;such&nbsp;as&nbsp;an&nbsp;SD&nbsp;card. |
| ERROR_FILE_ALREADY_EXISTS<sup>7+</sup> | number | Yes | No | Failure&nbsp;to&nbsp;download&nbsp;the&nbsp;file&nbsp;because&nbsp;it&nbsp;already&nbsp;exists. |
| ERROR_FILE_ERROR<sup>7+</sup> | number | Yes | No | File&nbsp;operation&nbsp;failure. |
| ERROR_HTTP_DATA_ERROR<sup>7+</sup> | number | Yes | No | HTTP&nbsp;transmission&nbsp;failure. |
| ERROR_INSUFFICIENT_SPACE<sup>7+</sup> | number | Yes | No | Insufficient&nbsp;storage&nbsp;space. |
| ERROR_TOO_MANY_REDIRECTS<sup>7+</sup> | number | Yes | No | Error&nbsp;caused&nbsp;by&nbsp;too&nbsp;many&nbsp;network&nbsp;redirections. |
| ERROR_UNHANDLED_HTTP_CODE<sup>7+</sup> | number | Yes | No | Unidentified&nbsp;HTTP&nbsp;code. |
| ERROR_UNKNOWN<sup>7+</sup> | number | Yes | No | Unknown&nbsp;error. |
| PAUSED_QUEUED_FOR_WIFI<sup>7+</sup> | number | Yes | No | Download&nbsp;paused&nbsp;and&nbsp;queuing&nbsp;for&nbsp;WLAN&nbsp;connection,&nbsp;because&nbsp;the&nbsp;file&nbsp;size&nbsp;exceeds&nbsp;the&nbsp;maximum&nbsp;value&nbsp;allowed&nbsp;by&nbsp;a&nbsp;cellular&nbsp;network&nbsp;session. |
| PAUSED_UNKNOWN<sup>7+</sup> | number | Yes | No | Download&nbsp;paused&nbsp;due&nbsp;to&nbsp;unknown&nbsp;reasons. |
| PAUSED_WAITING_FOR_NETWORK<sup>7+</sup> | number | Yes | No | Download&nbsp;paused&nbsp;due&nbsp;to&nbsp;a&nbsp;network&nbsp;connection&nbsp;problem,&nbsp;for&nbsp;example,&nbsp;network&nbsp;disconnection. |
| PAUSED_WAITING_TO_RETRY<sup>7+</sup> | number | Yes | No | Download&nbsp;paused&nbsp;and&nbsp;then&nbsp;retried. |
| SESSION_FAILED<sup>7+</sup> | number | Yes | No | Download&nbsp;failure&nbsp;without&nbsp;retry. |
| SESSION_PAUSED<sup>7+</sup> | number | Yes | No | Download&nbsp;paused. |
| SESSION_PENDING<sup>7+</sup> | number | Yes | No | Download&nbsp;pending. |
| SESSION_RUNNING<sup>7+</sup> | number | Yes | No | Download&nbsp;in&nbsp;progress. |
| SESSION_SUCCESSFUL<sup>7+</sup> | number | Yes | No | Successful&nbsp;download. |


## request.upload

upload(config: UploadConfig): Promise&lt;UploadTask&gt;

Uploads files. This method uses a promise to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Upload

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | config | [UploadConfig](#uploadconfig) | Yes | Configurations&nbsp;of&nbsp;the&nbsp;upload. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;[UploadTask](#uploadtask)&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;**UploadTask**&nbsp;object. |

- Example
  
  ```
  request.upload({ url: 'https://patch' }).then((data) => {
      uploadTask = data;
  }).catch((err) => {
      console.error('Failed to request the upload. Cause: ' + JSON.stringify(err));
  })
  ```


## request.upload

upload(config: UploadConfig, callback: AsyncCallback&lt;UploadTask&gt;): void

Uploads files. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Upload

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | config | [UploadConfig](#uploadconfig) | Yes | Configurations&nbsp;of&nbsp;the&nbsp;upload. |
  | callback | AsyncCallback&lt;[UploadTask](#uploadtask)&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;**UploadTask**&nbsp;object. |

- Example
  
  ```
  request.upload({ url: 'https://patch' }, (err, data) => {
      if (err) {
          console.error('Failed to request the upload. Cause: ' + JSON.stringify(err));
          return;
      }
      uploadTask = data;
  });
  ```


## UploadTask

Implements file uploads. Before using a method of this class, you must obtain an **UploadTask** object.


### on('progress')

on(type: 'progress', callback:(uploadedSize: number, totalSize: number) =&gt; void): void

Subscribes to the upload progress event. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Upload

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Type&nbsp;of&nbsp;the&nbsp;event&nbsp;to&nbsp;subscribe&nbsp;to.&nbsp;The&nbsp;value&nbsp;is&nbsp;**progress**&nbsp;(upload&nbsp;progress). |
  | callback | function | Yes | Callback&nbsp;for&nbsp;the&nbsp;upload&nbsp;progress&nbsp;event. |

  Parameters of the callback function

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | uploadedSize | number | Yes | Size&nbsp;of&nbsp;the&nbsp;uploaded&nbsp;files,&nbsp;in&nbsp;KB. |
  | totalSize | number | Yes | Total&nbsp;size&nbsp;of&nbsp;the&nbsp;files&nbsp;to&nbsp;upload,&nbsp;in&nbsp;KB. |

- Example
  
  ```
  uploadTask.on('progress', function callback(uploadedSize, totalSize) {
      console.info("upload totalSize:" + totalSize + "  uploadedSize:" + uploadedSize);
  }
  );
  ```


### on('headerReceive')<sup>7+</sup>

on(type: 'headerReceive', callback:  (header: object) =&gt; void): void

Subscribes to the **headerReceive** event, which is triggered when an HTTP response header is received. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Upload

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Type&nbsp;of&nbsp;the&nbsp;event&nbsp;to&nbsp;subscribe&nbsp;to.&nbsp;The&nbsp;value&nbsp;is&nbsp;**headerReceive**&nbsp;(response&nbsp;header). |
  | callback | function | Yes | Callback&nbsp;for&nbsp;the&nbsp;HTTP&nbsp;Response&nbsp;Header&nbsp;event. |

  Parameters of the callback function

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | header | object | Yes | HTTP&nbsp;Response&nbsp;Header. |

- Example
  
  ```
  uploadTask.on('headerReceive', function callback(headers){   
      console.info("upOnHeader headers:" + JSON.stringify(headers));
  }
  );
  ```


### off('progress')

off(type:  'progress',  callback?: (uploadedSize: number, totalSize: number) =&gt;  void): void

Unsubscribes from the upload progress event. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Upload

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Type&nbsp;of&nbsp;the&nbsp;event&nbsp;to&nbsp;unsubscribe&nbsp;from.&nbsp;The&nbsp;value&nbsp;is&nbsp;**progress**&nbsp;(upload&nbsp;progress). |
  | callback | function | No | Callback&nbsp;for&nbsp;the&nbsp;upload&nbsp;progress&nbsp;event. |

  Parameters of the callback function

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | uploadedSize | number | Yes | Size&nbsp;of&nbsp;the&nbsp;uploaded&nbsp;files,&nbsp;in&nbsp;KB. |
  | totalSize | number | Yes | Total&nbsp;size&nbsp;of&nbsp;the&nbsp;files&nbsp;to&nbsp;upload,&nbsp;in&nbsp;KB. |

- Example
  
  ```
  uploadTask.off('progress', function callback(uploadedSize, totalSize) {
      console.info('uploadedSize: ' + uploadedSize, 'totalSize: ' + totalSize);
  }
  );
  ```


### off('headerReceive')<sup>7+</sup>

off(type: 'headerReceive', callback?: (header: object) =&gt; void): void

Unsubscribes from the **headerReceive** event. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Upload

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Type&nbsp;of&nbsp;the&nbsp;event&nbsp;to&nbsp;unsubscribe&nbsp;from.&nbsp;The&nbsp;value&nbsp;is&nbsp;**headerReceive**&nbsp;(response&nbsp;header). |
  | callback | function | No | Callback&nbsp;for&nbsp;the&nbsp;HTTP&nbsp;Response&nbsp;Header&nbsp;event. |

  Parameters of the callback function

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | header | object | Yes | HTTP&nbsp;Response&nbsp;Header. |

- Example
  
  ```
  uploadTask.off('headerReceive', function callback(headers) {
      console.info("upOnHeader headers:" + JSON.stringify(headers));
  }
  );
  ```


### remove

remove(): Promise&lt;boolean&gt;

Removes this upload task. This method uses a promise to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Upload

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;task&nbsp;removal&nbsp;result.&nbsp;If&nbsp;**true**&nbsp;is&nbsp;returned,&nbsp;the&nbsp;task&nbsp;is&nbsp;removed.&nbsp;If&nbsp;**false**&nbsp;is&nbsp;returned,&nbsp;the&nbsp;task&nbsp;fails&nbsp;to&nbsp;be&nbsp;removed. |

- Example
  
  ```
  uploadTask.remove().then((result) => {
      if (result) {
          console.info('Upload task removed successfully. ');
      } else {
          console.error('Failed to remove the upload task. ');
      }
  }).catch((err) => {
      console.error('Failed to remove the upload task. Cause: ' + JSON.stringify(err));
  });
  ```


### remove

remove(callback: AsyncCallback&lt;boolean&gt;): void

Removes this upload task. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Upload

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |

- Example
  
  ```
  uploadTask.remove((err, result) => {
      if (err) {
          console.error('Failed to remove the upload task. Cause: ' + JSON.stringify(err));
          return;
      }
      if (result) {
          console.info('Upload task removed successfully.');
      } else {
          console.error('Failed to remove the upload task.');
      }
  });
  ```


## UploadConfig

**System capability**: SystemCapability.MiscServices.Upload

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| url | string | Yes | Resource&nbsp;URL. |
| header | object | No | HTTP&nbsp;or&nbsp;HTTPS&nbsp;header&nbsp;added&nbsp;to&nbsp;an&nbsp;upload&nbsp;request. |
| method | string | No | Request&nbsp;methods&nbsp;available:&nbsp;**POST**&nbsp;and&nbsp;**PUT**.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**POST**. |
| files | Array&lt;[File](#file)&gt; | Yes | List&nbsp;of&nbsp;files&nbsp;to&nbsp;upload,&nbsp;which&nbsp;is&nbsp;submitted&nbsp;through&nbsp;**multipart/form-data**. |
| data | Array&lt;[RequestData](#requestdata)&gt; | No | Form&nbsp;data&nbsp;in&nbsp;the&nbsp;request&nbsp;body. |


## File

**System capability**: SystemCapability.MiscServices.Upload

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| filename | string | No | File&nbsp;name&nbsp;in&nbsp;the&nbsp;header&nbsp;when&nbsp;**multipart**&nbsp;is&nbsp;used. |
| name | string | No | Name&nbsp;of&nbsp;a&nbsp;form&nbsp;item&nbsp;when&nbsp;**multipart**&nbsp;is&nbsp;used.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**file**. |
| uri | string | Yes | Local&nbsp;path&nbsp;for&nbsp;storing&nbsp;files.<br/>The&nbsp;**dataability**&nbsp;and&nbsp;**internal**&nbsp;protocol&nbsp;types&nbsp;are&nbsp;supported.&nbsp;However,&nbsp;the&nbsp;**internal**&nbsp;protocol&nbsp;type&nbsp;supports&nbsp;only&nbsp;temporary&nbsp;directories.&nbsp;The&nbsp;following&nbsp;is&nbsp;an&nbsp;example:<br/>dataability:///com.domainname.dataability.persondata/person/10/file.txt<br/>internal://cache/path/to/file.txt |
| type | string | No | Type&nbsp;of&nbsp;the&nbsp;file&nbsp;content.&nbsp;By&nbsp;default,&nbsp;the&nbsp;type&nbsp;is&nbsp;obtained&nbsp;based&nbsp;on&nbsp;the&nbsp;extension&nbsp;of&nbsp;the&nbsp;file&nbsp;name&nbsp;or&nbsp;URI. |


## RequestData

**System capability**: SystemCapability.MiscServices.Upload

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| name | string | Yes | Name&nbsp;of&nbsp;a&nbsp;form&nbsp;element. |
| value | string | Yes | Value&nbsp;of&nbsp;a&nbsp;form&nbsp;element. |


## request.download

download(config: DownloadConfig): Promise&lt;DownloadTask&gt;

Downloads files. This method uses a promise to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | config | [DownloadConfig](#downloadconfig) | Yes | Configurations&nbsp;of&nbsp;the&nbsp;download. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;[DownloadTask](#downloadtask)&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |

- Example
  
  ```
  request.download({ url: 'https://xxxx/xxxx.hap' }).then((data) => {
      downloadTask = data;
  }).catch((err) => {
      console.error('Failed to request the download. Cause: ' + JSON.stringify(err));
  })
  ```


## request.download

download(config: DownloadConfig, callback: AsyncCallback&lt;DownloadTask&gt;): void

Downloads files. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | config | [DownloadConfig](#downloadconfig) | Yes | Configurations&nbsp;of&nbsp;the&nbsp;download. |
  | callback | AsyncCallback&lt;[DownloadTask](#downloadtask)&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |

- Example
  
  ```
  request.download({ url: 'https://xxxx/xxxxx.hap', 
  filePath: 'xxx/xxxxx.hap'}, (err, data) => {
      if (err) {
          console.error('Failed to request the download. Cause: ' + JSON.stringify(err));
          return;
      }
      downloadTask = data;
  });
  ```


## DownloadTask

Implements file downloads.


### on('progress')

on(type: 'progress', callback:(receivedSize: number, totalSize: number) =&gt; void): void

Subscribes to the download progress event. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Type&nbsp;of&nbsp;the&nbsp;event&nbsp;to&nbsp;subscribe&nbsp;to.&nbsp;The&nbsp;value&nbsp;is&nbsp;**progress**&nbsp;(download&nbsp;progress). |
  | callback | function | Yes | Callback&nbsp;for&nbsp;the&nbsp;download&nbsp;progress&nbsp;event. |

  Parameters of the callback function

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | receivedSize | number | Yes | Size&nbsp;of&nbsp;the&nbsp;downloaded&nbsp;files,&nbsp;in&nbsp;KB. |
  | totalSize | number | Yes | Total&nbsp;size&nbsp;of&nbsp;the&nbsp;files&nbsp;to&nbsp;download,&nbsp;in&nbsp;KB. |

- Example
  
  ```
  request.download({ url: 'https://xxxx/xxxx.hap' }, (err, data)=> {    
      if (err) {        
          console.error('Failed to request download. Cause:' + err);
          return;
      }    
      downloadTask = data;    
      downloadTask.on('progress', function download_callback(receivedSize, totalSize) {
      console.info("download receivedSize:" + receivedSize + " totalSize:" + totalSize);
  }
  );
  });
  ```


### off('progress')

off(type: 'progress', callback?: (receivedSize: number, totalSize: number) =&gt; void): void

Unsubscribes from the download progress event. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Type&nbsp;of&nbsp;the&nbsp;event&nbsp;to&nbsp;unsubscribe&nbsp;from.&nbsp;The&nbsp;value&nbsp;is&nbsp;**progress**&nbsp;(download&nbsp;progress). |
  | callback | function | No | Callback&nbsp;for&nbsp;the&nbsp;download&nbsp;progress&nbsp;event. |

  Parameters of the callback function

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | receivedSize | number | Yes | Size&nbsp;of&nbsp;the&nbsp;downloaded&nbsp;files,&nbsp;in&nbsp;KB. |
  | totalSize | number | Yes | Total&nbsp;size&nbsp;of&nbsp;the&nbsp;files&nbsp;to&nbsp;download,&nbsp;in&nbsp;KB. |

- Example
  
  ```
  request.download({ url: 'https://xxxx/xxxx.hap' }, (err, data)=> {    
      if (err) {        
          console.error('Failed to request download. Cause:' + err);
          return;
      }
      downloadTask = data;    
      downloadTask .off('progress', function download_callback(receivedSize, totalSize) {
          console.info("download receivedSize:" + receivedSize + " totalSize:" + totalSize);
      }
  );
  });
  ```


### on('complete'|'pause'|'remove')<sup>7+</sup>

on(type: 'complete'|'pause'|'remove', callback:() =&gt; void): void

Subscribes to a download event. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Event&nbsp;type.<br/>-&nbsp;**complete**:&nbsp;download&nbsp;task&nbsp;completion&nbsp;event.<br/>-&nbsp;**pause**:&nbsp;download&nbsp;task&nbsp;pause&nbsp;event.<br/>-&nbsp;**remove**:&nbsp;download&nbsp;task&nbsp;removal&nbsp;event. |
  | callback | function | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |

- Example
  
  ```
  request.download({ url: 'https://xxxx/xxxx.hap' }, (err, data)=> {    
      if (err) {        
          console.error('Failed to request download. Cause:' + err);
          return;   
      }    
      downloadTask= data;    
      downloadTask.on('complete', function callback() {
          console.info('Download task completed.');
      }
  );
  });
  ```


### off('complete'|'pause'|'remove')<sup>7+</sup>

off(type: 'complete'|'pause'|'remove', callback?:() =&gt; void): void

Unsubscribes from the download event. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Event&nbsp;type.<br/>-&nbsp;**complete**:&nbsp;download&nbsp;task&nbsp;completion&nbsp;event.<br/>-&nbsp;**pause**:&nbsp;download&nbsp;task&nbsp;pause&nbsp;event.<br/>-&nbsp;**remove**:&nbsp;download&nbsp;task&nbsp;removal&nbsp;event. |
  | callback | function | No | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |

- Example
  
  ```
  request.download({ url: 'https://xxxx/xxxx.hap' }, (err, data)=> {    
      if (err) {        
          console.error('Failed to request download. Cause:' + JSON.stringify(err));
          return;
     }    
      downloadTask = data;
      downloadTask.off('complete', function callback() {
          console.info('Download task completed.');
      }
  );
  }); 
  ```


### on('fail')<sup>7+</sup>

on(type: 'fail', callback: (err: number) =&gt; void): void

Subscribes to the download task failure event. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Type&nbsp;of&nbsp;the&nbsp;subscribed&nbsp;event.&nbsp;The&nbsp;value&nbsp;is&nbsp;**fail**&nbsp;(download&nbsp;failure). |
  | callback | function | Yes | Callback&nbsp;for&nbsp;the&nbsp;download&nbsp;task&nbsp;failure&nbsp;event. |

  Parameters of the callback function

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | err | number | Yes | Error&nbsp;code&nbsp;of&nbsp;the&nbsp;download&nbsp;failure.&nbsp;For&nbsp;details&nbsp;about&nbsp;the&nbsp;error&nbsp;cause,&nbsp;see&nbsp;[ERROR_*](#constants). |

- Example
  
  ```
  request.download({ url: 'https://xxxx/xxxx.hap' }, (err, data)=> {    
      if (err) {        
          console.error('Failed to request download. Cause:' + err);
          return;
      }    
      downloadTask = data;    
      downloadTask.on('fail', function callBack(err) {
          console.info('Download task failed. Cause:' + err);
      }
  );
  });
  ```


### off('fail')<sup>7+</sup>

off(type: 'fail', callback?: (err: number) =&gt; void): void

Unsubscribes from the download task failure event. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Type&nbsp;of&nbsp;the&nbsp;event&nbsp;to&nbsp;unsubscribe&nbsp;from.&nbsp;The&nbsp;value&nbsp;is&nbsp;**fail**&nbsp;(download&nbsp;failure). |
  | callback | function | No | Callback&nbsp;for&nbsp;the&nbsp;download&nbsp;task&nbsp;failure&nbsp;event. |

  Parameters of the callback function

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | err | number | Yes | Error&nbsp;code&nbsp;of&nbsp;the&nbsp;download&nbsp;failure.&nbsp;For&nbsp;details&nbsp;about&nbsp;the&nbsp;error&nbsp;cause,&nbsp;see&nbsp;[ERROR_*](#constants). |

- Example
  
  ```
  request.download({ url: 'https://xxxx/xxxx.hap' }, (err, data)=> {    
      if (err) {        
          console.error('Failed to request download. Cause:' + err);
          return;
      }    
      downloadTask = data;       
      downloadTask.off('fail', function callBack(err) {
          console.info('Download task failed. Cause:' + err);
      } 
  );
  });
  ```


### remove

remove(): Promise&lt;boolean&gt;

Removes this download task. This method uses a promise to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;task&nbsp;removal&nbsp;result. |

- Example
  
  ```
  downloadTask.remove().then((result) => {
      if (result) {
          console.info('Download task removed.');
      } else {
          console.error('Failed to remove the download task.');
      }
  }).catch ((err) => {
      console.error('Failed to remove the download task.');
  });
  ```


### remove

remove(callback: AsyncCallback&lt;boolean&gt;): void

Removes this download task. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;task&nbsp;removal&nbsp;result. |

- Example
  
  ```
  downloadTask.remove((err, result)=>{
      if(err) {
          console.error('Failed to remove the download task.');
          return;
      } 
      if (result) {
          console.info('Download task removed.');
      } else {
          console.error('Failed to remove the download task.');
      } 
  });
  ```


### query<sup>7+</sup>

query(): Promise&lt;DownloadInfo&gt;

Queries this download task. This method uses a promise to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Parameters
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;[DownloadInfo](#downloadinfo7)&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;download&nbsp;task&nbsp;information. |

- Example
  
  ```
  downloadTask.query().then((downloadInfo) => {    
      console.info('Download task queried. Data:' + JSON.stringify(downloadInfo))
  }) .catch((err) => {
      console.error('Failed to query the download task. Cause:' + err)
  });
  ```


### query<sup>7+</sup>

query(callback: AsyncCallback&lt;DownloadInfo&gt;): void

Queries this download task. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[DownloadInfo](#downloadinfo7)&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;download&nbsp;task&nbsp;information. |

- Example
  
  ```
  downloadTask.query((err, downloadInfo)=>{
      if(err) {
          console.error('Failed to query the download mimeType. Cause:' + JSON.stringify(err));
      } else {
          console.info('download query success. data:'+ JSON.stringify(downloadInfo));
      }
  });
  ```


### queryMimeType<sup>7+</sup>

queryMimeType(): Promise&lt;string&gt;

Queries **MimeType** of this download task. This method uses a promise to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;string&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;**MimeType**&nbsp;of&nbsp;the&nbsp;download&nbsp;task. |

- Example
  
  ```
  downloadTask.queryMimeType().then((data) => {    
      console.info('Download task queried. Data:' + JSON.stringify(data));
  }).catch((err) => {
      console.error('Failed to query the download MimeType. Cause:' + JSON.stringify(err))
  });
  ```


### queryMimeType<sup>7+</sup>

queryMimeType(callback: AsyncCallback&lt;string&gt;): void;

Queries **MimeType** of this download task. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;string&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;**MimeType**&nbsp;of&nbsp;the&nbsp;download&nbsp;task. |

- Example
  
  ```
  downloadTask.queryMimeType((err, data)=>{
      if(err) {
          console.error('Failed to query the download mimeType. Cause:' + JSON.stringify(err));
      } else {
          console.info('Download task queried. data:' + JSON.stringify(data));
      }
  });
  ```


### pause<sup>7+</sup>

pause(): Promise&lt;void&gt;

Pauses this download task. This method uses a promise to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;download&nbsp;task&nbsp;pause&nbsp;result. |

- Example
  
  ```
  downloadTask.pause().then((result) => {    
      if (result) {
           console.info('Download task paused. ');
      } else {
          console.error('Failed to pause the download task. Cause:' + JSON.stringify(result));
      }
  }).catch((err) => {
      console.error('Failed to pause the download task. Cause:' + JSON.stringify(err));
  });
  ```


### pause<sup>7+</sup>

pause(callback: AsyncCallback&lt;void&gt;): void

Pauses this download task. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |

- Example
  
  ```
  downloadTask.pause((err, result)=>{
      if(err) {
          console.error('Failed to pause the download task. Cause:' + JSON.stringify(err));
          return;
      }
      if (result) {
           console.info('Download task paused. ');
      } else {
          console.error('Failed to pause the download task. Cause:' + JSON.stringify(result));
      }
  });
  ```


### resume<sup>7+</sup>

resume(): Promise&lt;void&gt;

Resumes this download task. This method uses a promise to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Parameters
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |

- Example
  
  ```
  downloadTask.resume().then((result) => {
      if (result) {
          console.info('Download task resumed.')
      } else {
          console.error('Failed to resume the download task. ');
      }
      console.info('Download task resumed.')
  }).catch((err) => {
      console.error('Failed to resume the download task. Cause:' + err);
  });
  ```


### resume<sup>7+</sup>

resume(callback: AsyncCallback&lt;void&gt;): void

Resumes this download task. This method uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |

- Example
  
  ```
  downloadTask.resume((err, result)=>{
      if (err) {
          console.error('Failed to resume the download task. Cause:' + err);
          return;
      } 
      if (result) {
          console.info('Download task resumed.');
      } else {
          console.error('Failed to resume the download task.');
      }
  });
  ```


## DownloadConfig

**System capability**: SystemCapability.MiscServices.Download

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| url | string | Yes | Resource&nbsp;URL. |
| header | object | No | HTTP&nbsp;or&nbsp;HTTPS&nbsp;header&nbsp;added&nbsp;to&nbsp;a&nbsp;download&nbsp;request. |
| enableMetered | boolean | No | Download&nbsp;allowed&nbsp;in&nbsp;metered&nbsp;connections. |
| enableRoaming | boolean | No | Download&nbsp;allowed&nbsp;on&nbsp;a&nbsp;roaming&nbsp;network. |
| description | string | No | Description&nbsp;of&nbsp;the&nbsp;download&nbsp;session. |
| filePath<sup>7+</sup> | string | No | Download&nbsp;path.&nbsp;(The&nbsp;default&nbsp;path&nbsp;is&nbsp;[ERROR:Invalid&nbsp;link:en-us_topic_0000001135742582.xml#xref8132147102215,link:en-us_topic_0000001127125012.xml#section1856519365229](en-us_topic_0000001127125012.xml#section1856519365229)).<br/>-&nbsp;filePath:'workspace/test.txt':&nbsp;The&nbsp;**workspace**&nbsp;directory&nbsp;is&nbsp;created&nbsp;in&nbsp;the&nbsp;default&nbsp;path&nbsp;to&nbsp;store&nbsp;files.<br/>-&nbsp;filePath:'test.txt':&nbsp;Files&nbsp;are&nbsp;stored&nbsp;in&nbsp;the&nbsp;default&nbsp;path.<br/>-&nbsp;filePath:'workspace/':&nbsp;The&nbsp;**workspace**&nbsp;directory&nbsp;is&nbsp;created&nbsp;in&nbsp;the&nbsp;default&nbsp;path&nbsp;to&nbsp;store&nbsp;files. |
| networkType | number | No | Network&nbsp;type&nbsp;allowed&nbsp;for&nbsp;download. |
| title | string | No | Title&nbsp;of&nbsp;the&nbsp;download&nbsp;session. |


## DownloadInfo<sup>7+</sup>

**System capability**: SystemCapability.MiscServices.Download

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| downloadId | number | Yes | ID&nbsp;of&nbsp;the&nbsp;downloaded&nbsp;file. |
| failedReason | number | No | Download&nbsp;failure&nbsp;cause,&nbsp;which&nbsp;can&nbsp;be&nbsp;any&nbsp;constant&nbsp;of&nbsp;[ERROR_*](#constants). |
| fileName | string | Yes | Name&nbsp;of&nbsp;the&nbsp;downloaded&nbsp;file. |
| filePath | string | Yes | URI&nbsp;of&nbsp;the&nbsp;saved&nbsp;file. |
| pausedReason | number | No | Reason&nbsp;for&nbsp;session&nbsp;pause,&nbsp;which&nbsp;can&nbsp;be&nbsp;any&nbsp;constant&nbsp;of&nbsp;[PAUSED_*](#constants). |
| status | number | Yes | Download&nbsp;status&nbsp;code,&nbsp;which&nbsp;can&nbsp;be&nbsp;any&nbsp;constant&nbsp;of&nbsp;[SESSION_*](#constants). |
| targetURI | string | Yes | URI&nbsp;of&nbsp;the&nbsp;downloaded&nbsp;file. |
| downloadTitle | string | Yes | Title&nbsp;of&nbsp;the&nbsp;downloaded&nbsp;file. |
| downloadTotalBytes | number | Yes | Total&nbsp;size&nbsp;of&nbsp;the&nbsp;downloaded&nbsp;file&nbsp;(int&nbsp;bytes). |
| description | string | Yes | Description&nbsp;of&nbsp;the&nbsp;file&nbsp;to&nbsp;download. |
| downloadedBytes | number | Yes | Size&nbsp;of&nbsp;the&nbsp;files&nbsp;downloaded&nbsp;(int&nbsp;bytes). |
