# Context模块

## 支持设备

| API                                                          | 手机 | 平板 | 智慧屏 | 智能穿戴 | 轻量级智能穿戴 | 智慧视觉设备 |
| ------------------------------------------------------------ | ---- | ---- | ------ | -------- | -------------- | ------------ |
| Context.getOrCreateLocalDir(callback: AsyncCallback\<string>) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.getOrCreateLocalDir()                                | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.verifyPermission(permission: string, options: PermissionOptions, callback: AsyncCallback\<number>) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.verifyPermission(permission: string, callback: AsyncCallback\<number>) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.verifyPermission(permission: string, options?: PermissionOptions) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.requestPermissionsFromUser(permissions: Array\<string>, requestCode: number, resultCallback: AsyncCallback\<PermissionRequestResult>) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.getApplicationInfo(callback: AsyncCallback\<ApplicationInfo>) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.getApplicationInfo()                                 | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.getBundleName(callback: AsyncCallback\<string>)      | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.getBundleName()                                      | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.getProcessInfo(callback: AsyncCallback\<ProcessInfo>) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.getProcessInfo()                                     | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.getElementName(callback: AsyncCallback\<ElementName>) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.getElementName()                                     | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.getProcessName(callback: AsyncCallback\<string>)     | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.getProcessName()                                     | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.getCallingBundle(callback: AsyncCallback\<string>)   | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| Context.getCallingBundle()                                   | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |

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

## Context.getOrCreateLocalDir(callback: AsyncCallback<string>)

- 接口说明

  获取应用程序的本地根目录。如果是第一次调用，将创建目录(callback形式)

- getOrCreateLocalDir参数描述


| 名称     | 读写属性 | 类型                   | 必填 | 描述                     |
| -------- | -------- | ---------------------- | ---- | ------------------------ |
| callback | 只读     | AsyncCallback\<string> | 是   | 返回应用程序的本地根目录 |

- 返回值

  void

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateLocalDir((err, data)=>{
    console.info("data=" + data);
})
```



## Context.getOrCreateLocalDir()

- 接口说明

  获取应用程序的本地根目录。如果是第一次调用，将创建目录(Promise形式)

- 返回值

  | 类型            | 说明                 |
  | --------------- | -------------------- |
  | Promise<string> | 应用程序的本地根目录 |

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getOrCreateLocalDir().then((void) => {
	console.info("==========================>getOrCreateLocalDirCallback=======================>");
});
```

## PermissionOptions类型说明

| 名称 | 读写属性 | 类型   | 必填 | 描述   |
| ---- | -------- | ------ | ---- | ------ |
| pid  | 只读     | number | 否   | 进程id |
| uid  | 只读     | number | 否   | 用户id |

## Context.verifyPermission(permission: string, options: PermissionOptions, callback: AsyncCallback<number>)

- 接口说明

  验证系统中运行的特定pid和uid是否允许指定的权限(callback形式)

- 参数描述


