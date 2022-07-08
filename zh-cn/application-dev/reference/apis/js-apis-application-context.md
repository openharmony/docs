# Context

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


提供开发者运行代码的上下文环境，包括应用信息、ResourceManager等信息。



## 使用说明


通过AbilityContext等继承实现。


## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| resourceManager | ResourceManager | 是 | 否 | ResourceManager对象。 |
| applicationInfo | ApplicationInfo | 是 | 否 | 当前应用信息。 |
| cacheDir | string | 是 | 否 | 应用在内部存储上的缓存路径。 |
| tempDir | string | 是 | 否 | 应用的临时文件路径。 |
| filesDir | string | 是 | 否 | 应用在内部存储上的文件路径。 |
| databaseDir | string | 是 | 否 | 获取本地数据存储路径。 |
| storageDir | string | 是 | 否 | 获取轻量级数据存储路径。 |
| bundleCodeDir | string | 是 | 否 | 应用安装路径。 |
| distributedFilesDir | string | 是 | 否 | 应用的分布式文件路径。 |
| eventHub | [EventHub](js-apis-eventhub.md) | 是 | 否 | 事件中心信息。|


## Context.createBundleContext

createBundleContext(bundleName: string): Context;

创建指定应用上下文。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 应用bundle名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Context | 对应创建应用的上下文context。 |

**示例：**
    
  ```js
  let test = "com.example.test";
  let context = this.context.createBundleContext(test);
  ```


## Context.getApplicationContext

getApplicationContext(): Context;

获取当前context。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Context | 当前Context&nbsp;信息。 |

**示例：**
    

  ```js
  // 必选项。
  let context = this.context.getApplicationContext();
  ```



>  **说明：**
> 当SDK :API 9版本为Canary版本时；

## Context.switchArea

switchArea(mode: AreaMode): void

开启文件范围

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型                  | 必填 | 说明           |
| ------ | --------------------- | ---- | -------------- |
| mode   | [AreaMode](#AreaMode) | 是   | 应用bundle名。 |

**示例**：

```js
var areaMode = 0
this.context.switchArea(areaMode);
```

## AreaMode

文件范围模式

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 参数类型 | 值   |
| ---- | -------- | ---- |
| EL1  | number   | 0    |
| EL2  | number   | 1    |