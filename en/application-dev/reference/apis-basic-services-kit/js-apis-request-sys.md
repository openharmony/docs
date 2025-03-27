# @ohos.request (Upload and Download) (System API)

The **request** module provides applications with basic upload, download, and background transmission agent capabilities.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.request](js-apis-request.md).


## Modules to Import


```js
import { request } from '@kit.BasicServicesKit';
```


## Filter<sup>10+</sup>

Defines the filter criteria.

**System capability**: SystemCapability.Request.FileTransferAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundle | string | No| Bundle name of the application.<br>**System API**: This is a system API.|


## TaskInfo<sup>10+</sup> 

Defines the data structure of the task information for query. The fields available vary depending on the query types: common query and system query.

**System capability**: SystemCapability.Request.FileTransferAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uid | string | No| UID of the application. It is only available for query by system applications.<br>**System API**: This is a system API.|
| bundle | string | No| Bundle name of the application. It is only available for query by system applications.<br>**System API**: This is a system API.|



## request.agent.query<sup>10+</sup>

query(id: string, callback: AsyncCallback&lt;TaskInfo&gt;): void

Queries a task details based on the task ID. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DOWNLOAD_SESSION_MANAGER or ohos.permission.UPLOAD_SESSION_MANAGER

**System capability**: SystemCapability.Request.FileTransferAgent

**System API**: This is a system API.

**Parameters**

| Name| Type                                          | Mandatory| Description|
|----------------------------------------------| -------- | -------- | -------- |
| id | string                                       | Yes| Task ID.|
| callback | AsyncCallback&lt;[TaskInfo](#taskinfo10)&gt; | Yes| Callback used to return task details.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Upload and Download Error Codes](errorcode-request.md).

| ID| Error Message|
| -------- | -------- |
| 201 | permission denied. |
| 202 | permission verification failed, application which is not a system application uses system API. |
| 401 | parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. |
| 13400003 | task service ability error. |
| 21900006 | task not found. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  request.agent.query("123456", (err: BusinessError, taskInfo: request.agent.TaskInfo) => {
    if (err) {
      console.error(`Failed to query a upload task, Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in querying the upload task. Result: ${taskInfo.uid}`);
  });
  ```


## request.agent.query<sup>10+</sup>

query(id: string): Promise&lt;TaskInfo&gt;

Queries a task details based on the task ID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.DOWNLOAD_SESSION_MANAGER or ohos.permission.UPLOAD_SESSION_MANAGER

**System capability**: SystemCapability.Request.FileTransferAgent

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| id | string | Yes| Task ID.|

**Return value**

| Type                                    | Description                     |
|----------------------------------------| ------------------------- |
| Promise&lt;[TaskInfo](#taskinfo10)&gt; | Promise Promise used to return task details.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Upload and Download Error Codes](errorcode-request.md).

| ID| Error Message|
| -------- | -------- |
| 201 | permission denied. |
| 202 | permission verification failed, application which is not a system application uses system API. |
| 401 | parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. |
| 13400003 | task service ability error. |
| 21900006 | task not found. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  request.agent.query("123456").then((taskInfo: request.agent.TaskInfo) => {
    console.info(`Succeeded in querying the upload task. Result: ${taskInfo.uid}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to query a upload task, Code: ${err.code}, message: ${err.message}`);
  });
  ```
