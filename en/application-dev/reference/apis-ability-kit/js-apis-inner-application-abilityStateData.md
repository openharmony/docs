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
| isAtomicService | boolean   | No | No | Whether the ability belongs to an atomic service.<br>- **true**: The ability belongs to an atomic service.<br>- **false**: The ability does not belong to an atomic service.    |
| appCloneIndex          | number   | No  | Yes  | Index of an application clone.                 |

### Ability States

| State                       | Value | Description                   |
| --------------------------  | --- | ---------------------- |
| ABILITY_STATE_CREATE        | 0   |  The ability is being created.   |
| ABILITY_STATE_READY         | 1   |  The ability has been created.   |
| ABILITY_STATE_FOREGROUND    | 2   |  The ability is running in the foreground.     |
| ABILITY_STATE_FOCUS         | 3   |   The ability has focus.    |
| ABILITY_STATE_BACKGROUND    | 4   |  The ability is running in the background.     |
| ABILITY_STATE_TERMINATED    | 5   |  The ability is terminated.     |
| ABILITY_STATE_CONNECTED     | 7   |  The background service is connected to the client.|
| ABILITY_STATE_DISCONNECTED  | 8   |  The background service is disconnected from the client.|

### ExtensionAbility States
| State                  | Value| Description                  |
| ---------------------- | ---- | ---------------------- |
| EXTENSION_STATE_CREATE | 0   | The ExtensionAbility is being created. |
| EXTENSION_STATE_READY  | 1   | The ExtensionAbility has been created. |
| EXTENSION_STATE_CONNECTED | 2  | The ExtensionAbility is connected to the client. |
| EXTENSION_STATE_DISCONNECTED | 3 | The ExtensionAbility is disconnected from the client.|
| EXTENSION_STATE_TERMINATED | 4  | The ExtensionAbility is terminated. |

### Ability Types

| State   | Value     | Description                 |
| ------  | ------- | --------------------- |
| UNKNOWN | 0 | Unknown type.             |
| PAGE    | 1 | Ability that has the UI.  |
| SERVICE | 2 | Ability that provides the background service.|
| DATA    | 3 | Ability that provides the data service.             |
| FORM    | 4 | Ability that provides the widget service.  |
| EXTENSION | 5 | Ability that provides extension capabilities.|
