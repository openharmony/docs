# Upload and Download


> **NOTE**<br>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import request from '@ohos.request';
```


## Constraints

HTTPS is supported by default. To support HTTP, you need to add **network** to the **config.json** file and set the **cleartextTraffic** attribute to **true**.

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

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| NETWORK_MOBILE | number | Yes | No | Whether download is allowed when the cellular network is used. |
| NETWORK_WIFI | number | Yes | No | Whether download is allowed when the WLAN is used. |
| ERROR_CANNOT_RESUME<sup>7+</sup> | number | Yes | No | Failure to resume the download due to an error. |
| ERROR_DEVICE_NOT_FOUND<sup>7+</sup> | number | Yes | No | Failure to find a storage device such as an SD card. |
| ERROR_FILE_ALREADY_EXISTS<sup>7+</sup> | number | Yes | No | Failure to download the file because it already exists. |
| ERROR_FILE_ERROR<sup>7+</sup> | number | Yes | No | File operation failure. |
| ERROR_HTTP_DATA_ERROR<sup>7+</sup> | number | Yes | No | HTTP transmission failure. |
| ERROR_INSUFFICIENT_SPACE<sup>7+</sup> | number | Yes | No | Insufficient storage space. |
| ERROR_TOO_MANY_REDIRECTS<sup>7+</sup> | number | Yes | No | Error caused by too many network redirections. |
| ERROR_UNHANDLED_HTTP_CODE<sup>7+</sup> | number | Yes | No | Unidentified HTTP code. |
| ERROR_UNKNOWN<sup>7+</sup> | number | Yes | No | Unknown error. |
| PAUSED_QUEUED_FOR_WIFI<sup>7+</sup> | number | Yes | No | Download paused and queuing for WLAN connection, because the file size exceeds the maximum value allowed by a cellular network session. |
| PAUSED_UNKNOWN<sup>7+</sup> | number | Yes | No | Download paused due to unknown reasons. |
| PAUSED_WAITING_FOR_NETWORK<sup>7+</sup> | number | Yes | No | Download paused due to a network connection problem, for example, network disconnection. |
| PAUSED_WAITING_TO_RETRY<sup>7+</sup> | number | Yes | No | Download paused and then retried. |
| SESSION_FAILED<sup>7+</sup> | number | Yes | No | Download failure without retry. |
| SESSION_PAUSED<sup>7+</sup> | number | Yes | No | Download paused. |
| SESSION_PENDING<sup>7+</sup> | number | Yes | No | Download pending. |
| SESSION_RUNNING<sup>7+</sup> | number | Yes | No | Download in progress. |
| SESSION_SUCCESSFUL<sup>7+</sup> | number | Yes | No | Successful download. |


## request.upload

upload(config: UploadConfig): Promise&lt;UploadTask&gt;

Uploads files. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Upload

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| config | [UploadConfig](#uploadconfig) | Yes | Configurations of the upload. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;[UploadTask](#uploadtask)&gt; | Promise used to return the **UploadTask** object. |

**Example**

  ```js
  let file1 = { filename: "test", name: "test", uri: "internal://cache/test.jpg", type: "jpg" };
  let uploadTask;
  request.upload({ url: 'https://patch', files:  [file1] }).then((data) => {
      uploadTask = data;
  }).catch((err) => {
      console.error('Failed to request the upload. Cause: ' + JSON.stringify(err));
  })
  ```


## request.upload

upload(config: UploadConfig, callback: AsyncCallback&lt;UploadTask&gt;): void

Uploads files. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Upload

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| config | [UploadConfig](#uploadconfig) | Yes | Configurations of the upload. |
| callback | AsyncCallback&lt;[UploadTask](#uploadtask)&gt; | No | Callback used to return the **UploadTask** object. |

**Example**

  ```js
  let file1 = { filename: "test", name: "test", uri: "internal://cache/test.jpg", type: "jpg" };
  let uploadTask;
  request.upload({ url: 'https://patch', files:  [file1] }, (err, data) => {
      if (err) {
          console.error('Failed to request the upload. Cause: ' + JSON.stringify(err));
          return;
      }
      uploadTask = data;
  });
  ```


## UploadTask

Implements file uploads. Before using any APIs of this class, you must obtain an **UploadTask** object.


### on('progress')

on(type: 'progress', callback:(uploadedSize: number, totalSize: number) =&gt; void): void

Subscribes to the upload progress event. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Upload

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Type of the event to subscribe to. The value is **progress** (upload progress). |
| callback | function | Yes | Callback for the upload progress event. |

Parameters of the callback function

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| uploadedSize | number | Yes | Size of the uploaded files, in KB. |
| totalSize | number | Yes | Total size of the files to upload, in KB. |

**Example**

  ```js
  uploadTask.on('progress', function callback(uploadedSize, totalSize) {
      console.info("upload totalSize:" + totalSize + "  uploadedSize:" + uploadedSize);
  }
  );
  ```


### on('headerReceive')<sup>7+</sup>

on(type: 'headerReceive', callback:  (header: object) =&gt; void): void

Subscribes to the **headerReceive** event, which is triggered when an HTTP response header is received. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Upload

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Type of the event to subscribe to. The value is **headerReceive** (response header). |
| callback | function | Yes | Callback for the HTTP Response Header event. |

Parameters of the callback function

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| header | object | Yes | HTTP Response Header. |

**Example**

  ```js
  uploadTask.on('headerReceive', function callback(headers){   
      console.info("upOnHeader headers:" + JSON.stringify(headers));
  }
  );
  ```


### off('progress')

off(type:  'progress',  callback?: (uploadedSize: number, totalSize: number) =&gt;  void): void

Unsubscribes from the upload progress event. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Upload

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Type of the event to unsubscribe from. The value is **progress** (upload progress). |
| callback | function | No | Callback for the upload progress event. |

Parameters of the callback function

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| uploadedSize | number | Yes | Size of the uploaded files, in KB. |
| totalSize | number | Yes | Total size of the files to upload, in KB. |

**Example**

  ```js
  uploadTask.off('progress', function callback(uploadedSize, totalSize) {
      console.info('uploadedSize: ' + uploadedSize, 'totalSize: ' + totalSize);
  }
  );
  ```


### off('headerReceive')<sup>7+</sup>

off(type: 'headerReceive', callback?: (header: object) =&gt; void): void

Unsubscribes from the **headerReceive** event. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Upload

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Type of the event to unsubscribe from. The value is **headerReceive** (response header). |
| callback | function | No | Callback for the HTTP Response Header event. |

Parameters of the callback function

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| header | object | Yes | HTTP Response Header. |

**Example**

  ```js
  uploadTask.off('headerReceive', function callback(headers) {
      console.info("upOnHeader headers:" + JSON.stringify(headers));
  }
  );
  ```


### remove

remove(): Promise&lt;boolean&gt;

Removes this upload task. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Upload

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the task removal result. If **true** is returned, the task is removed. If **false** is returned, the task fails to be removed. |

**Example**

  ```js
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

