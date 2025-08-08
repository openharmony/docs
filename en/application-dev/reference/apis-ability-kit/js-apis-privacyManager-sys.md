# @ohos.privacyManager (Privacy Management) (System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--SE: @linshuqing; @hehehe-li-->
<!--TSE: @leiyuqian-->

The **privacyManager** module provides APIs for privacy management, such as management of permission usage records.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { privacyManager } from '@kit.AbilityKit';
```


## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number, options?: AddPermissionUsedRecordOptions): Promise&lt;void&gt;

Adds a permission usage record when an application protected by the permission is called by another service or application. This API uses a promise to return the result.
The permission usage record includes the application identity (token ID) of the caller, name of the permission used, and number of successful and failed accesses to the target application.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Token ID of the caller, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions | Yes  | Name of the permission.|
| successCount | number | Yes  | Number of successful accesses.|
| failCount | number | Yes  | Number of failed accesses.|
| options<sup>12+</sup> | [AddPermissionUsedRecordOptions](#addpermissionusedrecordoptions12) | No  | Options for adding a permission usage record. The default value is **NORMAL_TYPE**. This parameter is supported since API version 12.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, the count value is invalid, or usedType in [AddPermissionUsedRecordOptions](#addpermissionusedrecordoptions12) is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // You can use getApplicationInfo to obtain accessTokenId.
privacyManager.addPermissionUsedRecord(tokenID, 'ohos.permission.READ_AUDIO', 1, 0).then(() => {
  console.log('addPermissionUsedRecord success');
}).catch((err: BusinessError) => {
  console.error(`addPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
});
// with options param
let options: privacyManager.AddPermissionUsedRecordOptions = {
  usedType: privacyManager.PermissionUsedType.PICKER_TYPE
};
privacyManager.addPermissionUsedRecord(tokenID, 'ohos.permission.READ_AUDIO', 1, 0, options).then(() => {
  console.log('addPermissionUsedRecord success');
}).catch((err: BusinessError) => {
  console.error(`addPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
});
```

## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number, callback: AsyncCallback&lt;void&gt;): void

Adds a permission usage record when an application protected by the permission is called by another service or application. This API uses an asynchronous callback to return the result.
The permission usage record includes the application identity (token ID) of the caller, name of the permission used, and number of successful and failed accesses to the target application.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Token ID of the caller, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions | Yes  | Permission name. For details, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| successCount | number | Yes  | Number of successful accesses.|
| failCount | number | Yes  | Number of failed accesses.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // You can use getApplicationInfo to obtain accessTokenId.
privacyManager.addPermissionUsedRecord(tokenID, 'ohos.permission.READ_AUDIO', 1, 0, (err: BusinessError, data: void) => {
  if (err) {
    console.error(`addPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
  } else {
    console.log('addPermissionUsedRecord success');
  }
});
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

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The value of flag, begin, or end in request is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

privacyManager.getPermissionUsedRecord(request).then((data) => {
  console.log(`getPermissionUsedRecord success, data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`getPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
});
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
| callback | AsyncCallback<[PermissionUsedResponse](#permissionusedresponse)> | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the permission usage record obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The value of flag, begin, or end in request is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

privacyManager.getPermissionUsedRecord(request, (err: BusinessError, data: privacyManager.PermissionUsedResponse) => {
  if (err) {
    console.error(`getPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
  } else {
    console.log(`getPermissionUsedRecord success, data->${JSON.stringify(data)}`);
  }
});
```

## privacyManager.setPermissionUsedRecordToggleStatus<sup>18+</sup>

setPermissionUsedRecordToggleStatus(status: boolean): Promise&lt;void&gt;

Sets whether to record the permission usage of this user. This API uses a promise to return the result.

If **status** is **true**, [addPermissionUsedRecord](#privacymanageraddpermissionusedrecord) can be called to add permission usage records. If **status** is set **false**, [addPermissionUsedRecord](#privacymanageraddpermissionusedrecord) does not add permission usage records. Instead, it deletes the historical records of the user.

**Required permissions**: ohos.permission.PERMISSION_RECORD_TOGGLE (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type  | Mandatory| Description                                 |
| -------------- | ------ | ---- | ------------------------------------ |
| status        | boolean | Yes  | Setting of the permission usage record switch. The value **true** means the switch is toggled on; the value **false** means the opposite.|

**Return value**

| Type         | Description                                   |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_RECORD_TOGGLE". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100007 | The service is abnormal. |
| 12100009 | Common inner error. |

**Example**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

privacyManager.setPermissionUsedRecordToggleStatus(true).then(() => {
  console.log('setPermissionUsedRecordToggleStatus success');
}).catch((err: BusinessError) => {
  console.error(`setPermissionUsedRecordToggleStatus fail, err->${JSON.stringify(err)}`);
});
```

## privacyManager.getPermissionUsedRecordToggleStatus<sup>18+</sup>

getPermissionUsedRecordToggleStatus(): Promise&lt;boolean&gt;

Obtains the settings of the permission usage record switch for this user. This API uses a promise to return the result.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Return value**

| Type         | Description                                   |
| ------------- | --------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the switch settings. **true** to enable, **false** otherwise.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 12100007 | The service is abnormal. |

**Example**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

privacyManager.getPermissionUsedRecordToggleStatus().then((res) => {
  console.log('getPermissionUsedRecordToggleStatus success');
  if (res == true) {
    console.log('get status is TRUE');
  } else {
    console.log('get status is FALSE');
  }
}).catch((err: BusinessError) => {
  console.error(`getPermissionUsedRecordToggleStatus fail, err->${JSON.stringify(err)}`);
});
```

## privacyManager.startUsingPermission

startUsingPermission(tokenID: number, permissionName: Permissions): Promise&lt;void&gt;

Starts using a permission. This API is called by a system application to report the permission usage of an application in the foreground and background, allowing the privacy service to respond based on the application lifecycle. This API uses a promise to return the result.

When an application starts to use a permission, the privacy service notifies the privacy indicator that the application is using the permission. Upon the application's exit, the privacy service notifies the privacy indicator that the application has stopped using the permission and clears the corresponding cache.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type  | Mandatory| Description                                 |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | Yes  | Token ID of the caller, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions | Yes  | Permission to use. For details, see [Application Permissions](../../security/AccessToken/app-permissions.md).|

**Return value**

| Type         | Description                                   |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the type of the specified tokenID is not of the application type. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100004 | The API is used repeatedly with the same input. It means the application specified by the tokenID has been using the specified permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // You can use getApplicationInfo to obtain accessTokenId.
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO').then(() => {
  console.log('startUsingPermission success');
}).catch((err: BusinessError) => {
  console.error(`startUsingPermission fail, err->${JSON.stringify(err)}`);
});
```

## privacyManager.startUsingPermission<sup>18+</sup>

startUsingPermission(tokenID: number, permissionName: Permissions, pid?: number, usedType?: PermissionUsedType): Promise&lt;void&gt;

Starts using a permission. This API is called by a system application to report the permission usage of an application in the foreground and background, allowing the privacy service to respond based on the application lifecycle. This API uses a promise to return the result.

When an application starts to use a permission, the privacy service notifies the privacy indicator that the application is using the permission. Upon the application's exit, the privacy service notifies the privacy indicator that the application has stopped using the permission and clears the corresponding cache.

For a multi-process application, you can specify the process ID (PID) of the application when reporting the permission usage. If no PID is specified, the privacy service responds by application. When the application exits, the privacy service notifies the privacy indicator and clears the cache.

If a PID is specified, the privacy service responds by process. when the process exits, the privacy service notifies the privacy indicator and clears the cache. In this case, the PID must be that of the application corresponding to the token ID.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type  | Mandatory| Description                                 |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | Yes  | Token ID of the caller, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions | Yes  | Permission to use. For details, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| pid            | number | No  | PID of the caller. The default value is **-1**, which indicates that the privacy service does not respond based on the process lifecycle.|
| usedType       | [PermissionUsedType](#permissionusedtype12) | No| Sensitive permission access mode. The default value is **NORMAL_TYPE**.|

**Return value**

| Type         | Description                                   |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, the type of the specified tokenID is not of the application type, or usedType is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100004 | The API is used repeatedly with the same input. It means the application specified by the tokenID has been using the specified permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit'

let tokenID: number = rpc.IPCSkeleton.getCallingTokenId(); // accessTokenId can also be obtained by using bundleManager.getBundleInfoForSelfSync.
let pid: number = rpc.IPCSkeleton.getCallingPid();
let usedType: privacyManager.PermissionUsedType = privacyManager.PermissionUsedType.PICKER_TYPE;

// without pid and usedType
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO').then(() => {
  console.log('startUsingPermission success');
}).catch((err: BusinessError) => {
  console.error(`startUsingPermission fail, err->${JSON.stringify(err)}`);
});
// with pid
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', pid).then(() => {
  console.log('startUsingPermission success');
}).catch((err: BusinessError) => {
  console.error(`startUsingPermission fail, err->${JSON.stringify(err)}`);
});
// with usedType
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', -1, usedType).then(() => {
  console.log('startUsingPermission success');
}).catch((err: BusinessError) => {
  console.error(`startUsingPermission fail, err->${JSON.stringify(err)}`);
});
// with pid and usedType
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', pid, usedType).then(() => {
  console.log('startUsingPermission success');
}).catch((err: BusinessError) => {
  console.error(`startUsingPermission fail, err->${JSON.stringify(err)}`);
});
```

## privacyManager.startUsingPermission

startUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback&lt;void&gt;): void

Starts using a permission. This API is called by a system application to report the permission usage of an application in the foreground and background, allowing the privacy service to respond based on the application lifecycle. This API uses an asynchronous callback to return the result.

When an application starts to use a permission, the privacy service notifies the privacy indicator that the application is using the permission. Upon the application's exit, the privacy service notifies the privacy indicator that the application has stopped using the permission and clears the corresponding cache.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type                 | Mandatory| Description                                 |
| -------------- | --------------------- | ---- | ------------------------------------ |
| tokenID        | number                | Yes  | Token ID of the caller, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions                | Yes  | Permission to use. For details, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| callback       | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the type of the specified tokenID is not of the application type. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100004 | The API is used repeatedly with the same input. It means the application specified by the tokenID has been using the specified permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // You can use getApplicationInfo to obtain accessTokenId.
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', (err: BusinessError, data: void) => {
  if (err) {
    console.error(`startUsingPermission fail, err->${JSON.stringify(err)}`);
  } else {
    console.log('startUsingPermission success');
  }
});
```

