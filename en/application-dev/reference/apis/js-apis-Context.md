# Context

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the FA module.

## Modules to Import

```js
import featureAbility from '@ohos.ability.featureAbility'
import bundle from '@ohos.bundle'
```

The **Context** object is created in a **featureAbility** and returned through its **getContext()** API. Therefore, you must import the **@ohos.ability.featureAbility** package before using the Context module. An example is as follows:

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateLocalDir()
```

## Context.getOrCreateLocalDir<sup>7+</sup>

getOrCreateLocalDir(callback: AsyncCallback\<string>): void

Obtains the local root directory of the application. This API uses an asynchronous callback to return the result.

If this API is called for the first time, a root directory will be created.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | ---------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<string> | Yes | Callback used to return the local root directory. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateLocalDir((err, data)=>{
    console.info("data=" + data);
})
```



## Context.getOrCreateLocalDir<sup>7+</sup>

getOrCreateLocalDir(): Promise\<string>

Obtains the local root directory of the application. This API uses a promise to return the result.

If this API is called for the first time, a root directory will be created.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type | Description |
| ---------------- | ---------------------- |
| Promise\<string> | Promise used to return the local root directory. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateLocalDir().then((data) => {
    console.info("data=" + data);
});
```



## Context.verifyPermission<sup>7+</sup>

verifyPermission(permission: string, options: PermissionOptions, callback: AsyncCallback\<number>): void

Verifies whether a specific PID and UID have the given permission. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| ---------- | --------------------------------------- | ---- | ------------------------------------- |
| permission | string | Yes | Name of the permission to verify. |
| options | [PermissionOptions](#permissionoptions) | Yes | Permission options. |
| callback | AsyncCallback\<number> | Yes | Callback used to return the permission verification result. The value **0** indicates that the PID and UID have the given permission, and the value **-1** indicates that the PID and UID do not have the given permission. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
import bundle from '@ohos.bundle'
var context = featureAbility.getContext();
bundle.getBundleInfo('com.context.test', 1, (err,datainfo) =>{
	context.verifyPermission("com.example.permission", {uid:datainfo.uid});
});
```



## Context.verifyPermission<sup>7+</sup>

verifyPermission(permission: string, callback: AsyncCallback\<number>): void

Verifies whether the current PID and UID have the given permission. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| ---------- | ---------------------- | ---- | ------------------------------------- |
| permission | string | Yes | Name of the permission to verify. |
| callback | AsyncCallback\<number> | Yes | Callback used to return the permission verification result. The value **0** indicates that the PID and UID have the given permission, and the value **-1** indicates that the PID and UID do not have the given permission. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.verifyPermission("com.example.permission")
```

## Context.verifyPermission<sup>7+</sup>

verifyPermission(permission: string, options?: PermissionOptions): Promise\<number>

Verifies whether a specific PID and UID have the given permission. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| ---------- | --------------------------------------- | ---- | ---------------- |
| permission | string | Yes | Name of the permission to verify. |
| options | [PermissionOptions](#permissionoptions) | No | Permission options. |

**Return value**

| Type | Description |
| ---------------- | ----------------------------------------------------------- |
| Promise\<number> | Promise used to return the permission verification result. The value **0** indicates that the PID and UID have the given permission, and the value **-1** indicates that the PID and UID do not have the given permission. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
var Permission = {pid:1};
context.verifyPermission('com.context.permission',Permission).then((data) => {
    console.info("======================>verifyPermissionCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```



## Context.requestPermissionsFromUser<sup>7+</sup>

