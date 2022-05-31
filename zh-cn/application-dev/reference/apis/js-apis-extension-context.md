# ExtensionContext

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import DataShareExtensionAbility from '@ohos.application.DataShareExtensionAbility';
```
## 使用说明

Extension的上下文环境，继承自Context。

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| currentHapModuleInfo | HapModuleInfo | 是 | 否 | 当前Hap包的信息。  | 
| config   | Configuration | 是 | 否 | 模块的配置信息。 |
