# @ohos.abilityAccessCtrl (Application Access Control)

The **AbilityAccessCtrl** module provides APIs for application permission management, including authentication, authorization, and revocation.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl'
```

## abilityAccessCtrl.createAtManager

createAtManager(): AtManager

Creates an **AtManager** instance, which is used for application access control.

**System capability**: SystemCapability.Security.AccessToken


**Return value**

| Type| Description|
| -------- | -------- |
| [AtManager](#atmanager) | **AtManager** instance created.|

**Example**

```js
let atManager = abilityAccessCtrl.createAtManager();
```

## AtManager

Provides APIs for application access control.

### checkAccessToken<sup>9+</sup>

checkAccessToken(tokenID: number, permissionName: Permissions): Promise&lt;GrantStatus&gt;

Checks whether a permission is granted to an application. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).            |
| permissionName | Permissions | Yes  | Permission to check. For details about the permissions, see the [Application Permission List](../../security/permission-list.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;GrantStatus&gt; | Promise used to return the permission grant state.|

**Error codes**

For details about the error codes, see [Application Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0, or the permissionName exceeds 256 bytes. |

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a non-system application.
try {
    atManager.checkAccessToken(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS").then((data) => {
        console.log(`checkAccessToken success, data->${JSON.stringify(data)}`);
    }).catch((err) => {
        console.log(`checkAccessToken fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

### verifyAccessTokenSync<sup>9+</sup>

verifyAccessTokenSync(tokenID: number, permissionName: Permissions): GrantStatus