requestPermissionsFromUser(permissions: Array\<string>, requestCode: number, resultCallback: AsyncCallback<[PermissionRequestResult](#permissionrequestresult)>): void

Requests certain permissions from the system. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| permissions | Array\<string> | Yes | Permissions to request. This parameter cannot be **null**. |
| requestCode | number | Yes | Request code to be passed to **PermissionRequestResult**. |
| resultCallback | AsyncCallback<[PermissionRequestResult](#permissionrequestresult)> | Yes | Permission request result. |

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



## Context.getApplicationInfo<sup>7+</sup>

getApplicationInfo(callback: AsyncCallback\<ApplicationInfo>): void

Obtains information about the current application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | ------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<ApplicationInfo> | Yes | Callback used to return the application information. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getApplicationInfo()
```



## Context.getApplicationInfo<sup>7+</sup>

getApplicationInfo(): Promise\<ApplicationInfo>

Obtains information about the current application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type | Description |
| ------------------------- | ------------------ |
| Promise\<ApplicationInfo> | Promise used to return the application information. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getApplicationInfo().then((data) => {
    console.info("=====================>getApplicationInfoCallback===================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```



## Context.getBundleName<sup>7+</sup>

getBundleName(callback: AsyncCallback\<string>): void

Obtains the bundle name of the current ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | ---------------------- | ---- | ----------------------------- |
| callback | AsyncCallback\<string> | Yes | Callback used to return the bundle name. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getBundleName()
```



## Context.getBundleName<sup>7+</sup>

getBundleName(): Promise\<string>

Obtains the bundle name of the current ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type | Description |
| ---------------- | ------------------------- |
| Promise\<string> | Promise used to return the bundle name. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getBundleName().then((data) => {
    console.info("=======================>getBundleNameCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```



## Context.getProcessInfo<sup>7+</sup>

getProcessInfo(callback: AsyncCallback\<ProcessInfo>): void

Obtains information about the current process, including the PID and process name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | --------------------------- | ---- | -------------------- |
| callback | AsyncCallback\<ProcessInfo> | Yes | Callback used to return the process information. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessInfo()
```



## Context.getProcessInfo<sup>7+</sup>

getProcessInfo(): Promise\<ProcessInfo>

Obtains information about the current process, including the PID and process name. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type | Description |
| --------------------- | -------------- |
| Promise\<ProcessInfo> | Promise used to return the process information. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessInfo().then((data) => {
    console.info("=======================>getProcessInfoCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```



## Context.getElementName<sup>7+</sup>

getElementName(callback: AsyncCallback\<ElementName>): void

Obtains the **ohos.bundle.ElementName** object of the current ability. This API uses an asynchronous callback to return the result.

This API is available only to Page abilities.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | --------------------------- | ---- | ---------------------------------------------- |
| callback | AsyncCallback\<ElementName> | Yes | Callback used to return the **ohos.bundle.ElementName** object. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getElementName()
```



## Context.getElementName<sup>7+</sup>

getElementName(): Promise\<ElementName>

Obtains the **ohos.bundle.ElementName** object of the current ability. This API uses a promise to return the result.

This API is available only to Page abilities.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type | Description |
| --------------------- | ------------------------------------------ |
| Promise\<ElementName> | Promise used to return the **ohos.bundle.ElementName** object. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getElementName().then((data) => {
    console.info("=======================>getElementNameCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```

## Context.getProcessName<sup>7+</sup>

getProcessName(callback: AsyncCallback\<string>): void

Obtains the name of the current process. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | Yes | Callback used to return the process name. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessName()
```



## Context.getProcessName<sup>7+</sup>

getProcessName(): Promise\<string>

Obtains the name of the current process. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type | Description |
| ---------------- | -------------------- |
| Promise\<string> | Promise used to return the process name. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessName().then((data) => {
    console.info("=======================>getProcessNameCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```



## Context.getCallingBundle<sup>7+</sup>

getCallingBundle(callback: AsyncCallback\<string>): void

Obtains the bundle name of the calling ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<string> | Yes | Callback used to return the bundle name. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getCallingBundle()
```



## Context.getCallingBundle<sup>7+</sup>

getCallingBundle(): Promise\<string>

Obtains the bundle name of the calling ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type | Description |
| --------------- | ------------------------- |
| Promise\<string> | Promise used to return the bundle name. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getCallingBundle().then((data) => {
    console.info("======================>getCallingBundleCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```

## Context.getCacheDir

getCacheDir(callback: AsyncCallback\<string>): void

Obtains the cache directory of the application on the internal storage. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<string> | Yes | Callback used to return the cache directory. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getCacheDir((err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
});
```

## Context.getCacheDir

getCacheDir(): Promise\<string>

Obtains the cache directory of the application on the internal storage. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type | Description |
| --------------- | ------------------------- |
| Promise\<string> | Promise used to return the cache directory. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getCacheDir().then((data) => {
    console.info("======================>getCacheDirPromsie====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```

## Context.getFilesDir

getFilesDir(callback: AsyncCallback\<string>): void

Obtains the file directory of the application on the internal storage. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<string> | Yes | Callback used to return the file directory. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getFilesDir((err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
});
```

## Context.getFilesDir

getFilesDir(): Promise\<string>

Obtains the file directory of the application on the internal storage. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type | Description |
| --------------- | ------------------------- |
| Promise\<string> | Promise used to return the file directory. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getFilesDir().then((data) => {
    console.info("======================>getFilesDirPromsie====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```

## Context.getOrCreateDistributedDir<sup>7+</sup>

getOrCreateDistributedDir(callback: AsyncCallback\<string>): void

Obtains the distributed file path for storing ability or application data files. This API uses an asynchronous callback to return the result.

If the distributed file path does not exist, the system will create one and return the created path.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<string> | Yes | Callback used to return the distributed file path. If the distributed file path does not exist, the system will create one and return the created path. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateDistributedDir((err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
});
```

## Context.getOrCreateDistributedDir<sup>7+</sup>

getOrCreateDistributedDir(): Promise\<string>

Obtains the distributed file path for storing ability or application data files. This API uses a promise to return the result.

If the distributed file path does not exist, the system will create one and return the created path.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type | Description |
| --------------- | ------------------------- |
| Promise\<string> | Promise used to return the distributed file path. If this API is called for the first time, a new path will be created. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateDistributedDir().then((data) => {
    console.info("====>data====>" + JSON.stringify(data));
});
```

## Context.getAppType<sup>7+</sup>

getAppType(callback: AsyncCallback\<string>): void

Obtains the application type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<string> | Yes | Callback used to return the application type. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getAppType((err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
});
```

## Context.getAppType<sup>7+</sup>

getAppType(): Promise\<string>

Obtains the application type. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type | Description |
| --------------- | ------------------------- |
| Promise\<string> | Promise used to return the application type. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getAppType().then((data) => {
    console.info("====>data====>" + JSON.stringify(data));
});
```

## Context.getHapModuleInfo<sup>7+</sup>

getHapModuleInfo(callback: AsyncCallback\<HapModuleInfo>): void

Obtains the **ModuleInfo** object of the application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<[HapModuleInfo](#hapmoduleinfo)> | Yes | Callback used to return the **ModuleInfo** object. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getHapModuleInfo((err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
});
```

## Context.getHapModuleInfo<sup>7+</sup>

getHapModuleInfo(): Promise\<HapModuleInfo>

Obtains the **ModuleInfo** object of the application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type | Description |
| --------------- | ------------------------- |
| Promise\<[HapModuleInfo](#hapmoduleinfo)> | Promise used to return the **ModuleInfo** object. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getHapModuleInfo().then((data) => {
    console.info("====>data====>" + JSON.stringify(data));
});
```

## Context.getAppVersionInfo<sup>7+</sup>

getAppVersionInfo(callback: AsyncCallback\<HapModuleInfo>): void

Obtains the version information of the application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<[AppVersionInfo](#appversioninfo)> | Yes | Callback used to return the version information. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getAppVersionInfo((err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
});
```

## Context.getAppVersionInfo<sup>7+</sup>

getAppVersionInfo(): Promise\<AppVersionInfo>

Obtains the version information of the application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type | Description |
| --------------- | ------------------------- |
| Promise\<[AppVersionInfo](#appversioninfo)> | Promise used to return the version information. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getAppVersionInfo().then((data) => {
    console.info("====>data====>" + JSON.stringify(data));
});
```

## Context.getAbilityInfo<sup>7+</sup>

getAbilityInfo(callback: AsyncCallback\<AbilityInfo>): void

Obtains information of the current ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<[AbilityInfo](#abilityInfo)> | Yes |Callback used to return the ability information. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getAbilityInfo((err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
});
```

## Context.getAbilityInfo<sup>7+</sup>

getAbilityInfo(): Promise\<AbilityInfo>

Obtains information of the current ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type | Description |
| --------------- | ------------------------- |
| Promise\<[AbilityInfo](#abilityInfo)> | Promise used to return the ability information. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getAbilityInfo().then((data) => {
    console.info("====>data====>" + JSON.stringify(data));
});
```

