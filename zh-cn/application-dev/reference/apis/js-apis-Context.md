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

## Context

### getOrCreateLocalDir

getOrCreateLocalDir(callback: AsyncCallback\<string>): void

获取应用程序的本地根目录（callback形式）。

如果是第一次调用，将创建目录。

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



### getOrCreateLocalDir

getOrCreateLocalDir(): Promise\<string>

获取应用程序的本地根目录（Promise形式）。

如果是第一次调用，将创建目录。

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



### verifyPermission

verifyPermission(permission: string, options: PermissionOptions, callback: AsyncCallback\<number>): void

验证系统中运行的特定pid和uid是否允许指定的权限（callback形式）。

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



### verifyPermission

verifyPermission(permission: string, callback: AsyncCallback\<number>): void

验证系统中运行的当前pid和uid是否具有指定的权限（callback形式）。

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

### verifyPermission

verifyPermission(permission: string, options?: PermissionOptions): Promise\<number>

验证系统中运行的特定pid和uid是否具有指定的权限（Promise形式）。

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



### requestPermissionsFromUser

requestPermissionsFromUser(permissions: Array\<string>, requestCode: number, resultCallback: AsyncCallback<[PermissionRequestResult](#permissionrequestresult)>)

从系统请求某些权限（callback形式）。

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



### getApplicationInfo

getApplicationInfo(callback: AsyncCallback\<ApplicationInfo>)

获取有关当前应用程序的信息（callback形式）。

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



### getApplicationInfo

getApplicationInfo(): Promise\<ApplicationInfo>

获取有关当前应用程序的信息（Promise形式）。

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



### getBundleName

getBundleName(callback: AsyncCallback\<string>): void

获取当前ability的捆绑包名称（callback形式）。

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



### getBundleName

getBundleName(): Promise\<string>

获取当前ability的捆绑包名称（Promise形式）。

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



### getProcessInfo

getProcessInfo(callback: AsyncCallback\<ProcessInfo>)

获取有关当前进程的信息，包括进程ID和名称（callback形式）。

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



### getProcessInfo

getProcessInfo(): Promise\<ProcessInfo>

获取有关当前进程的信息，包括进程id和名称（Promise形式）。

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



### getElementName

getElementName(callback: AsyncCallback\<ElementName>): void

获取当前ability的ohos.bundle.ElementName对象（callback形式）。

此方法仅适用于页面功能。

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



### getElementName

getElementName(): Promise\<ElementName>

获取当前能力的ohos.bundle.ElementName对象（Promise形式）。

此方法仅适用于页面功能。

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

### getProcessName

getProcessName(callback: AsyncCallback\<string>): void

获取当前进程的名称（callback形式）。

| 名称     | 类型                   | 必填 | 描述                 |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | 是   | 返回当前进程的名称。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessName()
```



### getProcessName

getProcessName(): Promise\<string>

获取当前进程的名称（Promise形式）。

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



### getCallingBundle

getCallingBundle(callback: AsyncCallback\<string>): void

获取调用ability的包名称（callback形式）。

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



### getCallingBundle

getCallingBundle(): Promise\<string>

获取调用ability的包名称（Promise形式）。

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

## PermissionOptions

| 名称 | 读写属性 | 类型   | 必填 | 描述   |
| ---- | -------- | ------ | ---- | ------ |
| pid  | 只读     | number | 否   | 进程id |
| uid  | 只读     | number | 否   | 用户id |

## PermissionRequestResult

| 名称        | 读写属性 | 类型           | 必填 | 描述               |
| ----------- | -------- | -------------- | ---- | ------------------ |
| requestCode | 只读     | number         | 是   | 用户传入的请求代码 |
| permissions | 只读     | Array\<string> | 是   | 用户传入的权限     |
| authResults | 只读     | Array\<number> | 是   | 求权限的结果       |
