# @ohos.abilityAccessCtrl (Application Access Control) (System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--SE: @linshuqing; @hehehe-li-->
<!--TSE: @leiyuqian-->

The **abilityAccessCtrl** module provides APIs for application permission management, including authentication, authorization, and revocation.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.abilityAccessCtrl (Application Access Control)](js-apis-abilityAccessCtrl.md).

## Modules to Import

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
```

## AtManager

Provides APIs for application access control.

### grantUserGrantedPermission

grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise&lt;void&gt;

Grants a user_grant permission to an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GRANT_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Identifier of the target application, which is the value of **accessTokenId** contained in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions              | Yes  | Permission to grant. For details, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| permissionFlags  | number | Yes  | Permission flag.<br>- **1**: A dialog box for user authorization will be displayed the next time if the user denies authorization for the permission.<br>- **2**: No dialog box will be displayed the next time if the user denies authorization for the permission. The permission must be granted by the user in **Settings**.<br>- **64**: The permission is given just once if the user allows the permission only this time. The authorization is canceled after the application is switched to the background or exits.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.GRANT_SENSITIVE_PERMISSIONS". |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters or is not declared in the module.json file, or the flags value is invalid. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100006 | The application specified by the tokenID is not allowed to be granted with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | The service is abnormal. |

**Example**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a non-system application.
let permissionFlags: number = 1;
atManager.grantUserGrantedPermission(tokenID, 'ohos.permission.READ_AUDIO', permissionFlags).then(() => {
  console.log('grantUserGrantedPermission success');
}).catch((err: BusinessError) => {
  console.error(`grantUserGrantedPermission fail, err->${JSON.stringify(err)}`);
});
```

### grantUserGrantedPermission

grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number, callback: AsyncCallback&lt;void&gt;): void

Grants a user_grant permission to an application. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GRANT_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Identifier of the target application, which is the value of **accessTokenId** contained in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions              | Yes  | Permission to grant. For details, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| permissionFlags  | number | Yes  | Permission flag.<br>- **1**: A dialog box for user authorization will be displayed the next time if the user denies authorization for the permission.<br>- **2**: No dialog box will be displayed the next time if the user denies authorization for the permission. The permission must be granted by the user in **Settings**.<br>- **64**: The permission is given just once if the user allows the permission only this time. The authorization is canceled after the application is switched to the background or exits.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the permission is granted, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.GRANT_SENSITIVE_PERMISSIONS". |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters or is not declared in the module.json file, or the flags value is invalid. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100006 | The application specified by the tokenID is not allowed to be granted with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | The service is abnormal. |

**Example**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a non-system application.
let permissionFlags: number = 1;
atManager.grantUserGrantedPermission(tokenID, 'ohos.permission.READ_AUDIO', permissionFlags, (err: BusinessError, data: void) => {
  if (err) {
    console.error(`grantUserGrantedPermission fail, err->${JSON.stringify(err)}`);
  } else {
    console.log('grantUserGrantedPermission success');
  }
});
```

### revokeUserGrantedPermission

revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise&lt;void&gt;

Revokes a user_grant permission from an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.REVOKE_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Identifier of the target application, which is the value of **accessTokenId** contained in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions              | Yes  | Permission to revoke. For details, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| permissionFlags  | number | Yes  | Permission flag.<br>- **1**: A dialog box for user authorization will be displayed the next time if the user denies authorization for the permission.<br>- **2**: No dialog box will be displayed the next time if the user denies authorization for the permission. The permission must be granted by the user in **Settings**.<br>- **64**: The permission is given just once if the user allows the permission only this time. The authorization is canceled after the application is switched to the background or exits.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.REVOKE_SENSITIVE_PERMISSIONS". |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters or is not declared in the module.json file, or the flags value is invalid. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100006 | The application specified by the tokenID is not allowed to be revoked with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | The service is abnormal. |

**Example**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a non-system application.
let permissionFlags: number = 1;
atManager.revokeUserGrantedPermission(tokenID, 'ohos.permission.READ_AUDIO', permissionFlags).then(() => {
  console.log('revokeUserGrantedPermission success');
}).catch((err: BusinessError) => {
  console.error(`revokeUserGrantedPermission fail, err->${JSON.stringify(err)}`);
});
```

