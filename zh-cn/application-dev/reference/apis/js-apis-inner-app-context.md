# Context

Context模块提供了ability或application的上下文的能力，包括允许访问特定于应用程序的资源、请求和验证权限等。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在FA模型下使用。

## 使用说明

Context对象是在featureAbility中创建实例，并通过featureAbility的getContext()接口返回，因此在使用Context时，必须导入@ohos.ability.featureAbility库。示例如下：

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getOrCreateLocalDir().then((data) => {
    console.info("getOrCreateLocalDir data: " + JSON.stringify(data));
});
```

## Context.getOrCreateLocalDir<sup>7+</sup>

getOrCreateLocalDir(callback: AsyncCallback\<string>): void

获取应用程序的本地根目录（callback形式）。

如果是第一次调用，将创建目录。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明            |
| -------- | ---------------------- | ---- | ------------- |
| callback | AsyncCallback\<string> | 是    | 返回应用程序的本地根目录。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getOrCreateLocalDir((err, data)=>{
    console.info("getOrCreateLocalDir err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```



## Context.getOrCreateLocalDir<sup>7+</sup>

getOrCreateLocalDir(): Promise\<string>

获取应用程序的本地根目录（Promise形式）。

如果是第一次调用，将创建目录。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明          |
| ---------------- | ----------- |
| Promise\<string> | 应用程序的本地根目录。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getOrCreateLocalDir().then((data) => {
    console.info("getOrCreateLocalDir data: " + JSON.stringify(data));
});
```

## Context.verifyPermission<sup>7+</sup>

verifyPermission(permission: string, options: PermissionOptions, callback: AsyncCallback\<number>): void

验证系统中运行的特定pid和uid是否允许指定的权限（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名         | 类型                                      | 必填   | 说明                   |
| ---------- | --------------------------------------- | ---- | -------------------- |
| permission | string                                  | 是    | 指定权限的名称。             |
| options    | [PermissionOptions](#permissionoptions7) | 是    | 权限选项。                |
| callback   | AsyncCallback\<number>                  | 是    | 返回权限验证结果，0有权限，-1无权限。 |

**示例：**

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

验证系统中运行的当前pid和uid是否具有指定的权限（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名         | 类型                     | 必填   | 说明                   |
| ---------- | ---------------------- | ---- | -------------------- |
| permission | string                 | 是    | 指定权限的名称。             |
| callback   | AsyncCallback\<number> | 是    | 返回权限验证结果，0有权限，-1无权限。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.verifyPermission("com.example.permission", (err, data) =>{
    console.info("verifyPermission err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.verifyPermission<sup>7+</sup>

verifyPermission(permission: string, options?: PermissionOptions): Promise\<number>

验证系统中运行的特定pid和uid是否具有指定的权限（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名         | 类型                                      | 必填   | 说明       |
| ---------- | --------------------------------------- | ---- | -------- |
| permission | string                                  | 是    | 指定权限的名称。 |
| options    | [PermissionOptions](#permissionoptions) | 否    | 权限选项。    |

**返回值：**

| 类型               | 说明                                 |
| ---------------- | ---------------------------------- |
| Promise\<number> | 如果pid和uid具有权限，则使用0进行异步回调；否则使用-1回调。 |

**示例：**

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

从系统请求某些权限（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名             | 类型                                       | 必填   | 说明                                  |
| -------------- | ---------------------------------------- | ---- | ----------------------------------- |
| permissions    | Array\<string>                           | 是    | 指示要请求的权限列表。此参数不能为null。              |
| requestCode    | number                                   | 是    | 指示要传递给PermissionRequestResult的请求代码。 |
| resultCallback | AsyncCallback<[PermissionRequestResult](#permissionrequestresult)> | 是    | 返回授权结果信息。                           |

**示例：**

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

从系统请求某些权限（promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名           | 类型                 | 必填  | 说明                                          |
| -------------- | ------------------- | ----- | -------------------------------------------- |
| permissions    | Array\<string>      | 是    | 指示要请求的权限列表。此参数不能为null。         |
| requestCode    | number              | 是    | 指示要传递给PermissionRequestResult的请求代码。 |

**返回值：**

| 类型                                                           | 说明             |
| ------------------------------------------------------------- | ---------------- |
| Promise\<[PermissionRequestResult](#permissionrequestresult7)> | 返回授权结果信息。 |

**示例：**

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

获取有关当前应用程序的信息（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                              | 必填   | 说明           |
| -------- | ------------------------------- | ---- | ------------ |
| callback | AsyncCallback\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)> | 是    | 返回当前应用程序的信息。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getApplicationInfo((err, data) => {
    console.info("getApplicationInfo err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```



