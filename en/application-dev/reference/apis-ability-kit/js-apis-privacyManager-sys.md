# @ohos.privacyManager (Privacy Management) (System API)

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
The permission usage record includes the application identity (token ID) of the invoker, name of the permission used, and number of successful and failed accesses to the target application.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Application token ID of the caller, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions | Yes  | Name of the permission.|
| successCount | number | Yes  | Number of successful accesses.|
| failCount | number | Yes  | Number of failed accesses.|
| options<sup>12+</sup> | [AddPermissionUsedRecordOptions](#addpermissionusedrecordoptions12) | No  | Options for adding a permission usage record. This parameter is supported since API version 12.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, the count value is invalid, or usedType in AddPermissionUsedRecordOptions is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
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
The permission usage record includes the application identity (token ID) of the invoker, name of the permission used, and number of successful and failed accesses to the target application.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Application token ID of the caller, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions | Yes  | Permission name. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|
| successCount | number | Yes  | Number of successful accesses.|
| failCount | number | Yes  | Number of failed accesses.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
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
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The value of flag in request is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
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
| callback | AsyncCallback<[PermissionUsedResponse](#permissionusedresponse)> | Yes| Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the permission usage record obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The value of flag in request is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
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

## privacyManager.startUsingPermission

startUsingPermission(tokenID: number, permissionName: Permissions): Promise&lt;void&gt;

Starts to use a permission and flushes the permission usage record. This API is called by a system application, either running in the foreground or background, and uses a promise to return the result. This API uses a promise to return the result.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type  | Mandatory| Description                                 |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | Yes  | Application token ID of the caller, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions | Yes  | Permission to use. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|

**Return value**

| Type         | Description                                   |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
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

## privacyManager.startUsingPermission

startUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback&lt;void&gt;): void

Starts to use a permission and flushes the permission usage record. This API is called by a system application, either running in the foreground or background, and uses a promise to return the result. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type                 | Mandatory| Description                                 |
| -------------- | --------------------- | ---- | ------------------------------------ |
| tokenID        | number                | Yes  | Application token ID of the caller, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions                | Yes  | Permission to use. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|
| callback       | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
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

Stops using a permission. This API is called by a system application and uses a promise to return the result. **startUsingPermission** and **stopUsingPermission** are used in pairs. This API uses a promise to return the result.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type  | Mandatory| Description                                 |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | Yes  | Application token ID of the caller, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions | Yes  | Permission to use. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|

**Return value**

| Type         | Description                                   |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
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

## privacyManager.stopUsingPermission

stopUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback&lt;void&gt;): void

Stops using a permission. This API is called by a system application and uses a promise to return the result. **startUsingPermission** and **stopUsingPermission** are used in pairs. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name         | Type                 | Mandatory| Description                                 |
| -------------- | --------------------- | ---- | ------------------------------------ |
| tokenID        | number                | Yes  | Application token ID of the caller, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions                | Yes  | Permission to use. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|
| callback       | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
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

Subscribes to the permission usage status changes of the specified permissions.

Multiple callbacks can be registered for the same **permissionList**.