### revokeUserGrantedPermission

revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number, callback: AsyncCallback&lt;void&gt;): void

Revokes a user_grant permission from an application. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.REVOKE_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Identifier of the target application, which is the value of **accessTokenId** contained in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions              | Yes  | Permission to revoke. For details, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| permissionFlags  | number | Yes  | Permission flag.<br>- **1**: A dialog box for user authorization will be displayed the next time if the user denies authorization for the permission.<br>- **2**: No dialog box will be displayed the next time if the user denies authorization for the permission. The permission must be granted by the user in **Settings**.<br>- **64**: The permission is given just once if the user allows the permission only this time. The authorization is canceled after the application is switched to the background or exits.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the permission is successfully revoked, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.REVOKE_SENSITIVE_PERMISSIONS". |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters or is not declared in the module.json file, or the flags value is invalid. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100006 | The application specified by the tokenID is not allowed to be revoked with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | The service is abnormal. |

**Example**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a non-system application.
let permissionFlags: number = 1;
atManager.revokeUserGrantedPermission(tokenID, 'ohos.permission.READ_AUDIO', permissionFlags, (err: BusinessError, data: void) => {
  if (err) {
    console.error(`revokeUserGrantedPermission fail, err->${JSON.stringify(err)}`);
  } else {
    console.log('revokeUserGrantedPermission success');
  }
});
```

### getPermissionFlags

getPermissionFlags(tokenID: number, permissionName: Permissions): Promise&lt;number&gt;

Obtains the flag of the specified permission of an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_SENSITIVE_PERMISSIONS, ohos.permission.GRANT_SENSITIVE_PERMISSIONS, or ohos.permission.REVOKE_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Identifier of the target application, which is the value of **accessTokenId** contained in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions              | Yes  | Target permission. For details, see [Application Permissions](../../security/AccessToken/app-permissions.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the flag obtained.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission specified below. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, or the permissionName exceeds 256 characters. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist or is not declared in the module.json file. |
| 12100006 | The operation is not allowed. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | The service is abnormal. |

**Example**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a non-system application.
atManager.getPermissionFlags(tokenID, 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS').then((data: number) => {
  console.log(`getPermissionFlags success, data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`getPermissionFlags fail, err->${JSON.stringify(err)}`);
});
```

### setPermissionRequestToggleStatus<sup>12+</sup>

setPermissionRequestToggleStatus(permissionName: Permissions, status: PermissionRequestToggleStatus): Promise&lt;void&gt;

Sets the toggle state of a permission. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.DISABLE_PERMISSION_DIALOG

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| permissionName | Permissions              | Yes  | Permission to be set with the toggle state. For details, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| status | [PermissionRequestToggleStatus](#permissionrequesttogglestatus12)    | Yes  | Toggle state to set.            |

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission specified below. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The permissionName exceeds 256 characters, the specified permission is not a user_grant permission, or the status value is invalid. |
| 12100003 | The specified permission does not exist. |
| 12100007 | The service is abnormal. |

**Example**

```ts
import { abilityAccessCtrl, Permissions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager = abilityAccessCtrl.createAtManager();
let permission: Permissions = 'ohos.permission.CAMERA';

atManager.setPermissionRequestToggleStatus(permission, abilityAccessCtrl.PermissionRequestToggleStatus.CLOSED).then((err) => {
  console.info('toggle_status: Set closed successful');
}).catch((err: BusinessError) => {
  console.error(`toggle_status: Code is ${err.code}, message is ${err.message}`);
});
```

### getPermissionRequestToggleStatus<sup>12+</sup>

getPermissionRequestToggleStatus(permissionName: Permissions): Promise&lt;PermissionRequestToggleStatus&gt;

Obtains the toggle state of a permission. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_SENSITIVE_PERMISSIONS

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| permissionName | Permissions              | Yes  | Permission whose toggle state is to be obtained. For details, see [Application Permissions](../../security/AccessToken/app-permissions.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;[PermissionRequestToggleStatus](#permissionrequesttogglestatus12)&gt; | Promise used to return the toggle state obtained.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission specified below. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The permissionName exceeds 256 characters, or the specified permission is not a user_grant permission. |
| 12100003 | The specified permission does not exist. |
| 12100007 | The service is abnormal. |

**Example**

```ts
import { abilityAccessCtrl, Permissions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager = abilityAccessCtrl.createAtManager();
let permission: Permissions = 'ohos.permission.CAMERA';

atManager.getPermissionRequestToggleStatus(permission).then((res) => {
  if (res == abilityAccessCtrl.PermissionRequestToggleStatus.CLOSED) {
    console.info('toggle_status: The toggle status is close');
  } else {
    console.info('toggle_status: The toggle status is open');
  }
}).catch((err: BusinessError) => {
console.error(`toggle_status: Code is ${err.code}, message is ${err.message}`);
});
```

### getVersion<sup>9+</sup>

getVersion(): Promise&lt;number&gt;

Obtains the data version of the permission management. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.AccessToken

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the version number obtained.|

| ID| Error Message|
| -------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |

**Example**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let promise = atManager.getVersion();
promise.then((data: number) => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### getPermissionsStatus<sup>12+</sup>

getPermissionsStatus(tokenID: number, permissionList: Array&lt;Permissions&gt;): Promise&lt;Array&lt;PermissionStatus&gt;&gt;

Obtains the status of the specified permissions. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Identifier of the target application, which is the value of **accessTokenId** contained in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionList | Array&lt;Permissions&gt;   | Yes  | Permissions whose status is to be obtained. For details, see [Application Permissions](../../security/AccessToken/app-permissions.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[PermissionStatus](js-apis-abilityAccessCtrl.md#permissionstatus20)&gt;&gt; | Promise used to return the permission statuses obtained.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.GET_SENSITIVE_PERMISSIONS". |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0 or the permissionList is empty or exceeds the size limit. |
| 12100002 | The specified tokenID does not exist. |
| 12100007 | The service is abnormal. |

**Example**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a non-system application.
atManager.getPermissionsStatus(tokenID, ['ohos.permission.CAMERA']).then((data: Array<abilityAccessCtrl.PermissionStatus>) => {
  console.log(`getPermissionsStatus success, data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`getPermissionsStatus fail, err->${JSON.stringify(err)}`);
});
```

### on<sup>9+</sup>

on(type: 'permissionStateChange', tokenIDList: Array&lt;number&gt;, permissionList: Array&lt;Permissions&gt;, callback: Callback&lt;PermissionStateChangeInfo&gt;): void

Subscribes to changes in the state of specified permissions for the given applications.

Multiple callbacks can be registered for the specified **tokenIDList** and **permissionList**.

If **tokenIDList** and **permissionList** have common values with the **tokenIDList** and **permissionList** of a callback registered, **callback** must be different.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | Yes  | Event type. The value is **'permissionStateChange'**, which indicates the permission state changes. |
| tokenIDList        | Array&lt;number&gt;   | Yes  | List of application token IDs. If this parameter is not specified, this API will subscribe to the permission state changes of all applications.|
| permissionList | Array&lt;Permissions&gt;   | Yes  | List of target permissions. If this parameter is not specified, this API will subscribe to state changes of all permissions. For details about the permissions, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| callback | Callback&lt;[PermissionStateChangeInfo](js-apis-abilityAccessCtrl.md#permissionstatechangeinfo18)&gt; | Yes| Callback invoked to return the permission state change.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.GET_SENSITIVE_PERMISSIONS". |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. Possible causes: 1. The tokenIDList or permissionList exceeds the size limit; 2. The tokenIDs or permissionNames in the list are all invalid. |
| 12100004 | The API is used repeatedly with the same input. |
| 12100005 | The registration time has exceeded the limit. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import { abilityAccessCtrl, Permissions, bundleManager } from '@kit.AbilityKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let appInfo: bundleManager.ApplicationInfo = bundleManager.getApplicationInfoSync('com.example.myapplication', 0, 100);
let tokenIDList: Array<number> = [appInfo.accessTokenId];
let permissionList: Array<Permissions> = ['ohos.permission.DISTRIBUTED_DATASYNC'];
try {
    atManager.on('permissionStateChange', tokenIDList, permissionList, (data: abilityAccessCtrl.PermissionStateChangeInfo) => {
        console.debug('receive permission state change, data:' + JSON.stringify(data));
    });
} catch(err) {
    console.error(`catch err->${JSON.stringify(err)}`);
}
```

