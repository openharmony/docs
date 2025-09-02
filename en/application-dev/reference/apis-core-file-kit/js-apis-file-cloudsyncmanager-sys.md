# @ohos.file.cloudSyncManager (Device-Cloud Sync Management) (System API)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @zsyztt; @Hermits; @reminder2352-->
<!--Designer: @yunlanying-->
<!--Tester: @liuhonggang123-->
<!--Adviser: @foryourself-->

The **cloudSyncManager** module provides APIs for managing device-cloud synergy for applications. You can use the APIs to enable or disable device-cloud synergy, change the device-cloud sync switch for an application, notify cloud data changes, and clear or retain cloud files when a cloud account exits.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { cloudSyncManager } from '@kit.CoreFileKit';
```

## cloudSyncManager.changeAppCloudSwitch

changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean): Promise&lt;void&gt;

Changes the device-cloud file sync switch for an application. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| accountId | string | Yes  | Account ID.|
| bundleName | string | Yes  | Bundle name.|
| status | boolean | Yes  | State of the cloud-device file sync switch to set. The value **true** means to enable this function; the value **false** means the opposite.|

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  let bundleName: string = "com.example.bundle";
  cloudSyncManager.changeAppCloudSwitch(accountId, bundleName, true).then(() => {
    console.info("changeAppCloudSwitch successfully");
  }).catch((err: BusinessError) => {
    console.error("changeAppCloudSwitch failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSyncManager.changeAppCloudSwitch

changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean, callback: AsyncCallback&lt;void&gt;): void

Changes the device-cloud file sync switch for an application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| accountId | string | Yes  | Account ID.|
| bundleName | string | Yes  | Bundle name of the application.|
| status | boolean | Yes  | State of the cloud-device file sync switch to set. The value **true** means to enable this function; the value **false** means the opposite.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  let bundleName: string = "com.example.bundle";
  cloudSyncManager.changeAppCloudSwitch(accountId, bundleName, true, (err: BusinessError) => {
    if (err) {
      console.error("changeAppCloudSwitch failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("changeAppCloudSwitch successfully");
    }
  });
  ```

## cloudSyncManager.notifyDataChange

notifyDataChange(accountId: string, bundleName: string): Promise&lt;void&gt;

