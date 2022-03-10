# Context

- [使用说明](#使用说明)
- [属性](#属性)
- [createBundleContext](#createBundleContext)
- [getApplicationContext](#getApplicationContext)


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。


提供开发者运行代码的上下文环境，包括应用信息、ResourceManager等信息。


## 使用说明


通过AbilityContext等集成实现。


## 属性

  | 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| resourceManager | ResourceManager | 是 | 否 | ResourceManager对象。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 
| applicationInfo | ApplicationInfo | 是 | 否 | 当前应用信息。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 
| cacheDir | string | 是 | 否 | 应用在内部存储上的缓存路径。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 
| tempDir | string | 是 | 否 | 应用的临时文件路径。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 
| filesDir | string | 是 | 否 | 应用在内部存储上的文件路径。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 
| databaseDir | string | 是 | 否 | 获取本地数据存储路径。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 
| storageDir | string | 是 | 否 | 获取轻量级数据存储路径。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 
| bundleCodeDir | string | 是 | 否 | 应用安装路径。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 
| distributedFilesDir | string | 是 | 否 | 应用的分布式文件路径。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 
| eventHub | [EventHub](js-apis-eventhub.md) | 是 | 否 | 事件中心信息。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core| 


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
  let test = "com.huawei.test";
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
