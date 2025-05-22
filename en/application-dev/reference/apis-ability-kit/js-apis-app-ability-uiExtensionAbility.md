# @ohos.app.ability.UIExtensionAbility (Base Class for ExtensionAbilities with UI)

**UIExtensionAbility**, inherited from [ExtensionAbility](js-apis-app-ability-extensionAbility.md), is a base class for ExtensionAbilities with UI in specific scenarios. It provides properties and APIs related to ExtensionAbilities with UI. You cannot inherit from this base class. For details about the inheritance relationship of each ability, see [Inheritance Relationship](./js-apis-app-ability-ability.md#ability-inheritance-relationship).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { UIExtensionAbility } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [UIExtensionContext](js-apis-inner-application-uiExtensionContext.md) | No| No| Context of the UIExtensionAbility.|

## UIExtensionAbility.onCreate

onCreate(launchParam: AbilityConstant.LaunchParam): void

Called to initialize the service logic when a UIExtensionAbility is being created.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| launchParam<sup>12+</sup> | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#launchparam) | Yes| Parameters for starting the UIExtensionAbility, and the reason for the last abnormal exit.|

**Example**

```ts
import { UIExtensionAbility, AbilityConstant } from '@kit.AbilityKit';

const TAG: string = '[testTag] UIExtAbility';

export default class UIExtAbility extends UIExtensionAbility {
  onCreate(launchParam: AbilityConstant.LaunchParam) {
    console.info(TAG, `onCreate`);
    console.log(`onCreate, launchParam: ${JSON.stringify(launchParam)}`);
  }
}
```

## UIExtensionAbility.onSessionCreate

onSessionCreate(want: Want, session: UIExtensionContentSession): void

Called when a **UIExtensionContentSession** instance is created for this UIExtensionAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information related to this UIExtensionAbility, including the ability name and bundle name.|
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | Yes| UI content information related to this UIExtensionAbility.|

**Example**

```ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

const TAG: string = '[testTag] UIExtAbility';

export default class UIExtAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    console.info(TAG, `onSessionCreate, want: ${JSON.stringify(want)}`);
  }
}
```

## UIExtensionAbility.onSessionDestroy

onSessionDestroy(session: UIExtensionContentSession): void

Called when a **UIExtensionContentSession** instance is destroyed for this UIExtensionAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | Yes| UI content information related to this UIExtensionAbility.|

**Example**

```ts
import { UIExtensionAbility, UIExtensionContentSession } from '@kit.AbilityKit';

const TAG: string = '[testTag] UIExtAbility';

export default class UIExtAbility extends UIExtensionAbility {
  onSessionDestroy(session: UIExtensionContentSession) {
    console.info(TAG, `onSessionDestroy`);
  }
}
```

## UIExtensionAbility.onForeground

onForeground(): void

Called when this UIExtensionAbility is switched from the background to the foreground.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

```ts
import { UIExtensionAbility } from '@kit.AbilityKit';

const TAG: string = '[testTag] UIExtAbility';

export default class UIExtAbility extends UIExtensionAbility {
  onForeground() {
    console.info(TAG, `onForeground`);
  }
}
```

## UIExtensionAbility.onBackground

onBackground(): void

Called when this UIExtensionAbility is switched from the foreground to the background.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

```ts
import { UIExtensionAbility } from '@kit.AbilityKit';

const TAG: string = '[testTag] UIExtAbility';

export default class UIExtAbility extends UIExtensionAbility {
  onBackground() {
    console.info(TAG, `onBackground`);
  }
}
```

## UIExtensionAbility.onDestroy

onDestroy(): void | Promise&lt;void&gt;

**Returns**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise that returns no value.                           |

Called to clear resources when this UIExtensionAbility is destroyed.
After the **onDestroy()** lifecycle callback is executed, the application may exit. Consequently, the asynchronous function (for example, asynchronously writing data to the database) in **onDestroy()** may fail to be executed. You can use the asynchronous lifecycle to ensure that the subsequent lifecycle continues only after the asynchronous function in **onDestroy()** finishes the execution.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Example**

```ts
import { UIExtensionAbility } from '@kit.AbilityKit';

const TAG: string = '[testTag] UIExtAbility';

export default class UIExtAbility extends UIExtensionAbility {
  onDestroy() {
    console.info(TAG, `onDestroy`);
  }
}
```
