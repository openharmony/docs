# @ohos.app.ability.EmbeddedUIExtensionAbility (ExtensionAbilities for Embedded UIs Across Processes)

**EmbeddedUIExtensionAbility**, inherited from [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md), provides ExtensionAbilities for the embedded UI across processes. Currently, the EmbeddedUIExtensionAbility can be started only by the UIAbility of the same application and can be used only in scenarios with multi-process permissions. For details about the inheritance relationship of each ability, see [Inheritance Relationship](./js-apis-app-ability-ability.md#ability-inheritance-relationship).

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { EmbeddedUIExtensionAbility } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Type| Read-only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [UIExtensionContext](js-apis-inner-application-uiExtensionContext.md) | No| No| Context of the ExtensionAbility.|

## EmbeddedUIExtensionAbility.onCreate

onCreate(): void

Called to initialize the service logic when an EmbeddedUIExtensionAbility is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Example**

  ```ts
  import { EmbeddedUIExtensionAbility } from '@kit.AbilityKit';

  const TAG: string = '[testTag] EmbeddedUIExt';

  export default class EmbeddedUIExt extends EmbeddedUIExtensionAbility {
    onCreate() {
      console.info(TAG, `onCreate`);
    }
  }
  ```

## EmbeddedUIExtensionAbility.onSessionCreate

onSessionCreate(want: Want, session: UIExtensionContentSession): void

Called when a **UIExtensionContentSession** instance is created for this EmbeddedUIExtensionAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information of the EmbeddedUIExtensionAbility, including the ability name and bundle name.|
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | Yes| UI content information related to the EmbeddedUIExtensionAbility.|

**Example**

  ```ts
  import { EmbeddedUIExtensionAbility, Want, UIExtensionContentSession } from '@kit.AbilityKit';

  const TAG: string = '[testTag] EmbeddedUIExt';

  export default class EmbeddedUIExt extends EmbeddedUIExtensionAbility {
    onSessionCreate(want: Want, session: UIExtensionContentSession) {
      console.info(TAG, `onSessionCreate, want: ${JSON.stringify(want)}`);
    }
  }
  ```

## EmbeddedUIExtensionAbility.onSessionDestroy

onSessionDestroy(session: UIExtensionContentSession): void

Called when a **UIExtensionContentSession** instance is destroyed for this EmbeddedUIExtensionAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | Yes| UI content information related to the EmbeddedUIExtensionAbility.|

**Example**

  ```ts
  import { EmbeddedUIExtensionAbility, UIExtensionContentSession } from '@kit.AbilityKit';

  const TAG: string = '[testTag] EmbeddedUIExt';

  export default class EmbeddedUIExt extends EmbeddedUIExtensionAbility {
    onSessionDestroy(session: UIExtensionContentSession) {
      console.info(TAG, `onSessionDestroy`);
    }
  }
  ```

## EmbeddedUIExtensionAbility.onForeground

onForeground(): void

Called when this EmbeddedUIExtensionAbility is switched from the background to the foreground.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

  ```ts
  import { EmbeddedUIExtensionAbility } from '@kit.AbilityKit';

  const TAG: string = '[testTag] EmbeddedUIExt';

  export default class EmbeddedUIExt extends EmbeddedUIExtensionAbility {
    onForeground() {
      console.info(TAG, `onForeground`);
    }
  }
  ```

## EmbeddedUIExtensionAbility.onBackground

onBackground(): void

Called when this EmbeddedUIExtensionAbility is switched from the foreground to the background.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

  ```ts
  import { EmbeddedUIExtensionAbility } from '@kit.AbilityKit';

  const TAG: string = '[testTag] EmbeddedUIExt';

  export default class EmbeddedUIExt extends EmbeddedUIExtensionAbility {
    onBackground() {
      console.info(TAG, `onBackground`);
    }
  }
  ```

## EmbeddedUIExtensionAbility.onDestroy

onDestroy(): void | Promise&lt;void&gt;

Called to clear resources when this EmbeddedUIExtensionAbility is destroyed.
After the **onDestroy()** lifecycle callback is executed, the application may exit. Consequently, the asynchronous function (for example, asynchronously writing data to the database) in **onDestroy()** may fail to be executed. You can use the asynchronous lifecycle to ensure that the subsequent lifecycle continues only after the asynchronous function in **onDestroy()** finishes the execution.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Returns**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| void \| Promise\<void> | No return value or a Promise object that returns no value.      |

**Example**

  ```ts
  import { EmbeddedUIExtensionAbility } from '@kit.AbilityKit';

  const TAG: string = '[testTag] EmbeddedUIExt';

  export default class EmbeddedUIExt extends EmbeddedUIExtensionAbility {
    onDestroy() {
      console.info(TAG, `onDestroy`);
    }
  }
  ```