Removes this upload task. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Upload

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes | Callback used to return the result. |

**Example**

  ```js
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
| url | string | Yes | Resource URL. |
| header | object | No | HTTP or HTTPS header added to an upload request. |
| method | string | No | Request methods available: **POST** and **PUT**. The default value is **POST**. |
| files | Array&lt;[File](#file)&gt; | Yes | List of files to upload, which is submitted through **multipart/form-data**. |
| data | Array&lt;[RequestData](#requestdata)&gt; | No | Form data in the request body. |


## File

**System capability**: SystemCapability.MiscServices.Upload

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| filename | string | No | File name in the header when **multipart** is used. |
| name | string | No | Name of a form item when **multipart** is used. The default value is **file**. |
| uri | string | Yes | Local path for storing files.<br/>The **dataability** and **internal** protocol types are supported. However, the **internal** protocol type supports only temporary directories. The following is an example:<br/>dataability:///com.domainname.dataability.persondata/person/10/file.txt<br/>internal://cache/path/to/file.txt |
| type | string | No | Type of the file content. By default, the type is obtained based on the extension of the file name or URI. |


## RequestData

**System capability**: SystemCapability.MiscServices.Upload

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| name | string | Yes | Name of a form element. |
| value | string | Yes | Value of a form element. |


## request.download

download(config: DownloadConfig): Promise&lt;DownloadTask&gt;

Downloads files. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| config | [DownloadConfig](#downloadconfig) | Yes | Configurations of the download. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;[DownloadTask](#downloadtask)&gt; | Promise used to return the result. |

**Example**

  ```js
  let downloadTask;
  request.download({ url: 'https://xxxx/xxxx.hap' }).then((data) => {
      downloadTask = data;
  }).catch((err) => {
      console.error('Failed to request the download. Cause: ' + JSON.stringify(err));
  })
  ```


## request.download

download(config: DownloadConfig, callback: AsyncCallback&lt;DownloadTask&gt;): void

Downloads files. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| config | [DownloadConfig](#downloadconfig) | Yes | Configurations of the download. |
| callback | AsyncCallback&lt;[DownloadTask](#downloadtask)&gt; | No | Callback used to return the result. |

**Example**

  ```js
  let downloadTask;
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

