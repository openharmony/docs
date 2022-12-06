# Ability Access Control

The **AbilityAccessCtrl** module provides APIs for application permission management, including authentication, authorization, and revocation.

> **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl'
```

## abilityAccessCtrl.createAtManager

createAtManager(): AtManager

Creates an **AtManager** instance, which is used for ability access control.

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

Implements ability access control.

### checkAccessToken<sup>9+</sup>

checkAccessToken(tokenID: number, permissionName: Permissions): Promise&lt;GrantStatus&gt;

Checks whether an application has the specified permission. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).            |
| permissionName | Permissions | Yes  | Permission to check.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;GrantStatus&gt; | Promise used to return the permission grant state.|

**Error codes**

For details about the error codes, see [Ability Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0 |

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // You can use getApplicationInfo to obtain the access token ID.
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

Verifies whether an application has the specified permission. This API returns the result synchronously.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Token ID of the application.             |
| permissionName | Permissions | Yes  | Name of the permission to verify.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| [GrantStatus](#grantstatus) | Permission grant state.|

**Error codes**

For details about the error codes, see [Ability Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0 |

**Example**

```js
let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0;
let data = atManager.verifyAccessTokenSync(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS");
console.log(`data->${JSON.stringify(data)}`);
```

### grantUserGrantedPermission

grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number): Promise&lt;void&gt;

Grants a user_grant permission to an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GRANT_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).           |
| permissionName | Permissions              | Yes  | Name of the permission to grant.|
| permissionFlag  | number | Yes  | Permission flag. The value **1** means that the permission request dialog box will still be displayed after the user grants or denies the permission. The value **2** means that no dialog box will be displayed after the user grants or denies the permission. The value **3** means a system permission that cannot be changed. |

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Ability Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0 |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist. |
| 12100006 | The application specified by the tokenID is not allowed to be granted with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | Service is abnormal. |

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // You can use getApplicationInfo to obtain the access token ID.
let permissionFlag = 1;
try {
    atManager.grantUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlag).then(() => {
        console.log('grantUserGrantedPermission success');
    }).catch((err) => {
        console.log(`grantUserGrantedPermission fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

### grantUserGrantedPermission

grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number, callback: AsyncCallback&lt;void&gt;): void

