# Context
<!--deprecated_code_no_check-->

The **Context** module provides context for abilities or applications. It allows access to application-specific resources, as well as permission requests and verification.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs of this module can be used only in the FA model.

## Modules to Import

```ts
import featureAbility from '@ohos.ability.featureAbility';
```

## Usage

The **Context** object is created in a **featureAbility** and returned through its [getContext](js-apis-ability-featureAbility.md#featureabilitygetcontext) API. Therefore, you must import the **@ohos.ability.featureAbility** package before using the **Context** module. An example is as follows:

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getOrCreateLocalDir().then((data) => {
    console.info(`getOrCreateLocalDir data: ${JSON.stringify(data)}`);
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getOrCreateLocalDir((error, data)=>{
    if (error && error.code !== 0) {
        console.error(`getOrCreateLocalDir fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getOrCreateLocalDir success, data: ${JSON.stringify(data)}`);
    }
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getOrCreateLocalDir().then((data) => {
    console.info(`getOrCreateLocalDir data: ${JSON.stringify(data)}`);
});
```

## Context.verifyPermission<sup>7+</sup>

verifyPermission(permission: string, options: PermissionOptions, callback: AsyncCallback\<number>): void

Verifies whether a PID and UID have the given permission. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name        | Type                                     | Mandatory  | Description                  |
| ---------- | --------------------------------------- | ---- | -------------------- |
| permission | string                                  | Yes   | Name of the permission to verify.            |
| options    | [PermissionOptions](#permissionoptions7) | Yes   | Permission options.               |
| callback   | AsyncCallback\<number>                  | Yes   | Callback used to return the permission verification result. The value **0** means that the PID and UID have the given permission, and the value **-1** means the opposite.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';
import bundle from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let context: featureAbility.Context = featureAbility.getContext();
bundle.getBundleInfo('com.context.test', 1, (err: BusinessError, datainfo: bundle.BundleInfo) =>{
    context.verifyPermission('com.example.permission', {uid:datainfo.appInfo.uid}, (error, data) =>{
        if (error && error.code !== 0) {
            console.error(`verifyPermission fail, error: ${JSON.stringify(error)}`);
        } else {
            console.log(`verifyPermission success, data: ${JSON.stringify(data)}`);
        }
    });
});
```
For details about **getBundleInfo** in the sample code, see [bundleManager](js-apis-bundleManager.md).



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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.verifyPermission('com.example.permission', (error, data) =>{
    if (error && error.code !== 0) {
        console.error(`verifyPermission fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`verifyPermission success, data: ${JSON.stringify(data)}`);
    }
});
```

## Context.verifyPermission<sup>7+</sup>

verifyPermission(permission: string, options?: PermissionOptions): Promise\<number>

Verifies whether a PID and UID have the given permission. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name        | Type                                     | Mandatory  | Description      |
| ---------- | --------------------------------------- | ---- | -------- |
| permission | string                                  | Yes   | Name of the permission to verify.|
| options    | [PermissionOptions](#permissionoptions7) | No   | Permission options.   |

**Return value**

| Type              | Description                                |
| ---------------- | ---------------------------------- |
| Promise\<number> | Promise used to return the permission verification result. The value **0** means that the PID and UID have the given permission, and the value **-1** means the opposite.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.verifyPermission('com.context.permission', {pid:1}).then((data) => {
    console.info(`verifyPermission data: ${JSON.stringify(data)}`);
});
```



## Context.requestPermissionsFromUser<sup>7+</sup>

requestPermissionsFromUser(permissions: Array\<string>, requestCode: number, resultCallback: AsyncCallback\<PermissionRequestResult>): void

Requests certain permissions from the system. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name            | Type                                      | Mandatory  | Description                                 |
| -------------- | ---------------------------------------- | ---- | ----------------------------------- |
| permissions    | Array\<string>                           | Yes   | Permissions to request. This parameter cannot be **null**.             |
| requestCode    | number                                   | Yes   | Request code to be passed to [PermissionRequestResult](#permissionrequestresult7).|
| resultCallback | AsyncCallback<[PermissionRequestResult](#permissionrequestresult7)> | Yes   | Callback used to return the permission request result.                          |

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.requestPermissionsFromUser(
    ['com.example.permission1',
     'com.example.permission2',
     'com.example.permission3',
     'com.example.permission4',
     'com.example.permission5'],
    1,
    (error, data) => {
        if (error && error.code !== 0) {
            console.error(`requestPermissionsFromUser fail, error: ${JSON.stringify(error)}`);
        } else {
            console.log(`requestPermissionsFromUser success, data: ${JSON.stringify(data)}`);
        }
    }
);
```


## Context.requestPermissionsFromUser<sup>7+</sup>

requestPermissionsFromUser(permissions: Array\<string>, requestCode: number): Promise\<PermissionRequestResult>

Requests certain permissions from the system. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name          | Type                | Mandatory | Description                                         |
| -------------- | ------------------- | ----- | -------------------------------------------- |
| permissions    | Array\<string>      | Yes   | Permissions to request. This parameter cannot be **null**.        |
| requestCode    | number              | Yes   | Request code to be passed to [PermissionRequestResult](#permissionrequestresult7).|

**Return value**

| Type                                                          | Description            |
| ------------------------------------------------------------- | ---------------- |
| Promise\<[PermissionRequestResult](#permissionrequestresult7)> | Promise used to return the permission request result.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.requestPermissionsFromUser(
    ['com.example.permission1',
     'com.example.permission2',
     'com.example.permission3',
     'com.example.permission4',
     'com.example.permission5'],
    1).then((data)=>{
        console.info(`requestPermissionsFromUser data: ${JSON.stringify(data)}`);
    }
);
```



## Context.getApplicationInfo<sup>7+</sup>

getApplicationInfo(callback: AsyncCallback\<ApplicationInfo>): void

Obtains information about the application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                             | Mandatory  | Description          |
| -------- | ------------------------------- | ---- | ------------ |
| callback | AsyncCallback\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | Yes   | Callback used to return the application information.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getApplicationInfo((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getApplicationInfo fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getApplicationInfo success, data: ${JSON.stringify(data)}`);
    }
});
```



## Context.getApplicationInfo<sup>7+</sup>

getApplicationInfo(): Promise\<ApplicationInfo>

Obtains information about the application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                       | Description       |
| ------------------------- | --------- |
| Promise\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)> | Promise used to return the application information.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getApplicationInfo().then((data) => {
    console.info(`getApplicationInfo data: ${JSON.stringify(data)}`);
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getBundleName((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getBundleName fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getBundleName success, data: ${JSON.stringify(data)}`);
    }
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getBundleName().then((data) => {
    console.info(`getBundleName data: ${JSON.stringify(data)}`);
});
```

## Context.getDisplayOrientation<sup>7+</sup>

getDisplayOrientation(callback: AsyncCallback\<bundle.DisplayOrientation>): void

Obtains the display orientation of this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name    | Type                                                        | Mandatory| Description              |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| callback | AsyncCallback\<[bundle.DisplayOrientation](js-apis-bundleManager.md#displayorientation)> | Yes  | Callback used to return the display orientation.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getDisplayOrientation((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getDisplayOrientation fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getDisplayOrientation success, data: ${JSON.stringify(data)}`);
    }
});
```

## Context.getDisplayOrientation<sup>7+</sup>

getDisplayOrientation(): Promise\<bundle.DisplayOrientation>

Obtains the display orientation of this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                      | Description       |
| ---------------------------------------- | --------- |
| Promise\<[bundle.DisplayOrientation](js-apis-bundleManager.md#displayorientation)> | Promise used to return the display orientation.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getDisplayOrientation().then((data) => {
    console.info(`getDisplayOrientation data: ${JSON.stringify(data)}`);
});
```

## Context.getExternalCacheDir<sup>(deprecated)</sup>

getExternalCacheDir(callback: AsyncCallback\<string>): void

Obtains the external cache directory of the application. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 7.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description                |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<string> | Yes   | Callback used to return the absolute path of the cache directory.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getExternalCacheDir((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getExternalCacheDir fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getExternalCacheDir success, data: ${JSON.stringify(data)}`);
    }
});
```

## Context.getExternalCacheDir<sup>(deprecated)</sup>

getExternalCacheDir(): Promise\<string>

Obtains the external cache directory of the application. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 7.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type              | Description              |
| ---------------- | ---------------- |
| Promise\<string> | Promise used to return the absolute path of the cache directory.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getExternalCacheDir().then((data) => {
    console.info(`getExternalCacheDir data: ${JSON.stringify(data)}`);
});
```

## Context.setDisplayOrientation<sup>7+</sup>

setDisplayOrientation(orientation: bundle.DisplayOrientation, callback: AsyncCallback\<void>): void

Sets the display orientation for this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name         | Type                                      | Mandatory  | Description          |
| ----------- | ---------------------------------------- | ---- | ------------ |
| orientation | [bundle.DisplayOrientation](js-apis-bundleManager.md#displayorientation) | Yes   | Display orientation to set.|
| callback    | AsyncCallback\<void> | Yes   | Callback used to return the result. If the setting is successful, **err** is **undefined**. Otherwise, **err** is an error object.   |

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';
import bundleManager from '@ohos.bundle';

let context: featureAbility.Context = featureAbility.getContext();
let orientation = bundleManager.DisplayOrientation.LANDSCAPE;
context.setDisplayOrientation(orientation, (error) => {
    console.error(`setDisplayOrientation fail, error: ${JSON.stringify(error)}`);
});
```

## Context.setDisplayOrientation<sup>7+</sup>

setDisplayOrientation(orientation: bundle.DisplayOrientation): Promise\<void>

Sets the display orientation for this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name                                      | Type                                      | Mandatory  | Description                                      |
| ---------------------------------------- | ---------------------------------------- | ---- | ------------ |
| orientation                              | [bundle.DisplayOrientation](js-apis-bundleManager.md#displayorientation) | Yes   | Callback used to return the display orientation.                               |

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';
import bundleManager from '@ohos.bundle';

let context: featureAbility.Context = featureAbility.getContext();
let orientation = bundleManager.DisplayOrientation.UNSPECIFIED;
context.setDisplayOrientation(orientation).then((data) => {
    console.info(`setDisplayOrientation data: ${JSON.stringify(data)}`);
});
```

## Context.setShowOnLockScreen<sup>(deprecated)</sup>

setShowOnLockScreen(show: boolean, callback: AsyncCallback\<void>): void

Sets whether to show this feature at the top of the lock screen so that the feature remains activated. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use **window.setShowOnLockScreen**, which is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                  | Mandatory  | Description                                      |
| -------- | -------------------- | ---- | ---------------------------------------- |
| show     | boolean              | Yes   | Whether to show this feature at the top of the lock screen. The value **true** means to show this feature at the top of the lock screen, and **false** means the opposite.|
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result. If the setting is successful, **err** is **undefined**. Otherwise, **err** is an error object.  |

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
let show = true;
context.setShowOnLockScreen(show, (error) => {
    console.error(`setShowOnLockScreen fail, error: ${JSON.stringify(error)}`);
});
```

## Context.setShowOnLockScreen<sup>(deprecated)</sup>

setShowOnLockScreen(show: boolean): Promise\<void>

Sets whether to show this feature at the top of the lock screen so that the feature remains activated. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use **window.setShowOnLockScreen**, which is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type     | Mandatory  | Description                                      |
| ---- | ------- | ---- | ---------------------------------------- |
| show | boolean | Yes   | Whether to show this feature at the top of the lock screen. The value **true** means to show this feature at the top of the lock screen, and **false** means the opposite.|

**Return value**

| Type            | Description             |
| -------------- | --------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
let show = true;
context.setShowOnLockScreen(show).then((data) => {
    console.info(`setShowOnLockScreen data: ${JSON.stringify(data)}`);
});
```

## Context.setWakeUpScreen<sup>(deprecated)</sup>

setWakeUpScreen(wakeUp: boolean, callback: AsyncCallback\<void>): void

Sets whether to wake up the screen when this feature is restored. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 12. Its substitute, **window.setWakeUpScreen**, is available only to system applications.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                  | Mandatory  | Description                               |
| -------- | -------------------- | ---- | --------------------------------- |
| wakeUp   | boolean              | Yes   | Whether to wake up the screen. The value **true** means to wake up the screen, and **false** means the opposite.|
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result. If the setting is successful, **err** is **undefined**. Otherwise, **err** is an error object. |

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
let wakeUp = true;
context.setWakeUpScreen(wakeUp, (error) => {
    console.error(`setWakeUpScreen fail, error: ${JSON.stringify(error)}`);
});
```

## Context.setWakeUpScreen<sup>(deprecated)</sup>

setWakeUpScreen(wakeUp: boolean): Promise\<void>

Sets whether to wake up the screen when this feature is restored. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 12. Its substitute, **window.setWakeUpScreen**, is available only to system applications.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name    | Type     | Mandatory  | Description                               |
| ------ | ------- | ---- | --------------------------------- |
| wakeUp | boolean | Yes   | Whether to wake up the screen. The value **true** means to wake up the screen, and **false** means the opposite.|

**Return value**

| Type            | Description             |
| -------------- | --------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
let wakeUp = true;
context.setWakeUpScreen(wakeUp).then((data) => {
    console.info(`setWakeUpScreen data: ${JSON.stringify(data)}`);
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getProcessInfo((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getProcessInfo fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getProcessInfo success, data: ${JSON.stringify(data)}`);
    }
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getProcessInfo().then((data) => {
    console.info(`getProcessInfo data: ${JSON.stringify(data)}`);
});
```



## Context.getElementName<sup>7+</sup>

getElementName(callback: AsyncCallback\<ElementName>): void

Obtains the element name of this ability. This API uses an asynchronous callback to return the result.

This API is available only to Page abilities.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                         | Mandatory  | Description                                    |
| -------- | --------------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<[ElementName](js-apis-bundleManager-elementName.md)> | Yes   | Callback used to return the element name, which is an **ohos.bundleManager.ElementName** object.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getElementName((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getElementName fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getElementName success, data: ${JSON.stringify(data)}`);
    }
});
```



## Context.getElementName<sup>7+</sup>

getElementName(): Promise\<ElementName>

Obtains the element name of this ability. This API uses a promise to return the result.

This API is available only to Page abilities.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                   | Description                                  |
| --------------------- | ------------------------------------ |
| Promise\<[ElementName](js-apis-bundleManager-elementName.md)> | Promise used to return the element name, which is an **ohos.bundleManager.ElementName** object.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getElementName().then((data) => {
    console.info(`getElementName data: ${JSON.stringify(data)}`);
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getProcessName((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getProcessName fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getProcessName success, data: ${JSON.stringify(data)}`);
    }
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getProcessName().then((data) => {
    console.info(`getProcessName data: ${JSON.stringify(data)}`);
});
```



## Context.getCallingBundle<sup>7+</sup>

getCallingBundle(callback: AsyncCallback\<string>): void

Obtains the bundle name of the caller ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description              |
| -------- | ---------------------- | ---- | ---------------- |
| callback | AsyncCallback\<string> | Yes   | Callback used to return the bundle name.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getCallingBundle((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getCallingBundle fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getCallingBundle success, data: ${JSON.stringify(data)}`);
    }
});
```



## Context.getCallingBundle<sup>7+</sup>

getCallingBundle(): Promise\<string>

Obtains the bundle name of the caller ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type              | Description            |
| ---------------- | -------------- |
| Promise\<string> | Promise used to return the bundle name.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getCallingBundle().then((data) => {
    console.info(`getCallingBundle data: ${JSON.stringify(data)}`);
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getCacheDir((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getCacheDir fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getCacheDir success, data: ${JSON.stringify(data)}`);
    }
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getCacheDir().then((data) => {
    console.info(`getCacheDir data: ${JSON.stringify(data)}`);
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getFilesDir((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getFilesDir fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getFilesDir success, data: ${JSON.stringify(data)}`);
    }
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getFilesDir().then((data) => {
    console.info(`getFilesDir data: ${JSON.stringify(data)}`);
});
```

## Context.getOrCreateDistributedDir<sup>7+</sup>

getOrCreateDistributedDir(callback: AsyncCallback\<string>): void

Obtains the distributed file path for storing ability or application data files. This API uses an asynchronous callback to return the result.

If the distributed file path does not exist, the system will create a path and return the created path.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description                                      |
| -------- | ---------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback\<string> | Yes   | Callback used to return the distributed file path.<br>If the path does not exist, the system will create one and return the created path.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getOrCreateDistributedDir((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getOrCreateDistributedDir fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getOrCreateDistributedDir success, data: ${JSON.stringify(data)}`);
    }
});
```

## Context.getOrCreateDistributedDir<sup>7+</sup>

getOrCreateDistributedDir(): Promise\<string>

Obtains the distributed file path for storing ability or application data files. This API uses a promise to return the result.

If the distributed file path does not exist, the system will create a path and return the created path.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type              | Description                                 |
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise used to return the distributed file path. If this API is called for the first time, a path will be created.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getOrCreateDistributedDir().then((data) => {
    console.info(`getOrCreateDistributedDir data: ${JSON.stringify(data)}`);
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getAppType((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getAppType fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getAppType success, data: ${JSON.stringify(data)}`);
    }
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getAppType().then((data) => {
    console.info(`getAppType data: ${JSON.stringify(data)}`);
});
```

## Context.getHapModuleInfo<sup>7+</sup>

getHapModuleInfo(callback: AsyncCallback\<HapModuleInfo>): void

Obtains the module information of the application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                                     |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| callback | AsyncCallback\<[HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md)> | Yes   | Callback used to return the module information, which is a **HapModuleInfo** object.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getHapModuleInfo((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getHapModuleInfo fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getHapModuleInfo success, data: ${JSON.stringify(data)}`);
    }
});
```

## Context.getHapModuleInfo<sup>7+</sup>

getHapModuleInfo(): Promise\<HapModuleInfo>

Obtains the module information of the application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                      | Description                |
| ---------------------------------------- | ------------------ |
| Promise\<[HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md)> | Promise used to return the module information, which is a **HapModuleInfo** object.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getHapModuleInfo().then((data) => {
    console.info(`getHapModuleInfo data: ${JSON.stringify(data)}`);
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getAppVersionInfo((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getAppVersionInfo fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getAppVersionInfo success, data: ${JSON.stringify(data)}`);
    }
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getAppVersionInfo().then((data) => {
    console.info(`getAppVersionInfo data: ${JSON.stringify(data)}`);
});
```

## Context.getAbilityInfo<sup>7+</sup>

getAbilityInfo(callback: AsyncCallback\<AbilityInfo>): void

Obtains information about this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                                     |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| callback | AsyncCallback\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)> | Yes   | Callback used to return the ability information.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getAbilityInfo((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getAbilityInfo fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getAbilityInfo success, data: ${JSON.stringify(data)}`);
    }
});
```

## Context.getAbilityInfo<sup>7+</sup>

getAbilityInfo(): Promise\<AbilityInfo>

Obtains information about this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                      | Description                |
| ---------------------------------------- | ------------------ |
| Promise\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)> | Promise used to return the ability information.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.getAbilityInfo().then((data) => {
    console.info(`getAbilityInfo data: ${JSON.stringify(data)}`);
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

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext().getApplicationContext();
```

## Context.isUpdatingConfigurations<sup>7+</sup>

isUpdatingConfigurations(callback: AsyncCallback\<boolean>): void

Checks whether the configuration of this ability is being updated. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                     | Mandatory  | Description                           |
| -------- | ----------------------- | ---- | ----------------------------- |
| callback | AsyncCallback\<boolean> | Yes   | Callback used to return the result. The value **true** means that the configuration of the ability is being updated, and **false** means the opposite.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.isUpdatingConfigurations((error, data) => {
    if (error && error.code !== 0) {
        console.error(`isUpdatingConfigurations fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`isUpdatingConfigurations success, data: ${JSON.stringify(data)}`);
    }
});
```

## Context.isUpdatingConfigurations<sup>7+</sup>

isUpdatingConfigurations(): Promise\<boolean>

Checks whether the configuration of this ability is being updated. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type               | Description                           |
| ----------------- | ----------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the configuration of the ability is being updated, and **false** means the opposite.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.isUpdatingConfigurations().then((data) => {
    console.info(`isUpdatingConfigurations data: ${JSON.stringify(data)}`);
});
```

## Context.printDrawnCompleted<sup>7+</sup>

printDrawnCompleted(callback: AsyncCallback\<void>): void

Notifies the system of the time required to draw this page function. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                  | Mandatory  | Description         |
| -------- | -------------------- | ---- | ----------- |
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result. If the notification is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.printDrawnCompleted((err) => {
    console.error(`printDrawnCompleted err: ${JSON.stringify(err)}`);
});
```

## Context.printDrawnCompleted<sup>7+</sup>

printDrawnCompleted(): Promise\<void>

Notifies the system of the time required to draw this page function. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type            | Description             |
| -------------- | --------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.printDrawnCompleted().then((data) => {
    console.info(`printDrawnCompleted data: ${JSON.stringify(data)}`);
});
```


## PermissionOptions<sup>7+</sup>

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name  | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| pid  |number | No   | Process ID.|
| uid  |number | No   | User ID.|

## PermissionRequestResult<sup>7+</sup>

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name        | Type            | Mandatory  | Description        |
| ----------- |-------------- | ---- | ---------- |
| requestCode | number         | Yes   | Request code passed.|
| permissions | Array\<string> | Yes   | Permissions requested.  |
| authResults | Array\<number> | Yes   | Permission request result.  |