Subscribes to the download progress event. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Type of the event to subscribe to. The value is **progress** (download progress). |
| callback | function | Yes | Callback for the download progress event. |

Parameters of the callback function

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| receivedSize | number | Yes | Size of the downloaded files, in KB. |
| totalSize | number | Yes | Total size of the files to download, in KB. |

**Example**

  ```js
      downloadTask.on('progress', function download_callback(receivedSize, totalSize) {
      console.info("download receivedSize:" + receivedSize + " totalSize:" + totalSize);
  }
  );
  });
  ```


### off('progress')

off(type: 'progress', callback?: (receivedSize: number, totalSize: number) =&gt; void): void

Unsubscribes from the download progress event. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Type of the event to unsubscribe from. The value is **progress** (download progress). |
| callback | function | No | Callback for the download progress event. |

Parameters of the callback function

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| receivedSize | number | Yes | Size of the downloaded files, in KB. |
| totalSize | number | Yes | Total size of the files to download, in KB. |

**Example**

  ```js
      downloadTask .off('progress', function download_callback(receivedSize, totalSize) {
          console.info("download receivedSize:" + receivedSize + " totalSize:" + totalSize);
      }
  );
  });
  ```


### on('complete'|'pause'|'remove')<sup>7+</sup>

on(type: 'complete'|'pause'|'remove', callback:() =&gt; void): void

Subscribes to a download event. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event type.<br/>- **complete**: download task completion event.<br/>- **pause**: download task pause event.<br/>- **remove**: download task removal event. |
| callback | function | Yes | Callback used to return the result. |

**Example**

  ```js
      downloadTask.on('complete', function callback() {
          console.info('Download task completed.');
      }
  );
  });
  ```


### off('complete'|'pause'|'remove')<sup>7+</sup>

off(type: 'complete'|'pause'|'remove', callback?:() =&gt; void): void

Unsubscribes from the download event. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event type.<br/>- **complete**: download task completion event.<br/>- **pause**: download task pause event.<br/>- **remove**: download task removal event. |
| callback | function | No | Callback used to return the result. |

**Example**

  ```js
      downloadTask.off('complete', function callback() {
          console.info('Download task completed.');
      }
  );
  }); 
  ```


### on('fail')<sup>7+</sup>

on(type: 'fail', callback: (err: number) =&gt; void): void

Subscribes to the download task failure event. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Type of the subscribed event. The value is **fail** (download failure). |
| callback | function | Yes | Callback for the download task failure event. |

