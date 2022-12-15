# Context

The **Context** module provides context for abilities or applications. It allows access to application-specific resources, as well as permission requests and verification.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the FA model.

## Usage

The **Context** object is created in a **featureAbility** and returned through its **getContext()** API. Therefore, you must import the **@ohos.ability.featureAbility** package before using the **Context** module. An example is as follows:

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getOrCreateLocalDir().then((data) => {
    console.info("getOrCreateLocalDir data: " + JSON.stringify(data));
});
```

## Context.getOrCreateLocalDir<sup>7+</sup>

getOrCreateLocalDir(callback: AsyncCallback\<string>): void

Obtains the local root directory of the application. This API uses an asynchronous callback to return the result.

If this API is called for the first time, a root directory will be created.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description           |
| -------- | ---------------------- | ---- | ------------- |
| callback | AsyncCallback\<string> | Yes   | Callback used to return the local root directory.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getOrCreateLocalDir((err, data)=>{
    console.info("getOrCreateLocalDir err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```



## Context.getOrCreateLocalDir<sup>7+</sup>

getOrCreateLocalDir(): Promise\<string>

Obtains the local root directory of the application. This API uses a promise to return the result.

If this API is called for the first time, a root directory will be created.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type              | Description         |
| ---------------- | ----------- |
| Promise\<string> | Promise used to return the local root directory.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getOrCreateLocalDir().then((data) => {
    console.info("getOrCreateLocalDir data: " + JSON.stringify(data));
});
```

## Context.verifyPermission<sup>7+</sup>

verifyPermission(permission: string, options: PermissionOptions, callback: AsyncCallback\<number>): void

Verifies whether a specific PID and UID have the given permission. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name        | Type                                     | Mandatory  | Description                  |
| ---------- | --------------------------------------- | ---- | -------------------- |
| permission | string                                  | Yes   | Name of the permission to verify.            |
| options    | [PermissionOptions](#permissionoptions7) | Yes   | Permission options.               |
| callback   | AsyncCallback\<number>                  | Yes   | Callback used to return the permission verification result. The value **0** means that the PID and UID have the given permission, and the value **-1** means the opposite.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import bundle from '@ohos.bundle';
var context = featureAbility.getContext();
bundle.getBundleInfo('com.context.test', 1, (err, datainfo) =>{
    context.verifyPermission("com.example.permission", {uid:datainfo.uid}, (err, data) =>{
        console.info("verifyPermission err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
    });
});
```



## Context.verifyPermission<sup>7+</sup>

verifyPermission(permission: string, callback: AsyncCallback\<number>): void

