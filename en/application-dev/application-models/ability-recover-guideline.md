# UIAbility Backup and Restore

## When to Use

When an application runs in the background, factors such as system resource control may cause the application to close or its process to terminate, which might result in the loss of user data. However, if the application has enabled the [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) backup and restore feature within [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) and saved temporary data, it can restore the previous state and data (including the page stack and the data stored in the [onSaveState](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onsavestate) callback) when it restarts after being closed, maintaining a seamless user experience.

> **NOTE**
>
> If the application is stopped normally, the UIAbility backup process is not triggered. If the application is started normally (for example, by calling the **startAbility** API or clicking the icon), the UIAbility restore process is not triggered.

## Working Mechanism
- UIAbility data backup: After an application transitions to the [onBackground](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onbackground) lifecycle, the system automatically calls [onSaveState](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onsavestate) to back up data.
- UIAbility data restore: The restored [Want](../reference/apis-ability-kit/js-apis-app-ability-want.md) data can be obtained from the [onCreate](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#oncreate) lifecycle of the application, and the page stack data can be restored in the [onWindowStageCreate](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onwindowstagecreate) lifecycle of the application.

## Constraints

- The UIAbility backup and restore feature supports multiple instances. Backup data is stored in the application sandbox path as files for seven days.

- Backup data is stored in the form of [WantParams](../reference/apis-ability-kit/js-apis-app-ability-want.md). Due to serialization constraints, the maximum data volume supported is 200 KB.

- Data restore is unavailable after device restart.

- The data backup and restore feature is unavailable for a [UIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md).

## Available APIs

The UIAbility backup and restore API is provided by the [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) module. You can directly use **this.context** in the [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) to call them. For details, see [How to Develop](#how-to-develop).

| API                                                      | Description                                                |
| ------------------------------------------------------------ | ---------------------------------------------------- |
| setRestoreEnabled(enabled: boolean): void | Sets whether to enable restore when the UIAbility is switched back from the background.|

[setRestoreEnabled](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#setrestoreenabled14) must be called during application initialization (before [onForeground](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onforeground) is invoked). For example, it can be called in the [onCreate](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#oncreate) callback of the UIAbility.


## How to Develop

To enable UIAbility backup and restore during application module initialization, refer to the code snippet below.

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
    onCreate() {
        console.info("[Demo] EntryAbility onCreate");
        this.context.setRestoreEnabled(true);
    }
}
```

To proactively save data and restore the data when the UIAbility is started, refer to the code snippet below.

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.info("[Demo] EntryAbility onCreate");
        this.context.setRestoreEnabled(true);
        if (want && want.parameters) {
          let recoveryMyData = want.parameters["myData"];
        }
    }

    onSaveState(state:AbilityConstant.StateType, wantParams: Record<string, Object>) {
        // Ability has called to save app data
        console.log("[Demo] EntryAbility onSaveState");
        wantParams["myData"] = "my1234567";
        return AbilityConstant.OnSaveResult.ALL_AGREE;
    }
}
```