Parameters of the callback function

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| err | number | Yes | Error code of the download failure. For details about the error cause, see [ERROR_*](#constants). |

**Example**

  ```js 
      downloadTask.on('fail', function callBack(err) {
          console.info('Download task failed. Cause:' + err);
      }
  );
  });
  ```


### off('fail')<sup>7+</sup>

off(type: 'fail', callback?: (err: number) =&gt; void): void

Unsubscribes from the download task failure event. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Type of the event to unsubscribe from. The value is **fail** (download failure). |
| callback | function | No | Callback for the download task failure event. |

Parameters of the callback function

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| err | number | Yes | Error code of the download failure. For details about the error cause, see [ERROR_*](#constants). |

**Example**

  ```js
      downloadTask.off('fail', function callBack(err) {
          console.info('Download task failed. Cause:' + err);
      } 
  );
  });
  ```


### remove

remove(): Promise&lt;boolean&gt;

Removes this download task. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the task removal result. |

**Example**

  ```js
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

Removes this download task. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes | Callback used to return the task removal result. |

**Example**

  ```js
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

Queries this download task. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Parameters**

| Type | Description |
| -------- | -------- |
| Promise&lt;[DownloadInfo](#downloadinfo7)&gt; | Promise used to return the download task information. |

**Example**

  ```js
  downloadTask.query().then((downloadInfo) => {    
      console.info('Download task queried. Data:' + JSON.stringify(downloadInfo))
  }) .catch((err) => {
      console.error('Failed to query the download task. Cause:' + err)
  });
  ```


### query<sup>7+</sup>

query(callback: AsyncCallback&lt;DownloadInfo&gt;): void

Queries this download task. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[DownloadInfo](#downloadinfo7)&gt; | Yes | Callback used to return the download task information. |

**Example**

  ```js
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

Queries **MimeType** of this download task. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;string&gt; | Promise used to return **MimeType** of the download task. |

**Example**

  ```js
  downloadTask.queryMimeType().then((data) => {    
      console.info('Download task queried. Data:' + JSON.stringify(data));
  }).catch((err) => {
      console.error('Failed to query the download MimeType. Cause:' + JSON.stringify(err))
  });
  ```


### queryMimeType<sup>7+</sup>

queryMimeType(callback: AsyncCallback&lt;string&gt;): void;

Queries **MimeType** of this download task. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;string&gt; | Yes | Callback used to return **MimeType** of the download task. |

**Example**

  ```js
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

Pauses this download task. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the download task pause result. |

**Example**

  ```js
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

Pauses this download task. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes | Callback used to return the result. |

**Example**

  ```js
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

Resumes this download task. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Parameters**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result. |

**Example**

  ```js
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

Resumes this download task. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.MiscServices.Download

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes | Callback used to return the result. |

**Example**

  ```js
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
| url | string | Yes | Resource URL. |
| header | object | No | HTTP or HTTPS header added to a download request. |
| enableMetered | boolean | No | Download allowed in metered connections. |
| enableRoaming | boolean | No | Download allowed on a roaming network. |
| description | string | No | Description of the download session. |
| filePath<sup>7+</sup> | string | No | Download path. (The default path is [ERROR:Invalid link:en-us_topic_0000001135742582.xml#xref8132147102215,link:en-us_topic_0000001127125012.xml#section1856519365229](en-us_topic_0000001127125012.xml#section1856519365229)).<br/>- filePath:'workspace/test.txt': The **workspace** directory is created in the default path to store files.<br/>- filePath:'test.txt': Files are stored in the default path.<br/>- filePath:'workspace/': The **workspace** directory is created in the default path to store files. |
| networkType | number | No | Network type allowed for download. |
| title | string | No | Title of the download session. |


## DownloadInfo<sup>7+</sup>

**System capability**: SystemCapability.MiscServices.Download

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| downloadId | number | Yes | ID of the downloaded file. |
| failedReason | number | No | Download failure cause, which can be any constant of [ERROR_*](#constants). |
| fileName | string | Yes | Name of the downloaded file. |
| filePath | string | Yes | URI of the saved file. |
| pausedReason | number | No | Reason for session pause, which can be any constant of [PAUSED_*](#constants). |
| status | number | Yes | Download status code, which can be any constant of [SESSION_*](#constants). |
| targetURI | string | Yes | URI of the downloaded file. |
| downloadTitle | string | Yes | Title of the downloaded file. |
| downloadTotalBytes | number | Yes | Total size of the downloaded file (int bytes). |
| description | string | Yes | Description of the file to download. |
| downloadedBytes | number | Yes | Size of the files downloaded (int bytes). |
