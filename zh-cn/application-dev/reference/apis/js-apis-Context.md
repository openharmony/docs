# Context模块

## 导入模块

```js
import featureAbility from '@ohos.ability.featureAbility'
import bundle from '@ohos.bundle'
```

Context对象是在featureAbility中创建实例，并通过featureAbility的getContext()接口返回，因此在使用Context时，必须导入@ohos.ability.featureAbility库。示例如下：

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateLocalDir()
```

## Context.getOrCreateLocalDir

getOrCreateLocalDir(callback: AsyncCallback\<string>): void

获取应用程序的本地根目录（callback形式）。

如果是第一次调用，将创建目录。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 类型                   | 必填 | 描述                       |
| -------- | ---------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<string> | 是   | 返回应用程序的本地根目录。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateLocalDir((err, data)=>{
    console.info("data=" + data);
})
```



## Context.getOrCreateLocalDir

getOrCreateLocalDir(): Promise\<string>

获取应用程序的本地根目录（Promise形式）。

如果是第一次调用，将创建目录。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型             | 说明                   |
| ---------------- | ---------------------- |
| Promise\<string> | 应用程序的本地根目录。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateLocalDir().then((data) => {
    console.info("data=" + data);
});
```



## Context.verifyPermission

verifyPermission(permission: string, options: PermissionOptions, callback: AsyncCallback\<number>): void

验证系统中运行的特定pid和uid是否允许指定的权限（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称       | 类型                                    | 必填 | 描述                                  |
| ---------- | --------------------------------------- | ---- | ------------------------------------- |
| permission | string                                  | 是   | 指定权限的名称。                      |
| options    | [PermissionOptions](#permissionoptions) | 是   | 权限选项。                            |
| callback   | AsyncCallback\<number>                  | 是   | 返回权限验证结果，0有权限，-1无权限。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
import bundle from '@ohos.bundle'
var context = featureAbility.getContext();
bundle.getBundleInfo('com.context.test', 1, (datainfo) =>{
	context.verifyPermission("com.example.permission", datainfo.uid);
});
```



## Context.verifyPermission

verifyPermission(permission: string, callback: AsyncCallback\<number>): void

验证系统中运行的当前pid和uid是否具有指定的权限（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称       | 类型                   | 必填 | 描述                                  |
| ---------- | ---------------------- | ---- | ------------------------------------- |
| permission | string                 | 是   | 指定权限的名称。                      |
| callback   | AsyncCallback\<number> | 是   | 返回权限验证结果，0有权限，-1无权限。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.verifyPermission("com.example.permission")
```

## Context.verifyPermission

verifyPermission(permission: string, options?: PermissionOptions): Promise\<number>

验证系统中运行的特定pid和uid是否具有指定的权限（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称       | 类型                                    | 必填 | 描述             |
| ---------- | --------------------------------------- | ---- | ---------------- |
| permission | string                                  | 是   | 指定权限的名称。 |
| options    | [PermissionOptions](#permissionoptions) | 否   | 权限选项。       |

**返回值：**

| 类型             | 说明                                                        |
| ---------------- | ----------------------------------------------------------- |
| Promise\<number> | 如果pid和uid具有权限，则使用0进行异步回调；否则使用-1回调。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
var Permission = context.PermissionOptions(1,1);
context.verifyPermission('com.context.permission',Permission).then((data) => {
    console.info("======================>verifyPermissionCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```



## Context.requestPermissionsFromUser

