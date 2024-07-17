# AppStartup Framework


## Overview

The AppStartup framework provides a simple and efficient method of initializing components. By explicitly specifying the component initialization sequence and dependencies, it enables asynchronous component initialization, thereby accelerating application startup. To use the AppStartup framework, you only need to implement [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) for each component to be initialized and configure the dependency between these startup tasks in the [startup_config.json](#adding-the-appstartup-framework-configuration-file) file. The AppStartup framework uses topological sorting to ensure that these startup tasks are initialized in the correct sequence.

> **NOTE**
>
> The AppStartup framework can be used only in the entry module.

## Development Process

1. [Enabling the AppStartup Framework](#enabling-the-appstartup-framework): Specify the path of the AppStartup framework configuration file in the **appStartup** field in the [module.json5 file](../quick-start/module-configuration-file.md).
2. [Compiling the AppStartup Framework Configuration File](#compiling-the-appstartup-framework-configuration-file): In the AppStartup framework configuration file, add the configuration of each component to be initialized and specify the path of the AppStartup framework parameter file.
3. [Adding a Startup Task for Each Component to Be Initialized](#adding-a-startup-task-for-each-component-to-be-initialized): Implement the [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) interface.
4. [Setting AppStartup Framework Parameters](#setting-appstartup-framework-parameters): In the AppStartup framework parameter file, set parameters such as the timeout interval and component initialization listener.

## How to Develop

### Enabling the AppStartup Framework

After the AppStartup framework is enabled, the system reads the configuration file of your application during its startup, checks whether circular dependencies exist, and uses topological sorting to sort the startup tasks. To enable the AppStartup framework, you only need to set the **appStartup** field in the [module.json5 file](../quick-start/module-configuration-file.md) to the path of the AppStartup Framework configuration file.

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

### Compiling the AppStartup Framework Configuration File

The AppStartup framework configuration file provides the specific implementation path and parameter settings of each [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) so that the system can read and execute these tasks. The file is in JSON format and stored in the **resource** directory of the project. The file path must be the same as the value of the **appStartup** field in the [module.json5 file](../quick-start/module-configuration-file.md). Circular dependencies are not allowed between startup tasks, and the name of each startup task must be unique.

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
      "dependencies": [
        "StartupTask_004"
      ],
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
      "dependencies": [
        "StartupTask_006"
      ],
      "runOnThread": "mainThread",
      "waitOnMainThread": true,
      "excludeFromAutoStart": true
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

**Figure 1** Dependency between startup tasks in the startup_config.json file

![app-startup](figures/app-startup.png) 


Fields in the **startup_config.json** file:

| Field| Description| Data Type| Left Unspecified Allowed|
| -------- | -------- | -------- | -------- |
| startupTasks | Information about the components to be initialized.| Object array| No|
| configEntry | Path of the [StartupConfig](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfig.md) file.| String| No|

Description of **startupTasks**:

| Field| Description| Data Type| Left Unspecified Allowed|
| -------- | -------- | -------- | -------- |
| name | Class name of the [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) API implemented by the component to be initialized.| String| No|
| srcEntry | Path of the code file of the [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) API implemented by the component to be initialized.| String| No|
| dependencies | Array of class names of the [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) API implemented by the dependency components of the current component.| Object array| Yes (initial value: left empty)|
| excludeFromAutoStart | Whether to exclude the automatic mode. For details, see [Component Startup Mode](#component-startup-mode).<br>- **true**: manual mode.<br>- **false**: automatic mode.| Boolean| Yes (initial value: **false**)|
| waitOnMainThread | Whether to wait in the main thread.<br>- **true**: The main thread waits for component initialization.<br>- **false**: The main thread does not wait for component initialization.| Boolean| Yes (initial value: **true**)|
| runOnThread | Thread where initialization is performed.<br>- **mainThread**: executed in the main thread.<br>- **taskPool**: executed in an asynchronous thread.| String| Yes (initial value: **mainThread**)|


### Adding a Startup Task for Each Component to Be Initialized

The AppStartup framework uses [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) to execute the component initialization logic. **StartupTask** has two APIs: [init](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md#startuptaskinit) and [onDependencyCompleted](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md#startuptaskondependencycompleted). Each startup task should implement functions as simple as possible. The file path should be the same as that configured in [startup_config](#compiling-the-appstartup-framework-configuration-file). The [Sendable](../arkts-utils/arkts-sendable.md) annotation should be added for every startup task. The following uses **StartupTask_001** as an example:

```ts
import { StartupTask, common } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

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

### Setting AppStartup Framework Parameters

[StartupConfigEntry](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfigEntry.md) provides the public configuration of the AppStartup framework. You can set parameters such as the timeout interval and component initialization listener, which is used to listen for whether a startup task is executed. The AppStartup framework needs to implement [StartupConfig](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfig.md) and [StartupListener](../reference/apis-ability-kit/js-apis-app-appstartup-startupListener.md). The file path must be the same as the value of **StartupConfig** configured in [startup_config](#compiling-the-appstartup-framework-configuration-file).

```ts
import { StartupConfig, StartupConfigEntry, StartupListener } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
    };
    let startupListener: StartupListener = {
      'onCompleted': onCompletedCallback
    };
    let config: StartupConfig = {
      'timeoutMs': 10000,
      'startupListener': startupListener
    };
    return config;
  }
}
```

## Component Startup Mode

The AppStartup framework provides automatic and manual component startup modes. In automatic mode, components are initialized before **onCreate** of **abilityStage** is called. If a component needs to be initialized only when it is used, you can manually call the initialization function after the application is started.

### Automatic Mode

In automatic mode, you do not need to set the **excludeFromAutoStart** field in [startup_config] (#compiling-the-appstartup-framework-configuration-file) or set the field to its default value **false**.

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

### Manual Mode

In manual mode, call [run](../reference/apis-ability-kit/js-apis-app-appstartup-startupManager.md#startupmanagerrun) in [StartupManager](../reference/apis-ability-kit/js-apis-app-appstartup-startupManager.md) to start component initialization. The following uses manual startup in the **onCreate** lifecycle as an example.

```ts
import { AbilityConstant, UIAbility, Want, startupManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    let startParams = ['StartupTask_005', 'StartupTask_006'];
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

  // ...
}
```

