# @ohos.file.cloudSyncManager (Device-Cloud Sync Management) (System API)

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
| bundleName | string | Yes  | Bundle name of the application.|
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
| bundleName | string | Yes  | Bundle name of the application.|

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

Notifies the cloud sync service of the application data change in the cloud. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| accountId | string | Yes  | Account ID.|
| bundleName | string | Yes  | Bundle name of the application.|
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
| extraData | ExtraData | Yes  | Change of the cloud data.|

## cloudSyncManager.notifyDataChange<sup>11+</sup>

notifyDataChange(userId: number, extraData: ExtraData): Promise&lt;void&gt;

Notifies the cloud sync service of the application data change in the cloud. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| userId | number | Yes  | User ID.|
| extraData | ExtraData | Yes  | Change of the cloud data.|

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
| extraData | ExtraData | Yes  | Change of the cloud data.|
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
| switches | object | Yes  | Whether to enable the device-cloud synergy feature. **bundleName** is a string indicating the application bundle name. The switch status is a Boolean value.|

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
| switches | object | Yes  | Whether to enable the device-cloud synergy feature. **bundleName** is a string indicating the application bundle name. The switch status is a Boolean value.|
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
| appActions | object | Yes  | Action to perform. **bundleName** is a string indicating the application whose data is to be cleared.[Action](#action) specifies the action to perform.|

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
| appActions | object | Yes  | Action to perform. **bundleName** is a string indicating the application whose data is to be cleared.[Action](#action) specifies the action to perform.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to clear the cloud data locally.|

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
