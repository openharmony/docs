# @ohos.privacyManager (Privacy Management)

The **privacyManager** module provides APIs for privacy management, such as management of permission usage records.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import privacyManager from '@ohos.privacyManager';
```


## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number): Promise&lt;void&gt;

Adds a permission usage record when an application protected by the permission is called by another service or application. This API uses a promise to return the result.
The permission usage record includes the application identity (token ID) of the invoker, name of the permission used, and number of successful and failed accesses to the target application.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Application token ID of the invoker. The value can be obtained from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).             |
| permissionName | Permissions | Yes  | Name of the permission.|
| successCount | number | Yes  | Number of successful accesses.|
| failCount | number | Yes  | Number of failed accesses.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0, or the string size of permissionName is larger than 256, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100007 | Service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import privacyManager from '@ohos.privacyManager';
import { BusinessError } from '@ohos.base';

let tokenID: number = 0; // You can use getApplicationInfo to obtain accessTokenId.
try {
    privacyManager.addPermissionUsedRecord(tokenID, 'ohos.permission.PERMISSION_USED_STATS', 1, 0).then(() => {
        console.log('addPermissionUsedRecord success');
    }).catch((err: BusinessError) => {
        console.log(`addPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number, callback: AsyncCallback&lt;void&gt;): void

Adds a permission usage record when an application protected by the permission is called by another service or application. This API uses an asynchronous callback to return the result.
The permission usage record includes the application identity (token ID) of the invoker, name of the permission used, and number of successful and failed accesses to the target application.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Application token ID of the invoker. The value can be obtained from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).             |
| permissionName | Permissions | Yes  | Application permission name. Valid permission names can be obtained in the [Application Permission List](../../security/permission-list.md).|
| successCount | number | Yes  | Number of successful accesses.|
| failCount | number | Yes  | Number of failed accesses.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0, or the string size of permissionName is larger than 256, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100007 | Service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import privacyManager from '@ohos.privacyManager';
import { BusinessError } from '@ohos.base';