## privacyManager.stopUsingPermission

stopUsingPermission(tokenID: number, permissionName: Permissions): Promise&lt;void&gt;

Stops using a permission. This API must be called by a system application, and used with **startUsingPermission** in pairs. This API uses a promise to return the result.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type  | Mandatory| Description                                 |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | Yes  | Token ID of the caller, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions | Yes  | Permission to use. For details, see [Application Permissions](../../security/AccessToken/app-permissions.md).|

**Return value**

| Type         | Description                                   |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the type of the specified tokenID is not of the application type. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100004 | The API is not used in pair with 'startUsingPermission'. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // You can use getApplicationInfo to obtain accessTokenId.
privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO').then(() => {
  console.log('stopUsingPermission success');
}).catch((err: BusinessError) => {
  console.error(`stopUsingPermission fail, err->${JSON.stringify(err)}`);
});
```

## privacyManager.stopUsingPermission<sup>18+</sup>

stopUsingPermission(tokenID: number, permissionName: Permissions, pid?: number): Promise&lt;void&gt;

Stops using a permission. This API must be called by a system application, and used with **startUsingPermission** in pairs. This API uses a promise to return the result.

The value of **pid** must match that used in **startUsingPermission**.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type  | Mandatory| Description                                 |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | Yes  | Token ID of the caller, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions | Yes  | Permission to use. For details, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| pid            | number | No  | PID of the application. The value must match that used in **startUsingPermission**. The default value is **-1**.|

**Return value**

| Type         | Description                                   |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the type of the specified tokenID is not of the application type. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100004 | The API is not used in pair with 'startUsingPermission'. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit'

let tokenID: number = rpc.IPCSkeleton.getCallingTokenId(); // accessTokenId can also be obtained by using bundleManager.getBundleInfoForSelfSync.
let pid: number = rpc.IPCSkeleton.getCallingPid();

// without pid
privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO').then(() => {
  console.log('stopUsingPermission success');
}).catch((err: BusinessError) => {
  console.error(`stopUsingPermission fail, err->${JSON.stringify(err)}`);
});

// with pid
privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', pid).then(() => {
  console.log('stopUsingPermission success');
}).catch((err: BusinessError) => {
  console.error(`stopUsingPermission fail, err->${JSON.stringify(err)}`);
});
```