| 名称       | 读写属性 | 类型                                            | 必填 | 描述                                |
| ---------- | -------- | ----------------------------------------------- | ---- | ----------------------------------- |
| permission | 只读     | string                                          | 是   | 指定权限的名称                      |
| options    | 只读     | [PermissionOptions](#PermissionOptions类型说明) | 是   | 权限选项                              |
| callback   | 只读     | AsyncCallback\<number>                          | 是   | 返回权限验证结果，0有权限，-1无权限 |

- 返回值

  void

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
import bundle from '@ohos.bundle'
var context = featureAbility.getContext();
var datainfo = await bundle.getBundleInfo('com.context.test',1);
context.verifyPermission("com.example.permission",datainfo.uid)

```



## Context.verifyPermission(permission: string, callback: AsyncCallback<number>)

- 接口说明

  验证系统中运行的当前pid和uid是否具有指定的权限(callback形式)

- 参数描述


| 名称       | 读写属性 | 类型                   | 必填 | 描述                                |
| ---------- | -------- | ---------------------- | ---- | ----------------------------------- |
| permission | 只读     | string                 | 是   | 指定权限的名称                      |
| callback   | 只读     | AsyncCallback\<number> | 是   | 返回权限验证结果，0有权限，-1无权限 |

- 返回值

  void

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.verifyPermission("com.example.permission")
```



## Context.verifyPermission(permission: string, options?: PermissionOptions)

- 接口说明

  验证系统中运行的特定pid和uid是否具有指定的权限(Promise形式)
- 参数描述


| 名称       | 读写属性 | 类型                                            | 必填 | 描述           |
| ---------- | -------- | ----------------------------------------------- | ---- | -------------- |
| permission | 只读     | string                                          | 是   | 指定权限的名称 |
| options    | 只读     | [PermissionOptions](#PermissionOptions类型说明) | 否   | 权限选项         |

- 返回值

  | 类型            | 说明                                                         |
  | --------------- | ------------------------------------------------------------ |
  | Promise<number> | 如果pid和uid具有权限，则使用**0**进行异步回调；否则使用**-1**回调。 |

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
var Permission = context.PermissionOptions(1,1);
context.getOrCreateLocalDir('com.context.permission',Permission).then((void) => {
	console.info("==========================>verifyPermissionCallback=======================>");
});
```

## PermissionRequestResult类型说明

| 名称        | 读写属性 | 类型           | 必填 | 描述               |
| ----------- | -------- | -------------- | ---- | ------------------ |
| requestCode | 只读     | number         | 是   | 用户传入的请求代码 |
| permissions | 只读     | Array\<string> | 是   | 用户传入的权限     |
| authResults | 只读     | Array\<number> | 是   | 求权限的结果       |



## Context.requestPermissionsFromUser(permissions: Array<string>, requestCode: number, resultCallback: AsyncCallback<[PermissionRequestResult](#PermissionRequestResult类型说明)>)

- 接口说明

  从系统请求某些权限(callback形式)

- requestPermissionsFromUser参数描述


| 名称           | 读写属性 | 类型                                                         | 必填 | 描述                                          |
| -------------- | -------- | ------------------------------------------------------------ | ---- | --------------------------------------------- |
| permissions    | 只读     | Array\<string>                                               | 是   | 指示要请求的权限列表。此参数不能为null        |
| requestCode    | 只读     | number                                                       | 是   | 指示要传递给PermissionRequestResult的请求代码 |
| resultCallback | 只读     | AsyncCallback\<[PermissionRequestResult](#PermissionRequestResult类型说明)> | 是   | 返回授权结果信息                              |
- 返回值

  void

- 示例

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

- 接口说明

  获取有关当前应用程序的信息（callback形式）

- 参数描述

  | 名称     | 读写属性 | 类型                            | 必填 | 描述                   |
  | -------- | -------- | ------------------------------- | ---- | ---------------------- |
  | callback | 只读     | AsyncCallback\<ApplicationInfo> | 是   | 返回当前应用程序的信息 |

- 返回值

  void

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getApplicationInfo()
```



## Context.getApplicationInfo

- 接口说明

  获取有关当前应用程序的信息（Promise形式)

- 参数描述

  无

- 返回值

  | 类型                     | 说明               |
  | ------------------------ | ------------------ |
  | Promise<ApplicationInfo> | 当前应用程序的信息 |

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getApplicationInfo().then((void) => {
	console.info("==========================>getApplicationInfoCallback=======================>");
});
```



##  Context.getBundleName(callback: AsyncCallback<string>)

- 接口说明

  获取当前ability的捆绑包名称（callback形式）

- 参数描述

  | 名称     | 读写属性 | 类型                   | 必填 | 描述                        |
  | -------- | -------- | ---------------------- | ---- | --------------------------- |
  | callback | 只读     | AsyncCallback\<string> | 是   | 返回当前ability的捆绑包名称 |

- 返回值

  void

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getBundleName()
```



## Context.getBundleName

- 接口说明

  获取当前ability的捆绑包名称（Promise形式)

