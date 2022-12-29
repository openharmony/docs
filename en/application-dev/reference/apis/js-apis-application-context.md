# @ohos.application.context

The **Context** module provides all level-2 module APIs for developers to export.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import context from '@ohos.application.context'
```

**System capability**: SystemCapability.Ability.AbilityBase

| Name       | Readable/Writable| Type                | Mandatory| Description                                                        |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| AbilityContext    | Read Only    | [AbilityContext](js-apis-ability-context.md)               | No  | Level-2 module **AbilityContext**.                               |
| AbilityStageContext   | Read Only    | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md)               | No  | Level-2 module **AbilityStageContext**.|
| ApplicationContext   | Read Only    | [ApplicationContext](js-apis-inner-application-applicationContext.md)               | No  | Level-2 module **ApplicationContext**.|
| BaseContext   | Read Only    | [BaseContext](js-apis-inner-application-baseContext.md)               | No  | Level-2 module **BaseContext**.|
| Context   | Read Only    | [Context](js-apis-inner-application-context.md)               | No  | Level-2 module **Context**.|
| ExtensionContext   | Read Only    | [ExtensionContext](js-apis-inner-application-extensionContext.md)               | No  | Level-2 module **ExtensionContext**.|
| FormExtensionContext   | Read Only    | [FormExtensionContext](js-apis-inner-application-formExtensionContext.md)               | No  | Level-2 module **FormExtensionContext**.|
| EventHub   | Read Only    | [EventHub](js-apis-inner-application-eventHub.md)               | No  | Level-2 module **EventHub**.|
| PermissionRequestResult   | Read Only    | [PermissionRequestResult](js-apis-inner-application-permissionRequestResult.md)               | No  | Level-2 module **PermissionRequestResult**.|

**Example**
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