## privacyManager.stopUsingPermission

stopUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback&lt;void&gt;): void

Stops using a permission. This API must be called by a system application, and used with **startUsingPermission** in pairs. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type                 | Mandatory| Description                                 |
| -------------- | --------------------- | ---- | ------------------------------------ |
| tokenID        | number                | Yes  | Token ID of the caller, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions                | Yes  | Permission to use. For details, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| callback       | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the type of the specified tokenID is not of the application type. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100004 | The API is not used in pair with 'startUsingPermission'. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // You can use getApplicationInfo to obtain accessTokenId.
privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', (err: BusinessError, data: void) => {
  if (err) {
    console.error(`stopUsingPermission fail, err->${JSON.stringify(err)}`);
  } else {
    console.log('stopUsingPermission success');
  }
});
```

## privacyManager.on

on(type: 'activeStateChange', permissionList: Array&lt;Permissions&gt;, callback: Callback&lt;ActiveChangeResponse&gt;): void

Subscribes to changes in the permission usage status of the specified permissions.

Multiple callbacks can be registered for the same **permissionList**.

The same callback cannot be registered for the **permissionList**s with overlapping values.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | Yes  | Event type. The value is **'activeStateChange'**, which indicates the permission usage change.  |
| permissionList | Array&lt;Permissions&gt;   | Yes  | List of target permissions. If this parameter is not specified, this API will subscribe to usage changes of all permissions. For details about the permissions, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| callback | Callback&lt;[ActiveChangeResponse](#activechangeresponse)&gt; | Yes| Callback used to return the permission usage change.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The permissionList exceeds the size limit, or the permissionNames in the list are all invalid. |
| 12100004 | The API is used repeatedly with the same input. |
| 12100005 | The registration time has exceeded the limit. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import { privacyManager, Permissions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let permissionList: Array<Permissions> = [];
try {
    privacyManager.on('activeStateChange', permissionList, (data: privacyManager.ActiveChangeResponse) => {
        console.debug('receive permission state change, data:' + JSON.stringify(data));
    });
} catch(err) {
    console.error(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.off

off(type: 'activeStateChange', permissionList: Array&lt;Permissions&gt;, callback?: Callback&lt;ActiveChangeResponse&gt;): void

Unsubscribes from changes in the permission usage of the specified permissions.

If **callback** is not specified, this API will unregister all callbacks for **permissionList**.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | Yes  | Event type. The value is **'activeStateChange'**, which indicates the permission usage change.  |
| permissionList | Array&lt;Permissions&gt;   | Yes  | List of target permissions. The value must be the same as that in **on()**. If this parameter is not specified, this API will unsubscribe from usage changes for all permissions. For details about the permissions, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| callback | Callback&lt;[ActiveChangeResponse](#activechangeresponse)&gt; | No| Callback to unregister.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The permissionList is not in the listening list. |
| 12100004 | The API is not used in pair with 'on'. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import { privacyManager, Permissions } from '@kit.AbilityKit';

let permissionList: Array<Permissions> = [];
try {
    privacyManager.off('activeStateChange', permissionList);
} catch(err) {
    console.error(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.getPermissionUsedTypeInfos<sup>12+</sup>

getPermissionUsedTypeInfos(tokenId?: number, permissionName?: Permissions): Promise&lt;Array&lt;PermissionUsedTypeInfo&gt;&gt;

Obtains information about how a sensitive permission is used by an application.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| tokenId            | number                | No  | ID of the application that uses the sensitive permission. If this parameter is **0**, this API obtains the sensitive permission access information of all applications.  |
| permissionName     | Permissions           | No  | Name of the sensitive permission used. If this parameter is left blank, this API obtains the access information about all sensitive permissions.  |

**Return value**

| Type         | Description                                   |
| ------------- | --------------------------------------- |
| Promise&lt;Array&lt;[PermissionUsedTypeInfo](#permissionusedtypeinfo12)&gt;&gt; | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 12100001 | Invalid parameter. PermissionName exceeds 256 characters. |
| 12100002 | The input tokenId does not exist. |
| 12100003 | The input permissionName does not exist. |

**Example**

```ts
import { privacyManager, Permissions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenId: number = 0; // You can use bundleManager.getApplicationInfo to obtain accessTokenId.
let permissionName: Permissions = 'ohos.permission.CAMERA';
// Without any parameter.
privacyManager.getPermissionUsedTypeInfos().then(() => {
  console.log('getPermissionUsedTypeInfos success');
}).catch((err: BusinessError) => {
  console.error(`getPermissionUsedTypeInfos fail, err->${JSON.stringify(err)}`);
});
// Pass in tokenId only.
privacyManager.getPermissionUsedTypeInfos(tokenId).then(() => {
  console.log('getPermissionUsedTypeInfos success');
}).catch((err: BusinessError) => {
  console.error(`getPermissionUsedTypeInfos fail, err->${JSON.stringify(err)}`);
});
// Pass in permissionName only.
privacyManager.getPermissionUsedTypeInfos(null, permissionName).then(() => {
  console.log('getPermissionUsedTypeInfos success');
}).catch((err: BusinessError) => {
  console.error(`getPermissionUsedTypeInfos fail, err->${JSON.stringify(err)}`);
});
// Pass in tokenId and permissionName.
privacyManager.getPermissionUsedTypeInfos(tokenId, permissionName).then(() => {
  console.log('getPermissionUsedTypeInfos success');
}).catch((err: BusinessError) => {
  console.error(`getPermissionUsedTypeInfos fail, err->${JSON.stringify(err)}`);
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

| Name      | Type            | Read-Only| Optional| Description                                      |
| -------- | -------------- | ---- | ---- | ---------------------------------------- |
| tokenId  | number         | No   | Yes   | Token ID of the application (caller).<br> The default value is **0**, indicating that all applications are queried.        |
| isRemote | boolean         | No   | Yes   | Whether to query the permission usage records of the remote device.<br> **false** (default) to query the local device; **true** to query the remote device.|
| deviceId  | string         | No   | Yes   | ID of the device hosting the target application.<br> The default value is the local device ID.  |
| bundleName | string         | No   | Yes   | Bundle name of the target application.<br> By default, all applications are queried.|
| permissionNames  | Array&lt;Permissions&gt;         | No   | Yes   | Permissions to query.<br> By default, the usage records of all permissions are queried.              |
| beginTime | number         | No   | Yes   | Start time of the query, in ms.<br>The default value is **0**, which means the start time is not set.|
| endTime | number         | No   | Yes   | End time of the query, in ms.<br>The default value is **0**, which means the end time is not set.|
| flag | [PermissionUsageFlag](#permissionusageflag)         | No   | No   | Query mode.|

## PermissionUsedResponse

Represents the permission usage records of all applications.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Read-Only| Optional| Description                                      |
| --------- | -------------- | ---- | ---- | ---------------------------------------- |
| beginTime | number         | No   | No   | Start time of the query, in ms.|
| endTime   | number         | No   | No   | End time of the query, in ms.|
| bundleRecords  | Array&lt;[BundleUsedRecord](#bundleusedrecord)&gt;         | No   | No   | Permission usage records.                                |

## BundleUsedRecord

Represents the permission access records of an application.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Read-Only| Optional| Description                                      |
| -------- | -------------- | ---- | ---- | ---------------------------------------- |
| tokenId  | number         | No   | No   | Token ID of the application (caller).                                |
| isRemote | boolean         | No   | No   | Whether it is a distributed device. **false** (default) means non-distributed devices; **true** means distributed devices.|
| deviceId  | string         | No   | No   | ID of the device hosting the target application.                                |
| bundleName | string         | No   | No   | Bundle name of the target application.|
| permissionRecords  | Array&lt;[PermissionUsedRecord](#permissionusedrecord)&gt;         | No   | No   | Permission usage records of the target application.                                |

## PermissionUsedRecord

Represents the usage records of a permission.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Read-Only| Optional| Description                                      |
| -------- | -------------- | ---- | ---- | ---------------------------------------- |
| permissionName  | Permissions         | No   | No   | Name of the permission.                                |
| accessCount | number         | No   | No   | Total number of times that the permission is accessed.|
| rejectCount | number         | No   | No   | Total number of times that the access to the permission is rejected.|
| lastAccessTime | number         | No   | No   | Last time when the permission was accessed, accurate to ms.|
| lastRejectTime | number         | No   | No   | Last time when the access to the permission was rejected, accurate to ms.|
| lastAccessDuration | number         | No   | No   | Last access duration, in ms.|
| accessRecords  | Array&lt;[UsedRecordDetail](#usedrecorddetail)&gt;         | No   | No   | Successful access records. This parameter is valid only when **flag** is **FLAG_PERMISSION_USAGE_DETAIL**. By default, 10 records are provided.                                |
| rejectRecords  | Array&lt;[UsedRecordDetail](#usedrecorddetail)&gt;         | No   | No   | Rejected access records. This parameter is valid only when **flag** is **FLAG_PERMISSION_USAGE_DETAIL**. By default, 10 records are provided.                                |

## UsedRecordDetail

Represents the details of a single access record.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Read-Only| Optional| Description                                      |
| -------- | -------------- | ---- | ---- | ---------------------------------------- |
| status  | number         | No   | No   | Access status.                                |
| lockScreenStatus<sup>11+</sup>  | number         | No   | Yes   | Status of the screen during the access.<br> - **1**: The screen is not locked when the permission is used.<br> - **2**: The screen is locked when the permission is used.                                |
| timestamp | number         | No   | No   | Access timestamp, in ms.|
| accessDuration  | number         | No   | No   | Access duration, in ms.                                |
| count<sup>11+</sup> | number | No| Yes   | Number of successful or failed accesses.
| usedType<sup>12+</sup> | [PermissionUsedType](#permissionusedtype12) | No| Yes   | Means for using the sensitive permission.|

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

| Name          | Type                   | Read-Only| Optional| Description                  |
| -------------- | ---------------------- | ---- | ---- | --------------------- |
| callingTokenId<sup>18+</sup> | number   | No  | Yes  | Token ID of the caller. This parameter is invalid when **activeStatus** is **INACTIVE**.|
| tokenId        | number                 | No  | No  | Token ID of the application whose permission usage changes are subscribed to.   |
| permissionName | Permissions            | No  | No  | Permissions whose usage status changes.|
| deviceId       | string                 | No  | No  | Device ID.                |
| activeStatus   | [PermissionActiveStatus](#permissionactivestatus) | No  | No  | Permission usage status.       |
| usedType<sup>18+</sup> | [PermissionUsedType](#permissionusedtype12) | No  | Yes  | Sensitive permission access mode. This parameter is invalid when **activeStatus** is **INACTIVE**.|

## PermissionUsedType<sup>12+</sup>

Enumerates the means for using a sensitive permission.

**System capability**: SystemCapability.Security.AccessToken

| Name                   | Value| Description             |
| ----------------------- | -- | ---------------- |
| NORMAL_TYPE             | 0  | The sensitive permission is used after authorization through a dialog box or a system settings page.  |
| PICKER_TYPE             | 1  | The sensitive permission is used through a system picker. This access mode does not grant the permissions to the application.|
| SECURITY_COMPONENT_TYPE | 2  | The sensitive permission is used through a security component, which comes with the authorization.|

## PermissionUsedTypeInfo<sup>12+</sup>

Represents detailed information about the use of a permission.

 **System capability**: SystemCapability.Security.AccessToken

| Name          | Type                   | Read-Only| Optional| Description                  |
| -------------- | ---------------------- | ---- | ---- | --------------------- |
| tokenId        | number                 | No  | No  | Token ID of the application that uses the sensitive permission.|
| permissionName | Permissions            | No  | No  | Name of the sensitive permission.|
| usedType | [PermissionUsedType](#permissionusedtype12) | No| No   | Access mode of the sensitive permission.|

## AddPermissionUsedRecordOptions<sup>12+</sup>

Represents the options for adding a permission usage record.

 **System capability**: SystemCapability.Security.AccessToken

| Name          | Type                   | Read-Only| Optional| Description                  |
| -------------- | ---------------------- | ---- | ---- | --------------------- |
| usedType | [PermissionUsedType](#permissionusedtype12) | No| Yes   | Access mode of the sensitive permission.|