- 参数描述

  无

- 返回值

  | 类型            | 说明                    |
  | --------------- | ----------------------- |
  | Promise<string> | 当前ability的捆绑包名称 |

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getBundleName().then((void) => {
	console.info("==========================>getBundleNameCallback=======================>");
});
```



##  Context.getProcessInfo(callback: AsyncCallback<ProcessInfo>)

- 接口说明

  获取有关当前进程的信息，包括进程ID和名称（callback形式）

- 参数描述

  | 名称     | 读写属性 | 类型                        | 必填 | 描述               |
  | -------- | -------- | --------------------------- | ---- | ------------------ |
  | callback | 只读     | AsyncCallback\<ProcessInfo> | 是   | 返回当前进程的信息 |

- 返回值

  void

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessInfo()
```



## Context.getProcessInfo

- 接口说明

  获取有关当前进程的信息，包括进程id和名称（Promise形式)

- 参数描述

  无

- 返回值

  | 类型                 | 说明           |
  | -------------------- | -------------- |
  | Promise<ProcessInfo> | 当前进程的信息 |

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessInfo().then((void) => {
	console.info("==========================>getProcessInfoCallback=======================>");
});
```



##  Context.getElementName(callback: AsyncCallback<ElementName>)

- 接口说明

  获取当前ability的ohos.bundle.ElementName对象。此方法仅适用于页面功能(callback形式）

- 参数描述

  | 名称     | 读写属性 | 类型                        | 必填 | 描述                                         |
  | -------- | -------- | --------------------------- | ---- | -------------------------------------------- |
  | callback | 只读     | AsyncCallback\<ElementName> | 是   | 返回当前ability的ohos.bundle.ElementName对象 |

- 返回值

  void

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getElementName()
```



## Context.getElementName

- 接口说明

  获取当前能力的ohos.bundle.ElementName对象。此方法仅适用于页面功能(Promise形式)

- 参数描述

  无

- 返回值

  | 类型                 | 说明                                     |
  | -------------------- | ---------------------------------------- |
  | Promise<ElementName> | 当前ability的ohos.bundle.ElementName对象 |

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getElementName().then((void) => {
	console.info("==========================>getElementNameCallback=======================>");
});
```

##   **Context.getProcessName(callback: AsyncCallback<string>)**

- 接口说明

  获取当前进程的名称(callback形式）

- 参数描述

  | 名称     | 读写属性 | 类型                   | 必填 | 描述               |
  | -------- | -------- | ---------------------- | ---- | ------------------ |
  | callback | 只读     | AsyncCallback\<string> | 是   | 返回当前进程的名称 |

- 返回值

  void

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessName()
```



## Context.getProcessName

- 接口说明

  获取当前进程的名称(Promise形式)

- 参数描述

  无

- 返回值

  | 类型            | 说明           |
  | --------------- | -------------- |
  | Promise<string> | 当前进程的名称 |

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getProcessName().then((void) => {
	console.info("==========================>getProcessNameCallback=======================>");
});
```



## Context.getCallingBundle(callback: AsyncCallback<string>)

- 接口说明

  获取调用ability的包名称(callback形式）

- 参数描述

  | 名称     | 读写属性 | 类型                   | 必填 | 描述                      |
  | -------- | -------- | ---------------------- | ---- | ------------------------- |
  | callback | 只读     | AsyncCallback\<string> | 是   | 返回调用ability的包名称 |

- 返回值

  void

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getCallingBundle()
```



## Context.getCallingBundle

- 接口说明

  获取调用ability的包名称(Promise形式)

- 参数描述

  无

- 返回值

  | 类型            | 说明                      |
  | --------------- | ------------------------- |
  | Promise<string> | 调用ability的包名称 |

  

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
var context = featureAbility.getContext();
context.getCallingBundle().then((void) => {
	console.info("==========================>getCallingBundleCallback=======================>");
});
```

