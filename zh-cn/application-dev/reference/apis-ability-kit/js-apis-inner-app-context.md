# Context

Context模块提供了ability或application的上下文的能力，包括允许访问特定于应用程序的资源、请求和验证权限等。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 本模块接口仅可在FA模型下使用。

## 导入模块

```ts
import featureAbility from '@ohos.ability.featureAbility';
```

## 使用说明

Context对象是在featureAbility中创建实例，并通过featureAbility的[getContext](js-apis-ability-featureAbility.md#featureabilitygetcontext)接口返回，因此在使用Context时，必须导入@ohos.ability.featureAbility库。示例如下：

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

获取应用程序的本地根目录。使用callback异步回调。

如果是第一次调用，将创建目录。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明            |
| -------- | ---------------------- | ---- | ------------- |
| callback | AsyncCallback\<string> | 是    | 回调函数，返回应用程序的本地根目录。 |

**示例：**

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

获取应用程序的本地根目录。使用Promise异步回调。

如果是第一次调用，将创建目录。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明          |
| ---------------- | ----------- |
| Promise\<string> | Promise对象，返回应用程序的本地根目录。 |

**示例：**

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

验证系统中运行的特定pid和uid是否允许指定的权限。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名         | 类型                                      | 必填   | 说明                   |
| ---------- | --------------------------------------- | ---- | -------------------- |
| permission | string                                  | 是    | 指定权限的名称。             |
| options    | [PermissionOptions](#permissionoptions7) | 是    | 权限选项。                |
| callback   | AsyncCallback\<number>                  | 是    | 回调函数，返回权限验证结果，0有权限，-1无权限。 |

**示例：**

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
示例代码中出现的getBundleInfo相关描述可参考对应[文档](js-apis-bundleManager.md)。



## Context.verifyPermission<sup>7+</sup>

verifyPermission(permission: string, callback: AsyncCallback\<number>): void

验证系统中运行的当前pid和uid是否具有指定的权限。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名         | 类型                     | 必填   | 说明                   |
| ---------- | ---------------------- | ---- | -------------------- |
| permission | string                 | 是    | 指定权限的名称。             |
| callback   | AsyncCallback\<number> | 是    | 回调函数，返回权限验证结果，0有权限，-1无权限。 |

**示例：**

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

验证系统中运行的特定pid和uid是否具有指定的权限。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名         | 类型                                      | 必填   | 说明       |
| ---------- | --------------------------------------- | ---- | -------- |
| permission | string                                  | 是    | 指定权限的名称。 |
| options    | [PermissionOptions](#permissionoptions7) | 否    | 权限选项。    |

**返回值：**

| 类型               | 说明                                 |
| ---------------- | ---------------------------------- |
| Promise\<number> | Promise对象，如果pid和uid具有权限，则使用0进行异步回调；否则使用-1回调。 |

**示例：**

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

从系统请求某些权限。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名             | 类型                                       | 必填   | 说明                                  |
| -------------- | ---------------------------------------- | ---- | ----------------------------------- |
| permissions    | Array\<string>                           | 是    | 指示要请求的权限列表。此参数不能为null。              |
| requestCode    | number                                   | 是    | 指示要传递给[PermissionRequestResult](#permissionrequestresult7)的请求代码。 |
| resultCallback | AsyncCallback<[PermissionRequestResult](#permissionrequestresult7)> | 是    | 回调函数，返回授权结果信息。                           |

**示例：**

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

从系统请求某些权限。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名           | 类型                 | 必填  | 说明                                          |
| -------------- | ------------------- | ----- | -------------------------------------------- |
| permissions    | Array\<string>      | 是    | 指示要请求的权限列表。此参数不能为null。         |
| requestCode    | number              | 是    | 指示要传递给[PermissionRequestResult](#permissionrequestresult7)的请求代码。 |

**返回值：**

| 类型                                                           | 说明             |
| ------------------------------------------------------------- | ---------------- |
| Promise\<[PermissionRequestResult](#permissionrequestresult7)> | Promise对象，返回授权结果信息。 |

**示例：**

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

获取有关当前应用程序的信息。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                              | 必填   | 说明           |
| -------- | ------------------------------- | ---- | ------------ |
| callback | AsyncCallback\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | 是    | 回调函数，返回当前应用程序的信息。 |

**示例：**

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

获取有关当前应用程序的信息。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                        | 说明        |
| ------------------------- | --------- |
| Promise\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)> | Promise对象，返回当前应用程序的信息。 |

**示例：**

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

获取当前ability的Bundle名称。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明                 |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<string> | 是    | 回调函数，返回当前ability的Bundle名称。 |

**示例：**

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

获取当前ability的Bundle名称。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明               |
| ---------------- | ---------------- |
| Promise\<string> | Promise对象，返回当前ability的Bundle名称。 |

**示例：**

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

获取当前ability的显示方向。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明               |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| callback | AsyncCallback\<[bundle.DisplayOrientation](js-apis-bundleManager.md#displayorientation)> | 是   | 回调函数，返回屏幕显示方向。 |

**示例：**

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

获取此能力的当前显示方向。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                       | 说明        |
| ---------------------------------------- | --------- |
| Promise\<[bundle.DisplayOrientation](js-apis-bundleManager.md#displayorientation)> | Promise对象，返回屏幕显示方向。 |

**示例：**

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

获取应用程序的外部缓存目录。使用callback异步回调。

**说明：**
>
> 从API version 7开始不再支持。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明                 |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<string> | 是    | 回调函数，返回应用程序的缓存目录的绝对路径。 |

**示例：**

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

获取应用程序的外部缓存目录。使用Promise异步回调。

**说明：**
>
> 从API version 7开始不再支持。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明               |
| ---------------- | ---------------- |
| Promise\<string> | Promise对象，返回应用程序的缓存目录的绝对路径。 |

**示例：**

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

设置当前Ability的显示方向。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名          | 类型                                       | 必填   | 说明           |
| ----------- | ---------------------------------------- | ---- | ------------ |
| orientation | [bundle.DisplayOrientation](js-apis-bundleManager.md#displayorientation) | 是    | 指示当前能力的新方向。 |
| callback    | AsyncCallback\<void> | 是    | 回调函数。当设置当前Ability的显示方向成功，err为undefined，否则为错误对象。    |

**示例：**

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

设置当前Ability的显示方向。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名                                       | 类型                                       | 必填   | 说明                                       |
| ---------------------------------------- | ---------------------------------------- | ---- | ------------ |
| orientation                              | [bundle.DisplayOrientation](js-apis-bundleManager.md#displayorientation) | 是    | 表示屏幕显示方向。                                |

**返回值：**

| 类型             | 说明               |
| -------------- | ---------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

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

设置每当显示锁屏时是否在锁屏顶部显示此功能，使该功能保持激活状态。使用callback异步回调。

**说明：**
>
> 从API version 9开始不再支持。建议使用window.setShowOnLockScreen替代，新接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                   | 必填   | 说明                                       |
| -------- | -------------------- | ---- | ---------------------------------------- |
| show     | boolean              | 是    | 指定是否在锁屏顶部显示此功能。值true表示在锁屏上显示，值false表示不显示。 |
| callback | AsyncCallback\<void> | 是    | 回调函数。当设置每当显示锁屏时是否在锁屏顶部显示此功能并使该功能保持激活状态的操作成功，err为undefined，否则为错误对象。   |

**示例：**

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

设置每当显示锁屏时是否在锁屏顶部显示此功能，使该功能保持激活状态。使用Promise异步回调。

**说明：**
>
> 从API version 9开始不再支持。建议使用window.setShowOnLockScreen替代，新接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型      | 必填   | 说明                                       |
| ---- | ------- | ---- | ---------------------------------------- |
| show | boolean | 是    | 指定是否在锁屏顶部显示此功能。值true表示在锁屏上显示，值false表示不显示。 |

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

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

设置恢复此功能时是否唤醒屏幕。使用callback异步回调。

**说明：**
>
> 从API version 7开始支持，从API version 12开始废弃，替代接口window.setWakeUpScreen仅面向系统应用开放。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                   | 必填   | 说明                                |
| -------- | -------------------- | ---- | --------------------------------- |
| wakeUp   | boolean              | 是    | 指定是否唤醒屏幕。值true表示唤醒它，值false表示不唤醒它。 |
| callback | AsyncCallback\<void> | 是    | 回调函数。当设置恢复此功能时是否唤醒屏幕成功，err为undefined，否则为错误对象。  |

**示例：**

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

设置恢复此功能时是否唤醒屏幕。使用Promise异步回调。

**说明：**
>
> 从API version 7开始支持，从API version 12开始废弃，替代接口window.setWakeUpScreen仅面向系统应用开放。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名     | 类型      | 必填   | 说明                                |
| ------ | ------- | ---- | --------------------------------- |
| wakeUp | boolean | 是    | 指定是否唤醒屏幕。值true表示唤醒它，值false表示不唤醒它。 |

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

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

获取有关当前进程的信息，包括进程ID和名称。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                          | 必填   | 说明         |
| -------- | --------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[ProcessInfo](js-apis-inner-app-processInfo.md)> | 是    | 回调函数，返回当前进程的信息。 |

**示例：**

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

获取有关当前进程的信息，包括进程id和名称。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                    | 说明      |
| --------------------- | ------- |
| Promise\<[ProcessInfo](js-apis-inner-app-processInfo.md)> | Promise对象，返回当前进程的信息。 |

**示例：**

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

获取当前ability的ohos.bundleManager.ElementName对象。使用callback异步回调。

此方法仅适用于页面功能。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                          | 必填   | 说明                                     |
| -------- | --------------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<[ElementName](js-apis-bundleManager-elementName.md)> | 是    | 回调函数，返回当前ability的ohos.bundleManager.ElementName对象。 |

**示例：**

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

获取当前能力的ohos.bundleManager.ElementName对象。使用Promise异步回调。

此方法仅适用于页面功能。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                    | 说明                                   |
| --------------------- | ------------------------------------ |
| Promise\<[ElementName](js-apis-bundleManager-elementName.md)> | Promise对象，返回当前ability的ohos.bundleManager.ElementName对象。 |

**示例：**

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

获取当前进程的名称。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明         |
| -------- | ---------------------- | ---- | ---------- |
| callback | AsyncCallback\<string> | 是    | 回调函数，返回当前进程的名称。 |

**示例：**

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

获取当前进程的名称。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明         |
| ---------------- | ---------- |
| Promise\<string> | Promise对象，返回当前进程的名称。 |

**示例：**

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

获取ability调用方的Bundle名称。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明               |
| -------- | ---------------------- | ---- | ---------------- |
| callback | AsyncCallback\<string> | 是    | 回调函数，返回ability调用方的Bundle名称。 |

**示例：**

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

获取ability调用方的Bundle名称。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明             |
| ---------------- | -------------- |
| Promise\<string> | Promise对象，返回ability调用方的Bundle名称。 |

**示例：**

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

获取该应用程序的内部存储目录。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明              |
| -------- | ---------------------- | ---- | --------------- |
| callback | AsyncCallback\<string> | 是    | 回调函数，返回该应用程序的内部存储目录。 |

**示例：**

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

获取该应用程序的内部存储目录。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明              |
| ---------------- | --------------- |
| Promise\<string> | Promise对象，返回该应用程序的内部存储目录。 |

**示例：**

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

获取内部存储器上此应用程序的文件目录。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明                  |
| -------- | ---------------------- | ---- | ------------------- |
| callback | AsyncCallback\<string> | 是    | 回调函数，返回内部存储器上此应用程序的文件目录。 |

**示例：**

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

获取内部存储器上此应用程序的文件目录。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明                  |
| ---------------- | ------------------- |
| Promise\<string> | Promise对象，返回内部存储器上此应用程序的文件目录。 |

**示例：**

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

获取Ability或应用的分布式文件路径。使用callback异步回调。

如果分布式文件路径不存在，系统将创建一个路径并返回创建的路径。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明                                       |
| -------- | ---------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback\<string> | 是    | 回调函数，返回Ability或应用的分布式文件路径。<br>若路径不存在，系统将创建一个路径并返回创建的路径。 |

**示例：**

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

获取Ability或应用的分布式文件路径。使用Promise异步回调。

如果分布式文件路径不存在，系统将创建一个路径并返回创建的路径。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明                                  |
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise对象，返回Ability或应用的分布式文件路径。若为首次调用，则将创建目录。 |

**示例：**

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

获取此应用的类型。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明                               |
| -------- | ---------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<string> | 是    | 回调函数，返回此应用程序的类型。 |

**示例：**

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

获取此应用的类型。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明                 |
| ---------------- | ------------------ |
| Promise\<string> | Promise对象，返回此应用的类型。 |

**示例：**

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

获取应用的ModuleInfo对象。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                                       | 必填   | 说明                                      |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| callback | AsyncCallback\<[HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md)> | 是    | 回调函数，返回应用的ModuleInfo对象。 |

**示例：**

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

获取应用的ModuleInfo对象。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                       | 说明                 |
| ---------------------------------------- | ------------------ |
| Promise\<[HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md)> | Promise对象，返回应用的ModuleInfo对象。 |

**示例：**

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

获取应用的版本信息。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                                       | 必填   | 说明                             |
| -------- | ---------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<[AppVersionInfo](js-apis-inner-app-appVersionInfo.md)> | 是    | 回调函数，返回应用版本信息。 |

**示例：**

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

获取应用的版本信息。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                       | 说明        |
| ---------------------------------------- | --------- |
| Promise\<[AppVersionInfo](js-apis-inner-app-appVersionInfo.md)> | Promise对象，返回应用版本信息。 |

**示例：**

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

查询当前归属Ability详细信息。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                                       | 必填   | 说明                                      |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| callback | AsyncCallback\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)> | 是    | 回调函数，返回当前归属Ability详细信息。 |

**示例：**

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

查询当前归属Ability详细信息。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                       | 说明                 |
| ---------------------------------------- | ------------------ |
| Promise\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)> | Promise对象，返回当前归属Ability详细信息。 |

**示例：**

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

获取应用上下文信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型      | 说明         |
| ------- | ---------- |
| Context | 返回应用上下文信息。 |

**示例：**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext().getApplicationContext();
```

## Context.isUpdatingConfigurations<sup>7+</sup>

isUpdatingConfigurations(callback: AsyncCallback\<boolean>): void

检查此能力的配置是否正在更改。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                      | 必填   | 说明                            |
| -------- | ----------------------- | ---- | ----------------------------- |
| callback | AsyncCallback\<boolean> | 是    | 回调函数，返回true表示该Ability的配置正在更改，否则返回false。 |

**示例：**

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

检查此能力的配置是否正在更改。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                | 说明                            |
| ----------------- | ----------------------------- |
| Promise\<boolean> | Promise对象，返回true表示该Ability的配置正在更改，否则返回false。 |

**示例：**

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

通知系统绘制此页面功能所需的时间。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                   | 必填   | 说明          |
| -------- | -------------------- | ---- | ----------- |
| callback | AsyncCallback\<void> | 是    | 回调函数。当通知系统绘制此页面功能所需的时间成功，err为undefined，否则为错误对象。 |

**示例：**

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

通知系统绘制此页面功能所需的时间。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext();
context.printDrawnCompleted().then((data) => {
    console.info(`printDrawnCompleted data: ${JSON.stringify(data)}`);
});
```


## PermissionOptions<sup>7+</sup>

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称   | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| pid  |number | 否    | 进程id。 |
| uid  |number | 否    | 用户id。 |

## PermissionRequestResult<sup>7+</sup>

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称         | 类型             | 必填   | 说明         |
| ----------- |-------------- | ---- | ---------- |
| requestCode | number         | 是    | 用户传入的请求代码。 |
| permissions | Array\<string> | 是    | 用户传入的权限。   |
| authResults | Array\<number> | 是    | 请求权限的结果。   |