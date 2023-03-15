# AbilityStateData

The **AbilityStateData** module defines the ability state information, which can be obtained through the **onAbilityStateChanged** lifecycle callback of [ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md). The callback can be invoked after a lifecycle change listener is registered through [registerApplicationStateObserver](js-apis-application-appManager.md#appmanagerregisterapplicationstateobserver8).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                    | Type    | Readable| Writable| Description                      |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| pid<sup>8+</sup>                     | number   | Yes  | No  | Process ID.                   |
| bundleName<sup>8+</sup>              | string   | Yes  | No | Bundle name.         |
| abilityName<sup>8+</sup>             | string   | Yes  | No  | Ability name.              |
| uid<sup>8+</sup>                     | number   | Yes  | No  | User ID.                 |
| state<sup>8+</sup>                   | number   | Yes  | No  | [Ability state](#ability-states).               |
| moduleName<sup>9+</sup> | string   | Yes  | No  | Name of the HAP file to which the ability belongs.   |
| abilityType<sup>8+</sup> | number | Yes  | No  | [Ability type](#ability-types), which can be **page** or **service**.|

#### Ability States

| Value  | State                      | Description                  |
| ---- | -------------------------- | ---------------------- |
| 0    | ABILITY_STATE_CREATE       | The ability is being created.     |
| 1    | ABILITY_STATE_READY        | The ability has been created.     |
| 2    | ABILITY_STATE_FOREGROUND   | The ability is running in the foreground.       |
| 3    | ABILITY_STATE_FOCUS        | The ability has focus.       |
| 4    | ABILITY_STATE_BACKGROUND   | The ability is running in the background.       |
| 5    | ABILITY_STATE_TERMINATED   | The ability is terminated.       |
| 8    | ABILITY_STATE_CONNECTED    | The background service is connected to the client.|
| 9    | ABILITY_STATE_DISCONNECTED | The background service is disconnected from the client.|

#### Ability Types

| Value  | Status   | Description                 |
| ---- | ------- | --------------------- |
| 0    | UNKNOWN | Unknown type.             |
| 1    | PAGE    | Ability that has the UI.  |
| 2    | SERVICE | Ability that provides the background service.|