### off<sup>9+</sup>

off(type: 'permissionStateChange', tokenIDList: Array&lt;number&gt;, permissionList: Array&lt;Permissions&gt;, callback?: Callback&lt;PermissionStateChangeInfo&gt;): void

Unsubscribes from changes in the state of specified permissions for the given applications. This API uses an asynchronous callback to return the result.

During unsubscribing, if no callback is passed, all callbacks in **tokenIDList** and **permissionList** are deleted in batches.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string         | Yes  | Event type. The value is **'permissionStateChange'**, which indicates the permission state changes. |
| tokenIDList        | Array&lt;number&gt;   | Yes  | List of application token IDs. The value must be the same as that in **on()**. If this parameter is not specified, this API will unsubscribe from the permission state changes of all applications.|
| permissionList | Array&lt;Permissions&gt;   | Yes  | List of target permissions. The value must be the same as that in **on()**. If this parameter is not specified, this API will unsubscribe from state changes for all permissions. For details about the permissions, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| callback | Callback&lt;[PermissionStateChangeInfo](js-apis-abilityAccessCtrl.md#permissionstatechangeinfo18)&gt; | No| Callback to unregister.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.GET_SENSITIVE_PERMISSIONS". |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenIDList or permissionList is not in the listening list. |
| 12100004 | The API is not used in pair with 'on'. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```ts
import { abilityAccessCtrl, Permissions, bundleManager } from '@kit.AbilityKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let appInfo: bundleManager.ApplicationInfo = bundleManager.getApplicationInfoSync('com.example.myapplication', 0, 100);
let tokenIDList: Array<number> = [appInfo.accessTokenId];
let permissionList: Array<Permissions> = ['ohos.permission.DISTRIBUTED_DATASYNC'];
try {
    atManager.off('permissionStateChange', tokenIDList, permissionList);
} catch(err) {
    console.error(`catch err->${JSON.stringify(err)}`);
}
```

### requestPermissionOnApplicationSetting<sup>18+</sup>

requestPermissionOnApplicationSetting(tokenID: number): Promise&lt;void&gt;

Starts the permission settings page for an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Identifier of the target application, which is the value of **accessTokenId** contained in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 12100002 | The specified tokenID does not exist. |
| 12100007 | The service is abnormal. |

**Example**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // System applications can obtain the token ID using bundleManager.getApplicationInfo.
atManager.requestPermissionOnApplicationSetting(tokenID).then(() => {
  console.log('requestPermissionOnApplicationSetting success');
}).catch((err: BusinessError) => {
  console.error(`requestPermissionOnApplicationSetting fail, err->${JSON.stringify(err)}`);
});
```

### PermissionRequestToggleStatus<sup>12+</sup>

Enumerates the permission toggle states.

**System capability**: SystemCapability.Security.AccessToken

| Name              |    Value| Description       |
| ------------------ | ----- | ----------- |
| CLOSED  | 0    | The permission is toggled off.|
| OPEN | 1     | The permission is toggled on.|
