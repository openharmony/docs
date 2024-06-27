# AppStartup Framework


## Overview

The AppStartup framework provides a simpler and more efficient method of initializing components. It supports asynchronous component initialization to accelerate application startup. To use the AppStartup framework, you only need to implement [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) for each component to be initialized and configure the dependency between AppStartups in the [startup_config](#adding-the-appstartup-framework-configuration-file) file. The AppStartup framework uses topological sorting to ensure that these components are initialized in the correct sequence. The AppStartup framework can be used only in the entry module.


### Setting appStartup

Set the **appStartup** field in the [module.json5 file](../quick-start/module-configuration-file.md) to the path of the AppStartup framework configuration file, which is **startup_config**.

```json
{
  "module": {
    "name": "entry",
    "type": "entry",
    ...
    "appStartup": "$profile:startup_config",
    ...
  }
}
```

### Adding the AppStartup Framework Configuration File

Add the AppStartup framework configuration file to the **resource** directory of the project. The file path must be the same as that specified by **appStartup** in the [module.json5 file](../quick-start/module-configuration-file.md).

The sample code is as follows:

```json
{
  "startupTasks": [
    {
      "name": "StartupTask_001",
      "srcEntry": "./ets/startup/StartupTask_001.ets",
      "dependencies": [
        "StartupTask_002",
        "StartupTask_003"
      ],
      "runOnThread": "taskPool",
      "waitOnMainThread": false
    },
    {
      "name": "StartupTask_002",
      "srcEntry": "./ets/startup/StartupTask_002.ets",
      "dependencies": [
        "StartupTask_004"
      ],
      "runOnThread": "taskPool",
      "waitOnMainThread": false
    },
    {
      "name": "StartupTask_003",
      "srcEntry": "./ets/startup/StartupTask_003.ets",
      "runOnThread": "taskPool",
      "waitOnMainThread": false
    },
    {
      "name": "StartupTask_004",
      "srcEntry": "./ets/startup/StartupTask_004.ets",
      "runOnThread": "taskPool",
      "waitOnMainThread": false
    },
    {
      "name": "StartupTask_005",
      "srcEntry": "./ets/startup/StartupTask_005.ets",
      "runOnThread": "mainThread",
      "waitOnMainThread": true
    },
    {
      "name": "StartupTask_006",
      "srcEntry": "./ets/startup/StartupTask_006.ets",
      "runOnThread": "mainThread",
      "waitOnMainThread": false,
      "excludeFromAutoStart": true
    }
  ],
  "configEntry": "./ets/startup/StartupConfig.ets"
}
```

Fields in the **startup_config** file:

| Field| Description| Data Type| Default Value Allowed|
| -------- | -------- | -------- | -------- |
| startupTasks | Information about the components to be initialized.| Object array| No|
| configEntry | Path of the [StartupConfig](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfig.md) file.| String| No|

Description of **startupTasks**:

| Field| Description| Data Type| Default Value Allowed|
| -------- | -------- | -------- | -------- |
| name | Class name of the [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) API implemented by the component to be initialized.| Object array| No|
| srcEntry | Path of the code file of the [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) API implemented by the component to be initialized.| String| No|
| dependencies | Array of class names of the [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) API implemented by the dependency components of the current component.| Object array| Yes (initial value: left empty)|
| excludeFromAutoStart | Indicates whether to exclude the automatic mode.<br>- **true**: manual mode.<br>- **false**: automatic mode.| Boolean| Yes (initial value: **false**)|
| waitOnMainThread | Indicates whether to wait in the main thread.<br>- **true**: The main thread waits for component initialization.<br>- **false**: The main thread does not wait for component initialization.| Boolean| Yes (initial value: **true**)|
| runOnThread | Thread where initialization is performed.<br>- **mainThread**: executed in the main thread.<br>- **taskPool**: executed in an asynchronous thread.| String| Yes (initial value: **mainThread**)|


### Adding Components

All components to be initialized must implement the [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) API. The code file should be stored in the **startup** folder in the **ets** directory of the project, and the [Sendable](../arkts-utils/arkts-sendable.md) annotation must be added to **StartupTask**.

```ts
import StartupTask from '@ohos.app.appstartup.StartupTask';
import common from '@ohos.app.ability.common';
import hilog from '@ohos.hilog';

@Sendable
export default class StartupTask_001 extends StartupTask {
  constructor() {
    super();
  }
  async init(context: common.AbilityStageContext) {
    hilog.info(0x0000, 'testTag', 'StartupTask_001 init.');
    return 'StartupTask_001';
  }

  onDependencyCompleted(dependence: string, result: Object): void {
    hilog.info(0x0000, 'testTag', 'StartupTask_001 onDependencyCompleted, dependence: %{public}s, result: %{public}s',
      dependence, JSON.stringify(result));
  }
}
```

### Adding the AppStartup Framework Configuration

Add the AppStartup framework configuration to the **startup** folder in the **ets** directory of the project. You can configure the timeout interval and component initialization listener in the configuration file by setting [StartupConfig](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfig.md) and [StartupListener](../reference/apis-ability-kit/js-apis-app-appstartup-startupListener.md) in [StartupConfigEntry](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfigEntry.md).

```ts
import StartupConfig from '@ohos.app.appstartup.StartupConfig';
import StartupConfigEntry from '@ohos.app.appstartup.StartupConfigEntry';
import StartupListener from '@ohos.app.appstartup.StartupListener';
import hilog from '@ohos.hilog';
import { BusinessError } from '@ohos.base';

export default class MyStartupConfigEntry extends StartupConfigEntry {
  onConfig() {
    hilog.info(0x0000, 'testTag', `onConfig`);
    let onCompletedCallback = (error: BusinessError<void>) => {
      hilog.info(0x0000, 'testTag', `onCompletedCallback`);
      if (error) {
        hilog.info(0x0000, 'testTag', 'onCompletedCallback: %{public}d, message: %{public}s', error.code, error.message);
      } else {
        hilog.info(0x0000, 'testTag', `onCompletedCallback: success.`);
      }
    }
    let startupListener: StartupListener = {
      'onCompleted': onCompletedCallback
    }
    let config: StartupConfig = {
      'timeoutMs': 10000,
      'startupListener': startupListener
    }
    return config;
  }
}
```

## Starting Components

The AppStartup framework provides automatic and manual modes for component initialization.

### Manual Mode

In manual mode, call [run](../reference/apis-ability-kit/js-apis-app-appstartup-startupManager.md#startupmanagerrun) in [StartupManager](../reference/apis-ability-kit/js-apis-app-appstartup-startupManager.md) to manually start component initialization.

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@ohos.base';
import startupManager from '@ohos.app.appstartup.startupManager';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    let startParams = ['StartupTask_006'];
    try {
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
  ...
}
```

### Automatic Mode

In automatic mode, you only need to set **excludeFromAutoStart** in [startup_config](#adding-the-appstartup-framework-configuration-file) to **false**. During application launch, the AppStartup framework initializes the components before **onCreate** of **abilityStage** is invoked.

```json
{
  "startupTasks": [
    {
      "name": "StartupTask_001",
      ...
      "excludeFromAutoStart": false
    },
    ...
  ],
  ...
}
```
   
