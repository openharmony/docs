# AbilityStateData

The module defines the ability state information, which can be obtained through the **onAbilityStateChanged** lifecycle callback of [ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md). The callback can be invoked after a lifecycle change listener is registered through [on](js-apis-app-ability-appManager.md#appmanageronapplicationstate14).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 14. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { appManager } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                    | Type    | Read-Only| Optional| Description                      |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| pid                     | number   | No  | No  | Process ID.                   |
| bundleName              | string   | No  | No | Bundle name.         |
| abilityName            | string   | No  | No  | Ability name.              |
| uid                    | number   | No  | No  | User ID.                 |
| state                   | number   | No  | No  | Ability state.<br>- In the stage model, the states of a UIAbility are described in [Ability States](#ability-states), and the states of an ExtensionAbility are described in [ExtensionAbility States](#extensionability-states).<br>- In the FA model, the states of an ability are described in [Ability States](#ability-states).               |
| moduleName | string   | No  | No  | Name of the HAP file to which the ability belongs.   |
| abilityType | number | No  | No  | [Ability type](#ability-types), which can be **page** or **service**.|
| isAtomicService | boolean   | No | No | Whether the ability belongs to an atomic service.<br>**true**: The ability belongs to an atomic service.<br>**false**: The ability does not belong to an atomic service.    |
| appCloneIndex          | number   | No  | Yes  | Index of an application clone.                 |

### Ability States

| Value  | State                      | Description                  |
| ---- | -------------------------- | ---------------------- |
| 0    | ABILITY_STATE_CREATE       | The ability is being created.     |
| 1    | ABILITY_STATE_READY        | The ability has been created.     |
| 2    | ABILITY_STATE_FOREGROUND   | The ability is running in the foreground.       |
| 3    | ABILITY_STATE_FOCUS        | The ability has focus.       |
| 4    | ABILITY_STATE_BACKGROUND   | The ability is running in the background.       |
| 5    | ABILITY_STATE_TERMINATED   | The ability is terminated.       |
| 7    | ABILITY_STATE_CONNECTED    | The background service is connected to the client.|
| 8    | ABILITY_STATE_DISCONNECTED | The background service is disconnected from the client.|

### ExtensionAbility States
| Value  | State   | Description                 |
| ---- | -------------------------- | ---------------------- |
| 0    | EXTENSION_STATE_CREATE     | The ExtensionAbility is being created. |
| 1    | EXTENSION_STATE_READY      | The ExtensionAbility has been created. |
| 2    | EXTENSION_STATE_CONNECTED  | The ExtensionAbility is connected to the client. |
| 3    | EXTENSION_STATE_DISCONNECTED | The ExtensionAbility is disconnected from the client.|
| 4    | EXTENSION_STATE_TERMINATED  | The ExtensionAbility is terminated. |

### Ability Types

| Value  | State   | Description                 |
| ---- | ------- | --------------------- |
| 0    | UNKNOWN | Unknown type.             |
| 1    | PAGE    | Ability that has the UI.  |
| 2    | SERVICE | Ability that provides the background service.|
| 3    | DATA | Ability that provides the data service.             |
| 4    | FORM    | Ability that provides the widget service.  |
| 5    | EXTENSION | Ability that provides extension capabilities.|
