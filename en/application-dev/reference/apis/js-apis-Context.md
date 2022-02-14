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

## Context.getOrCreateLocalDir(callback: AsyncCallback<string>)

- Functionality

  Obtains the local root directory of the application. If this method is called for the first time, a root directory is created. This method uses a callback to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | ---------------------- | ---- | ------------------------ |
| callback | Read-only| AsyncCallback\<string> | Yes| Callback used to return the local root directory of the application.|

- Return values

  void

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateLocalDir((err, data)=>{
    console.info("data=" + data);
})
```



## Context.getOrCreateLocalDir()

- Functionality

  Obtains the local root directory of the application. If this method is called for the first time, a root directory is created. This method uses a promise to return the result.

- Parameters

  None

- Return values

  | Type| Description|
  | --------------- | -------------------- |
  | Promise<string> | Promise used to return the local root directory of the application.|

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateLocalDir().then((void) => {
	console.info("==========================>getOrCreateLocalDirCallback=======================>");
});
```

## PermissionOptions

| Name| Readable/Writable| Type| Mandatory| Description|
| ---- | -------- | ------ | ---- | ------ |
| pid  | Read-only| number | No| PID.|
| uid  | Read-only| number | No| UID.|

## Context.verifyPermission(permission: string, options: PermissionOptions, callback: AsyncCallback<number>)

- Functionality

  Verifies whether a specific PID and UID have the given permission. This method uses a callback to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | ----------------------------------------------- | ---- | ----------------------------------- |
