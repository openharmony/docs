# Application Recovery Development

## When to Use

During application running, some unexpected behaviors are inevitable. For example, unprocessed exceptions and errors are thrown, and the call or running constraints of the recovery framework are violated.

Process exit is treated as the default exception handling method. However, if user data is generated during application use, process exit may interrupt user operations and cause data loss.
In this way, application recovery APIs may help you save temporary data, restart an application after it exits, and restore its status and data, which deliver a better user experience.

Currently, the APIs support only the development of an application that adopts the stage model, single process, and single ability.

## Available APIs

The application recovery APIs are provided by the **appRecovery** module, which can be imported via **import**. For details, see [Development Example](#development-example). This document describes behaviors of APIs in API version 9, and the content will update with changes.

### Available APIs

| API                                                      | Description                                                |
| ------------------------------------------------------------ | ---------------------------------------------------- |
| enableAppRecovery(restart?: RestartFlag, saveOccasion?: SaveOccasionFlag, saveMode?: SaveModeFlag) : void; | Enables the application recovery function.|
| saveAppState(): boolean; | Saves the ability status of an application. |
| restartApp(): void; | Restarts the current process. If there is saved ability status, it will be passed to the **want** parameter's **wantParam** attribute of the **onCreate** lifecycle callback of the ability.|

The APIs are used for troubleshooting and do not return any exception. Therefore, you need to be familiar with when they are used.

**enableAppRecovery**: This API should be called during application initialization. For example, you can call this API in **onCreate** of **AbilityStage**. For details, see [Parameter Description](../reference/apis/js-apis-app-ability-appRecovery.md).

**saveAppState**: After this API is called, the framework calls back **onSaveState** of the ability. If data saving is accepted in this API, relevant data and the page stack of the ability are persisted to the local cache of the application.

**restartApp**: After this API is called, the framework kills the current application process and restarts the ability in the foreground, with **APP_RECOVERY** specified as the startup cause.

### Framework Fault Management

Fault management is an important way for applications to deliver a better user experience. The application framework offers three methods for application fault management: fault listening, fault rectification, and fault query.

- Fault listening refers to the process of registering an [ErrorObserver](../reference/apis/js-apis-inner-application-errorObserver.md) via [errorManager](../reference/apis/js-apis-app-ability-errorManager.md), listening for faults, and notifying the listener of the faults.

- Fault rectification refers to the process of restoring the application state and data through [appRecovery](../reference/apis/js-apis-app-ability-appRecovery.md).

- Fault query is the process of calling APIs of [faultLogger](../reference/apis/js-apis-faultLogger.md) to obtain the fault information.

The figure below does not illustrate the time when [faultLogger](../reference/apis/js-apis-faultLogger.md) is called. You can refer to the [LastExitReason](../reference/apis/js-apis-app-ability-abilityConstant.md#abilityconstantlastexitreason) passed during application initialization to determine whether to call [faultLogger](../reference/apis/js-apis-faultLogger.md) to query information about the previous fault.

![Fault rectification process](./figures/fault_rectification.png)

It is recommended that you call [errorManager](../reference/apis/js-apis-app-ability-errorManager.md) to handle the exception. After the processing is complete, you can call the **saveAppState** API and restart the application.
If you do not register [ErrorObserver](../reference/apis/js-apis-inner-application-errorObserver.md) or enable application recovery, the application process will exit according to the default processing logic of the system. Users can restart the application from the home screen.
If you have enabled application recovery, the recovery framework first checks whether application state saving is supported and whether the application state saving is enabled. If so, the recovery framework invokes [onSaveState](../reference/apis/js-apis-app-ability-uiAbility.md#uiabilityonsavestate) of the [Ability](../reference/apis/js-apis-app-ability-uiAbility.md). Finally, the application is restarted.

### Supported Application Recovery Scenarios

Common fault types include JavaScript application crash, application freezing, and C++ application crash. Generally, an application is closed when a crash occurs. Application freezing occurs when the application does not respond. The fault type can be ignored for the upper layer of an application. The recovery framework implements fault management in different scenarios based on the fault type.

| Fault  | Fault Listening | State Saving| Automatic Restart| Log Query|
| ----------|--------- |--------- |--------- |--------- |
| [JS_CRASH](../reference/apis/js-apis-faultLogger.md#faulttype) | Supported|Supported|Supported|Supported|
| [APP_FREEZE](../reference/apis/js-apis-faultLogger.md#faulttype) | Not supported|Not supported|Supported|Supported|
| [CPP_CRASH](../reference/apis/js-apis-faultLogger.md#faulttype) | Not supported|Not supported|Not supported|Supported|

**State Saving** in the table header means saving of the application state when a fault occurs. To protect user data as much as possible when an AppFreeze occurs, you can adopt either the periodic or automatic way, and the latter will save user data when an ability is switched to the background.



## Development Example

### Enabling Application Recovery

   Enable **appRecovery** during application initialization. The following is an example of **AbilityStage**:

```ts
import AbilityStage from '@ohos.app.ability.AbilityStage'
import appRecovery from '@ohos.app.ability.appRecovery'

export default class MyAbilityStage extends AbilityStage {
    onCreate() {
        console.info("[Demo] MyAbilityStage onCreate")
        appRecovery.enableAppRecovery(appRecovery.RestartFlag.ALWAYS_RESTART,
            appRecovery.SaveOccasionFlag.SAVE_WHEN_ERROR | appRecovery.SaveOccasionFlag.SAVE_WHEN_BACKGROUND,
            appRecovery.SaveModeFlag.SAVE_WITH_FILE);
    }
}
```

### Saving and Restoring Data

After enabling **appRecovery**, you can use this function by either actively or passively saving the application state and restoring data in the ability.
The following is an example of **MainAbility**:

#### Importing the Service Package

```ts
import errorManager from '@ohos.app.ability.errorManager'
import appRecovery from '@ohos.app.ability.appRecovery'
import AbilityConstant from '@ohos.app.ability.AbilityConstant'
```

#### Actively Saving the Application State and Restoring Data

- Define and register the [ErrorObserver](../reference/apis/js-apis-inner-application-errorObserver.md) callback. For details about its usage, see [errorManager](../reference/apis/js-apis-app-ability-errorManager.md).

```ts
  var registerId = -1;
  var callback = {
      onUnhandledException(errMsg) {
          console.log(errMsg);
          appRecovery.saveAppState();
          appRecovery.restartApp();
      }
  }

  onWindowStageCreate(windowStage) {
      // Main window is created, set main page for this ability
      console.log("[Demo] MainAbility onWindowStageCreate")

      globalThis.registerObserver = (() => {
          registerId = errorManager.on('error', callback);
      })

      windowStage.loadContent("pages/index", null);
  }
```

- Save data.

After the callback triggers **appRecovery.saveAppState()**, **onSaveState(state, wantParams)** of **MainAbility** is triggered.

```ts
  onSaveState(state, wantParams) {
      // Ability has called to save app data
      console.log("[Demo] MainAbility onSaveState")
      wantParams["myData"] = "my1234567";
      return AbilityConstant.OnSaveResult.ALL_AGREE;
  }
```

- Restore data.

After the callback triggers **appRecovery.restartApp()**, the application is restarted. After the restart, **onCreate(want, launchParam)** of **MainAbility** is called, and the saved data is in **parameters** of **want**.

```ts
storage: LocalStorage
onCreate(want, launchParam) {
    console.log("[Demo] MainAbility onCreate")
    globalThis.abilityWant = want;
    if (launchParam.launchReason == AbilityConstant.LaunchReason.APP_RECOVERY) {
        this.storage = new LocalStorage();
        let recoveryData = want.parameters["myData"];
        this.storage.setOrCreate("myData", recoveryData);
        this.context.restoreWindowStage(this.storage);
    }
}
```

- Unregister the **ErrorObserver** callback.

```ts
onWindowStageDestroy() {
    // Main window is destroyed, release UI related resources
    console.log("[Demo] MainAbility onWindowStageDestroy")

    globalThis.unRegisterObserver = (() => {
        errorManager.off('error', registerId, (err) => {
            console.error("[Demo] err:", err);
        });
    })
}
```

#### Passively Saving the Application State and Restoring Data

This is triggered by the recovery framework. You do not need to register an **ErrorObserver** callback. You only need to implement **onSaveState** for application state saving and **onCreate** for data restore.

```ts
export default class MainAbility extends Ability {
    storage: LocalStorage
    onCreate(want, launchParam) {
        console.log("[Demo] MainAbility onCreate")
        globalThis.abilityWant = want;
        if (launchParam.launchReason == AbilityConstant.LaunchReason.APP_RECOVERY) {
            this.storage = new LocalStorage();
            let recoveryData = want.parameters["myData"];
            this.storage.setOrCreate("myData", recoveryData);
            this.context.restoreWindowStage(this.storage);
        }
    }

    onSaveState(state, wantParams) {
        // Ability has called to save app data
        console.log("[Demo] MainAbility onSaveState")
        wantParams["myData"] = "my1234567";
        return AbilityConstant.OnSaveResult.ALL_AGREE;
    }
}
```