Notifies the cloud sync service of the application data change in the cloud. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| accountId | string | Yes  | Account ID.|
| bundleName | string | Yes  | Bundle name.|

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the application data change in the cloud.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  let bundleName: string = "com.example.bundle";
  cloudSyncManager.notifyDataChange(accountId, bundleName).then(() => {
    console.info("notifyDataChange successfully");
  }).catch((err: BusinessError) => {
    console.error("notifyDataChange failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSyncManager.notifyDataChange

notifyDataChange(accountId: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void

Notifies the cloud sync service of the application data change in the cloud. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| accountId | string | Yes  | Account ID.|
| bundleName | string | Yes  | Bundle name.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the application data change in the cloud.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  let bundleName: string = "com.example.bundle";
  cloudSyncManager.notifyDataChange(accountId, bundleName, (err: BusinessError) => {
    if (err) {
      console.error("notifyDataChange failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("notifyDataChange successfully");
    }
  });
  ```

## ExtraData<sup>11+</sup>

Represents the cloud data change information.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| eventId | string | Yes  | Change event ID.|
| extraData | ExtraData | Yes  | Represents the cloud data change information.|

## cloudSyncManager.notifyDataChange<sup>11+</sup>

notifyDataChange(userId: number, extraData: ExtraData): Promise&lt;void&gt;

Notifies the cloud sync service of the application data change in the cloud. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| userId | number | Yes  | User ID.|
| extraData | ExtraData | Yes  | Represents the cloud data change information.|

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the application data change in the cloud.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userId: number = 100;
  let extraData: cloudSyncManager.ExtraData = {eventId: "eventId", extraData: "data"};
  cloudSyncManager.notifyDataChange(userId, extraData).then(() => {
    console.info("notifyDataChange successfully");
  }).catch((err: BusinessError) => {
    console.error("notifyDataChange failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSyncManager.notifyDataChange<sup>11+</sup>

notifyDataChange(userId: number, extraData: ExtraData, callback: AsyncCallback&lt;void&gt;): void

Notifies the cloud sync service of the application data change in the cloud. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| userId | number | Yes  | User ID.|
| extraData | ExtraData | Yes  | Represents the cloud data change information.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the application data change in the cloud.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001  | IPC error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userId: number = 100;
  let extraData: cloudSyncManager.ExtraData = {eventId: "eventId", extraData: "data"};
  cloudSyncManager.notifyDataChange(userId, extraData, (err: BusinessError) => {
    if (err) {
      console.error("notifyDataChange failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("notifyDataChange successfully");
    }
  });
  ```

## cloudSyncManager.enableCloud

enableCloud(accountId: string, switches: Record<string, boolean>): Promise&lt;void&gt;

Enables device-cloud synergy. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| accountId | string | Yes  | Account ID.|
| switches | Record<string, boolean> | Yes  | Whether to enable the device-cloud synergy feature. The application bundle name is a string. The switch status is a Boolean value. The value **true** means to enable this function; the value **false** means the opposite.|

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  let switches: Record<string, boolean> = {
    'com.example.bundleName1': true,
    'com.example.bundleName2': false
  }
  cloudSyncManager.enableCloud(accountId, switches).then(() => {
    console.error("enableCloud successfully");
  }).catch((err: BusinessError) => {
    console.info("enableCloud failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSyncManager.enableCloud

enableCloud(accountId: string, switches: Record<string, boolean>, callback: AsyncCallback&lt;void&gt;): void

Enables device-cloud synergy. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| accountId | string | Yes  | Account ID.|
| switches | Record<string, boolean> | Yes  | Whether to enable the device-cloud synergy feature. The application bundle name is a string. The switch status is a Boolean value. The value **true** means to enable this function; the value **false** means the opposite.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  let switches: Record<string, boolean> = {
    'com.example.bundleName1': true,
    'com.example.bundleName2': false
  }
  cloudSyncManager.enableCloud(accountId, switches, (err: BusinessError) => {
    if (err) {
      console.error("enableCloud failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("enableCloud successfully");
    }
  });
  ```

## cloudSyncManager.disableCloud

disableCloud(accountId: string): Promise&lt;void&gt;

Disables device-cloud synergy. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| accountId | string | Yes  | Account ID.|

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  cloudSyncManager.disableCloud(accountId).then(() => {
    console.info("disableCloud successfully");
  }).catch((err: BusinessError) => {
    console.error("disableCloud failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSyncManager.disableCloud

disableCloud(accountId: string, callback: AsyncCallback&lt;void&gt;): void

Disables device-cloud synergy. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| accountId | string | Yes  | Account ID.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  cloudSyncManager.disableCloud(accountId, (err: BusinessError) => {
    if (err) {
      console.error("disableCloud failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("disableCloud successfully");
    }
  });
  ```

## Action

Enumerates the actions that can be taken to clear local cloud data.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

| Name|  Value|  Description|
| ----- |  ---- |  ---- |
| RETAIN_DATA |  0 |  Clear the cloud identifier but retain the files cached locally.|
| CLEAR_DATA |  1 |  Clear the cloud identifier and the files cached locally.|

## cloudSyncManager.clean

clean(accountId: string, appActions: Record<string, Action>): Promise&lt;void&gt;

Clears the cloud data locally. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| accountId | string | Yes  | Account ID.|
| appActions | Record<string, Action> | Yes  | Action to perform. The bundle name of the application whose data is to be cleared is a string. [Action](#action) specifies the action to perform.|

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  let appActions: Record<string, cloudSyncManager.Action> = {
    'com.example.bundleName1': cloudSyncManager.Action.RETAIN_DATA,
    'com.example.bundleName2': cloudSyncManager.Action.CLEAR_DATA
  };
  cloudSyncManager.clean(accountId, appActions).then(() => {
    console.info("clean successfully");
  }).catch((err: BusinessError) => {
    console.error("clean failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSyncManager.clean

clean(accountId: string, appActions: Record<string, Action>, callback: AsyncCallback&lt;void&gt;): void

Clears the cloud data locally. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| accountId | string | Yes  | Account ID.|
| appActions | Record<string, Action> | Yes  | Action to perform. The bundle name of the application whose data is to be cleared is a string. [Action](#action) specifies the action to perform.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to clear the cloud data locally.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
    let appActions: Record<string, cloudSyncManager.Action> = {
    'com.example.bundleName1': cloudSyncManager.Action.RETAIN_DATA,
    'com.example.bundleName2': cloudSyncManager.Action.CLEAR_DATA
  };
  cloudSyncManager.clean(accountId, appActions, (err: BusinessError) => {
    if (err) {
      console.error("clean failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("clean successfully");
    }
  });
  ```

## DowngradeDownload<sup>20+</sup>

Represents the downgrade download for cloud data to prevent data loss when Cloud Premium expires.

It supports the download of cloud application files.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

### constructor<sup>20+</sup>

constructor(bundleName: string)

A constructor used to create a **DowngradeDownload** instance with a specified bundle name.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description      |
| ---------- | ------ | ---- | ---------- |
| bundleName | string | Yes  | Bundle name.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                                                                                                                         |
| -------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.                                                                                                 |
| 202      | Permission verification failed, application which is not a system application uses system API.                                                                                    |
| 13900020 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.                                                                     |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**Example**

  ```ts
  let bundleName = 'com.demo.a';
  try {
    let downgradeMgr = new cloudSyncManager.DowngradeDownload(bundleName);
  } catch (e) {
    let error = e as BusinessError;
    console.error(`Failed to create downgrade manager object, error code: ${error.code}, message: ${error.message}`);
  }
  ```

### getCloudFileInfo<sup>20+</sup>

getCloudFileInfo(): Promise&lt;CloudFileInfo&gt;

Obtains the size and count of files for applications requiring downgrade download, including those stored only locally, only in the cloud, or both locally and in the cloud. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Return value**

  | Type                             | Description                    |
  | --------------------------------- | ------------------------ |
  | Promise&lt;[CloudFileInfo](#cloudfileinfo20)&gt; | Promise used to return the local and cloud file information.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                                                                                                                         |
| -------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.                                                                                                 |
| 202      | Permission verification failed, application which is not a system application uses system API.                                                                                    |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service.                                                                                              |
| 13900010 | Try again.                                                                                                                                                                        |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let bundleName: string = "com.demo.a";
  let downgradeMgr = new cloudSyncManager.DowngradeDownload(bundleName);
  downgradeMgr.getCloudFileInfo().then((fileInfo: cloudSyncManager.CloudFileInfo) => {
    console.info("cloud file info: " + JSON.stringify(fileInfo));
  }).catch((err: BusinessError) => {
    console.error(`Failed to get downgrade info, error message: ${err.message}, error code: ${err.code}`);
  });
  ```

### startDownload<sup>20+</sup>

startDownload(callback: Callback&lt;DownloadProgress&gt;): Promise&lt;void&gt;

Starts the downgrade download for the specified application's cloud files. This API uses a promise to return the result.

Repeated triggering of a downgrade download task will throw an error (22400006).

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name  | Type                            | Mandatory| Description                                                                               |
| -------- | -------------------------------- | ---- | ----------------------------------------------------------------------------------- |
| callback | Callback&lt;[DownloadProgress](#downloadprogress20)&gt; | Yes  | Callback used to return the download progress. The parameter is **DownloadProgress**, and the return value is **void**.|

**Return value**

  | Type               | Description                     |
  | ------------------- | ------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                                                                                                                         |
| -------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.                                                                                                 |
| 202      | Permission verification failed, application which is not a system application uses system API.                                                                                    |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service.                                                                                              |
| 13900010 | Try again.                                                                                                                                                                        |
| 13900020 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.                                                                     |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |
| 22400006 | The same task is already in progress.                                                                                                                                             |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let bundleName: string = "com.demo.a";
  let downgradeMgr = new cloudSyncManager.DowngradeDownload(bundleName);
  let callback = (data: cloudSyncManager.DownloadProgress) => {
    console.info(`Dwongrade progress: downloadedSize: ${data.downloadedSize}, totalSize: ${data.totalSize}`);
    if (data.state == cloudSyncManager.DownloadState.COMPLETED) {
      console.info('Dwongrade finished.');
    } else if (data.state == cloudSyncManager.DownloadState.STOPPED) {
      console.info(`Dwongrade stopped, reason: ${data.stopReason}.`);
    }
  };
  downgradeMgr.startDownload(callback).then(() => {
    console.info("Downgrade started successfully.");
  }).catch((err: BusinessError) => {
    console.error(`Failed to start downgrade, error message: ${err.message}, error code: ${err.code}`);
  });
  ```

### stopDownload<sup>20+</sup>

stopDownload(): Promise&lt;void&gt;

Stops the downgrade download task triggered by [startDownload](#startdownload20). This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Return value**

  | Type               | Description                     |
  | ------------------- | ------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                                                                                                                         |
| -------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.                                                                                                 |
| 202      | Permission verification failed, application which is not a system application uses system API.                                                                                    |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service.                                                                                              |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let bundleName: string = "com.demo.a";
  let downgradeMgr = new cloudSyncManager.DowngradeDownload(bundleName);
  downgradeMgr.startDownload((data: cloudSyncManager.DownloadProgress) => {
    console.info(`Dwongrade progress: downloadedSize: ${data.downloadedSize}, totalSize: ${data.totalSize}`);
  }).then(() => {
    console.info("Downgrade started successfully.");
  }).catch((err: BusinessError) => {
    console.error(`Failed to start downgrade, error message: ${err.message}, error code: ${err.code}`);
  });

  let needStop = true;
  if (needStop) {
    downgradeMgr.stopDownload().then(() => {
      console.info("Downgrade stopped successfully.");
    }).catch((err: BusinessError) => {
      console.error(`Failed to stop downgrade, error message: ${err.message}, error code: ${err.code}`);
    });
  }
  ```
## DownloadStopReason<sup>20+</sup>

Enumerates the reasons why the download stops. The default value is **NO_STOP**.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

| Name               | Value | Description                                                  |
| ------------------- | --- | ------------------------------------------------------ |
| NO_STOP             | 0   | Downloading.                                        |
| NETWORK_UNAVAILABLE | 1   | Downloading. Mobile network and Wi-Fi are unavailable.              |
| LOCAL_STORAGE_FULL  | 2   | Downloading. The device storage is full.                        |
| TEMPERATURE_LIMIT   | 3   | Downloading. The device temperature exceeds the upper limit.                            |
| USER_STOPPED        | 4   | Downloading. The user stops the download.                      |
| APP_UNLOAD          | 5   | Downloading. The application is uninstalled.                    |
| OTHER_REASON        | 6   | Downloading. The download stops due to other reasons, for example, the cloud server does not respond.|

## DownloadState<sup>20+</sup>

Enumerates the download states.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

| Name     | Value | Description      |
| --------- | --- | ---------- |
| RUNNING   | 0   | Downloading.  |
| COMPLETED | 1   | Downloaded.|
| STOPPED   | 2   | Downloading stopped.|

## DownloadProgress<sup>20+</sup>

Represents the downgrade download progress.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

### Property

| Name           | Type                                       | Read-Only| Optional| Description                                                                         |
| --------------- | ------------------------------------------- | ---- | ---- | ----------------------------------------------------------------------------- |
| state           | [DownloadState](#downloadstate20)           | No  | No  | Download state.                                                             |
| successfulCount | number                                      | No  | No  | Number of downloaded files. The value range is [0, INT32_MAX]. If the progress is abnormal, **-1** is returned.       |
| failedCount     | number                                      | No  | No  | Number of files that fail to be downloaded. The value range is [0, INT32_MAX]. If the progress is abnormal, **-1** is returned.     |
| totalCount      | number                                      | No  | No  | Total number of files to be downloaded. The value range is [0, INT32_MAX]. If the progress is abnormal, **-1** is returned.       |
| downloadedSize  | number                                      | No  | No  | Size of the downloaded data, in bytes. The value range is [0, INT64_MAX). If the progress is abnormal, **INT64_MAX** is returned.|
| totalSize       | number                                      | No  | No  | Total size of the files to be downloaded, in bytes. The value range is [0, INT64_MAX). If the progress is abnormal, **INT64_MAX** is returned.|
| stopReason      | [DownloadStopReason](#downloadstopreason20) | No  | No  | Reason why the download stops.                                                             |

## CloudFileInfo<sup>20+</sup>

Represents the number and size of local and cloud files of an application.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

### Property

| Name              | Type  | Read-Only| Optional| Description                                                            |
| ------------------ | ------ | ---- | ---- | ---------------------------------------------------------------- |
| cloudFileCount     | number | No  | No  | Total number of cloud files that are not downloaded locally. The value range is [0, INT32_MAX].  |
| cloudFileTotalSize | number | No  | No  | Total size of cloud files that are not downloaded locally, in bytes. The value range is [0, INT64_MAX].|
| localFileCount     | number | No  | No  | Total number of local files that are not uploaded to the cloud. The value range is [0, INT32_MAX].  |
| localFileTotalSize | number | No  | No  | Total size of local files that are not uploaded to the cloud, in bytes. The value range is [0, INT64_MAX].|
| bothFileCount      | number | No  | No  | Total number of local files that have been uploaded to the cloud. The value range is [0, INT32_MAX].  |
| bothlFileTotalSize | number | No  | No  | Total size of local files that have been uploaded to the cloud, in bytes. The value range is [0, INT64_MAX].|