## Context.getApplicationContext<sup>7+</sup>

getApplicationContext(): Context

Obtains the context of the application.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type | Description |
| --------- |------ |
|  Context |Application context. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext().getApplicationContext();
```

## PermissionOptions<sup>7+</sup>

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Readable/Writable | Type | Mandatory | Description |
| ---- | -------- | ------ | ---- | ------ |
| pid | Read-only | number | No | Process ID. |
| uid | Read-only | number | No | User ID. |

## PermissionRequestResult<sup>7+</sup>

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name | Readable/Writable | Type | Mandatory | Description |
| ----------- | -------- | -------------- | ---- | ------------------ |
| requestCode | Read-only | number | Yes | Request code passed. |
| permissions | Read-only | Array\<string> | Yes | Permissions requested. |
| authResults | Read-only | Array\<number> | Yes | Permission request result. |

## HapModuleInfo<sup>7+</sup>

Describes the HAP module information.

| Name | Type| Readable | Writable | Description |
| ------ | ------ | ------ | ------ | ------ |
| name | string | Yes | No | Module name. |
| description | string | Yes | No | Module description. |
| descriptionId | number | Yes | No | Module description ID. |
| icon | string | Yes | No | Module icon. |
| label | string | Yes | No | Module label. |
| labelId | number | Yes | No | Module label ID. |
| iconId | number | Yes | No | Module icon ID. |
| backgroundImg | string | Yes | No | Module background image. |
| supportedModes | number | Yes | No | Modes supported by the module. |
| reqCapabilities | Array<string> | Yes | No | Capabilities required for module running. |
| deviceTypes | Array<string> | Yes | No | An array of supported device types. |
| abilityInfo | Array<AbilityInfo> | Yes | No | Ability information. |
| moduleName | string | Yes | No | Module name. |
| mainAbilityName | string | Yes | No | Name of the entrance ability. |
| installationFree | boolean | Yes | No | When installation-free is supported. |
| mainElementName | string | Yes| No| Information about the entry ability. |

## AppVersionInfo<sup>7+</sup>

| Name | Type| Readable | Writable | Description |
| ------ | ------ | ------| ------ | ------ |
| appName | string | Yes | No | Module name. |
| versionCode | number | Yes | No | Module description. |
| versionName | string | Yes | No | Module description ID. |