| permission | Read-only| string                                          | Yes| Name of the permission to verify.|
| options    | Read-only| [PermissionOptions](#PermissionOptions)| Yes| Permission options.|
| callback   | Read-only| AsyncCallback\<number>                          | Yes| Callback used to return the permission verification result. The value **0** indicates that the PID and UID have the given permission, and the value **-1** indicates that the PID and UID do not have the given permission.|

- Return values

  void

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
import bundle from '@ohos.bundle'
var context = featureAbility.getContext();
var datainfo = await bundle.getBundleInfo('com.context.test',1);
context.verifyPermission("com.example.permission",datainfo.uid)

```



## Context.verifyPermission(permission: string, callback: AsyncCallback<number>)

- Functionality

  Verifies whether the current PID and UID have the given permission. This method uses a callback to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | ---------------------- | ---- | ----------------------------------- |
| permission | Read-only| string                 | Yes| Name of the permission to verify.|
| callback   | Read-only| AsyncCallback\<number> | Yes| Callback used to return the permission verification result. The value **0** indicates that the PID and UID have the given permission, and the value **-1** indicates that the PID and UID do not have the given permission.|

- Return values

  void

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.verifyPermission("com.example.permission")
```



## Context.verifyPermission(permission: string, options?: PermissionOptions)

- Functionality

  Verifies whether a specific PID and UID have the given permission. This method uses a promise to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | ----------------------------------------------- | ---- | -------------- |
| permission | Read-only| string                                          | Yes| Name of the permission to verify.|
| options    | Read-only| [PermissionOptions](#PermissionOptions)| No| Permission options.|

- Return values

  | Type| Description|
  | --------------- | ------------------------------------------------------------ |
  | Promise<number> | Promise used to return the permission verification result. The value **0** indicates that the PID and UID have the given permission, and the value **-1** indicates that the PID and UID do not have the given permission.|

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
var Permission = context.PermissionOptions(1,1);
context.getOrCreateLocalDir('com.context.permission',Permission).then((void) => {
	console.info("==========================>verifyPermissionCallback=======================>");
});
```

## PermissionRequestResult

| Name| Readable/Writable| Type| Mandatory| Description|
| ----------- | -------- | -------------- | ---- | ------------------ |
| requestCode | Read-only| number         | Yes| Request code passed.|
| permissions | Read-only| Array\<string> | Yes| Permissions passed.|
| authResults | Read-only| Array\<number> | Yes| Permission request result.|



## Context.requestPermissionsFromUser(permissions: Array<string>, requestCode: number, resultCallback: AsyncCallback<[PermissionRequestResult](#PermissionRequestResult)>)

- Functionality

  Requests certain permissions from the system. This method uses a callback to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| -------------- | -------- | ------------------------------------------------------------ | ---- | --------------------------------------------- |
| permissions    | Read-only| Array\<string>                                               | Yes| Permissions to request. This parameter cannot be **null**.|
| requestCode    | Read-only| number                                                       | Yes| Request code to be passed to **PermissionRequestResult**.|
| resultCallback | Read-only| AsyncCallback\<[PermissionRequestResult](#PermissionRequestResult)> | Yes| Permission request result.|
- Return values

  void

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateLocalDir(    
    ["com.example.permission1",
     "com.example.permission2",
     "com.example.permission3",
     "com.example.permission4",
     "com.example.permission5"],
    1,
)
```



## Context.getApplicationInfo(callback: AsyncCallback<ApplicationInfo>)

- Functionality

  Obtains information about the current application. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | -------- | -------- | ------------------------------- | ---- | ---------------------- |
  | callback | Read-only| AsyncCallback\<ApplicationInfo> | Yes| Callback used to return the application information.|

- Return values

  void

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getApplicationInfo()
```



## Context.getApplicationInfo

- Functionality

  Obtains information about the current application. This method uses a promise to return the result.

- Parameters

  None

- Return values

  | Type| Description|
  | ------------------------ | ------------------ |
  | Promise<ApplicationInfo> | Promise used to return the application information.|

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getApplicationInfo().then((void) => {
	console.info("==========================>getApplicationInfoCallback=======================>");
});
```



##  Context.getBundleName(callback: AsyncCallback<string>)

- Functionality

  Obtains the bundle name of the current ability. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | -------- | -------- | ---------------------- | ---- | --------------------------- |
  | callback | Read-only| AsyncCallback\<string> | Yes| Callback used to return the bundle name.|

- Return values

  void

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getBundleName()
```



## Context.getBundleName

- Functionality

  Obtains the bundle name of the current ability. This method uses a promise to return the result.

- Parameters

  None

- Return values

  | Type| Description|
  | --------------- | ----------------------- |
  | Promise<string> | Promise used to return the bundle name.|

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getBundleName().then((void) => {
	console.info("==========================>getBundleNameCallback=======================>");
});
```



##  Context.getProcessInfo(callback: AsyncCallback<ProcessInfo>)

- Functionality

  Obtains information about the current process, including the PID and process name. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | -------- | -------- | --------------------------- | ---- | ------------------ |
  | callback | Read-only| AsyncCallback\<ProcessInfo> | Yes| Callback used to return the process information.|

- Return values

  void

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessInfo()
```



## Context.getProcessInfo

- Functionality

  Obtains information about the current process, including the PID and process name. This method uses a promise to return the result.

- Parameters

  None

- Return values

  | Type| Description|
  | -------------------- | -------------- |
  | Promise<ProcessInfo> | Promise used to return the process information.|

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessInfo().then((void) => {
	console.info("==========================>getProcessInfoCallback=======================>");
});
```



##  Context.getElementName(callback: AsyncCallback<ElementName>)

- Functionality

  Obtains the **ohos.bundle.ElementName** object of the current ability. This method is available only to Page abilities. It uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | -------- | -------- | --------------------------- | ---- | -------------------------------------------- |
  | callback | Read-only| AsyncCallback\<ElementName> | Yes| Callback used to return the **ohos.bundle.ElementName** object.|

- Return values

  void

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getElementName()
```



## Context.getElementName

- Functionality

  Obtains the **ohos.bundle.ElementName** object of the current ability. This method is available only to Page abilities. It uses a promise to return the result.

- Parameters

  None

- Return values

  | Type| Description|
  | -------------------- | ---------------------------------------- |
  | Promise<ElementName> | Promise used to return the **ohos.bundle.ElementName** object.|

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getElementName().then((void) => {
	console.info("==========================>getElementNameCallback=======================>");
});
```

##   **Context.getProcessName(callback: AsyncCallback<string>)**

- Functionality

  Obtains the name of the current process. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | -------- | -------- | ---------------------- | ---- | ------------------ |
  | callback | Read-only| AsyncCallback\<string> | Yes| Callback used to return the process name.|

- Return values

  void

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessName()
```



## Context.getProcessName

- Functionality

  Obtains the name of the current process. This method uses a promise to return the result.

- Parameters

  None

- Return values

  | Type| Description|
  | --------------- | -------------- |
  | Promise<string> | Promise used to return the process name.|

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessName().then((void) => {
	console.info("==========================>getProcessNameCallback=======================>");
});
```



## Context.getCallingBundle(callback: AsyncCallback<string>)

- Functionality

  Obtains the bundle name of the calling ability. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | -------- | -------- | ---------------------- | ---- | ------------------------- |
  | callback | Read-only| AsyncCallback\<string> | Yes| Callback used to return the bundle name.|

- Return values

  void

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getCallingBundle()
```



## Context.getCallingBundle

- Functionality

  Obtains the bundle name of the calling ability. This method uses a promise to return the result.

- Parameters

  None

- Return values

  | Type| Description|
  | --------------- | ------------------------- |
  | Promise<string> | Promise used to return the bundle name.|

  

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getCallingBundle().then((void) => {
	console.info("==========================>getCallingBundleCallback=======================>");
});
```
