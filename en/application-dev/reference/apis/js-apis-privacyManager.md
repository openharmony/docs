# Privacy Management

The **PrivacyManager** module provides APIs for privacy management, such as management of permission usage records.

> **NOTE**
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module are system APIs and cannot be called by third-party applications.

## Modules to Import

```js
import privacyManager from '@ohos.privacyManager';
```


## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: string, successCount: number, failCount: number): Promise&lt;void&gt;

Adds a permission usage record when an application protected by the permission is called by another service or application. This API uses a promise to return the result.
The permission usage record includes the application identity of the invoker, name of the permission used, and number of successful and failed accesses to the application.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Application token ID of the invoker. You can obtain it from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).             |
| permissionName | string | Yes  | Name of the permission.|
| successCount | number | Yes  | Number of successful accesses.|
| failCount | number | Yes  | Number of failed accesses.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
import privacyManager from '@ohos.privacyManager';

let tokenID = 0; // You can use getApplicationInfo to obtain the access token ID.
try {
    privacyManager.addPermissionUsedRecord(tokenID, "ohos.permission.PERMISSION_USED_STATS", 1, 0).then(() => {
        console.log('addPermissionUsedRecord success');
    }).catch((err) => {
        console.log(`addPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: string, successCount: number, failCount: number, callback: AsyncCallback&lt;void&gt;): void

Adds a permission usage record when an application protected by the permission is called by another service or application. This API uses an asynchronous callback to return the result.
The permission usage record includes the application identity of the invoker, name of the permission used, and number of successful and failed accesses to the application.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Application token ID of the invoker. You can obtain it from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).             |
| permissionName | string | Yes  | Name of the permission.|
| successCount | number | Yes  | Number of successful accesses.|
| failCount | number | Yes  | Number of failed accesses.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.|

**Example**

```js
import privacyManager from '@ohos.privacyManager';

let tokenID = 0; // You can use getApplicationInfo to obtain the access token ID.
try {
    privacyManager.addPermissionUsedRecord(tokenID, "ohos.permission.PERMISSION_USED_STATS", 1, 0, (data, err) => {
        if (err) {
            console.log(`addPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
        } else {
            console.log('addPermissionUsedRecord success');
        }
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
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
import privacyManager from '@ohos.privacyManager';

let request = {
    "tokenId": 1,
    "isRemote": false,
    "deviceId": "device",
    "bundleName": "bundle",
    "permissionNames": [],
    "beginTime": 0,
    "endTime": 1,
    "flag":privacyManager.PermissionUsageFlag.FLAG_PERMISSION_USAGE_DETAIL,
};
try {
    privacyManager.getPermissionUsedRecords(request).then((data) => {
        console.log(`getPermissionUsedRecords success, data->${JSON.stringify(data)}`);
    }).catch((err) => {
        console.log(`getPermissionUsedRecords fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
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
| callback | AsyncCallback<[PermissionUsedResponse](#permissionusedresponse)> | Yes| Callback invoked to return the permission usage records obtained.|

**Example**

```js
import privacyManager from '@ohos.privacyManager';

let request = {
    "tokenId": 1,
    "isRemote": false,
    "deviceId": "device",
    "bundleName": "bundle",
    "permissionNames": [],
    "beginTime": 0,
    "endTime": 1,
    "flag":privacyManager.PermissionUsageFlag.FLAG_PERMISSION_USAGE_DETAIL,
};
try {
    privacyManager.getPermissionUsedRecords(request, (err, data) => {
        if (err) {
            console.log(`getPermissionUsedRecords fail, err->${JSON.stringify(err)}`);
        } else {
            console.log(`getPermissionUsedRecords success, data->${JSON.stringify(data)}`);
        }
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.startUsingPermission

startUsingPermission(tokenID: number, permissionName: string): Promise&lt;void&gt;

Starts to record a permission usage event. This API is called by a system service and uses a promise to return the result. The permissions used by an app in the foreground and background can be observed, and the permission usage records can be saved.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type  | Mandatory| Description                                 |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | Yes  | Application token ID of the invoker. You can obtain it from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).|
| permissionName | string | Yes  | Permission to use.                    |

**Return value**

| Type         | Description                                   |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
import privacyManager from '@ohos.privacyManager';

let tokenID = 0; // You can use getApplicationInfo to obtain the access token ID.
try {
    privacyManager.startUsingPermission(tokenID, "ohos.permission.PERMISSION_USED_STATS").then(() => {
        console.log('startUsingPermission success');
    }).catch((err) => {
        console.log(`startUsingPermission fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.startUsingPermission

startUsingPermission(tokenID: number, permissionName: string, callback: AsyncCallback&lt;void&gt;): void

Starts to record a permission usage event. This API is called by a system service and uses an asynchronous callback to return the result. The permissions used by an app in the foreground and background can be observed and saved.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type                 | Mandatory| Description                                 |
| -------------- | --------------------- | ---- | ------------------------------------ |
| tokenID        | number                | Yes  | Application token ID of the invoker. You can obtain it from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).|
| permissionName | string                | Yes  | Permission to use.                    |
| callback       | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.|

**Example**

```js
import privacyManager from '@ohos.privacyManager';

let tokenID = 0; // You can use getApplicationInfo to obtain the access token ID.
try {
    privacyManager.startUsingPermission(tokenID, "ohos.permission.PERMISSION_USED_STATS", (data, err) => {
        if (err) {
            console.log(`startUsingPermission fail, err->${JSON.stringify(err)}`);
        } else {
            console.log('startUsingPermission success');
        }
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.stopUsingPermission

stopUsingPermission(tokenID: number, permissionName: string): Promise&lt;void&gt;

Stops recording the permission usage event. This API is called by a system service and uses a promise to return the result. **startUsingPermission** and **stopUsingPermission** are used in pairs.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type  | Mandatory| Description                                 |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | Yes  | Application token ID of the invoker. You can obtain it from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).|
| permissionName | string | Yes  | Permission to use.                    |

**Return value**

| Type         | Description                                   |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
import privacyManager from '@ohos.privacyManager';

let tokenID = 0; // You can use getApplicationInfo to obtain the access token ID.
try {
    privacyManager.stopUsingPermission(tokenID, "ohos.permission.PERMISSION_USED_STATS").then(() => {
        console.log('stopUsingPermission success');
    }).catch((err) => {
        console.log(`stopUsingPermission fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.stopUsingPermission

stopUsingPermission(tokenID: number, permissionName: string, callback: AsyncCallback&lt;void&gt;): void

Stops recording the permission usage event. This API is called by the system service and uses an asynchronous callback to return the result. **startUsingPermission** and **stopUsingPermission** are used in pairs.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type                 | Mandatory| Description                                 |
| -------------- | --------------------- | ---- | ------------------------------------ |
| tokenID        | number                | Yes  | Application token ID of the invoker. You can obtain it from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).|
| permissionName | string                | Yes  | Permission to use.                     |
| callback       | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.|

**Example**

```js
import privacyManager from '@ohos.privacyManager';

let tokenID = 0; // You can use getApplicationInfo to obtain the access token ID.
try {
    privacyManager.stopUsingPermission(tokenID, "ohos.permission.PERMISSION_USED_STATS", (data, err) => {
        if (err) {
            console.log(`stopUsingPermission fail, err->${JSON.stringify(err)}`);
        } else {
            console.log('stopUsingPermission success');
        }
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.on

on(type: 'activeStateChange', permissionNameList: Array&lt;string&gt;, callback: Callback&lt;ActiveChangeResponse&gt;): void

Subscribes to the changes in the usage of the specified permission list. This API uses a callback to return the result.

This is a system API.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | Yes  | Event type to subscribe to. The value is **activeStateChange**, which indicates permission usage change event.  |
| permissionNameList | Array&lt;string&gt;   | No  | List of permissions to be observed. If this parameter is left empty, the usage changes of all permissions are observed.          |
| callback | Callback&lt;[ActiveChangeResponse](#activechangeresponse)&gt; | Yes| Callback invoked to return a change in permission usage.|

**Example**

```js
import privacyManager from '@ohos.privacyManager';

let permissionNameList: Array<string> = [];
try {
    atManager.on('activeStateChange', permissionNameList, (data) => {
        console.debug("receive permission state change, data:" + JSON.stringify(data));
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.off

off(type: 'activeStateChange', permissionNameList: Array&lt;string&gt;, callback?: Callback&lt;ActiveChangeResponse&gt;): void;

Unsubscribes from the changes in the usage of the specified permission list. This API uses a callback to return the result.

This is a system API.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | Yes  | Event type to subscribe to. The value is **activeStateChange**, which indicates permission usage change event.  |
| permissionNameList | Array&lt;string&gt;   | No  | List of permissions to be observed. If this parameter is left blank, the usage changes of all permissions are unsubscribed from. The value must be the same as that specified in **on()**.|
| callback | Callback&lt;[ActiveChangeResponse](#activechangeresponse)&gt; | No| Callback for the permission usage change event.|

**Example**

```js
import privacyManager from '@ohos.privacyManager';

let permissionNameList: Array<string> = [];
try {
    privacyManager.off('activeStateChange', permissionNameList);
}catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
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
| bundleRecords  | Array&lt;[BundleUsedRecord](#bundleusedrecord)&gt;         | No   | Permission usage records obtained.                                |

## BundleUsedRecord

Represents the permission access records of an application.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Mandatory  | Description                                      |
| -------- | -------------- | ---- | ---------------------------------------- |
| tokenId  | number         | No   | Token ID of the application.                                |
| isRemote | boolean         | No   | Whether the token ID belongs to a remote device. The default value is **false**.|
| deviceId  | string         | No   | ID of the device hosting the target application.                                |
| bundleName | string         | No   | Bundle name of the target application.|
| permissionRecords  | Array&lt;[PermissionUsedRecord](#permissionusedrecord)&gt;         | No   | Permission usage records of the target application.                                |

## PermissionUsedRecord

Represents the usage records of a permission.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Mandatory  | Description                                      |
| -------- | -------------- | ---- | ---------------------------------------- |
| permissionName  | string         | No   | Name of the permission.                                |
| accessCount | number         | No   | Total number of times that the permission is accessed.|
| rejectCount | number         | No   | Total number of times that the access to the permission is rejected.|
| lastAccessTime | number         | No   | Last time when the permission was accessed, accurate to ms.|
| lastRejectTime | number         | No   | Last time when the access to the permission was rejected, accurate to ms.|
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

## PermissionActiveStatus

Enumerates of permission usage statuses.

**System capability**: SystemCapability.Security.AccessToken

| Name                     | Default Value| Description             |
| ------------------------- | ------ | ---------------- |
| PERM_INACTIVE             | 0      | The permission is not used.  |
| PERM_ACTIVE_IN_FOREGROUND | 1      | The permission is being used in the foreground.|
| PERM_ACTIVE_IN_BACKGROUND | 2      | The permission is being used in the background.|

## ActiveChangeResponse

Defines the detailed permission usage information.

 **System capability**: SystemCapability.Security.AccessToken

| Name          | Type                   | Readable| Writable| Description                  |
| -------------- | ---------------------- | ---- | ---- | --------------------- |
| tokenId        | number                 | Yes  | No  | Token ID of the application that applies for the permission.   |
| permissionName | string                 | Yes  | No  | Name of the permission.|
| deviceId       | string                 | Yes  | No  | Device number.                |
| activeStatus   | [PermissionActiveStatus](#permissionactivestatus) | Yes  | No  | Permission usage status.       |