Verifies whether a permission is granted to an application. This API returns the result synchronously.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).             |
| permissionName | Permissions | Yes  | Permission to verify. For details about the permissions, see the [Application Permission List](../../security/permission-list.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| [GrantStatus](#grantstatus) | Permission grant state.|

**Error codes**

For details about the error codes, see [Application Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0, or the permissionName exceeds 256 bytes. |

**Example**

```js
let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a non-system application.
let data = atManager.verifyAccessTokenSync(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS");
console.log(`data->${JSON.stringify(data)}`);
```

### grantUserGrantedPermission

grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise&lt;void&gt;

Grants a user_grant permission to an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GRANT_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).           |
| permissionName | Permissions              | Yes  | Permission to grant. For details about the permissions, see the [Application Permission List](../../security/permission-list.md).|
| permissionFlags  | number | Yes  | Permission flag.<br>- **0**: The permission is not set by the user.<br>- **1**: A dialog box for user authorization will be displayed the next time if the user denies authorization for the permission.<br>- **2**: No dialog box will be displayed the next time if the user denies authorization for the permission. The permission must be granted by the user in **Settings**.<br>- **4**: The permission is authorized by the system and cannot be changed.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Application Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0, the permissionName exceeds 256 bytes, or the flags value is invalid. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist. |
| 12100006 | The application specified by the tokenID is not allowed to be granted with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | Service is abnormal. |

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a non-system application.
let permissionFlags = 1;
try {
    atManager.grantUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlags).then(() => {
        console.log('grantUserGrantedPermission success');
    }).catch((err) => {
        console.log(`grantUserGrantedPermission fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
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
| tokenID      | number              | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions              | Yes  | Permission to grant. For details about the permissions, see the [Application Permission List](../../security/permission-list.md).|
| permissionFlags  | number | Yes  | Permission flag.<br>- **0**: The permission is not set by the user.<br>- **1**: A dialog box for user authorization will be displayed the next time if the user denies authorization for the permission.<br>- **2**: No dialog box will be displayed the next time if the user denies authorization for the permission. The permission must be granted by the user in **Settings**.<br>- **4**: The permission is authorized by the system and cannot be changed.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result. If the permission is granted, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Application Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0, the permissionName exceeds 256 bytes, or the flags value is invalid. |
| 12100002 | TokenId does not exist. |
| 12100003 | Permission does not exist. |
| 12100006 | The application specified by the tokenID is not allowed to be granted with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | Service is abnormal. |

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a non-system application.
let permissionFlags = 1;
try {
    atManager.grantUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlags, (err, data) => {
        if (err) {
            console.log(`grantUserGrantedPermission fail, err->${JSON.stringify(err)}`);
        } else {
            console.log('grantUserGrantedPermission success');
        }
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
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
| tokenID      | number              | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).          |
| permissionName | Permissions              | Yes  | Permission to revoke. For details about the permissions, see the [Application Permission List](../../security/permission-list.md).|
| permissionFlags  | number | Yes  | Permission flag.<br>- **0**: The permission is not set by the user.<br>- **1**: A dialog box for user authorization will be displayed the next time if the user denies authorization for the permission.<br>- **2**: No dialog box will be displayed the next time if the user denies authorization for the permission. The permission must be granted by the user in **Settings**.<br>- **4**: The permission is authorized by the system and cannot be changed.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Application Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0, the permissionName exceeds 256 bytes, or the flags value is invalid. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist. |
| 12100006 | The application specified by the tokenID is not allowed to be revoked with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | Service is abnormal. |

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a non-system application.
let permissionFlags = 1;
try {
    atManager.revokeUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlags).then(() => {
        console.log('revokeUserGrantedPermission success');
    }).catch((err) => {
        console.log(`revokeUserGrantedPermission fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
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
| tokenID      | number              | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).          |
| permissionName | Permissions              | Yes  | Permission to revoke. For details about the permissions, see the [Application Permission List](../../security/permission-list.md).|
| permissionFlags  | number | Yes  | Permission flag.<br>- **0**: The permission is not set by the user.<br>- **1**: A dialog box for user authorization will be displayed the next time if the user denies authorization for the permission.<br>- **2**: No dialog box will be displayed the next time if the user denies authorization for the permission. The permission must be granted by the user in **Settings**.<br>- **4**: The permission is authorized by the system and cannot be changed.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result. If the permission is revoked, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Application Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0, the permissionName exceeds 256 bytes, or the flags value is invalid. |
| 12100002 | TokenId does not exist. |
| 12100003 | Permission does not exist. |
| 12100006 | The application specified by the tokenID is not allowed to be revoked with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | Service is abnormal. |

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a non-system application.
let permissionFlags = 1;
try {
    atManager.revokeUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlags, (err, data) => {
        if (err) {
            console.log(`revokeUserGrantedPermission fail, err->${JSON.stringify(err)}`);
        } else {
            console.log('revokeUserGrantedPermission success');
        }
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

### getPermissionFlags

getPermissionFlags(tokenID: number, permissionName: Permissions): Promise&lt;number&gt;

Obtains the permission flag of an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_SENSITIVE_PERMISSIONS, ohos.permission.GRANT_SENSITIVE_PERMISSIONS, or ohos.permission.REVOKE_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).           |
| permissionName | Permissions              | Yes  | Target permission. For details about the permissions, see the [Application Permission List](../../security/permission-list.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the permission flag obtained. |

**Error codes**

For details about the error codes, see [Application Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0, or the permissionName exceeds 256 bytes. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist. |
| 12100006 | The operation is not allowed. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | Service is abnormal. |

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a non-system application.
try {
    atManager.getPermissionFlags(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS").then((data) => {
        console.log(`getPermissionFlags success, data->${JSON.stringify(data)}`);
    }).catch((err) => {
        console.log(`getPermissionFlags fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

### getVersion<sup>9+</sup>

getVersion(): Promise&lt;number&gt;

Obtains the data version of the permission management. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.AccessToken

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the version.|

**Example**

```js
let atManager = abilityAccessCtrl.createAtManager();
let promise = atManager.getVersion();
promise.then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### on<sup>9+</sup>

on(type: 'permissionStateChange', tokenIDList: Array&lt;number&gt;, permissionList: Array&lt;Permissions&gt;, callback: Callback&lt;PermissionStateChangeInfo&gt;): void;

Subscribes to permission state changes of the specified applications and permissions.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | Yes  | Event type to subscribe to. The value is **'permissionStateChange'**, which indicates the permission grant state change. |
| tokenIDList        | Array&lt;number&gt;   | Yes  | Token IDs of the applications to observe. If this parameter is left empty, the permission grant state changes of all applications are observed. |
| permissionList | Array&lt;Permissions&gt;   | Yes  | Permissions to observe. If this parameter is left empty, the grant state changes of all permissions are observed. |
| callback | Callback&lt;[PermissionStateChangeInfo](#permissionstatechangeinfo9)&gt; | Yes| Callback invoked to return the permission grant state change.|

**Error codes**

For details about the error codes, see [Application Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0, or the permissionName exceeds 256 bytes. |
| 12100004 | The interface is called repeatedly with the same input. |
| 12100005 | The registration time has exceeded the limitation. |
| 12100007 | Service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```js
import {Permissions} from '@ohos.abilityAccessCtrl';
import bundleManager from '@ohos.bundle.bundleManager';

let atManager = abilityAccessCtrl.createAtManager();
let appInfo = bundleManager.getApplicationInfoSync('com.example.myapplication', 0, 100);
let tokenIDList: Array<number> = [appInfo.accessTokenId];
let permissionList: Array<Permissions> = ["ohos.permission.DISTRIBUTED_DATASYNC"];
try {
    atManager.on('permissionStateChange', tokenIDList, permissionList, (data) => {
        console.debug("receive permission state change, data:" + JSON.stringify(data));
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

### off<sup>9+</sup>

off(type: 'permissionStateChange', tokenIDList: Array&lt;number&gt;, permissionList: Array&lt;Permissions&gt;, callback?: Callback&lt;PermissionStateChangeInfo&gt;): void;

Unsubscribes from permission grant state changes of the specified applications and permissions. This API uses a callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | Yes  | Event type to unsubscribe from. The value is **'permissionStateChange'**, which indicates the permission grant state change. |
| tokenIDList        | Array&lt;number&gt;   | Yes  | Token IDs of the applications. If this parameter is left empty, the permission grant state changes of all applications are unsubscribed from. The value must be the same as that passed in **on()**. |
| permissionList | Array&lt;Permissions&gt;   | Yes  | Permission names. If this parameter is left empty, the grant state changes of all permissions are unsubscribed from. The value must be the same as that passed in **on()**. |
| callback | Callback&lt;[PermissionStateChangeInfo](#permissionstatechangeinfo9)&gt; | No| Callback for the permission grant state change. |

**Error codes**

For details about the error codes, see [Application Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenIDs or permissionNames in the list are all invalid. |
| 12100004 | The interface is not used together with "on". |
| 12100007 | Service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```js
import {Permissions} from '@ohos.abilityAccessCtrl';
import bundleManager from '@ohos.bundle.bundleManager';

let atManager = abilityAccessCtrl.createAtManager();
let appInfo = bundleManager.getApplicationInfoSync('com.example.myapplication', 0, 100);
let tokenIDList: Array<number> = [appInfo.accessTokenId];
let permissionList: Array<Permissions> = ["ohos.permission.DISTRIBUTED_DATASYNC"];
try {
    atManager.off('permissionStateChange', tokenIDList, permissionList);
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

### verifyAccessToken<sup>9+</sup>

verifyAccessToken(tokenID: number, permissionName: Permissions): Promise&lt;GrantStatus&gt;

Verifies whether a permission is granted to an application. This API uses a promise to return the result.

> **NOTE**
> 
> You are advised to use [checkAccessToken](#checkaccesstoken9).

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).            |
| permissionName | Permissions | Yes  | Permission to verify. For details about the permissions, see the [Application Permission List](../../security/permission-list.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;GrantStatus&gt; | Promise used to return the permission grant state.|

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a non-system application.
let promise = atManager.verifyAccessToken(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS");
promise.then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### requestPermissionsFromUser<sup>9+</sup>

requestPermissionsFromUser(context: Context, permissionList: Array&lt;Permissions&gt;, requestCallback: AsyncCallback&lt;PermissionRequestResult&gt;) : void;

Requests user authorization in a dialog box opened by a UIAbility. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> The API cannot be called by any non-UIAbility.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | Context | Yes| Context of the UIAbility.|
| permissionList | Array&lt;Permissions&gt; | Yes| Permissions requested. For details about the permissions, see the [Application Permission List](../../security/permission-list.md).|
| callback | AsyncCallback&lt;[PermissionRequestResult](js-apis-permissionrequestresult.md)&gt; | Yes| Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [Application Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The context is invalid when it does not belong to the application itself. |

**Example**

  ```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';
let atManager = abilityAccessCtrl.createAtManager();
try {
    atManager.requestPermissionsFromUser(this.context, ["ohos.permission.CAMERA"], (err, data)=>{
        console.info("data:" + JSON.stringify(data));
        console.info("data permissions:" + data.permissions);
        console.info("data authResults:" + data.authResults);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
  ```

### requestPermissionsFromUser<sup>9+</sup>

requestPermissionsFromUser(context: Context, permissionList: Array&lt;Permissions&gt;) : Promise&lt;PermissionRequestResult&gt;;

Requests user authorization in a dialog box opened by a UIAbility. This API uses a promise to return the result.

> **NOTE**
>
> The API cannot be called by any non-UIAbility.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | Context | Yes| Context of the UIAbility.|
| permissionList | Array&lt;Permissions&gt; | Yes| Permissions requested. For details about the permissions, see the [Application Permission List](../../security/permission-list.md).|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[PermissionRequestResult](js-apis-permissionrequestresult.md)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Application Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The context is invalid when it does not belong to the application itself. |

**Example**

  ```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';
let atManager = abilityAccessCtrl.createAtManager();
try {
    atManager.requestPermissionsFromUser(this.context, ["ohos.permission.CAMERA"]).then((data) => {
        console.info("data:" + JSON.stringify(data));
        console.info("data permissions:" + data.permissions);
        console.info("data authResults:" + data.authResults);
    }).catch((err) => {
        console.info("data:" + JSON.stringify(err));
    })
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
  ```

### verifyAccessToken<sup>(deprecated)</sup>

verifyAccessToken(tokenID: number, permissionName: string): Promise&lt;GrantStatus&gt;

Verifies whether a permission is granted to an application. This API uses a promise to return the result.

> **NOTE**
> 
> This API is no longer maintained since API version 9. You are advised to use [checkAccessToken](#checkaccesstoken9).

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).            |
| permissionName | string | Yes  | Permission to verify.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;GrantStatus&gt; | Promise used to return the permission grant state.|

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a non-system application.
let promise = atManager.verifyAccessToken(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS");
promise.then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### GrantStatus

Enumerates the permission grant states.

**System capability**: SystemCapability.Security.AccessToken

| Name              |    Value| Description       |
| ------------------ | ----- | ----------- |
| PERMISSION_DENIED  | -1    | Permission denied.|
| PERMISSION_GRANTED | 0     | Permission granted.|

### PermissionStateChangeType<sup>9+</sup>

Enumerates the operations that trigger permission grant state changes.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.AccessToken

| Name                    |    Value| Description             |
| ----------------------- | ------ | ----------------- |
| PERMISSION_REVOKED_OPER | 0      | Operation to revoke the permission.|
| PERMISSION_GRANTED_OPER | 1      | Operation to grant the permission.|

### PermissionStateChangeInfo<sup>9+</sup>

Defines detailed information about the permission grant state change.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.AccessToken

| Name          | Type                      | Readable| Writable| Description               |
| -------------- | ------------------------- | ---- | ---- | ------------------ |
| change         | [PermissionStateChangeType](#permissionstatechangetype9) | Yes  | No  | Operation that triggers the permission grant state change.       |
| tokenID        | number                    | Yes  | No  | Token ID of the application. |
| permissionName | Permissions                    | Yes  | No  | Permission whose grant state changes. For details about the permissions, see the [Application Permission List](../../security/permission-list.md). |
