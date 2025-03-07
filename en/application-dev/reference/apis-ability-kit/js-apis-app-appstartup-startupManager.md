# @ohos.app.appstartup.startupManager

The startupManager module provides APIs to manage startup tasks in AppStartup. It can be called only in the main thread.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module supports .so file preloading since API version 16.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { startupManager }  from '@kit.AbilityKit';
```

## startupManager.run
run(startupTasks: Array\<string\>, config?: StartupConfig): Promise\<void\>

Runs startup tasks or loads .so files.

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| startupTasks | Array\<string\> | Yes| Array of class names of the [StartupTask](js-apis-app-appstartup-startupTask.md) API implemented by the startup task and names of .so files to be preloaded.|
| config | [StartupConfig](./js-apis-app-appstartup-startupConfig.md) | No| Configuration for the AppStartup timeout and startup task listener.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000050 | Internal error. |
| 28800001 | Startup task or its dependency not found. |
| 28800002  | The startup tasks have circular dependencies. |
| 28800003 | An error occurred while running the startup tasks. |
| 28800004 | Running startup tasks timeout. |

**Example**

```ts
import { AbilityConstant, UIAbility, Want, startupManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    let startParams = ["StartupTask_001", "libentry_001"];
    try {
      // Manually call the run method.
      startupManager.run(startParams).then(() => {
        console.log('StartupTest startupManager run then, startParams = ');
      }).catch((error: BusinessError) => {
        console.info("StartupTest promise catch error, error = " + JSON.stringify(error));
        console.info("StartupTest promise catch error, startParams = "
          + JSON.stringify(startParams));
      })
    } catch (error) {
      let errMsg = JSON.stringify(error);
      let errCode: number = error.code;
      console.log('Startup catch error , errCode= ' + errCode);
      console.log('Startup catch error ,error= ' + errMsg);
    }
  }
  // ...
}
```

## startupManager.removeAllStartupTaskResults

removeAllStartupTaskResults(): void

Removes all startup task results.

If there are preloading tasks for .so files, the corresponding .so files is set to the unloaded state. However, .so files that have already been loaded in the cache will not be removed.

**System capability**: SystemCapability.Ability.AppStartup

**Example**

```ts
import { AbilityConstant, UIAbility, Want, startupManager } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    startupManager.run(["StartupTask_001", "libentry_001"]).then(() => {
      console.info("StartupTask_001 init successful");
    })
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    startupManager.removeAllStartupTaskResults(); // Remove all startup task results.

    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }
}
```


## startupManager.getStartupTaskResult

getStartupTaskResult(startupTask: string): Object

Obtains the execution result of a startup task or .so file preloading task.

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| startupTask | string | Yes| Class name of the [StartupTask](js-apis-app-appstartup-startupTask.md) API implemented by the startup task or .so file name. All the startup tasks must implement the [StartupTask](js-apis-app-appstartup-startupTask.md) API.|

**Return value**

| Type| Description|
| -------- | -------- |
| Object | Execution result of the startup task if a startup task name is passed.<br>undefined if a .so file name is passed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { AbilityConstant, UIAbility, Want, startupManager } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    startupManager.run(["StartupTask_001"]).then(() => {
      console.info("StartupTask_001 init successful");
    })
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    let result = startupManager.getStartupTaskResult("StartupTask_001"); // Manually obtain the startup task result.
    console.info("getStartupTaskResult result = " + result);
    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }
}
```


## startupManager.isStartupTaskInitialized

isStartupTaskInitialized(startupTask: string): boolean

Checks whether a startup task or .so file preloading task is initialized.

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| startupTask | string | Yes| Class name of the [StartupTask](js-apis-app-appstartup-startupTask.md) API implemented by the startup task or .so file name.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** means that the task is initialized, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { AbilityConstant, UIAbility, Want, startupManager } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    startupManager.run(["StartupTask_001", "libentry_001"]).then(() => {
      console.info("StartupTask_001 init successful");
    })
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    let result1 = startupManager.isStartupTaskInitialized('StartupTask_001');
    let result2 = startupManager.isStartupTaskInitialized('libentry_001');
    if (result1) {
      console.info("StartupTask_001 init successful");
    } else {
      console.info("StartupTask_001 uninitialized");
    }
    if (result2) {
      console.info("libentry_001 init successful");
    } else {
      console.info("libentry_001 uninitialized");
    }

    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }
}
```

## startupManager.removeStartupTaskResult

removeStartupTaskResult(startupTask: string): void

Removes the initialization result of a startup task or .so file preloading task.

- If a startup task name is passed, the initialization result of that startup task is removed.

- If a .so file is passed, the .so file is set to the unloaded state, but the loaded .so file in the cache is not removed.

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| startupTask | string | Yes| Class name of the [StartupTask](js-apis-app-appstartup-startupTask.md) API implemented by the startup task or .so file name.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { AbilityConstant, UIAbility, Want, startupManager } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    startupManager.run(["StartupTask_001", "libentry_001"]).then(() => {
      console.info("StartupTask_001 init successful");
    })
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    startupManager.removeStartupTaskResult("StartupTask_001");
    startupManager.removeStartupTaskResult("libentry_001");

    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }
}
```
