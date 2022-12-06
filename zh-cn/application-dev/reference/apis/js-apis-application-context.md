# Context

Context模块将二级模块API组织在一起方便开发者进行导出。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用

## 导入模块

```ts
import context from '@ohos.application.context'
```

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称        | 读写属性 | 类型                 | 必填 | 描述                                                         |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| AbilityContext    | 只读     | [AbilityContext](js-apis-ability-context.md)               | 否   | AbilityContext二级模块。                                |
| AbilityStageContext   | 只读     | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md)               | 否   | AbilityStageContext二级模块。 |
| ApplicationContext   | 只读     | [ApplicationContext](js-apis-inner-application-applicationContext.md)               | 否   | ApplicationContext二级模块。 |
| BaseContext   | 只读     | [BaseContext](js-apis-inner-application-baseContext.md)               | 否   | BaseContext二级模块。 |
| Context   | 只读     | [Context](js-apis-inner-application-context.md)               | 否   | Context二级模块。 |
| ExtensionContext   | 只读     | [ExtensionContext](js-apis-inner-application-extensionContext.md)               | 否   | ExtensionContext二级模块。 |
| FormExtensionContext   | 只读     | [FormExtensionContext](js-apis-inner-application-formExtensionContext.md)               | 否   | FormExtensionContext二级模块。 |
| EventHub   | 只读     | [EventHub](js-apis-inner-application-eventHub.md)               | 否   | EventHub二级模块。 |
| PermissionRequestResult   | 只读     | [PermissionRequestResult](js-apis-inner-application-permissionRequestResult.md)               | 否   | PermissionRequestResult二级模块。 |

**示例：**
```ts
let abilityContext: context.AbilityContext;
let abilityStageContext: context.AbilityStageContext;
let applicationContext: context.ApplicationContext;
let baseContext: context.BaseContext;
let context: context.Context;
let extensionContext: context.ExtensionContext;  
let formExtensionContext: context.FormExtensionContext;
let eventHub: context.EventHub;
let permissionRequestResult: context.PermissionRequestResult;
```