# Context Module

## Modules to Import

```js
import featureAbility from '@ohos.ability.featureAbility'
import bundle from '@ohos.bundle'
```

The **Context** object is created in a **featureAbility** and returned through its **getContext()** method. Therefore, you must import the **@ohos.ability.featureAbility** package before using the Context module. An example is as follows:

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateLocalDir()
```

## Context

### getOrCreateLocalDir

getOrCreateLocalDir(callback: AsyncCallback\<string>): void

Obtains the local root directory of the application. This method uses a callback to return the result.

If this method is called for the first time, a root directory is created.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

**Parameters**


| Name    | Type                  | Mandatory| Description                      |
| -------- | ---------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the local root directory of the application.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateLocalDir((err, data)=>{
    console.info("data=" + data);
})
```



### getOrCreateLocalDir

getOrCreateLocalDir(): Promise\<string>

Obtains the local root directory of the application. This method uses a promise to return the result.

If this method is called for the first time, a root directory is created.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type            | Description                  |
| ---------------- | ---------------------- |
| Promise\<string> | Promise used to return the local root directory of the application.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateLocalDir().then((data) => {
    console.info("data=" + data);
});
```



### verifyPermission

verifyPermission(permission: string, options: PermissionOptions, callback: AsyncCallback\<number>): void

Verifies whether a specific PID and UID have the given permission. This method uses a callback to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

**Parameters**


| Name      | Type                                   | Mandatory| Description                                 |
| ---------- | --------------------------------------- | ---- | ------------------------------------- |
| permission | string                                  | Yes  | Name of the permission to verify.                     |
| options    | [PermissionOptions](#permissionoptions) | Yes  | Permission options.                           |
| callback   | AsyncCallback\<number>                  | Yes  | Callback used to return the permission verification result. The value **0** indicates that the PID and UID have the given permission, and the value **-1** indicates that the PID and UID do not have the given permission.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
import bundle from '@ohos.bundle'
var context = featureAbility.getContext();
bundle.getBundleInfo('com.context.test', 1, (datainfo) =>{
	context.verifyPermission("com.example.permission", datainfo.uid);
});
```



### verifyPermission

verifyPermission(permission: string, callback: AsyncCallback\<number>): void

Verifies whether the current PID and UID have the given permission. This method uses a callback to return the result.

**Parameters**


| Name      | Type                  | Mandatory| Description                                 |
| ---------- | ---------------------- | ---- | ------------------------------------- |
| permission | string                 | Yes  | Name of the permission to verify.                     |
| callback   | AsyncCallback\<number> | Yes  | Callback used to return the permission verification result. The value **0** indicates that the PID and UID have the given permission, and the value **-1** indicates that the PID and UID do not have the given permission.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.verifyPermission("com.example.permission")
```

### verifyPermission

verifyPermission(permission: string, options?: PermissionOptions): Promise\<number>

Verifies whether a specific PID and UID have the given permission. This method uses a promise to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

**Parameters**


| Name      | Type                                   | Mandatory| Description            |
| ---------- | --------------------------------------- | ---- | ---------------- |
| permission | string                                  | Yes  | Name of the permission to verify.|
| options    | [PermissionOptions](#permissionoptions) | No  | Permission options.      |

**Return value**

| Type            | Description                                                       |
| ---------------- | ----------------------------------------------------------- |
| Promise\<number> | Promise used to return the permission verification result. The value **0** indicates that the PID and UID have the given permission, and the value **-1** indicates that the PID and UID do not have the given permission.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
var Permission = context.PermissionOptions(1,1);
context.verifyPermission('com.context.permission',Permission).then((data) => {
    console.info("======================>verifyPermissionCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```



### requestPermissionsFromUser

