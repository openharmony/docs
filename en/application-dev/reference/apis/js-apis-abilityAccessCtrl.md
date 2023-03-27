#  	Ability Access Control

> **NOTE**
>
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
| [AtManager](#atmanager) | **AtManager** instance obtained.|

**Example**

```
var AtManager = abilityAccessCtrl.createAtManager();
```

## AtManager

Provides APIs for ability access control.

### verifyAccessToken

verifyAccessToken(tokenID: number, permissionName: string): Promise&lt;GrantStatus&gt;

Checks whether an application has been granted the specified permission. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Token ID of the application to verify.             |
| permissionName | string | Yes  | Name of the permission to verify.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;GrantStatus&gt; | Promise used to return the result.|

**Example**

```
var AtManager = abilityAccessCtrl.createAtManager();
let tokenID = 0;
let promise = AtManager.verifyAccessToken(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS");
promise.then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### grantUserGrantedPermission

grantUserGrantedPermission(tokenID: number, permissionName: string, permissionFlags: number): Promise&lt;number&gt;

Grants a user_grant permission to an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GRANT_SENSITIVE_PERMISSIONS

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Token ID of the application.           |
| permissionName | string              | Yes  | Name of the permission to grant.|
| permissionFlags  | number | Yes  | Permission flag.<br>- **0**: The permission is not set by the user.<br>- **1**: A dialog box for user authorization will be displayed the next time if the user denies authorization for the permission.<br>- **2**: No dialog box will be displayed the next time if the user denies authorization for the permission. The permission must be granted by the user in **Settings**.<br>- **4**: The permission is authorized by the system and cannot be changed.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Example**

```
var AtManager = abilityAccessCtrl.createAtManager();
let tokenID = 0;
let permissionFlags = 1;
let promise = AtManager.grantUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlags);
promise.then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```



### grantUserGrantedPermission

grantUserGrantedPermission(tokenID: number, permissionName: string, permissionFlags: number, callback: AsyncCallback&lt;number&gt;): void

Grants a user_grant permission to an application. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GRANT_SENSITIVE_PERMISSIONS

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Token ID of the application.          |
| permissionName | string              | Yes  | Name of the permission to grant.|
| permissionFlags  | number | Yes  | Permission flag.<br>- **0**: The permission is not set by the user.<br>- **1**: A dialog box for user authorization will be displayed the next time if the user denies authorization for the permission.<br>- **2**: No dialog box will be displayed the next time if the user denies authorization for the permission. The permission must be granted by the user in **Settings**.<br>- **4**: The permission is authorized by the system and cannot be changed.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the result.|

**Example**

```
var AtManager = abilityAccessCtrl.createAtManager();
let tokenID = 0;
let permissionFlags = 1;
AtManager.grantUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS",permissionFlags, data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

### revokeUserGrantedPermission

revokeUserGrantedPermission(tokenID: number, permissionName: string, permissionFlags: number): Promise&lt;number&gt;

Revokes a user_grant permission given to an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.REVOKE_SENSITIVE_PERMISSIONS

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Token ID of the application.           |
| permissionName | string              | Yes  | Name of the permission to revoke.|
| permissionFlags  | number | Yes  | Permission flag.<br>- **0**: The permission is not set by the user.<br>- **1**: A dialog box for user authorization will be displayed the next time if the user denies authorization for the permission.<br>- **2**: No dialog box will be displayed the next time if the user denies authorization for the permission. The permission must be granted by the user in **Settings**.<br>- **4**: The permission is authorized by the system and cannot be changed.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Example**

```
var AtManager = abilityAccessCtrl.createAtManager();
let tokenID = 0;
let permissionFlags = 1;
let promise = AtManager.revokeUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlags);
promise.then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### revokeUserGrantedPermission

revokeUserGrantedPermission(tokenID: number, permissionName: string, permissionFlags: number, callback: AsyncCallback&lt;number&gt;): void

Revokes a user_grant permission given to an application. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.REVOKE_SENSITIVE_PERMISSIONS

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Token ID of the application.           |
| permissionName | string              | Yes  | Name of the permission to revoke.|
| permissionFlags  | number | Yes  | Permission flag.<br>- **0**: The permission is not set by the user.<br>- **1**: A dialog box for user authorization will be displayed the next time if the user denies authorization for the permission.<br>- **2**: No dialog box will be displayed the next time if the user denies authorization for the permission. The permission must be granted by the user in **Settings**.<br>- **4**: The permission is authorized by the system and cannot be changed.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the result.|

**Example**

```
var AtManager = abilityAccessCtrl.createAtManager();
let tokenID = 0;
let permissionFlags = 1;
AtManager.revokeUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS",permissionFlags, data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

### getPermissionFlags

getPermissionFlags(tokenID: number, permissionName: string): Promise&lt;number&gt;

Obtains the flag of the specified permission for an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_SENSITIVE_PERMISSIONS, GRANT_SENSITIVE_PERMISSIONS, or REVOKE_SENSITIVE_PERMISSIONS

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name   | Type               | Mandatory| Description                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | Yes  | Token ID of the application.           |
| permissionName | string              | Yes  | Name of the permission to query.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Example**

```
var AtManager = abilityAccessCtrl.createAtManager();
let tokenID = 0;
let promise = AtManager.getPermissionFlags(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS");
promise.then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### GrantStatus

Enumerates the permission grant statues.

**System capability**: SystemCapability.Security.AccessToken

| Name                         | Value                 | Description                   |
| ----------------------------- | ---------------------- | -----------------------  |
| PERMISSION_DENIED             | -1                     | The permission is not granted.            |
| PERMISSION_GRANTED            | 0                      | The permission is granted.            |
