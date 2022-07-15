# Privacy Management

Provides APIs for privacy management, such as management of permission usage records.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module are system APIs and cannot be called by third-party applications.

## Modules to Import

```js
import privacyManager from '@ohos.privacyManager';
```


## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: string, successCount: number, failCount: number): Promise&lt;number&gt;

Adds a permission usage record when an application protected by the permission is called by another service or application. This API uses a promise to return the result.

The permission usage record includes the application identity of the invoker, name of the permission used, and number of successful and failed accesses to the application.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Application token ID of the invoker.             |
| permissionName | string | Yes  | Name of the permission.|
| successCount | number | Yes  | Number of successful accesses.|
| failCount | number | Yes  | Number of failed accesses.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result. If **0** is returned, the record is added successfully. If **-1** is returned, the record fails to be added.|

```

```

**Example**

```js
var tokenID = appInfo.accessTokenId; // accessTokenId can be obtained by using getApplicationInfo().
privacyManager.addPermissionUsedRecord(tokenID, "ohos.permission.PERMISSION_USED_STATS", 1, 0).then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: string, successCount: number, failCount: number, callback: AsyncCallback&lt;number&gt;): void

Adds a permission usage record when an application protected by the permission is called by another service or application. This API uses an asynchronous callback to return the result.

The permission usage record includes the application identity of the invoker, name of the permission used, and number of successful and failed accesses to the application.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Application token ID of the invoker.             |
| permissionName | string | Yes  | Name of the permission.|
| successCount | number | Yes  | Number of successful accesses.|
| failCount | number | Yes  | Number of failed accesses.|
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result. If **0** is returned, the record is added successfully. If **-1** is returned, the record fails to be added.|

**Example**

```js
var tokenID = appInfo.accessTokenId; // accessTokenId can be obtained by using getApplicationInfo().
privacyManager.privacyManager.addPermissionUsedRecord(tokenID, "ohos.permission.PERMISSION_USED_STATS", 1, 0, (err, data) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## privacyManager.getPermissionUsedRecords

getPermissionUsedRecords(request: PermissionUsedRequest): Promise&lt;PermissionUsedResponse&gt;

Obtains historical permission usage records. This API uses a promise to return the result.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| request   |  [PermissionUsedRequest](#permissionusedrequest)   | Yes  | Request for querying permission usage records.             |

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise<[PermissionUsedResponse](#permissionusedresponse)> | Promise used to return the permission usage records obtained.|

**Example**

```js
let request = {
    "tokenId": 1,
    "isRemote": 1,
    "deviceId": "device",
    "bundleName": "bundle",
    "permissionNames": 1,
    "beginTime": 0,
    "endTime": 1,
    "flag":privacyManager.PermissionUsageFlag.FLAG_PERMISSION_USAGE_DETAIL,
};
privacyManager.getPermissionUsedRecords(request).then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

## privacyManager.getPermissionUsedRecords

getPermissionUsedRecords(request: PermissionUsedRequest, callback: AsyncCallback&lt;PermissionUsedResponse&gt;): void

Obtains historical permission usage records. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| request | [PermissionUsedRequest](#permissionusedrequest) | Yes| Request for querying permission usage records.|
| callback | AsyncCallback<[PermissionUsedResponse](#permissionusedresponse)> | Yes| Callback used to return the permission usage records obtained.|

**Example**

```js
let request = {
    "tokenId": 1,
    "isRemote": 1,
    "deviceId": "device",
    "bundleName": "bundle",
    "permissionNames": 1,
    "beginTime": 0,
    "endTime": 1,
    "flag":privacyManager.PermissionUsageFlag.FLAG_PERMISSION_USAGE_DETAIL,
};
privacyManager.getPermissionUsedRecords(request, (err, data) => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

## PermissionUsageFlag

Enumerates the modes for querying the permission usage records.

**System capability**: SystemCapability.Security.AccessToken

| Name                   | Value| Description                  |
| ----------------------- | ------ | ---------------------- |
| FLAG_PERMISSION_USAGE_SUMMARY             | 0    | Query the permission usage summary.|
| FLAG_PERMISSION_USAGE_DETAIL         | 1    | Query detailed permission usage records.        |

## PermissionUsedRequest

Represents the request for querying permission usage records.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Mandatory  | Description                                      |
| -------- | -------------- | ---- | ---------------------------------------- |
| tokenId  | number         | No   | Token ID of the application.                                |
| isRemote | boolean         | No   | Whether the token ID belongs to a remote device. The default value is **false**.|
| deviceId  | string         | No   | ID of the device hosting the target application.                                |
| bundleName | string         | No   | Bundle name of the target application.|
| permissionNames  | Array&lt;string&gt;         | No   | Permissions to query.                                |
| beginTime | number         | No   | Start time of the query, in ms. The default value is **0**, indicating that no start time is set.|
| endTime | number         | No   | End time of the query, in ms. The default value is **0**, indicating that no end time is set.|
| flag | [PermissionUsageFlag](#permissionusageflag)         | Yes   | Query mode. The default value is **FLAG_PERMISSION_USAGE_SUMMARY**.|

## PermissionUsedResponse

Represents the permission usage records of all applications.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Mandatory  | Description                                      |
| -------- | -------------- | ---- | ---------------------------------------- |
| beginTime | number         | No   | Start time of the query, in ms.|
| endTime | number         | No   | End time of the query, in ms.|
| bundleRecords  | Array&lt;[BundleUsedRecord](#BundleUsedRecord)&gt;         | No   | Permission usage records obtained.                                |

## BundleUsedRecord

Represents the application access records of an application.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Mandatory  | Description                                      |
| -------- | -------------- | ---- | ---------------------------------------- |
| tokenId  | number         | No   | Token ID of the application.                                |
| isRemote | boolean         | No   | Whether the token ID belongs to a remote device. The default value is **false**.|
| deviceId  | string         | No   | ID of the device hosting the target application.                                |
| bundleName | string         | No   | Bundle name of the target application.|
| permissionRecords  | Array&lt;[PermissionUsedRecord](#PermissionUsedRecord)&gt;         | No   | Permission usage records of the specified application obtained.                                |

## PermissionUsedRecord

Represents the access records of a permission.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Mandatory  | Description                                      |
| -------- | -------------- | ---- | ---------------------------------------- |
| permissionName  | string         | No   | Name of the permission.                                |
| accessCount | number         | No   | Total number of times that the permission is accessed.|
| rejectCount | number         | No   | Total number of times that the access to the permission is rejected.|
| lastAccessTime | number         | No   | Last time when the permission was accessed, in ms.|
| lastRejectTime | number         | No   | Last time when the access to the permission was rejected, in ms.|
| lastAccessDuration | number         | No   | Last access duration, in ms.|
| accessRecords  | Array&lt;[UsedRecordDetail](#usedrecorddetail)&gt;         | No   | Access records. This parameter is valid only when **flag** is **FLAG_PERMISSION_USAGE_SUMMARY**. By default, 10 records are provided.                                |
| rejectRecords  | Array&lt;[UsedRecordDetail](#usedrecorddetail)&gt;         | No   | Rejected records. This parameter is valid only when **flag** is **FLAG_PERMISSION_USAGE_SUMMARY**. By default, 10 records are provided.                                |

## UsedRecordDetail

Represents the details of a single access record.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Mandatory  | Description                                      |
| -------- | -------------- | ---- | ---------------------------------------- |
| status  | number         | No   | Access status.                                |
| timestamp | number         | No   | Access timestamp, in ms.|
| accessDuration  | number         | No   | Access duration, in ms.                                |