requestPermissionsFromUser(permissions: Array\<string>, requestCode: number, resultCallback: AsyncCallback<[PermissionRequestResult](#permissionrequestresult)>)

Requests certain permissions from the system. This method uses a callback to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

**Parameters**


| Name          | Type                                                        | Mandatory| Description                                           |
| -------------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| permissions    | Array\<string>                                               | Yes  | Permissions to request. This parameter cannot be **null**.       |
| requestCode    | number                                                       | Yes  | Request code to be passed to **PermissionRequestResult**.|
| resultCallback | AsyncCallback<[PermissionRequestResult](#permissionrequestresult)> | Yes  | Permission request result.                             |
**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.requestPermissionsFromUser(
    ["com.example.permission1",
     "com.example.permission2",
     "com.example.permission3",
     "com.example.permission4",
     "com.example.permission5"],
    1,(err, data)=>{
        console.info("====>requestdata====>" + JSON.stringify(data));
        console.info("====>requesterrcode====>" + JSON.stringify(err.code));
    }
)
```



### getApplicationInfo

getApplicationInfo(callback: AsyncCallback\<ApplicationInfo>)

Obtains information about the current application. This method uses a callback to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                    |
| -------- | ------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<ApplicationInfo> | Yes  | Callback used to return the application information.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getApplicationInfo()
```



### getApplicationInfo

getApplicationInfo(): Promise\<ApplicationInfo>

Obtains information about the current application. This method uses a promise to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                     | Description              |
| ------------------------- | ------------------ |
| Promise\<ApplicationInfo> | Promise used to return the application information.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getApplicationInfo().then((data) => {
    console.info("=====================>getApplicationInfoCallback===================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```



### getBundleName

getBundleName(callback: AsyncCallback\<string>): void

Obtains the bundle name of the current ability. This method uses a callback to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                         |
| -------- | ---------------------- | ---- | ----------------------------- |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the bundle name.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getBundleName()
```



### getBundleName

getBundleName(): Promise\<string>

Obtains the bundle name of the current ability. This method uses a promise to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type            | Description                     |
| ---------------- | ------------------------- |
| Promise\<string> | Promise used to return the bundle name.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getBundleName().then((data) => {
    console.info("=======================>getBundleNameCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```



### getProcessInfo

getProcessInfo(callback: AsyncCallback\<ProcessInfo>)

Obtains information about the current process, including the PID and process name. This method uses a callback to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name    | Type                       | Mandatory| Description                |
| -------- | --------------------------- | ---- | -------------------- |
| callback | AsyncCallback\<ProcessInfo> | Yes  | Callback used to return the process information.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessInfo()
```



### getProcessInfo

getProcessInfo(): Promise\<ProcessInfo>

Obtains information about the current process, including the PID and process name. This method uses a promise to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                 | Description          |
| --------------------- | -------------- |
| Promise\<ProcessInfo> | Promise used to return the process information.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessInfo().then((data) => {
    console.info("=======================>getProcessInfoCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```



### getElementName

getElementName(callback: AsyncCallback\<ElementName>): void

Obtains the **ohos.bundle.ElementName** object of the current ability. This method uses a callback to return the result.

This method is available only to Page abilities.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name    | Type                       | Mandatory| Description                                          |
| -------- | --------------------------- | ---- | ---------------------------------------------- |
| callback | AsyncCallback\<ElementName> | Yes  | Callback used to return the **ohos.bundle.ElementName** object.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getElementName()
```



### getElementName

getElementName(): Promise\<ElementName>

Obtains the **ohos.bundle.ElementName** object of the current ability. This method uses a promise to return the result.

This method is available only to Page abilities.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                 | Description                                      |
| --------------------- | ------------------------------------------ |
| Promise\<ElementName> | Promise used to return the **ohos.bundle.ElementName** object.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getElementName().then((data) => {
    console.info("=======================>getElementNameCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```

### getProcessName

getProcessName(callback: AsyncCallback\<string>): void

Obtains the name of the current process. This method uses a callback to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

| Name    | Type                  | Mandatory| Description                |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the process name.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessName()
```



### getProcessName

getProcessName(): Promise\<string>

Obtains the name of the current process. This method uses a promise to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<string> | Promise used to return the process name.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessName().then((data) => {
    console.info("=======================>getProcessNameCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```



### getCallingBundle

getCallingBundle(callback: AsyncCallback\<string>): void

Obtains the bundle name of the calling ability. This method uses a callback to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                     |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the bundle name.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getCallingBundle()
```



### getCallingBundle

getCallingBundle(): Promise\<string>

Obtains the bundle name of the calling ability. This method uses a promise to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type           | Description                     |
| --------------- | ------------------------- |
| Promise\<string> | Promise used to return the bundle name.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getCallingBundle().then((data) => {
    console.info("======================>getCallingBundleCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```

## PermissionOptions

| Name| Readable/Writable| Type  | Mandatory| Description  |
| ---- | -------- | ------ | ---- | ------ |
| pid  | Read-only    | number | No  | PID.<br><b>System capabilities: </b>SystemCapability.Ability.AbilityRuntime.Core|
| uid  | Read-only    | number | No  | UID.<br><b>System capabilities: </b>SystemCapability.Ability.AbilityRuntime.Core|

## PermissionRequestResult

| Name       | Readable/Writable| Type          | Mandatory| Description              |
| ----------- | -------- | -------------- | ---- | ------------------ |
| requestCode | Read-only    | number         | Yes  | Request code passed.<br><b>System capabilities: </b>SystemCapability.Ability.AbilityRuntime.Core|
| permissions | Read-only    | Array\<string> | Yes  | Permissions passed.<br><b>System capabilities: </b>SystemCapability.Ability.AbilityRuntime.Core    |
| authResults | Read-only    | Array\<number> | Yes  | Permission request result.<br><b>System capabilities: </b>SystemCapability.Ability.AbilityRuntime.Core      |