## Context.getApplicationInfo<sup>7+</sup>

getApplicationInfo(): Promise\<ApplicationInfo>

获取有关当前应用程序的信息（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                        | 说明        |
| ------------------------- | --------- |
| Promise\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)> | 当前应用程序的信息 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getApplicationInfo().then((data) => {
    console.info("getApplicationInfo data: " + JSON.stringify(data));
});
```



## Context.getBundleName<sup>7+</sup>

getBundleName(callback: AsyncCallback\<string>): void

获取当前ability的捆绑包名称（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明                 |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<string> | 是    | 返回当前ability的捆绑包名称。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getBundleName((err, data) => {
    console.info("getBundleName err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```



## Context.getBundleName<sup>7+</sup>

getBundleName(): Promise\<string>

获取当前ability的捆绑包名称（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明               |
| ---------------- | ---------------- |
| Promise\<string> | 当前ability的捆绑包名称。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getBundleName().then((data) => {
    console.info("getBundleName data: " + JSON.stringify(data));
});
```

## Context.getDisplayOrientation<sup>7+</sup>

getDisplayOrientation(callback: AsyncCallback\<bundle.DisplayOrientation>): void

获取此能力的当前显示方向（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明               |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| callback | AsyncCallback\<[bundle.DisplayOrientation](js-apis-Bundle.md#displayorientation)> | 是   | 表示屏幕显示方向。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getDisplayOrientation((err, data) => {
    console.info("getDisplayOrientation err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getDisplayOrientation<sup>7+</sup>

getDisplayOrientation(): Promise\<bundle.DisplayOrientation>;

获取此能力的当前显示方向（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                       | 说明        |
| ---------------------------------------- | --------- |
| Promise\<[bundle.DisplayOrientation](js-apis-Bundle.md#displayorientation)> | 表示屏幕显示方向。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getDisplayOrientation().then((data) => {
    console.info("getDisplayOrientation data: " + JSON.stringify(data));
});
```

## Context.getExternalCacheDir

getExternalCacheDir(callback: AsyncCallback\<string>): void