let tokenID: number = 0; // You can use getApplicationInfo to obtain accessTokenId.
try {
    privacyManager.addPermissionUsedRecord(tokenID, 'ohos.permission.PERMISSION_USED_STATS', 1, 0, (err: BusinessError, data: void) => {
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

## privacyManager.getPermissionUsedRecord

getPermissionUsedRecord(request: PermissionUsedRequest): Promise&lt;PermissionUsedResponse&gt;

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
| Promise<[PermissionUsedResponse](#permissionusedresponse)> | Promise used to return the permission usage records.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. the value of flag in request is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100007 | Service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import privacyManager from '@ohos.privacyManager';
import { BusinessError } from '@ohos.base';

let request: privacyManager.PermissionUsedRequest = {
    'tokenId': 1,
    'isRemote': false,
    'deviceId': 'device',
    'bundleName': 'bundle',
    'permissionNames': [],
    'beginTime': 0,
    'endTime': 1,
    'flag':privacyManager.PermissionUsageFlag.FLAG_PERMISSION_USAGE_DETAIL,
};
try {
    privacyManager.getPermissionUsedRecord(request).then((data) => {
        console.log(`getPermissionUsedRecord success, data->${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
        console.log(`getPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.getPermissionUsedRecord

getPermissionUsedRecord(request: PermissionUsedRequest, callback: AsyncCallback&lt;PermissionUsedResponse&gt;): void

Obtains historical permission usage records. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| request | [PermissionUsedRequest](#permissionusedrequest) | Yes| Request for querying permission usage records.|
| callback | AsyncCallback<[PermissionUsedResponse](#permissionusedresponse)> | Yes| Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the permission usage record obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. the value of flag in request is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100007 | Service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import privacyManager from '@ohos.privacyManager';
import { BusinessError } from '@ohos.base';

let request: privacyManager.PermissionUsedRequest = {
    'tokenId': 1,
    'isRemote': false,
    'deviceId': 'device',
    'bundleName': 'bundle',
    'permissionNames': [],
    'beginTime': 0,
    'endTime': 1,
    'flag':privacyManager.PermissionUsageFlag.FLAG_PERMISSION_USAGE_DETAIL,
};
try {
    privacyManager.getPermissionUsedRecord(request, (err: BusinessError, data: privacyManager.PermissionUsedResponse) => {
        if (err) {
            console.log(`getPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
        } else {
            console.log(`getPermissionUsedRecord success, data->${JSON.stringify(data)}`);
        }
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.startUsingPermission

startUsingPermission(tokenID: number, permissionName: Permissions): Promise&lt;void&gt;

Starts to use a permission and flushes the permission usage record. This API is called by a system application, either running in the foreground or background, and uses a promise to return the result. This API uses a promise to return the result.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type  | Mandatory| Description                                 |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | Yes  | Application token ID of the invoker. The value can be obtained from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).|
| permissionName | Permissions | Yes  | Name of the permission to use. Valid permission names can be obtained in the [Application Permission List](../../security/permission-list.md).|

**Return value**

| Type         | Description                                   |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The tokenID is 0, permissionName is longer than 256 bytes, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100004 | The interface is called repeatedly with the same input. It means the application specified by the tokenID has been using the specified permission. |
| 12100007 | Service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import privacyManager from '@ohos.privacyManager';
import { BusinessError } from '@ohos.base';

let tokenID: number = 0; // You can use getApplicationInfo to obtain accessTokenId.
try {
    privacyManager.startUsingPermission(tokenID, 'ohos.permission.PERMISSION_USED_STATS').then(() => {
        console.log('startUsingPermission success');
    }).catch((err: BusinessError) => {
        console.log(`startUsingPermission fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.startUsingPermission

startUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback&lt;void&gt;): void

Starts to use a permission and flushes the permission usage record. This API is called by a system application, either running in the foreground or background, and uses a promise to return the result. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type                 | Mandatory| Description                                 |
| -------------- | --------------------- | ---- | ------------------------------------ |
| tokenID        | number                | Yes  | Application token ID of the invoker. The value can be obtained from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).|
| permissionName | Permissions                | Yes  | Name of the permission to use. Valid permission names can be obtained in the [Application Permission List](../../security/permission-list.md).|
| callback       | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The tokenID is 0, permissionName is longer than 256 bytes, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100004 | The interface is called repeatedly with the same input. It means the application specified by the tokenID has been using the specified permission. |
| 12100007 | Service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import privacyManager from '@ohos.privacyManager';
import { BusinessError } from '@ohos.base';

let tokenID: number = 0; // You can use getApplicationInfo to obtain accessTokenId.
try {
    privacyManager.startUsingPermission(tokenID, 'ohos.permission.PERMISSION_USED_STATS', (err: BusinessError, data: void) => {
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

stopUsingPermission(tokenID: number, permissionName: Permissions): Promise&lt;void&gt;

Stops using a permission. This API is called by a system application and uses a promise to return the result. **startUsingPermission** and **stopUsingPermission** are used in pairs. This API uses a promise to return the result.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type  | Mandatory| Description                                 |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | Yes  | Application token ID of the invoker. The value can be obtained from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).|
| permissionName | Permissions | Yes  | Name of the permission to use. Valid permission names can be obtained in the [Application Permission List](../../security/permission-list.md).|

**Return value**

| Type         | Description                                   |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The tokenID is 0, permissionName is longer than 256 bytes, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100004 | The interface is not used with |
| 12100007 | Service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import privacyManager from '@ohos.privacyManager';
import { BusinessError } from '@ohos.base';

let tokenID: number = 0; // You can use getApplicationInfo to obtain accessTokenId.
try {
    privacyManager.stopUsingPermission(tokenID, 'ohos.permission.PERMISSION_USED_STATS').then(() => {
        console.log('stopUsingPermission success');
    }).catch((err: BusinessError) => {
        console.log(`stopUsingPermission fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.stopUsingPermission

stopUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback&lt;void&gt;): void

Stops using a permission. This API is called by a system application and uses a promise to return the result. **startUsingPermission** and **stopUsingPermission** are used in pairs. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type                 | Mandatory| Description                                 |
| -------------- | --------------------- | ---- | ------------------------------------ |
| tokenID        | number                | Yes  | Application token ID of the invoker. The value can be obtained from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).|
| permissionName | Permissions                | Yes  | Name of the permission to use. Valid permission names can be obtained in the [Application Permission List](../../security/permission-list.md).|
| callback       | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The tokenID is 0, permissionName is longer than 256 bytes, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100004 | The interface is not used with |
| 12100007 | Service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import privacyManager from '@ohos.privacyManager';
import { BusinessError } from '@ohos.base';

let tokenID: number = 0; // You can use getApplicationInfo to obtain accessTokenId.
try {
    privacyManager.stopUsingPermission(tokenID, 'ohos.permission.PERMISSION_USED_STATS', (err: BusinessError, data: void) => {
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

on(type: 'activeStateChange', permissionList: Array&lt;Permissions&gt;, callback: Callback&lt;ActiveChangeResponse&gt;): void

Subscribes to the permission usage status changes of the specified permissions.

Multiple callbacks can be registered for the same **permissionList**.

The same callback cannot be registered for the **permissionList**s with common values.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | Yes  | Event type. The value is **'activeStateChange'**, which indicates the permission usage change.  |
| permissionList | Array&lt;Permissions&gt;   | Yes  | List of the permissions to be observed. If this parameter is left empty, this API subscribes to the permission usage status change of all permissions. Valid permission names can be obtained in the [Application Permission List](../../security/permission-list.md).|
| callback | Callback&lt;[ActiveChangeResponse](#activechangeresponse)&gt; | Yes| Callback invoked to return a change in the permission usage.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0, or the string size of permissionName is larger than 256. |
| 12100004 | The interface is called repeatedly with the same input. |
| 12100005 | The registration time has exceeded the limitation. |
| 12100007 | Service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import privacyManager, { Permissions } from '@ohos.privacyManager';
import { BusinessError } from '@ohos.base';

let permissionList: Array<Permissions> = [];
try {
    privacyManager.on('activeStateChange', permissionList, (data: privacyManager.ActiveChangeResponse) => {
        console.debug('receive permission state change, data:' + JSON.stringify(data));
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.off

off(type: 'activeStateChange', permissionList: Array&lt;Permissions&gt;, callback?: Callback&lt;ActiveChangeResponse&gt;): void

Unsubscribes from the permission usage status changes of the specified permissions.

If no callback is passed in **privacyManager.off**, all callbacks of **permissionList** will be unregistered.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | Yes  | Event type. The value is **'activeStateChange'**, which indicates the permission usage change.  |
| permissionList | Array&lt;Permissions&gt;   | Yes  | List of permissions. The value must be the same as that of **on()**. If this parameter is left empty, this API unsubscribes from the permission usage change of all permissions. Valid permission names can be obtained in the [Application Permission List](../../security/permission-list.md).|
| callback | Callback&lt;[ActiveChangeResponse](#activechangeresponse)&gt; | No| Callback for the permission usage change event.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The permissionNames in the list are all invalid, or the list size exceeds 1024 bytes. |
| 12100004 | The interface is not used together with 'on'.|
| 12100007 | Service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import privacyManager, { Permissions } from '@ohos.privacyManager';

let permissionList: Array<Permissions> = [];
try {
    privacyManager.off('activeStateChange', permissionList);
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
| tokenId  | number         | No   | Token ID of the application (invoker).<br> By default, all applications are queried.        |
| isRemote | boolean         | No   | Whether to query the permission usage records of the remote device.<br> The default value is **false**, which means the permission usage records of the local device are queried by default.|
| deviceId  | string         | No   | ID of the device hosting the target application.<br> The default value is the local device ID.  |
| bundleName | string         | No   | Bundle name of the target application.<br> By default, all applications are queried.|
| permissionNames  | Array&lt;Permissions&gt;         | No   | Permissions to query.<br> By default, the usage records of all permissions are queried.              |
| beginTime | number         | No   | Start time of the query, in ms.<br>The default value is **0**, which means the start time is not set.|
| endTime | number         | No   | End time of the query, in ms.<br>The default value is **0**, which means the end time is not set.|
| flag | [PermissionUsageFlag](#permissionusageflag)         | Yes   | Query mode.|

## PermissionUsedResponse

Represents the permission usage records of all applications.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Mandatory  | Description                                      |
| -------- | -------------- | ---- | ---------------------------------------- |
| beginTime | number         | Yes   | Start time of the query, in ms.|
| endTime | number         | Yes   | End time of the query, in ms.|
| bundleRecords  | Array&lt;[BundleUsedRecord](#bundleusedrecord)&gt;         | Yes   | Permission usage records.                                |

## BundleUsedRecord

Represents the permission access records of an application.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Mandatory  | Description                                      |
| -------- | -------------- | ---- | ---------------------------------------- |
| tokenId  | number         | Yes   | Token ID of the application (invoker).                                |
| isRemote | boolean         | Yes   | Whether the token ID belongs to the application on a remote device. The default value is **false**.|
| deviceId  | string         | Yes   | ID of the device hosting the target application.                                |
| bundleName | string         | Yes   | Bundle name of the target application.|
| permissionRecords  | Array&lt;[PermissionUsedRecord](#permissionusedrecord)&gt;         | Yes   | Permission usage records of the target application.                                |

## PermissionUsedRecord

Represents the usage records of a permission.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Mandatory  | Description                                      |
| -------- | -------------- | ---- | ---------------------------------------- |
| permissionName  | Permissions         | Yes   | Name of the permission.                                |
| accessCount | number         | Yes   | Total number of times that the permission is accessed.|
| rejectCount | number         | Yes   | Total number of times that the access to the permission is rejected.|
| lastAccessTime | number         | Yes   | Last time when the permission was accessed, accurate to ms.|
| lastRejectTime | number         | Yes   | Last time when the access to the permission was rejected, accurate to ms.|
| lastAccessDuration | number         | Yes   | Last access duration, in ms.|
| accessRecords  | Array&lt;[UsedRecordDetail](#usedrecorddetail)&gt;         | Yes   | Successful access records. This parameter is valid only when **flag** is **FLAG_PERMISSION_USAGE_DETAIL**. By default, 10 records are provided.                                |
| rejectRecords  | Array&lt;[UsedRecordDetail](#usedrecorddetail)&gt;         | Yes   | Rejected access records. This parameter is valid only when **flag** is **FLAG_PERMISSION_USAGE_DETAIL**. By default, 10 records are provided.                                |

## UsedRecordDetail

Represents the details of a single access record.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Mandatory  | Description                                      |
| -------- | -------------- | ---- | ---------------------------------------- |
| status  | number         | Yes   | Access status.                                |
| lockScreenStatus<sup>11+</sup>  | number         | No   | Status of the screen during the access.<br> - **1**: The screen is not locked when the permission is used.<br> - **2**: The screen is locked when the permission is used.                                |
| timestamp | number         | Yes   | Access timestamp, in ms.|
| accessDuration  | number         | Yes   | Access duration, in ms.                                |
| count<sup>11+</sup> | number | No| Number of successful or failed accesses.|

## PermissionActiveStatus

Enumerates the permission usage statuses.

**System capability**: SystemCapability.Security.AccessToken

| Name                     | Value    | Description             |
| ------------------------- | ------ | ---------------- |
| PERM_INACTIVE             | 0      | The permission is not used.  |
| PERM_ACTIVE_IN_FOREGROUND | 1      | The permission is being used by an application running in the foreground.|
| PERM_ACTIVE_IN_BACKGROUND | 2      | The permission is being used by an application running in the background.|

## ActiveChangeResponse

Defines the detailed permission usage information.

 **System capability**: SystemCapability.Security.AccessToken

| Name          | Type                   | Readable| Writable| Description                  |
| -------------- | ---------------------- | ---- | ---- | --------------------- |
| tokenId        | number                 | Yes  | No  | Token ID of the application.   |
| permissionName | Permissions                 | Yes  | No  | Name of the permission.|
| deviceId       | string                 | Yes  | No  | Device ID.                |
| activeStatus   | [PermissionActiveStatus](#permissionactivestatus) | Yes  | No  | Permission usage status.       |
