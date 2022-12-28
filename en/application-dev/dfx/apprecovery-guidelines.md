# Development of Application Recovery

## When to Use

During application running, some unexpected behaviors are inevitable. For example, unprocessed exceptions and errors are thrown, and the call or running constraints of the framework are violated.

By default, the processes will exit as exception handling. However, if user data is generated during application use, process exits may interrupt user operations and cause data loss.
In this way, application recovery APIs may help you save temporary data, restart an application after it exits, and restore its status and data, which deliver a better user experience.

Currently, the APIs support only the development of an application that adopts the stage model, single process, and single ability.

## Available APIs

The application recovery APIs are provided by the **appRecovery** module, which can be imported via **import**. For details, please refer to [Development Example](#development-example). This document describes behaviors of APIs in API version 9, and the content will update with changes.

### Available APIs

| API                                                    | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| enableAppRecovery(restart?: RestartFlag, saveOccasion?: SaveOccasionFlag, saveMode?: SaveModeFlag) : void; | Enables the application recovery function.                                          |
| saveAppState(): boolean;                                     | Saves the ability status of an application.                           |
| restartApp(): void;                                          | Restarts the current process. If there is saved ability status, it will be passed to the **want** parameter's **wantParam** attribute of the **onCreate** lifecycle callback of the ability.|

The APIs are used for troubleshooting and do not return any exception. Therefore, you need to be familiar with when they are used.

**enableAppRecovery**: This API should be called during application initialization. For example, you can call this API in **onCreate** of **AbilityStage**. For details, please refer to the [parameter description](../reference/apis/js-apis-app-ability-appRecovery.md).

**saveAppState**: After this API is called, the framework calls back **onSaveState** of the ability. If data saving is agreed to in this method, relevant data and the page stack of the ability are persisted to the local cache of the application.

**restartApp**: After this API is called, the framework kills the current application process and restarts the ability in the foreground, with **APP_RECOVERY** specified as the startup cause.

### Framework Fault Management Process

Fault management is an important way for applications to deliver a better user experience. The application framework offers three methods for application fault management: fault listening, fault rectification, and fault query.

- Fault listening refers to the process of registering [ErrorObserver](../reference/apis/js-apis-application-errorManager.md#errorobserver) via [errorManager](../reference/apis/js-apis-application-errorManager.md), listening for fault occurrence, and notifying the fault listener.

- Fault rectification refers to [appRecovery](../reference/apis/js-apis-app-ability-appRecovery.md) and restarts an application to restore its status previous to a fault.

- Fault query indicates that [faultLogger](../reference/apis/js-apis-faultLogger.md) obtains the fault information using its query API.

The figure below does not illustrate the time when [faultLogger](../reference/apis/js-apis-faultLogger.md) is called. You can refer to [LastExitReason](../reference/apis/js-apis-application-abilityConstant.md#abilityconstantlastexitreason) passed during application initialization to determine whether to call [faultLogger](../reference/apis/js-apis-faultLogger.md) to query the information about the last fault.
![Fault rectification process](./figures/fault_rectification.png)

It is recommended that you call [errorManager](../reference/apis/js-apis-application-errorManager.md) to process the exception. After the processing is complete, you can call the status saving API and restart the application.
If you do not register [ErrorObserver](../reference/apis/js-apis-application-errorManager.md#errorobserver) or enable application recovery, the application process will exit according to the default processing logic of the system. Users can restart the application from the home screen.
If you have enabled application recovery, the framework first checks whether a fault allows for ability status saving and whether you have configured ability status saving. If so, [onSaveState](../reference/apis/js-apis-application-ability.md#abilityonsavestate) of [Ability](../reference/apis/js-apis-application-ability.md#ability) is called back. Finally, the application is restarted.

### Scenarios Supported by Application Fault Management APIs

Common fault types include JavaScript application crash, application freezing, and C++ application crash. Generally, an application is closed when a crash occurs. Application freezing occurs when the application does not respond. The fault type can be ignored for the upper layer of an application. The recovery framework implements fault management in different scenarios based on the fault type.

| Fault                                                    | Fault Listening| Status Saving| Automatic Restart| Log Query|
| ------------------------------------------------------------ | -------- | -------- | -------- | -------- |
| [JS_CRASH](../reference/apis/js-apis-faultLogger.md#faulttype) | Supported    | Supported    | Supported    | Supported    |
| [APP_FREEZE](../reference/apis/js-apis-faultLogger.md#faulttype) | Not supported  | Not supported  | Supported    | Supported    |
| [CPP_CRASH](../reference/apis/js-apis-faultLogger.md#faulttype) | Not supported  | Not supported  | Not supported  | Supported    |

**Status Saving** in the table header means status saving when a fault occurs. To protect user data as much as possible in the application freezing fault, you can adopt either the periodic or automatic way, and the latter will save user data when an ability is switched to the background.



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

After enabling **appRecovery**, you can use this function by either actively or passively saving the status and restoring data in the ability.
The following is an example of **MainAbility**:

#### Importing the Service Package

```ts
import errorManager from '@ohos.app.ability.errorManager'
import appRecovery from '@ohos.app.ability.appRecovery'
import AbilityConstant from '@ohos.app.ability.AbilityConstant'
```

#### Actively Saving Status and Restoring Data

- Define and register the [ErrorObserver](../reference/apis/js-apis-application-errorManager.md#errorobserver) callback.

```ts
  var registerId = -1;
  var callback = {
      onUnhandledException: function (errMsg) {
          console.log(errMsg);
          appRecovery.saveAppState();
          appRecovery.restartApp();
      }
  }

  onWindowStageCreate(windowStage) {
      // Main window is created. Set a main page for this ability.
      console.log("[Demo] MainAbility onWindowStageCreate")

      globalThis.registerObserver = (() => {
          registerId = errorManager.registerErrorObserver(callback);
      })

      windowStage.loadContent("pages/index", null);
  }
```

- Save data.

After the callback triggers **appRecovery.saveAppState()**, **onSaveState(state, wantParams)** of **MainAbility** is triggered.

```ts
  onSaveState(state, wantParams) {
      // Save application data.
      console.log("[Demo] MainAbility onSaveState")
      wantParams["myData"] = "my1234567";
      return AbilityConstant.onSaveResult.ALL_AGREE;
  }
```

- Restore data.

After the callback triggers **appRecovery.restartApp()**, the application is restarted. After the restart, **onSaveState(state, wantParams)** of **MainAbility** is called, and the saved data is in **parameters** of **want**.

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

- Deregister **ErrorObserver callback**.

```ts
onWindowStageDestroy() {
    // Main window is destroyed to release UI resources.
    console.log("[Demo] MainAbility onWindowStageDestroy")

    globalThis.unRegisterObserver = (() => {
        errorManager.unregisterErrorObserver(registerId, (result) => {
            console.log("[Demo] result " + result.code + ";" + result.message)
        });
    })
}
```

#### Passively Saving Status and Restoring Data

This is triggered by the recovery framework. You do not need to register **ErrorObserver callback**. You only need to implement **onSaveState** of the ability for status saving and **onCreate** of the ability for data restoration.

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
        // Save application data.
        console.log("[Demo] MainAbility onSaveState")
        wantParams["myData"] = "my1234567";
        return AbilityConstant.onSaveResult.ALL_AGREE;
    }
}
```
