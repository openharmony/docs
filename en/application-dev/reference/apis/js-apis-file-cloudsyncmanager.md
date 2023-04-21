# @ohos.file.cloudSyncManager (Device-Cloud Synchronization Management)

The **cloudSyncManager** module provides APIs for changing the cloud and device service status and notifying the data changes. 

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module are system APIs and cannot be called by third-party applications.
> - The APIs of this module support processing of error codes. For details, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

## Modules to Import

```js
import cloudSyncManager from '@ohos.file.cloudSyncManager';
```

## cloudSyncManager.changeAppCloudSwitch

changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean): Promise&lt;void&gt;;

Changes the device-cloud file synchronization switch for an application. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| accountId | string | Yes  | Account ID.|
| bundleName | string | Yes  | Bundle name of the application.|
| status | boolean | Yes  | State of the cloud-device file synchronization switch to set. The value **true** means to enable this function; the value **false** means the opposite.|

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  let accountId = "testAccount";
  let bundleName = "com.example.bundle";
  cloudSyncManager.changeAppCloudSwitch(accountId, bundleName, true).then(function() {
      console.info("changeAppCloudSwitch successfully");
  }).catch(function(err) {
      console.info("changeAppCloudSwitch failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSyncManager.changeAppCloudSwitch

changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean, callback: AsyncCallback&lt;void&gt;): void;

Changes the device-cloud file synchronization switch for an application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| accountId | string | Yes  | Account ID.|
| bundleName | string | Yes  | Bundle name of the application.|
| status | boolean | Yes  | State of the cloud-device file synchronization switch to set. The value **true** means to enable this function; the value **false** means the opposite.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.|

**Example**

  ```js
  let accountId = "testAccount";
  let bundleName = "com.example.bundle";
  cloudSyncManager.changeAppCloudSwitch(accountId, bundleName, true, (err) => {
    if (err) {
      console.info("changeAppCloudSwitch failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("changeAppCloudSwitch successfully");
    }
  });
  ```
## cloudSyncManager.notifyDataChange

notifyDataChange(accountId: string, bundleName: string): Promise&lt;void&gt;;

Notifies the cloud and device services of the application data change in the cloud. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| accountId | string | Yes  | Account ID.|
| bundleName | string | Yes  | Bundle name of the application.|

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the application data change in the cloud.|

**Example**

  ```js
  let accountId = "testAccount";
  let bundleName = "com.example.bundle";
  cloudSyncManager.notifyDataChange(accountId, bundleName).then(function() {
      console.info("notifyDataChange successfully");
  }).catch(function(err) {
      console.info("notifyDataChange failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSyncManager.notifyDataChange

notifyDataChange(accountId: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void;

Notifies the cloud and device services of the application data change in the cloud. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| accountId | string | Yes  | Account ID.|
| bundleName | string | Yes  | Bundle name of the application.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the application data change in the cloud.|

**Example**

  ```js
  let accountId = "testAccount";
  let bundleName = "com.example.bundle";
  cloudSyncManager.notifyDataChange(accountId, bundleName, (err) => {
    if (err) {
      console.info("notifyDataChange failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("notifyDataChange successfully");
    }
  });
  ```
