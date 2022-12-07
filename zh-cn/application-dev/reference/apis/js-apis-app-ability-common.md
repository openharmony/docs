# Common

Common模块将二级模块API组织在一起方便开发者进行导出。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用

## 导入模块

```ts
import common from '@ohos.app.ability.common'
```

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称        | 类型                 | 必填 | 说明                                                         |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| UIAbilityContext    | [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md)               | 否   | UIAbilityContext二级模块。                                |
| AbilityStageContext   | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md)               | 否   | AbilityStageContext二级模块。 |
| ApplicationContext   | [ApplicationContext](js-apis-inner-application-applicationContext.md)               | 否   | ApplicationContext二级模块。 |
| BaseContext   | [BaseContext](js-apis-inner-application-baseContext.md)               | 否   | BaseContext二级模块。 |
| Context   | [Context](js-apis-inner-application-context.md)               | 否   | Context二级模块。 |
| ExtensionContext   | [ExtensionContext](js-apis-inner-application-extensionContext.md)               | 否   | ExtensionContext二级模块。 |
| FormExtensionContext   | [FormExtensionContext](js-apis-inner-application-formExtensionContext.md)               | 否   | FormExtensionContext二级模块。 |
| AreaMode   | [AreaMode](#areamode)               | 否   | AreaMode枚举值。 |
| EventHub   | [EventHub](js-apis-inner-application-eventHub.md)               | 否   | EventHub二级模块。 |
| PermissionRequestResult   | [PermissionRequestResult](js-apis-inner-application-permissionRequestResult.md)               | 否   | PermissionRequestResult二级模块。 |
| PacMap   | [PacMap](js-apis-inner-ability-dataAbilityHelper.md#PacMap)               | 否   | PacMap二级模块。 |
| AbilityResult   | [AbilityResult](js-apis-inner-ability-abilityResult.md)               | 否   | AbilityResult二级模块。 |
| ConnectOptions   | [ConnectOptions](js-apis-inner-ability-connectOptions.md)               | 否   | ConnectOptions二级模块。 |

**示例：**
```ts
import common from '@ohos.app.ability.common'

let uiAbilityContext: common.UIAbilityContext;
let abilityStageContext: common.AbilityStageContext;
let applicationContext: common.ApplicationContext;
let baseContext: common.BaseContext;
let context: common.Context;
let extensionContext: common.ExtensionContext;
let formExtensionContext: common.FormExtensionContext;
let areaMode: common.AreaMode;
let eventHub: common.EventHub;
let permissionRequestResult: common.PermissionRequestResult;
let pacMap: common.PacMap;
let abilityResult: common.AbilityResult;
let connectOptions: common.ConnectOptions;
```

## AreaMode

访问的文件分区，每个文件分区有对应自己的内容。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称            | 值    | 说明            |
| --------------- | ---- | --------------- |
| EL1             | 0    | 设备级加密区。   |
| EL2             | 1    | 用户凭据加密区。默认为EL2。 |