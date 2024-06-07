# @ohos.app.appstartup.startupManager

The @ohos.app.appstartup.startupManager module enables the AppStartup framework to manage component initialization.

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

Runs the AppStartup framework.

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | startupTasks | Array\<string\> | Yes| Array of class names of the [StartupTask](js-apis-app-appstartup-startupTask.md) API implemented by the components to be initialized.|
  | config | [StartupConfig](./js-apis-app-appstartup-startupConfig.md) | No| Startup configuration, including the timeout for starting the framework and listener for component initialization.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise<void> | Promise that returns no value.|

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

Removes the initialization results of all components.

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

Obtains the initialization result of a component.

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | startupTask | string | Yes| Class name of the [StartupTask](./js-apis-app-appstartup-startupTask.md) API implemented by the component to be initialized. All components to be initialized must implement the [StartupTask](./js-apis-app-appstartup-startupTask.md) API.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Object | Initialization result of the component.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

  | ID| Error Message|
  | ------- | -------------------------------- |
  | 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

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

Checks whether a component has been initialized.

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | startupTask | string | Yes| Class name of the [StartupTask](js-apis-app-appstartup-startupTask.md) API implemented by the component to be initialized.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | **true**: The component has been initialized.<br>**false**: The component has not been initialized.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

  | ID| Error Message|
  | ------- | -------------------------------- |
  | 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

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

Removes the initialization result of a component.

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | startupTask | string | Yes| Class name of the [StartupTask](js-apis-app-appstartup-startupTask.md) API implemented by the component to be initialized.|
  
**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

  | ID| Error Message|
  | ------- | -------------------------------- |
  | 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

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