requestPermissionsFromUser(permissions: Array\<string>, requestCode: number, resultCallback: AsyncCallback<[PermissionRequestResult](#permissionrequestresult)>): void

从系统请求某些权限（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称           | 类型                                                         | 必填 | 描述                                            |
| -------------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| permissions    | Array\<string>                                               | 是   | 指示要请求的权限列表。此参数不能为null。        |
| requestCode    | number                                                       | 是   | 指示要传递给PermissionRequestResult的请求代码。 |
| resultCallback | AsyncCallback<[PermissionRequestResult](#permissionrequestresult)> | 是   | 返回授权结果信息。                              |

**示例：**

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



## Context.getApplicationInfo

getApplicationInfo(callback: AsyncCallback\<ApplicationInfo>): void

获取有关当前应用程序的信息（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 类型                            | 必填 | 描述                     |
| -------- | ------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<ApplicationInfo> | 是   | 返回当前应用程序的信息。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getApplicationInfo()
```



## Context.getApplicationInfo

getApplicationInfo(): Promise\<ApplicationInfo>

获取有关当前应用程序的信息（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                      | 说明               |
| ------------------------- | ------------------ |
| Promise\<ApplicationInfo> | 当前应用程序的信息 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getApplicationInfo().then((data) => {
    console.info("=====================>getApplicationInfoCallback===================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```



## Context.getBundleName

getBundleName(callback: AsyncCallback\<string>): void

获取当前ability的捆绑包名称（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 类型                   | 必填 | 描述                          |
| -------- | ---------------------- | ---- | ----------------------------- |
| callback | AsyncCallback\<string> | 是   | 返回当前ability的捆绑包名称。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getBundleName()
```



## Context.getBundleName

getBundleName(): Promise\<string>

获取当前ability的捆绑包名称（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型             | 说明                      |
| ---------------- | ------------------------- |
| Promise\<string> | 当前ability的捆绑包名称。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getBundleName().then((data) => {
    console.info("=======================>getBundleNameCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```



## Context.getProcessInfo

getProcessInfo(callback: AsyncCallback\<ProcessInfo>): void

获取有关当前进程的信息，包括进程ID和名称（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 类型                        | 必填 | 描述                 |
| -------- | --------------------------- | ---- | -------------------- |
| callback | AsyncCallback\<ProcessInfo> | 是   | 返回当前进程的信息。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessInfo()
```



## Context.getProcessInfo

getProcessInfo(): Promise\<ProcessInfo>

获取有关当前进程的信息，包括进程id和名称（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| Promise\<ProcessInfo> | 当前进程的信息 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessInfo().then((data) => {
    console.info("=======================>getProcessInfoCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```



## Context.getElementName

getElementName(callback: AsyncCallback\<ElementName>): void

获取当前ability的ohos.bundle.ElementName对象（callback形式）。

此方法仅适用于页面功能。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 类型                        | 必填 | 描述                                           |
| -------- | --------------------------- | ---- | ---------------------------------------------- |
| callback | AsyncCallback\<ElementName> | 是   | 返回当前ability的ohos.bundle.ElementName对象。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getElementName()
```



## Context.getElementName

getElementName(): Promise\<ElementName>

获取当前能力的ohos.bundle.ElementName对象（Promise形式）。

此方法仅适用于页面功能。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                  | 说明                                       |
| --------------------- | ------------------------------------------ |
| Promise\<ElementName> | 当前ability的ohos.bundle.ElementName对象。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getElementName().then((data) => {
    console.info("=======================>getElementNameCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```

## Context.getProcessName

getProcessName(callback: AsyncCallback\<string>): void

获取当前进程的名称（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 类型                   | 必填 | 描述                 |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | 是   | 返回当前进程的名称。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessName()
```



## Context.getProcessName

getProcessName(): Promise\<string>

获取当前进程的名称（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<string> | 返回当前进程的名称。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessName().then((data) => {
    console.info("=======================>getProcessNameCallback====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```



## Context.getCallingBundle

getCallingBundle(callback: AsyncCallback\<string>): void

获取调用ability的包名称（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 类型                   | 必填 | 描述                      |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<string> | 是   | 返回调用ability的包名称。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getCallingBundle()
```



## Context.getCallingBundle

getCallingBundle(): Promise\<string>

获取调用ability的包名称（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| Promise\<string> | 调用ability的包名称 |

**示例：**

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

获取该应用程序的内部存储目录（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 类型                   | 必填 | 描述                      |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<string> | 是   | 返回该应用程序的内部存储目录。|

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getCacheDir();
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

获取该应用程序的内部存储目录（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| Promise\<string> | 获取该应用程序的内部存储目录 |

**示例：**

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

获取内部存储器上此应用程序的文件目录（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 类型                   | 必填 | 描述                      |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<string> | 是   | 返回内部存储器上此应用程序的文件目录。|

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getFilesDir();
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

获取内部存储器上此应用程序的文件目录（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| Promise\<string> | 返回内部存储器上此应用程序的文件目录。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getFilesDir().then((data) => {
    console.info("======================>getFilesDirPromsie====================>");
    console.info("====>data====>" + JSON.stringify(data));
});
```

## Context.getOrCreateDistributedDir

getOrCreateDistributedDir(callback: AsyncCallback\<string>): void

获取Ability或应用的分布式文件路径。

如果分布式文件路径不存在，系统将创建一个路径并返回创建的路径（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 类型                   | 必填 | 描述                      |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<string> | 是   | 回调函数，可以在回调函数中处理接口返回值，返回Ability或应用的分布式文件路径。如果分布式文件路径不存在，系统将创建一个路径并返回创建的路径。|

**示例：**

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

## Context.getOrCreateDistributedDir

getOrCreateDistributedDir(): Promise\<string>

获取Ability或应用的分布式文件路径。

如果分布式文件路径不存在，系统将创建一个路径并返回创建的路径（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| Promise\<string> | Ability或应用的分布式文件路径。如果是第一次调用，则将创建目录。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateDistributedDir().then((data) => {
    console.info("====>data====>" + JSON.stringify(data));
});
```

## Context.getAppType

getAppType(callback: AsyncCallback\<string>): void

获取此应用的类型（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 类型                   | 必填 | 描述                      |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<string> | 是   | 回调函数，可以在回调函数中处理接口返回值，返回此应用程序的类型。|

**示例：**

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

## Context.getAppType

getAppType(): Promise\<string>

获取此应用的类型（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| Promise\<string> | Promise形式返回此应用的类型。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getAppType().then((data) => {
    console.info("====>data====>" + JSON.stringify(data));
});
```

## Context.getHapModuleInfo

getHapModuleInfo(callback: AsyncCallback\<HapModuleInfo>): void

获取应用的ModuleInfo对象（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 类型                   | 必填 | 描述                      |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<[HapModuleInfo](#hapmoduleinfo)> | 是   | 回调函数，可以在回调函数中处理接口返回值，返回应用的ModuleInfo对象。|

**示例：**

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

## Context.getHapModuleInfo

getHapModuleInfo(): Promise\<HapModuleInfo>

获取应用的ModuleInfo对象（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| Promise\<[HapModuleInfo](#hapmoduleinfo)> | Promise形式返回应用的ModuleInfo对象。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getHapModuleInfo().then((data) => {
    console.info("====>data====>" + JSON.stringify(data));
});
```

## Context.getAppVersionInfo

getAppVersionInfo(callback: AsyncCallback\<HapModuleInfo>): void

获取应用的版本信息（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 类型                   | 必填 | 描述                      |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<[AppVersionInfo](#appversioninfo)> | 是   | 回调函数，可以在回调函数中处理接口返回值，返回应用版本信息。|

**示例：**

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

## Context.getAppVersionInfo

getAppVersionInfo(): Promise\<AppVersionInfo>

获取应用的版本信息（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| Promise\<[AppVersionInfo](#appversioninfo)> | 返回应用版本信息。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getAppVersionInfo().then((data) => {
    console.info("====>data====>" + JSON.stringify(data));
});
```

## Context.getAbilityInfo

getAbilityInfo(callback: AsyncCallback\<AbilityInfo>): void

查询当前归属Ability详细信息（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 类型                   | 必填 | 描述                      |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback\<[AbilityInfo](#abilityInfo)> | 是   |回调函数，可以在回调函数中处理接口返回值，返回当前归属Ability详细信息。|

**示例：**

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

## Context.getAbilityInfo

getAbilityInfo(): Promise\<AbilityInfo>

查询当前归属Ability详细信息（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| Promise\<[AbilityInfo](#abilityInfo)> | 返回当前归属Ability详细信息。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getAbilityInfo().then((data) => {
    console.info("====>data====>" + JSON.stringify(data));
});
```

## Context.getApplicationContext

getApplicationContext(): Context

获取应用上下文信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型      | 说明   |
| --------- |------ |
|  Context |返回应用上下文信息。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext().getApplicationContext();
```

## PermissionOptions

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 读写属性 | 类型   | 必填 | 描述   |
| ---- | -------- | ------ | ---- | ------ |
| pid  | 只读     | number | 否   | 进程id。 |
| uid  | 只读     | number | 否   | 用户id。 |

## PermissionRequestResult

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称        | 读写属性 | 类型           | 必填 | 描述               |
| ----------- | -------- | -------------- | ---- | ------------------ |
| requestCode | 只读     | number         | 是   | 用户传入的请求代码。 |
| permissions | 只读     | Array\<string> | 是   | 用户传入的权限。     |
| authResults | 只读     | Array\<number> | 是   | 请求权限的结果。    |

## HapModuleInfo

Hap模块信息

| 名称               | 类型 | 可读 | 可写 | 说明 |
| ------ | ------ | ------ | ------ | ------ |
| name             | string        | 是   | 否   | 模块名称           |
| description      | string        | 是   | 否   | 模块描述信息       |
| descriptionId    | number        | 是   | 否   | 描述信息ID         |
| icon             | string        | 是   | 否   | 模块图标           |
| label            | string        | 是   | 否   | 模块标签           |
| labelId          | number        | 是   | 否   | 模块标签ID         |
| iconId           | number        | 是   | 否   | 模块图标ID         |
| backgroundImg    | string        | 是   | 否   | 模块背景图片       |
| supportedModes   | number        | 是   | 否   | 模块支持的模式     |
| reqCapabilities  | Array\<string> | 是   | 否   | 模块运行需要的能力 |
| deviceTypes      | Array\<string> | 是   | 否   | 支持运行的设备类型 |
| abilityInfo      | Array\<AbilityInfo> | 是   | 否   | Ability信息        |
| moduleName       | string        | 是   | 否   | 模块名             |
| mainAbilityName  | string        | 是   | 否   | 入口Ability名称    |
| installationFree | boolean       | 是   | 否   | 是否支持免安装     |
| mainElementName | string | 是 | 否 | 入口ability信息 |

## AppVersionInfo

| 名称             | 类型 | 可读    | 可写   | 说明 |
| ------          | ------ | ------| ------ | ------    |
| appName         | string | 是    | 否     | 模块名称      |
| versionCode     | number | 是    | 否     | 模块描述信息   |
| versionName     | string | 是    | 否     | 描述信息ID     |