获取应用程序的外部缓存目录（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明                 |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<string> | 是    | 返回应用程序的缓存目录的绝对路径。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getExternalCacheDir((err, data) => {
    console.info("getExternalCacheDir err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getExternalCacheDir

getExternalCacheDir(): Promise\<string>;

获取应用程序的外部缓存目录（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明               |
| ---------------- | ---------------- |
| Promise\<string> | 返回应用程序的缓存目录的绝对路径。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getExternalCacheDir().then((data) => {
    console.info("getExternalCacheDir data: " + JSON.stringify(data));
});
```

## Context.setDisplayOrientation<sup>7+</sup>

setDisplayOrientation(orientation: bundle.DisplayOrientation, callback: AsyncCallback\<void>): void

设置当前能力的显示方向（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名          | 类型                                       | 必填   | 说明           |
| ----------- | ---------------------------------------- | ---- | ------------ |
| orientation | [bundle.DisplayOrientation](js-apis-Bundle.md#displayorientation) | 是    | 指示当前能力的新方向。。 |
| callback    | AsyncCallback\<void> | 是    | 表示屏幕显示方向。    |

**示例：**

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

设置当前能力的显示方向（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                       | 说明                                       |
| ---------------------------------------- | ---------------------------------------- |
| orientation                              | [bundle.DisplayOrientation](js-apis-Bundle.md#displayorientation) |
| Promise\<void> | 表示屏幕显示方向。                                |

**示例：**

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

设置每当显示锁屏时是否在锁屏顶部显示此功能，使该功能保持激活状态（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                   | 必填   | 说明                                       |
| -------- | -------------------- | ---- | ---------------------------------------- |
| show     | boolean              | 是    | 指定是否在锁屏顶部显示此功能。值true表示在锁屏上显示，值false表示不显示。 |
| callback | AsyncCallback\<void> | 是    | 返回回调结果。                                  |

**示例：**

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

设置每当显示锁屏时是否在锁屏顶部显示此功能，使该功能保持激活状态（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型      | 必填   | 说明                                       |
| ---- | ------- | ---- | ---------------------------------------- |
| show | boolean | 是    | 指定是否在锁屏顶部显示此功能。值true表示在锁屏上显示，值false表示不显示。 |

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| Promise\<void> | 使用Promise形式返回结果 |

**示例：**

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

设置恢复此功能时是否唤醒屏幕。（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                   | 必填   | 说明                                |
| -------- | -------------------- | ---- | --------------------------------- |
| wakeUp   | boolean              | 是    | 指定是否唤醒屏幕。值true表示唤醒它，值false表示不唤醒它。 |
| callback | AsyncCallback\<void> | 是    | 返回回调结果。                           |

**示例：**

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

设置恢复此功能时是否唤醒屏幕。（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名     | 类型      | 必填   | 说明                                |
| ------ | ------- | ---- | --------------------------------- |
| wakeUp | boolean | 是    | 指定是否唤醒屏幕。值true表示唤醒它，值false表示不唤醒它。 |

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| Promise\<void> | 使用Promise形式返回结果 |

**示例：**

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

获取有关当前进程的信息，包括进程ID和名称（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                          | 必填   | 说明         |
| -------- | --------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[ProcessInfo](js-apis-inner-app-processInfo.md)> | 是    | 返回当前进程的信息。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getProcessInfo((err, data) => {
    console.info("getProcessInfo err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```



## Context.getProcessInfo<sup>7+</sup>

getProcessInfo(): Promise\<ProcessInfo>

获取有关当前进程的信息，包括进程id和名称（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                    | 说明      |
| --------------------- | ------- |
| Promise\<[ProcessInfo](js-apis-inner-app-processInfo.md)> | 当前进程的信息 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getProcessInfo().then((data) => {
    console.info("getProcessInfo data: " + JSON.stringify(data));
});
```



## Context.getElementName<sup>7+</sup>

getElementName(callback: AsyncCallback\<ElementName>): void

获取当前ability的ohos.bundle.ElementName对象（callback形式）。

此方法仅适用于页面功能。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                          | 必填   | 说明                                     |
| -------- | --------------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<[ElementName](js-apis-bundle-ElementName.md)> | 是    | 返回当前ability的ohos.bundle.ElementName对象。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getElementName((err, data) => {
    console.info("getElementName err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```



## Context.getElementName<sup>7+</sup>

getElementName(): Promise\<ElementName>

获取当前能力的ohos.bundle.ElementName对象（Promise形式）。

此方法仅适用于页面功能。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                    | 说明                                   |
| --------------------- | ------------------------------------ |
| Promise\<[ElementName](js-apis-bundle-ElementName.md)> | 当前ability的ohos.bundle.ElementName对象。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getElementName().then((data) => {
    console.info("getElementName data: " + JSON.stringify(data));
});
```

## Context.getProcessName<sup>7+</sup>

getProcessName(callback: AsyncCallback\<string>): void

获取当前进程的名称（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明         |
| -------- | ---------------------- | ---- | ---------- |
| callback | AsyncCallback\<string> | 是    | 返回当前进程的名称。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getProcessName((err, data) => {
    console.info("getProcessName err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```



## Context.getProcessName<sup>7+</sup>

getProcessName(): Promise\<string>

获取当前进程的名称（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明         |
| ---------------- | ---------- |
| Promise\<string> | 返回当前进程的名称。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getProcessName().then((data) => {
    console.info("getProcessName data: " + JSON.stringify(data));
});
```



## Context.getCallingBundle<sup>7+</sup>

getCallingBundle(callback: AsyncCallback\<string>): void

获取调用ability的包名称（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明               |
| -------- | ---------------------- | ---- | ---------------- |
| callback | AsyncCallback\<string> | 是    | 返回调用ability的包名称。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getCallingBundle((err, data) => {
    console.info("getCallingBundle err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```



## Context.getCallingBundle<sup>7+</sup>

getCallingBundle(): Promise\<string>

获取调用ability的包名称（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明             |
| ---------------- | -------------- |
| Promise\<string> | 调用ability的包名称。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getCallingBundle().then((data) => {
    console.info("getCallingBundle data: " + JSON.stringify(data));
});
```

## Context.getCacheDir

getCacheDir(callback: AsyncCallback\<string>): void

获取该应用程序的内部存储目录（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明              |
| -------- | ---------------------- | ---- | --------------- |
| callback | AsyncCallback\<string> | 是    | 返回该应用程序的内部存储目录。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getCacheDir((err, data) => {
    console.info("getCacheDir err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getCacheDir

getCacheDir(): Promise\<string>

获取该应用程序的内部存储目录（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明              |
| ---------------- | --------------- |
| Promise\<string> | 获取该应用程序的内部存储目录。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getCacheDir().then((data) => {
    console.info("getCacheDir data: " + JSON.stringify(data));
});
```

## Context.getFilesDir

getFilesDir(callback: AsyncCallback\<string>): void

获取内部存储器上此应用程序的文件目录（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明                  |
| -------- | ---------------------- | ---- | ------------------- |
| callback | AsyncCallback\<string> | 是    | 返回内部存储器上此应用程序的文件目录。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getFilesDir((err, data) => {
    console.info("getFilesDir err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getFilesDir

getFilesDir(): Promise\<string>

获取内部存储器上此应用程序的文件目录（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明                  |
| ---------------- | ------------------- |
| Promise\<string> | 返回内部存储器上此应用程序的文件目录。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getFilesDir().then((data) => {
    console.info("getFilesDir data: " + JSON.stringify(data));
});
```

## Context.getOrCreateDistributedDir<sup>7+</sup>

getOrCreateDistributedDir(callback: AsyncCallback\<string>): void

获取Ability或应用的分布式文件路径。

如果分布式文件路径不存在，系统将创建一个路径并返回创建的路径（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明                                       |
| -------- | ---------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback\<string> | 是    | 回调函数，可以在回调函数中处理接口返回值，返回Ability或应用的分布式文件路径。如果分布式文件路径不存在，系统将创建一个路径并返回创建的路径。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getOrCreateDistributedDir((err, data) => {
    console.info("getOrCreateDistributedDir err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getOrCreateDistributedDir<sup>7+</sup>

getOrCreateDistributedDir(): Promise\<string>

获取Ability或应用的分布式文件路径。

如果分布式文件路径不存在，系统将创建一个路径并返回创建的路径（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明                                  |
| ---------------- | ----------------------------------- |
| Promise\<string> | Ability或应用的分布式文件路径。如果是第一次调用，则将创建目录。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getOrCreateDistributedDir().then((data) => {
    console.info("getOrCreateDistributedDir data: " + JSON.stringify(data));
});
```

## Context.getAppType<sup>7+</sup>

getAppType(callback: AsyncCallback\<string>): void

获取此应用的类型（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明                               |
| -------- | ---------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<string> | 是    | 回调函数，可以在回调函数中处理接口返回值，返回此应用程序的类型。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getAppType((err, data) => {
    console.info("getAppType err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getAppType<sup>7+</sup>

getAppType(): Promise\<string>

获取此应用的类型（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型               | 说明                 |
| ---------------- | ------------------ |
| Promise\<string> | Promise形式返回此应用的类型。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getAppType().then((data) => {
    console.info("getAppType data: " + JSON.stringify(data));
});
```

## Context.getHapModuleInfo<sup>7+</sup>

getHapModuleInfo(callback: AsyncCallback\<HapModuleInfo>): void

获取应用的ModuleInfo对象（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                                       | 必填   | 说明                                      |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| callback | AsyncCallback\<[HapModuleInfo](js-apis-bundle-HapModuleInfo.md)> | 是    | 回调函数，可以在回调函数中处理接口返回值，返回应用的ModuleInfo对象。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getHapModuleInfo((err, data) => {
    console.info("getHapModuleInfo err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getHapModuleInfo<sup>7+</sup>

getHapModuleInfo(): Promise\<HapModuleInfo>

获取应用的ModuleInfo对象（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                       | 说明                 |
| ---------------------------------------- | ------------------ |
| Promise\<[HapModuleInfo](js-apis-bundle-HapModuleInfo.md)> | 返回应用的ModuleInfo对象。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getHapModuleInfo().then((data) => {
    console.info("getHapModuleInfo data: " + JSON.stringify(data));
});
```

## Context.getAppVersionInfo<sup>7+</sup>

getAppVersionInfo(callback: AsyncCallback\<AppVersionInfo>): void

获取应用的版本信息（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                                       | 必填   | 说明                             |
| -------- | ---------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<[AppVersionInfo](js-apis-inner-app-appVersionInfo.md)> | 是    | 回调函数，可以在回调函数中处理接口返回值，返回应用版本信息。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getAppVersionInfo((err, data) => {
    console.info("getAppVersionInfo err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getAppVersionInfo<sup>7+</sup>

getAppVersionInfo(): Promise\<AppVersionInfo>

获取应用的版本信息（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                       | 说明        |
| ---------------------------------------- | --------- |
| Promise\<[AppVersionInfo](js-apis-inner-app-appVersionInfo.md)> | 返回应用版本信息。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getAppVersionInfo().then((data) => {
    console.info("getAppVersionInfo data: " + JSON.stringify(data));
});
```

## Context.getAbilityInfo<sup>7+</sup>

getAbilityInfo(callback: AsyncCallback\<AbilityInfo>): void

查询当前归属Ability详细信息（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                                       | 必填   | 说明                                      |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| callback | AsyncCallback\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)> | 是    | 回调函数，可以在回调函数中处理接口返回值，返回当前归属Ability详细信息。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getAbilityInfo((err, data) => {
    console.info("getAbilityInfo err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.getAbilityInfo<sup>7+</sup>

getAbilityInfo(): Promise\<AbilityInfo>

查询当前归属Ability详细信息（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                       | 说明                 |
| ---------------------------------------- | ------------------ |
| Promise\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)> | 返回当前归属Ability详细信息。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.getAbilityInfo().then((data) => {
    console.info("getAbilityInfo data: " + JSON.stringify(data));
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

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext().getApplicationContext();
```

## Context.isUpdatingConfigurations<sup>7+</sup>

isUpdatingConfigurations(callback: AsyncCallback\<boolean>): void;

检查此能力的配置是否正在更改（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                      | 必填   | 说明                            |
| -------- | ----------------------- | ---- | ----------------------------- |
| callback | AsyncCallback\<boolean> | 是    | 如果该能力的配置正在更改，则为true，否则为false。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.isUpdatingConfigurations((err, data) => {
    console.info("isUpdatingConfigurations err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## Context.isUpdatingConfigurations<sup>7+</sup>

isUpdatingConfigurations(): Promise\<boolean>;

检查此能力的配置是否正在更改（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                | 说明                            |
| ----------------- | ----------------------------- |
| Promise\<boolean> | 如果该能力的配置正在更改，则为true，否则为false。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.isUpdatingConfigurations().then((data) => {
    console.info("isUpdatingConfigurations data: " + JSON.stringify(data));
});
```

## Context.printDrawnCompleted<sup>7+</sup>

printDrawnCompleted(callback: AsyncCallback\<void>): void;

通知系统绘制此页面功能所需的时间（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                   | 必填   | 说明          |
| -------- | -------------------- | ---- | ----------- |
| callback | AsyncCallback\<void> | 是    | 表示被指定的回调方法。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.printDrawnCompleted((err) => {
    console.error('printDrawnCompleted err: ' + JSON.stringify(err));
});
```

## Context.printDrawnCompleted<sup>7+</sup>

printDrawnCompleted(): Promise\<void>;

通知系统绘制此页面功能所需的时间（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| Promise\<void> | 以Promise形式返回结果。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext();
context.printDrawnCompleted().then((data) => {
    console.info("printDrawnCompleted data: " + JSON.stringify(data));
});
```


## PermissionOptions<sup>7+</sup>

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称   | 读写属性 | 类型     | 必填   | 说明    |
| ---- | ---- | ------ | ---- | ----- |
| pid  | 只读   | number | 否    | 进程id。 |
| uid  | 只读   | number | 否    | 用户id。 |

## PermissionRequestResult<sup>7+</sup>

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称          | 读写属性 | 类型             | 必填   | 说明         |
| ----------- | ---- | -------------- | ---- | ---------- |
| requestCode | 只读   | number         | 是    | 用户传入的请求代码。 |
| permissions | 只读   | Array\<string> | 是    | 用户传入的权限。   |
| authResults | 只读   | Array\<number> | 是    | 请求权限的结果。   |

## AppVersionInfo<sup>7+</sup>

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称          | 类型     | 可读   | 可写   | 说明      |
| ----------- | ------ | ---- | ---- | ------- |
| appName     | string | 是    | 否    | 模块名称。   |
| versionCode | number | 是    | 否    | 模块描述信息。 |
| versionName | string | 是    | 否    | 描述信息ID。 |