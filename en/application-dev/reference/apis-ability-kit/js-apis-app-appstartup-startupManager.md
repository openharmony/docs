# @ohos.app.appstartup.startupManager

The @ohos.app.appstartup.startupManager module enables the application startup framework to manage startup tasks.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import startupManager  from '@ohos.app.appstartup.startupManager';
```

## startupManager.run
run(startupTasks: Array\<string\>, config?: StartupConfig): Promise\<void\>

Runs startup tasks.

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | startupTasks | Array\<string\> | Yes| Array of startup tasks to run.|
  | config | [StartupConfig](./js-apis-app-appstartup-startupConfig.md) | No| Startup configuration, including the timeout for starting the framework and listener for startup task initialization.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise<void> | Promise that returns no value.|

**Error codes**

  | ID| Error Message|
  | ------- | -------------------------------- |
  | 401 | If the input parameter is not valid parameter. |
  | 16000050 | Internal error. |
  | 28800001 | Startup task or its dependency not found. |
  | 28800002  | The startup tasks have circular dependencies. |
  | 28800003 | An error occurred while running the startup tasks. |
  | 28800004 | Running startup tasks timeout. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

```ts
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import UIAbility from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import startupManager from '@ohos.app.appstartup.startupManager';
import StartupConfig from '@ohos.app.appstartup.StartupConfig';
import StartupListener from '@ohos.app.appstartup.StartupListener';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let startup = startupManager;
    let startParams = 'Sample_001';
    try {
        startup.run(startParams).then(() => {
        console.log('StartupTest startupManager run then, startParams = ')
        }).catch(error => {
        console.info("StartupTest promise catch error, error = " + JSON.stringify(error));
        console.info("StartupTest promise catch error, startParams = "
            + JSON.stringify(startParams));
        })
    } catch (error) {
        let errmsg = JSON.stringify(error)
        let errCode = error.code
        console.log('Startup catch error , errCode= ' + errCode);
        console.log('Startup catch error ,error= ' + errmsg);
  }
}
```

## startupManager.removeAllStartupTaskResults

removeAllStartupTaskResults(): void

Removes the initialization results of all startup tasks.

**System capability**: SystemCapability.Ability.AppStartup

**Example**

```ts
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import hilog from '@ohos.hilog';
import UIAbility from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import window from '@ohos.window';
import startupManager from '@ohos.app.appstartup.startupManager';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    startupManager.run(['Sample_001']).then(() => {
      console.info("Sample_001 init successful");
    })
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    let result = removeAllStartupTaskResults.removeAllStartupTaskResults();
    
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

Obtains the initialization result of a startup task.

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | startupTask | string | Yes| Name of the startup task.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Object | Initialization result of the startup task.|

**Error codes**

  | ID| Error Message|
  | ------- | -------------------------------- |
  | 401 | If the input parameter is not valid parameter. |

**Example**

```ts
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import hilog from '@ohos.hilog';
import UIAbility from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import window from '@ohos.window';
import startupManager from '@ohos.app.appstartup.startupManager';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    startupManager.run(['Sample_001']).then(() => {
      console.info("Sample_001 init successful");
    })
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    let result = startupManager.getStartupTaskResult('Sample_001');
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

Checks whether a startup task has been initialized.

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | startupTask | string | Yes| Name of the startup task.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | **true**: The startup task has been initialized.<br>**false**: The startup task has not been initialized.|

**Error codes**

  | ID| Error Message|
  | ------- | -------------------------------- |
  | 401 | If the input parameter is not valid parameter. |

**Example**

```ts
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import hilog from '@ohos.hilog';
import UIAbility from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import window from '@ohos.window';
import startupManager from '@ohos.app.appstartup.startupManager';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    startupManager.run(['Sample_001']).then(() => {
      console.info("Sample_001 init successful");
    })
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    let result = startupManager.isStartupTaskInitialized('Sample_001');
    if (result) {
      console.info("Sample_001 init successful");
    } else {
      console.info("Sample_001 uninitialized");
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

Removes the initialization result of a startup task.

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | startupTask | string | Yes| Name of the startup task.|
  
**Error codes**

  | ID| Error Message|
  | ------- | -------------------------------- |
  | 401 | If the input parameter is not valid parameter. |

**Example**

```ts
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import hilog from '@ohos.hilog';
import UIAbility from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import window from '@ohos.window';
import startupManager from '@ohos.app.appstartup.startupManager';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    startupManager.run(['Sample_001']).then(() => {
      console.info("Sample_001 init successful");
    })
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    startupManager.removeStartupTaskResult('Sample_001');
    
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