Grants a user_grant permission to an application. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GRANT_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).|
| permissionName | Permissions              | Yes  | Name of the permission to grant.|
| permissionFlag  | number | Yes  | Permission flag. The value **1** means that the permission request dialog box will still be displayed after the user grants or denies the permission. The value **2** means that no dialog box will be displayed after the user grants or denies the permission. The value **3** means a system permission that cannot be changed. |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the permission is granted successfully, **err** is **undefine**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Ability Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0 |
| 12100002 | TokenId does not exist. |
| 12100003 | Permission does not exist. |
| 12100006 | The specified application does not support the permissions granted or ungranted as specified. |

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // You can use getApplicationInfo to obtain the access token ID.
let permissionFlag = 1;
try {
    atManager.grantUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlag, (err, data) => {
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

revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number): Promise&lt;void&gt;

Revokes a user_grant permission from an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.REVOKE_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).          |
| permissionName | Permissions              | Yes  | Name of the permission to revoke.|
| permissionFlag  | number | Yes  | Permission flag. The value **1** means that the permission request dialog box will still be displayed after the user grants or denies the permission. The value **2** means that no dialog box will be displayed after the user grants or denies the permission. The value **3** means a system permission that cannot be changed. |

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Ability Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0 |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist. |
| 12100006 | The application specified by the tokenID is not allowed to be revoked with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | Service is abnormal. |

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // You can use getApplicationInfo to obtain the access token ID.
let permissionFlag = 1;
try {
    atManager.revokeUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlag).then(() => {
        console.log('revokeUserGrantedPermission success');
    }).catch((err) => {
        console.log(`revokeUserGrantedPermission fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

### revokeUserGrantedPermission

revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number, callback: AsyncCallback&lt;void&gt;): void

Revokes a user_grant permission from an application. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.REVOKE_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).          |
| permissionName | Permissions              | Yes  | Name of the permission to revoke.|
| permissionFlag  | number | Yes  | Permission flag. The value **1** means that the permission request dialog box will still be displayed after the user grants or denies the permission. The value **2** means that no dialog box will be displayed after the user grants or denies the permission. The value **3** means a system permission that cannot be changed. |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the permission is revoked successfully, **err** is **undefine**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Ability Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0 |
| 12100002 | TokenId does not exist. |
| 12100003 | Permission does not exist. |
| 12100006 | The specified application does not support the permissions granted or ungranted as specified. |

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // You can use getApplicationInfo to obtain the access token ID.
let permissionFlag = 1;
try {
    atManager.revokeUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlag, (err, data) => {
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

Obtains the flags of the specified permission of an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_SENSITIVE_PERMISSIONS, ohos.permission.GRANT_SENSITIVE_PERMISSIONS, or ohos.permission.REVOKE_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).           |
| permissionName | Permissions              | Yes  | Name of the permission to query.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Ability Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0 |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist. |
| 12100006 | The operation is not allowd. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | Service is abnormal. |

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // You can use getApplicationInfo to obtain the access token ID.
let permissionFlag = 1;
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

on(type: 'permissionStateChange', tokenIDList: Array&lt;number&gt;, permissionNameList: Array&lt;Permissions&gt;, callback: Callback&lt;PermissionStateChangeInfo&gt;): void;

Subscribes to permission grant state changes of the specified applications and permissions.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | Yes  | Event type. The value is fixed at **'permissionStateChange'**, indicating the permission grant state change event. |
| tokenIDList        | Array&lt;number&gt;   | Yes  | List of token IDs. If this parameter is left empty, the permission grant state changes of all applications are subscribed to.       |
| permissionNameList | Array&lt;Permissions&gt;   | Yes  | List of permission names. If this parameter is left empty, the permission grant state changes of all permissions are subscribed to.              |
| callback | Callback&lt;[PermissionStateChangeInfo](#permissionstatechangeinfo9)&gt; | Yes| Callback used to return the permission grant state change information.|

**Error codes**

For details about the error codes, see [Ability Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0 |
| 12100004 | The interface is called repeatedly with the same input. |
| 12100005 | The registration time has exceeded the limitation. |
| 12100007 | Service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenIDList: Array<number> = [];
let permissionNameList = [];
try {
    atManager.on('permissionStateChange', tokenIDList, permissionNameList, (data) => {
        console.debug("receive permission state change, data:" + JSON.stringify(data));
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

### off<sup>9+</sup>

off(type: 'permissionStateChange', tokenIDList: Array&lt;number&gt;, permissionNameList: Array&lt;Permissions&gt;, callback?: Callback&lt;PermissionStateChangeInfo&gt;): void;

Unsubscribes from permission grant state changes of the specified applications and permissions. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_SENSITIVE_PERMISSIONS (available only to system applications)

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | Yes  | Event type. The value is fixed at **'permissionStateChange'**, indicating the permission grant state change event. |
| tokenIDList        | Array&lt;number&gt;   | Yes  | List of token IDs. If this parameter is left empty, the permission grant state changes of all applications are unsubscribed from. The value must be the same as that passed in **on()**.|
| permissionNameList | Array&lt;Permissions&gt;   | Yes  | List of permission names. If this parameter is left empty, the permission grant state changes of all permissions are unsubscribed from. The value must be the same as that passed in **on()**.|
| callback | Callback&lt;[PermissionStateChangeInfo](#permissionstatechangeinfo9)&gt; | No| Callback used to return the permission grant state change information.|

**Error codes**

For details about the error codes, see [Ability Access Control Error Codes](../errorcodes/errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID in list is all invalid |
| 12100004 | The interface is not used with |
| 12100007 | Service is abnormal. |
| 12100008 | Out of memory. |

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenIDList: Array<number> = [];
let permissionNameList = [];
try {
    atManager.off('permissionStateChange', tokenIDList, permissionNameList);
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

### verifyAccessToken<sup>9+</sup>

verifyAccessToken(tokenID: number, permissionName: Permissions): Promise&lt;GrantStatus&gt;

Verifies whether an application has the specified permission. This API uses a promise to return the result.

> **NOTE**<br>You are advised to use [checkAccessToken](#checkaccesstoken9).

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).            |
| permissionName | Permissions | Yes  | Name of the permission to verify. Only valid permission names are supported.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;GrantStatus&gt; | Promise used to return the permission grant state.|

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // You can use getApplicationInfo to obtain the access token ID.
let promise = atManager.verifyAccessToken(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS");
promise.then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### verifyAccessToken<sup>(deprecated)</sup>

verifyAccessToken(tokenID: number, permissionName: string): Promise&lt;GrantStatus&gt;

Verifies whether an application has the specified permission. This API uses a promise to return the result.

> NOTE<br>This API is deprecated since API version 9. You are advised to use [checkAccessToken](#checkaccesstoken9).

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Token ID of the application. The value can be obtained from [ApplicationInfo](js-apis-bundle-ApplicationInfo.md).            |
| permissionName | string | Yes  | Name of the permission to verify.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;GrantStatus&gt; | Promise used to return the permission grant state.|

**Example**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // You can use getApplicationInfo to obtain the access token ID.
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

Defines the detailed permission grant state change information.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.AccessToken

| Name          | Type                      | Readable| Writable| Description               |
| -------------- | ------------------------- | ---- | ---- | ------------------ |
| change         | [PermissionStateChangeType](#permissionstatechangetype9) | Yes  | No  | Operation that triggers the permission grant state change.       |
| tokenID        | number                    | Yes  | No  | Token ID of the application whose permission grant state changes are subscribed.|
| permissionName | Permissions                    | Yes  | No  | Name of the permission whose grant state is changed.|
