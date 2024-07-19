# @ohos.abilityAccessCtrl (Application Access Control) (System API)

The **abilityAccessCtrl** module provides APIs for application permission management, including authentication, authorization, and revocation.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.abilityAccessCtrl (Application Access Control)](js-apis-abilityAccessCtrl.md).

## Modules to Import

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit'
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
| tokenID      | number              | Yes  | Application token ID, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions              | Yes  | Permission to grant. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|
| permissionFlags  | number | Yes  | Permission flag.<br>- **1**: A dialog box for user authorization will be displayed the next time if the user denies authorization for the permission.<br>- **2**: No dialog box will be displayed the next time if the user denies authorization for the permission. The permission must be granted by the user in **Settings**.<br>- **64**: The permission is granted to the user only this time. The authorization is revoked after the application switches to the background or exits.|

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
| 12100001 | Invalid parameter. The tokenID is 0, or the permissionName exceeds 256 characters, or the flags value is invalid. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist. |
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
| tokenID      | number              | Yes  | Application token ID, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions              | Yes  | Permission to grant. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|
| permissionFlags  | number | Yes  | Permission flag.<br>- **1**: A dialog box for user authorization will be displayed the next time if the user denies authorization for the permission.<br>- **2**: No dialog box will be displayed the next time if the user denies authorization for the permission. The permission must be granted by the user in **Settings**.<br>- **64**: The permission is granted to the user only this time. The authorization is revoked after the application switches to the background or exits.|
| callback | AsyncCallback&lt;void&gt; | Yes| Grants a user_grant permission to an application. If the permission is granted, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, or the permissionName exceeds 256 characters, or the flags value is invalid. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist. |
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
| tokenID      | number              | Yes  | Application token ID, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions              | Yes  | Permission to revoke. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|
| permissionFlags  | number | Yes  | Permission flag.<br>- **1**: A dialog box for user authorization will be displayed the next time if the user denies authorization for the permission.<br>- **2**: No dialog box will be displayed the next time if the user denies authorization for the permission. The permission must be granted by the user in **Settings**.<br>- **64**: The permission is granted to the user only this time. The authorization is revoked after the application switches to the background or exits.|

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
| 12100001 | Invalid parameter. The tokenID is 0, or the permissionName exceeds 256 characters, or the flags value is invalid. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist. |
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
| tokenID      | number              | Yes  | Application token ID, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions              | Yes  | Permission to revoke. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|
| permissionFlags  | number | Yes  | Permission flag.<br>- **1**: A dialog box for user authorization will be displayed the next time if the user denies authorization for the permission.<br>- **2**: No dialog box will be displayed the next time if the user denies authorization for the permission. The permission must be granted by the user in **Settings**.<br>- **64**: The permission is granted to the user only this time. The authorization is revoked after the application switches to the background or exits.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result. If the permission is revoked, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, or the permissionName exceeds 256 characters, or the flags value is invalid. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist. |
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
| tokenID      | number              | Yes  | Application token ID, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions              | Yes  | Permission whose flag is to be obtained. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, or the permissionName exceeds 256 characters. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist. |
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
| permissionName | Permissions              | Yes  | Permission to be set with the toggle state. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|
| status | [PermissionRequestToggleStatus](#permissionrequesttogglestatus12)    | Yes  | Toggle state to set.            |

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
| 12100001 | Invalid parameter. The permissionName exceeds 256 characters, or the status value is invalid. |
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
  console.error('toggle_status: Code is ${err.code}, message is ${err.message}');
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
| permissionName | Permissions              | Yes  | Permission whose toggle state is to be obtained. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;[PermissionRequestToggleStatus](#permissionrequesttogglestatus12)&gt; | Promise used to return the toggle state obtained.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The permissionName exceeds 256 characters. |
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
console.error('toggle_status: Code is ${err.code}, message is ${err.message}');
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
| Promise&lt;number&gt; | Promise used to return the version obtained.|

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
| tokenID      | number              | Yes  | Application token ID, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionList | Array&lt;Permissions&gt;   | Yes  | Permissions whose status is to be obtained. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[PermissionStatus](#permissionstatus12)&gt;&gt; | Promise used to return the permission status obtained.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, or the permissionName exceeds 256 characters. |
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

Subscribes to permission state changes of the specified applications and permissions.

Multiple callbacks can be registered for the specified **tokenIDList** and **permissionList**.

If **tokenIDList** and **permissionList** have common values with the **tokenIDList** and **permissionList** of a callback registered, **callback** must be different.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | Yes  | Event type. The value is **'permissionStateChange'**, which indicates the permission grant state changes. |
| tokenIDList        | Array&lt;number&gt;   | Yes  | List of application token IDs. If this parameter is left empty, this API subscribes to the permission grant state changes of all applications.|
| permissionList | Array&lt;Permissions&gt;   | Yes  | List of permissions to be subscribed to. If this parameter is left empty, this API subscribes to state changes of all permissions. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|
| callback | Callback&lt;[PermissionStateChangeInfo](#permissionstatechangeinfo9)&gt; | Yes| Callback invoked to return the permission grant state change.|

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

Unsubscribes from permission grant state changes of the specified applications and permissions. This API uses a callback to return the result.

If no callback is passed in **atManager.off**, all callbacks for **tokenIDList** and **permissionList** will be unregistered.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string         | Yes  | Event type. The value is **'permissionStateChange'**, which indicates the permission grant state changes. |
| tokenIDList        | Array&lt;number&gt;   | Yes  | List of application token IDs. The value must be the same as that passed in **on()**. If this parameter is left empty, this API unsubscribes from the permission grant state changes of all applications.|
| permissionList | Array&lt;Permissions&gt;   | Yes  | List of permissions. The value must be the same as that of **on()**. If this parameter is left empty, this API unsubscribes from state changes of all permissions. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|
| callback | Callback&lt;[PermissionStateChangeInfo](#permissionstatechangeinfo9)&gt; | No| Callback for the permission grant state change.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenIDs or permissionNames in the list are all invalid. |
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

### PermissionStateChangeType<sup>9+</sup>

Enumerates the operations that trigger permission grant state changes.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.AccessToken

| Name                    |    Value| Description             |
| ----------------------- | ------ | ----------------- |
| PERMISSION_REVOKED_OPER | 0      | Operation to revoke the permission.|
| PERMISSION_GRANTED_OPER | 1      | Operation to grant the permission.|

### PermissionRequestToggleStatus<sup>12+</sup>

Enumerates the permission toggle states.

**System capability**: SystemCapability.Security.AccessToken

| Name              |    Value| Description       |
| ------------------ | ----- | ----------- |
| CLOSED  | 0    | The permission request toggle is disabled.|
| OPEN | 1     | The permission request toggle is enabled.|

### PermissionStateChangeInfo<sup>9+</sup>

Defines detailed information about the permission grant state change.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.AccessToken

| Name          | Type                      | Read Only| Mandatory| Description               |
| -------------- | ------------------------- | ---- | ---- | ------------------ |
| change         | [PermissionStateChangeType](#permissionstatechangetype9) | Yes  | Yes  | Operation that triggers the permission grant state change.       |
| tokenID        | number                    | Yes  | Yes  | Application token ID, which is the value of **accessTokenId** in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions                    | Yes  | Yes  | Permission whose grant state changes. For details about the permissions, see [Permissions for All Applications](../../security/AccessToken/permissions-for-all.md).|

### PermissionStatus<sup>12+</sup>

Enumerates the permission states.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.AccessToken

| Name              |    Value| Description       |
| ------------------ | ----- | ----------- |
| DENIED  | -1    | The permission is not granted.|
| GRANTED | 0     | The permission is granted.|
| NOT_DETERMINED | 1     | The permission state is not determined.|
| INVALID | 2     | The permission is invalid.|
| RESTRICTED | 3     | The permission is restricted.|