The same callback cannot be registered for the **permissionList**s with common values.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | Yes  | Event type. The value is **'activeStateChange'**, which indicates the permission usage change.  |
| permissionList | Array&lt;Permissions&gt;   | Yes  | Permissions to be observed. If this parameter is left empty, this API subscribes to usage status changes of all permissions. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|
| callback | Callback&lt;[ActiveChangeResponse](#activechangeresponse)&gt; | Yes| Callback invoked to return a change in the permission usage.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, or the permissionName exceeds 256 characters. |
| 12100004 | The API is used repeatedly with the same input. |
| 12100005 | The registration time has exceeded the limitation. |
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

Unsubscribes from the permission usage status changes of the specified permissions.

If no callback is passed in **privacyManager.off**, all callbacks of **permissionList** will be unregistered.

**Required permissions**: ohos.permission.PERMISSION_USED_STATS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | Yes  | Event type. The value is **'activeStateChange'**, which indicates the permission usage change.  |
| permissionList | Array&lt;Permissions&gt;   | Yes  | List of permissions. The value must be the same as that of **on()**. If this parameter is left empty, this API unsubscribes from usage status changes of all permissions. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|
| callback | Callback&lt;[ActiveChangeResponse](#activechangeresponse)&gt; | No| Callback for the permission usage change event.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The permissionNames in the list are all invalid, or the list size exceeds 1024 bytes. |
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
| tokenId            | number                | No  | ID of the application that uses the sensitive permission. If this parameter is left empty, this API obtains the sensitive permission access information of all applications.  |
| permissionName     | Permissions           | No  | Name of the sensitive permission used. If this parameter is left blank, this API obtains the access information about all sensitive permissions.  |

**Return value**

| Type         | Description                                   |
| ------------- | --------------------------------------- |
| Promise&lt;Array&lt;[PermissionUsedTypeInfo](#permissionusedtypeinfo12)&gt;&gt; | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
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

| Name      | Type            | Readable| Writable| Description                                      |
| --------- | -------------- | ---- | ---- | ---------------------------------------- |
| beginTime | number         | Yes   | No   | Start time of the query, in ms.|
| endTime   | number         | Yes   | No   | End time of the query, in ms.|
| bundleRecords  | Array&lt;[BundleUsedRecord](#bundleusedrecord)&gt;         | Yes   | No   | Permission usage records.                                |

## BundleUsedRecord

Represents the permission access records of an application.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Readable| Writable| Description                                      |
| -------- | -------------- | ---- | ---- | ---------------------------------------- |
| tokenId  | number         | Yes   | No   | Token ID of the application (invoker).                                |
| isRemote | boolean         | Yes   | No   | Whether the token ID belongs to the application on a remote device. The default value is **false**.|
| deviceId  | string         | Yes   | No   | ID of the device hosting the target application.                                |
| bundleName | string         | Yes   | No   | Bundle name of the target application.|
| permissionRecords  | Array&lt;[PermissionUsedRecord](#permissionusedrecord)&gt;         | Yes   | No   | Permission usage records of the target application.                                |

## PermissionUsedRecord

Represents the usage records of a permission.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Readable| Writable| Description                                      |
| -------- | -------------- | ---- | ---- | ---------------------------------------- |
| permissionName  | Permissions         | Yes   | No   | Name of the permission.                                |
| accessCount | number         | Yes   | No   | Total number of times that the permission is accessed.|
| rejectCount | number         | Yes   | No   | Total number of times that the access to the permission is rejected.|
| lastAccessTime | number         | Yes   | No   | Last time when the permission was accessed, accurate to ms.|
| lastRejectTime | number         | Yes   | No   | Last time when the access to the permission was rejected, accurate to ms.|
| lastAccessDuration | number         | Yes   | No   | Last access duration, in ms.|
| accessRecords  | Array&lt;[UsedRecordDetail](#usedrecorddetail)&gt;         | Yes   | No   | Successful access records. This parameter is valid only when **flag** is **FLAG_PERMISSION_USAGE_DETAIL**. By default, 10 records are provided.                                |
| rejectRecords  | Array&lt;[UsedRecordDetail](#usedrecorddetail)&gt;         | Yes   | No   | Rejected access records. This parameter is valid only when **flag** is **FLAG_PERMISSION_USAGE_DETAIL**. By default, 10 records are provided.                                |

## UsedRecordDetail

Represents the details of a single access record.

**System capability**: SystemCapability.Security.AccessToken

| Name      | Type            | Readable| Writable| Description                                      |
| -------- | -------------- | ---- | ---- | ---------------------------------------- |
| status  | number         | Yes   | No   | Access status.                                |
| lockScreenStatus<sup>11+</sup>  | number         | Yes   | No   | Status of the screen during the access.<br> - **1**: The screen is not locked when the permission is used.<br> - **2**: The screen is locked when the permission is used.                                |
| timestamp | number         | Yes   | No   | Access timestamp, in ms.|
| accessDuration  | number         | Yes   | No   | Access duration, in ms.                                |
| count<sup>11+</sup> | number | Yes| No   | Number of successful or failed accesses.
| usedType<sup>12+</sup> | [PermissionUsedType](#permissionusedtype12) | Yes| No   | Means for using the sensitive permission.|

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
| permissionName | Permissions            | Yes  | No  | Name of the permission.|
| deviceId       | string                 | Yes  | No  | Device ID.                |
| activeStatus   | [PermissionActiveStatus](#permissionactivestatus) | Yes  | No  | Permission usage status.       |

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

| Name          | Type                   | Readable| Writable| Description                  |
| -------------- | ---------------------- | ---- | ---- | --------------------- |
| tokenId        | number                 | Yes  | No  | ID of the application that uses the sensitive permission.|
| permissionName | Permissions            | Yes  | No  | Name of the sensitive permission.|
| usedType | [PermissionUsedType](#permissionusedtype12) | Yes| No   | Means for using the sensitive permission.|

## AddPermissionUsedRecordOptions<sup>12+</sup>

Represents the options for adding a permission usage record.

 **System capability**: SystemCapability.Security.AccessToken

| Name          | Type                   | Readable| Writable| Description                  |
| -------------- | ---------------------- | ---- | ---- | --------------------- |
| usedType | [PermissionUsedType](#permissionusedtype12) | Yes| No   | Means for using the sensitive permission.|
