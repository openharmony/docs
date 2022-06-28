# ExtensionContext

ExtensionContext是Extension的上下文环境，继承自Context。

ExtensionContext模块提供扩展的上下文的能力，包括允许访问特定于扩展的资源。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```js
import DataShareExtensionAbility from '@ohos.application.DataShareExtensionAbility';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| currentHapModuleInfo | HapModuleInfo | 是 | 否 | 当前Hap包的信息。  | 
| config   | Configuration | 是 | 否 | 模块的配置信息。 |
