# @ohos.app.ability.UIExtensionAbility (Base Class for ExtensionAbilities with UI)

**UIExtensionAbility**, inherited from [ExtensionAbility](js-apis-app-ability-extensionAbility.md), is a base class for ExtensionAbilities with UI in specific scenarios. It provides attributes and APIs related to ExtensionAbilities with UI. You cannot inherit from this base class.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import UIExtensionAbility from '@ohos.app.ability.UIExtensionAbility';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [UIExtensionContext](js-apis-inner-application-uiExtensionContext.md) | Yes| No| Context.|

## UIExtensionAbility.onCreate

onCreate(): void

Called to initialize the service logic when a UIExtensionAbility is being created.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

## UIExtensionAbility.onSessionCreate

onSessionCreate(want: Want, session: UIExtensionContentSession): void

Called when a **UIExtensionContentSession** instance is created for this UIExtensionAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information related to this UIExtensionAbility, including the ability name and bundle name.|
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | Yes| UI content information related to this UIExtensionAbility.|

## UIExtensionAbility.onSessionDestroy

onSessionDestroy(session: UIExtensionContentSession): void

Called when a **UIExtensionContentSession** instance is destroyed for this UIExtensionAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | Yes| UI content information related to this UIExtensionAbility.|

## UIExtensionAbility.onForeground

onForeground(): void;

Called when this UIExtensionAbility is switched from the background to the foreground.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

## UIExtensionAbility.onBackground

onBackground(): void;

Called when this UIExtensionAbility is switched from the foreground to the background.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

## UIExtensionAbility.onDestroy

onDestroy(): void | Promise&lt;void&gt;;

Called to clear resources when this UIExtensionAbility is destroyed.

After the **onDestroy()** lifecycle callback is executed, the application may exit. Consequently, the asynchronous function (for example, asynchronously writing data to the database) in **onDestroy()** may fail to be executed. You can use the asynchronous lifecycle to ensure that the subsequent lifecycle continues only after the asynchronous function in **onDestroy()** finishes the execution.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core