Verifies whether the current PID and UID have the given permission. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name        | Type                    | Mandatory  | Description                  |
| ---------- | ---------------------- | ---- | -------------------- |
| permission | string                 | Yes   | Name of the permission to verify.            |
| callback   | AsyncCallback\<number> | Yes   | Callback used to return the permission verification result. The value **0** means that the PID and UID have the given permission, and the value **-1** means the opposite.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.verifyPermission("com.example.permission", (err, data) =>{
    console.info("verifyPermission err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.verifyPermission<sup>7+</sup>

verifyPermission(permission: string, options?: PermissionOptions): Promise\<number>

Verifies whether a specific PID and UID have the given permission. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name        | Type                                     | Mandatory  | Description      |
| ---------- | --------------------------------------- | ---- | -------- |
| permission | string                                  | Yes   | Name of the permission to verify.|
| options    | [PermissionOptions](#permissionoptions) | No   | Permission options.   |

**Return value**

| Type              | Description                                |
| ---------------- | ---------------------------------- |
| Promise\<number> | Promise used to return the permission verification result. The value **0** means that the PID and UID have the given permission, and the value **-1** means the opposite.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
var Permission = {pid:1};
context.verifyPermission('com.context.permission',Permission).then((data) => {
    console.info("verifyPermission data: " + JSON.stringify(data));
});
```



## Context.requestPermissionsFromUser<sup>7+</sup>

requestPermissionsFromUser(permissions: Array\<string>, requestCode: number, resultCallback: AsyncCallback<[PermissionRequestResult](#permissionrequestresult)>): void

Requests certain permissions from the system. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name            | Type                                      | Mandatory  | Description                                 |
| -------------- | ---------------------------------------- | ---- | ----------------------------------- |
| permissions    | Array\<string>                           | Yes   | Permissions to request. This parameter cannot be **null**.             |
| requestCode    | number                                   | Yes   | Request code to be passed to **PermissionRequestResult**.|
| resultCallback | AsyncCallback<[PermissionRequestResult](#permissionrequestresult)> | Yes   | Callback used to return the permission request result.                          |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.requestPermissionsFromUser(
    ["com.example.permission1",
     "com.example.permission2",
     "com.example.permission3",
     "com.example.permission4",
     "com.example.permission5"],
    1,
    (err, data) => {
        console.info("requestPermissionsFromUser err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
    }
);
```


## Context.requestPermissionsFromUser<sup>7+</sup>

requestPermissionsFromUser(permissions: Array\<string>, requestCode: number): Promise\<[PermissionRequestResult](#permissionrequestresult7)>

Requests certain permissions from the system. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name          | Type                | Mandatory | Description                                         |
| -------------- | ------------------- | ----- | -------------------------------------------- |
| permissions    | Array\<string>      | Yes   | Permissions to request. This parameter cannot be **null**.        |
| requestCode    | number              | Yes   | Request code to be passed to **PermissionRequestResult**.|

**Return value**

| Type                                                          | Description            |
| ------------------------------------------------------------- | ---------------- |
| Promise\<[PermissionRequestResult](#permissionrequestresult7)> | Promise used to return the permission request result.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.requestPermissionsFromUser(
    ["com.example.permission1",
     "com.example.permission2",
     "com.example.permission3",
     "com.example.permission4",
     "com.example.permission5"],
    1).then((data)=>{
        console.info("requestPermissionsFromUser data: " + JSON.stringify(data));
    }
);
```



## Context.getApplicationInfo<sup>7+</sup>

getApplicationInfo(callback: AsyncCallback\<ApplicationInfo>): void

Obtains information about the current application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                             | Mandatory  | Description          |
| -------- | ------------------------------- | ---- | ------------ |
| callback | AsyncCallback\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)> | Yes   | Callback used to return the application information.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getApplicationInfo((err, data) => {
    console.info("getApplicationInfo err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```



## Context.getApplicationInfo<sup>7+</sup>

getApplicationInfo(): Promise\<ApplicationInfo>

Obtains information about the current application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                       | Description       |
| ------------------------- | --------- |
| Promise\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)> | Promise used to return the application information.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getApplicationInfo().then((data) => {
    console.info("getApplicationInfo data: " + JSON.stringify(data));
});
```



## Context.getBundleName<sup>7+</sup>

getBundleName(callback: AsyncCallback\<string>): void

Obtains the bundle name of this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description                |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<string> | Yes   | Callback used to return the bundle name.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getBundleName((err, data) => {
    console.info("getBundleName err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```



## Context.getBundleName<sup>7+</sup>

getBundleName(): Promise\<string>

Obtains the bundle name of this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type              | Description              |
| ---------------- | ---------------- |
| Promise\<string> | Promise used to return the bundle name.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getBundleName().then((data) => {
    console.info("getBundleName data: " + JSON.stringify(data));
});
```

## Context.getDisplayOrientation<sup>7+</sup>

getDisplayOrientation(callback: AsyncCallback\<bundle.DisplayOrientation>): void

Obtains the display orientation of this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name    | Type                                                        | Mandatory| Description              |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| callback | AsyncCallback\<[bundle.DisplayOrientation](js-apis-Bundle.md#displayorientation)> | Yes  | Callback used to return the display orientation.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getDisplayOrientation((err, data) => {
    console.info("getDisplayOrientation err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getDisplayOrientation<sup>7+</sup>

getDisplayOrientation(): Promise\<bundle.DisplayOrientation>;

Obtains the display orientation of this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                      | Description       |
| ---------------------------------------- | --------- |
| Promise\<[bundle.DisplayOrientation](js-apis-Bundle.md#displayorientation)> | Promise used to return the display orientation.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getDisplayOrientation().then((data) => {
    console.info("getDisplayOrientation data: " + JSON.stringify(data));
});
```

## Context.getExternalCacheDir

getExternalCacheDir(callback: AsyncCallback\<string>): void

Obtains the external cache directory of the application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description                |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<string> | Yes   | Callback used to return the absolute path of the cache directory.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getExternalCacheDir((err, data) => {
    console.info("getExternalCacheDir err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getExternalCacheDir

getExternalCacheDir(): Promise\<string>;

Obtains the external cache directory of the application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type              | Description              |
| ---------------- | ---------------- |
| Promise\<string> | Promise used to return the absolute path of the cache directory.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getExternalCacheDir().then((data) => {
    console.info("getExternalCacheDir data: " + JSON.stringify(data));
});
```

## Context.setDisplayOrientation<sup>7+</sup>

setDisplayOrientation(orientation: bundle.DisplayOrientation, callback: AsyncCallback\<void>): void

Sets the display orientation for this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name         | Type                                      | Mandatory  | Description          |
| ----------- | ---------------------------------------- | ---- | ------------ |
| orientation | [bundle.DisplayOrientation](js-apis-Bundle.md#displayorientation) | Yes   | Display orientation to set.|
| callback    | AsyncCallback\<void> | Yes   | Callback used to return the display orientation.   |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import bundle from '@ohos.bundle';
var context = featureAbility.getContext();
var orientation=bundle.DisplayOrientation.UNSPECIFIED
context.setDisplayOrientation(orientation, (err) => {
    console.info("setDisplayOrientation err: " + JSON.stringify(err));
});
```

## Context.setDisplayOrientation<sup>7+</sup>

setDisplayOrientation(orientation: bundle.DisplayOrientation): Promise\<void>;

Sets the display orientation for this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| orientation                              | [bundle.DisplayOrientation](js-apis-Bundle.md#displayorientation) |
| Promise\<void> | Promise used to return the display orientation.                               |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import bundle from '@ohos.bundle';
var context = featureAbility.getContext();
var orientation=bundle.DisplayOrientation.UNSPECIFIED
context.setDisplayOrientation(orientation).then((data) => {
    console.info("setDisplayOrientation data: " + JSON.stringify(data));
});
```

## Context.setShowOnLockScreen<sup>7+</sup>

setShowOnLockScreen(show: boolean, callback: AsyncCallback\<void>): void

Sets whether to show this feature at the top of the lock screen so that the feature remains activated. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                  | Mandatory  | Description                                      |
| -------- | -------------------- | ---- | ---------------------------------------- |
| show     | boolean              | Yes   | Whether to show this feature at the top of the lock screen. The value **true** means to show this feature at the top of the lock screen, and **false** means the opposite.|
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result.                                 |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
var show=true
context.setShowOnLockScreen(show, (err) => {
    console.info("setShowOnLockScreen err: " + JSON.stringify(err));
});
```

## Context.setShowOnLockScreen<sup>7+</sup>

setShowOnLockScreen(show: boolean): Promise\<void>;

Sets whether to show this feature at the top of the lock screen so that the feature remains activated. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type     | Mandatory  | Description                                      |
| ---- | ------- | ---- | ---------------------------------------- |
| show | boolean | Yes   | Whether to show this feature at the top of the lock screen. The value **true** means to show this feature at the top of the lock screen, and **false** means the opposite.|

**Return value**

| Type            | Description             |
| -------------- | --------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
var show=true
context.setShowOnLockScreen(show).then((data) => {
    console.info("setShowOnLockScreen data: " + JSON.stringify(data));
});
```

## Context.setWakeUpScreen<sup>7+</sup>

setWakeUpScreen(wakeUp: boolean, callback: AsyncCallback\<void>): void

Sets whether to wake up the screen when this feature is restored. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                  | Mandatory  | Description                               |
| -------- | -------------------- | ---- | --------------------------------- |
| wakeUp   | boolean              | Yes   | Whether to wake up the screen. The value **true** means to wake up the screen, and **false** means the opposite.|
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result.                          |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
var wakeUp=true
context.setWakeUpScreen(wakeUp, (err) => {
    console.info("setWakeUpScreen err: " + JSON.stringify(err));
});
```

## Context.setWakeUpScreen<sup>7+</sup>

setWakeUpScreen(wakeUp: boolean): Promise\<void>; 

Sets whether to wake up the screen when this feature is restored. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name    | Type     | Mandatory  | Description                               |
| ------ | ------- | ---- | --------------------------------- |
| wakeUp | boolean | Yes   | Whether to wake up the screen. The value **true** means to wake up the screen, and **false** means the opposite.|

**Return value**

| Type            | Description             |
| -------------- | --------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
var wakeUp=true
context.setWakeUpScreen(wakeUp).then((data) => {
    console.info("setWakeUpScreen data: " + JSON.stringify(data));
});
```




## Context.getProcessInfo<sup>7+</sup>

getProcessInfo(callback: AsyncCallback\<ProcessInfo>): void

Obtains information about the current process, including the PID and process name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                         | Mandatory  | Description        |
| -------- | --------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[ProcessInfo](js-apis-inner-app-processInfo.md)> | Yes   | Callback used to return the process information.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getProcessInfo((err, data) => {
    console.info("getProcessInfo err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```



## Context.getProcessInfo<sup>7+</sup>

getProcessInfo(): Promise\<ProcessInfo>

Obtains information about the current process, including the PID and process name. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                   | Description     |
| --------------------- | ------- |
| Promise\<[ProcessInfo](js-apis-inner-app-processInfo.md)> | Promise used to return the process information.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getProcessInfo().then((data) => {
    console.info("getProcessInfo data: " + JSON.stringify(data));
});
```



## Context.getElementName<sup>7+</sup>

getElementName(callback: AsyncCallback\<ElementName>): void

Obtains the **ohos.bundle.ElementName** object of this ability. This API uses an asynchronous callback to return the result.

This API is available only to Page abilities.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                         | Mandatory  | Description                                    |
| -------- | --------------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<[ElementName](js-apis-bundle-ElementName.md)> | Yes   | Callback used to return the **ohos.bundle.ElementName** object.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getElementName((err, data) => {
    console.info("getElementName err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```



## Context.getElementName<sup>7+</sup>

getElementName(): Promise\<ElementName>

Obtains the **ohos.bundle.ElementName** object of this ability. This API uses a promise to return the result.

This API is available only to Page abilities.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                   | Description                                  |
| --------------------- | ------------------------------------ |
| Promise\<[ElementName](js-apis-bundle-ElementName.md)> | Promise used to return the **ohos.bundle.ElementName** object.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getElementName().then((data) => {
    console.info("getElementName data: " + JSON.stringify(data));
});
```

## Context.getProcessName<sup>7+</sup>

getProcessName(callback: AsyncCallback\<string>): void

Obtains the name of the current process. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description        |
| -------- | ---------------------- | ---- | ---------- |
| callback | AsyncCallback\<string> | Yes   | Callback used to return the process name.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getProcessName((err, data) => {
    console.info("getProcessName err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```



## Context.getProcessName<sup>7+</sup>

getProcessName(): Promise\<string>

Obtains the name of the current process. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type              | Description        |
| ---------------- | ---------- |
| Promise\<string> | Promise used to return the process name.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getProcessName().then((data) => {
    console.info("getProcessName data: " + JSON.stringify(data));
});
```



## Context.getCallingBundle<sup>7+</sup>

getCallingBundle(callback: AsyncCallback\<string>): void

Obtains the bundle name of the calling ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description              |
| -------- | ---------------------- | ---- | ---------------- |
| callback | AsyncCallback\<string> | Yes   | Callback used to return the bundle name.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getCallingBundle((err, data) => {
    console.info("getCallingBundle err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```



## Context.getCallingBundle<sup>7+</sup>

getCallingBundle(): Promise\<string>

Obtains the bundle name of the calling ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type              | Description            |
| ---------------- | -------------- |
| Promise\<string> | Promise used to return the bundle name.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getCallingBundle().then((data) => {
    console.info("getCallingBundle data: " + JSON.stringify(data));
});
```

## Context.getCacheDir

getCacheDir(callback: AsyncCallback\<string>): void

Obtains the cache directory of the application in the internal storage. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description             |
| -------- | ---------------------- | ---- | --------------- |
| callback | AsyncCallback\<string> | Yes   | Callback used to return the cache directory.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getCacheDir((err, data) => {
    console.info("getCacheDir err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getCacheDir

getCacheDir(): Promise\<string>

Obtains the cache directory of the application in the internal storage. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type              | Description             |
| ---------------- | --------------- |
| Promise\<string> | Promise used to return the cache directory.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getCacheDir().then((data) => {
    console.info("getCacheDir data: " + JSON.stringify(data));
});
```

## Context.getFilesDir

getFilesDir(callback: AsyncCallback\<string>): void

Obtains the file directory of the application in the internal storage. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description                 |
| -------- | ---------------------- | ---- | ------------------- |
| callback | AsyncCallback\<string> | Yes   | Callback used to return the file directory.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getFilesDir((err, data) => {
    console.info("getFilesDir err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getFilesDir

getFilesDir(): Promise\<string>

Obtains the file directory of the application in the internal storage. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type              | Description                 |
| ---------------- | ------------------- |
| Promise\<string> | Promise used to return the file directory.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getFilesDir().then((data) => {
    console.info("getFilesDir data: " + JSON.stringify(data));
});
```

## Context.getOrCreateDistributedDir<sup>7+</sup>

getOrCreateDistributedDir(callback: AsyncCallback\<string>): void

Obtains the distributed file path for storing ability or application data files. This API uses an asynchronous callback to return the result.

If the distributed file path does not exist, the system will create one and return the created path.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description                                      |
| -------- | ---------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback\<string> | Yes   | Callback used to return the distributed file path. If the distributed file path does not exist, the system will create one and return the created path.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getOrCreateDistributedDir((err, data) => {
    console.info("getOrCreateDistributedDir err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getOrCreateDistributedDir<sup>7+</sup>

getOrCreateDistributedDir(): Promise\<string>

Obtains the distributed file path for storing ability or application data files. This API uses a promise to return the result.

If the distributed file path does not exist, the system will create one and return the created path.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type              | Description                                 |
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise used to return the distributed file path. If this API is called for the first time, a new path will be created.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getOrCreateDistributedDir().then((data) => {
    console.info("getOrCreateDistributedDir data: " + JSON.stringify(data));
});
```

## Context.getAppType<sup>7+</sup>

getAppType(callback: AsyncCallback\<string>): void

Obtains the application type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description                              |
| -------- | ---------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<string> | Yes   | Callback used to return the application type.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getAppType((err, data) => {
    console.info("getAppType err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getAppType<sup>7+</sup>

getAppType(): Promise\<string>

Obtains the application type. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type              | Description                |
| ---------------- | ------------------ |
| Promise\<string> | Promise used to return the application type.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getAppType().then((data) => {
    console.info("getAppType data: " + JSON.stringify(data));
});
```

## Context.getHapModuleInfo<sup>7+</sup>

getHapModuleInfo(callback: AsyncCallback\<HapModuleInfo>): void

Obtains the **ModuleInfo** object of the application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                                     |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| callback | AsyncCallback\<[HapModuleInfo](js-apis-bundle-HapModuleInfo.md)> | Yes   | Callback used to return the **ModuleInfo** object.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getHapModuleInfo((err, data) => {
    console.info("getHapModuleInfo err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getHapModuleInfo<sup>7+</sup>

getHapModuleInfo(): Promise\<HapModuleInfo>

Obtains the **ModuleInfo** object of the application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                      | Description                |
| ---------------------------------------- | ------------------ |
| Promise\<[HapModuleInfo](js-apis-bundle-HapModuleInfo.md)> | Promise used to return the **ModuleInfo** object.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getHapModuleInfo().then((data) => {
    console.info("getHapModuleInfo data: " + JSON.stringify(data));
});
```

## Context.getAppVersionInfo<sup>7+</sup>

getAppVersionInfo(callback: AsyncCallback\<AppVersionInfo>): void

Obtains the version information of the application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                            |
| -------- | ---------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<[AppVersionInfo](js-apis-inner-app-appVersionInfo.md)> | Yes   | Callback used to return the version information.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getAppVersionInfo((err, data) => {
    console.info("getAppVersionInfo err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getAppVersionInfo<sup>7+</sup>

getAppVersionInfo(): Promise\<AppVersionInfo>

Obtains the version information of the application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                      | Description       |
| ---------------------------------------- | --------- |
| Promise\<[AppVersionInfo](js-apis-inner-app-appVersionInfo.md)> | Promise used to return the version information.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getAppVersionInfo().then((data) => {
    console.info("getAppVersionInfo data: " + JSON.stringify(data));
});
```

## Context.getAbilityInfo<sup>7+</sup>

getAbilityInfo(callback: AsyncCallback\<AbilityInfo>): void

Obtains information about this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                                     |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| callback | AsyncCallback\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)> | Yes   | Callback used to return the ability information.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getAbilityInfo((err, data) => {
    console.info("getAbilityInfo err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getAbilityInfo<sup>7+</sup>

getAbilityInfo(): Promise\<AbilityInfo>

Obtains information about this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                      | Description                |
| ---------------------------------------- | ------------------ |
| Promise\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)> | Promise used to return the ability information.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getAbilityInfo().then((data) => {
    console.info("getAbilityInfo data: " + JSON.stringify(data));
});
```

## Context.getApplicationContext<sup>7+</sup>

getApplicationContext(): Context

Obtains the context of the application.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type     | Description        |
| ------- | ---------- |
| Context | Application context.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext().getApplicationContext();
```

## Context.isUpdatingConfigurations<sup>7+</sup>

isUpdatingConfigurations(callback: AsyncCallback\<boolean>): void;

Checks whether the configuration of this ability is being updated. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                     | Mandatory  | Description                           |
| -------- | ----------------------- | ---- | ----------------------------- |
| callback | AsyncCallback\<boolean> | Yes   | Returns **true** if the configuration of the capability is being updated; returns **false** otherwise.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.isUpdatingConfigurations((err, data) => {
    console.info("isUpdatingConfigurations err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.isUpdatingConfigurations<sup>7+</sup>

isUpdatingConfigurations(): Promise\<boolean>;

Checks whether the configuration of this ability is being updated. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type               | Description                           |
| ----------------- | ----------------------------- |
| Promise\<boolean> | Returns **true** if the configuration of the capability is being updated; returns **false** otherwise.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.isUpdatingConfigurations().then((data) => {
    console.info("isUpdatingConfigurations data: " + JSON.stringify(data));
});
```

## Context.printDrawnCompleted<sup>7+</sup>

printDrawnCompleted(callback: AsyncCallback\<void>): void;

Notifies the system of the time required to draw this page function. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                  | Mandatory  | Description         |
| -------- | -------------------- | ---- | ----------- |
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.printDrawnCompleted((err) => {
    console.error('printDrawnCompleted err: ' + JSON.stringify(err));
});
```

## Context.printDrawnCompleted<sup>7+</sup>

printDrawnCompleted(): Promise\<void>;

Notifies the system of the time required to draw this page function. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type            | Description             |
| -------------- | --------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.printDrawnCompleted().then((data) => {
    console.info("printDrawnCompleted data: " + JSON.stringify(data));
});
```


## PermissionOptions<sup>7+</sup>

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name  | Readable/Writable| Type    | Mandatory  | Description   |
| ---- | ---- | ------ | ---- | ----- |
| pid  | Read-only  | number | No   | Process ID.|
| uid  | Read-only  | number | No   | User ID.|

## PermissionRequestResult<sup>7+</sup>

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name         | Readable/Writable| Type            | Mandatory  | Description        |
| ----------- | ---- | -------------- | ---- | ---------- |
| requestCode | Read-only  | number         | Yes   | Request code passed.|
| permissions | Read-only  | Array\<string> | Yes   | Permissions requested.  |
| authResults | Read-only  | Array\<number> | Yes   | Permission request result.  |

## AppVersionInfo<sup>7+</sup>

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name         | Type    | Readable  | Writable  | Description     |
| ----------- | ------ | ---- | ---- | ------- |
| appName     | string | Yes   | No   | Module name.  |
| versionCode | number | Yes   | No   | Module description.|
| versionName | string | Yes   | No   | Module description ID.|
