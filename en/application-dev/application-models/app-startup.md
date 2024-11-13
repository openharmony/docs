# AppStartup


## Overview

During application initialization, a series of startup tasks are triggered. If these tasks are concentratedly placed within the [onCreate](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#uiabilityoncreate) lifecycle of the [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) of the application's main module ([module](../quick-start/application-package-overview.md#module-types) of the entry type), they must be executed sequentially on the main thread, which significantly affects the application launch speed. In addition, when there are too many tasks, complex dependencies between them make the code difficult to maintain.

AppStartup offers an efficient approach to application initialization. By enabling the asynchronous initiation of startup tasks, it ensures a smoother startup process. The centralized configuration of task execution order and interdependencies in a single file simplifies and clarifies the startup codebase, enhancing maintainability.

AppStartup supports startup tasks in automatic or manual mode. By default, the automatic mode is used. After an [AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md) is created, the configured startup tasks are loaded and executed in automatic mode. You can also call [startupManager.run](../reference/apis-ability-kit/js-apis-app-appstartup-startupManager.md#startupmanagerrun) to execute the startup tasks in manual mode after a UIAbility is created.

**Figure 1** Startup procedure

![app-startup-procedure](figures/app-startup-procedure.png)

## Constraints

- AppStartup can be used only in entry [modules](../quick-start/application-package-overview.md#module-types).

- Circular dependencies are not allowed between startup tasks.

## Development Process

1. [Defining an AppStartup Configuration File](#defining-an-appstartup-configuration-file): Create an AppStartup configuration file in the resource file directory, add the configuration about startup tasks, and reference the configuration file in [module.json5](../quick-start/module-configuration-file.md).
2. [Setting Startup Parameters](#setting-startup-parameters): In the startup parameter file, set parameters such as the timeout interval and startup task listener.
3. [Adding a Startup Task for Each Component to Be Initialized](#adding-a-startup-task-for-each-component-to-be-initialized): Implement the [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) interface.

## How to Develop

### Defining an AppStartup Configuration File

1. Create a AppStartup configuration file in the **resources/base/profile** directory of the application's main module ([module](../quick-start/application-package-overview.md#module-types) of the entry type). The file name can be customized. The following uses **startup_config.json** as an example.

2. In the **startup_config.json** file, add the configuration for each startup task in sequence.

    It is assumed that the application has six startup tasks. The dependencies between the tasks are shown in the figure below. To facilitate concurrent execution of startup tasks, a startup task file should contain only one startup task. In this example, each startup task corresponds to a startup task file.

    **Figure 2** Dependencies between startup tasks
    
    ![app-startup](figures/app-startup.png) 
    
    1. In the **ets/startup** directory, create six startup task files and a common startup parameter file. The file names must be unique.
    
        1. Create six startup task files. In this example, the six files are named from **StartupTask_001.ets** to **StartupTask_006.ets**.
        2. Create a startup parameter file. In this example, the file name is **StartupConfig.ets**.
        
    2. Add the information about the startup task files and startup parameter file to the **startup_config.json** file.
    
        The following is an example of the **startup_config.json** file:
        
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
    
        **Table 1** Fields in the startup_config.json file

        | Field| Description| Data Type| Default Value Allowed|
        | -------- | -------- | -------- | -------- |
        | startupTasks | Configuration about the startup tasks. For details, see the following table.| Object array| No|
        | configEntry | Path of the startup parameter file.| String| No|
        
        
        **Table 2** Description of startupTasks

        | Field| Description| Data Type| Default Value Allowed|
        | -------- | -------- | -------- | -------- |
        | name | Class name of the startup task.| String| No|
        | srcEntry | Path of the file corresponding to the startup task.| String| No|
        | dependencies | Array holding the class names of other startup tasks on which the startup task depends.| Object array| Yes (initial value: left empty)|
        | excludeFromAutoStart | Whether to exclude the automatic mode. For details, see [Changing the Startup Mode](#optional-changing-the-startup-mode).<br>- **true**: manual mode.<br>- **false**: automatic mode.| Boolean| Yes (initial value: **false**)|
        | runOnThread | Thread where the startup task is executed.<br>- **mainThread**: executed in the main thread.<br>- **taskPool**: executed in an asynchronous thread.| String| Yes (initial value: **mainThread**)|
        | waitOnMainThread | Whether the main thread needs to wait until the startup task finishes execution. This parameter is valid only when **runOnThread** is set to **taskPool**.<br>- **true**: The main thread loads the application home page only the startup task finishes execution.<br>- **false**: The main thread does not wait for the startup task to finish execution.| Boolean| Yes (initial value: **true**)|
        
    3. Add the index of the AppStartup configuration file to the **appStartup** tag in the [module.json5 file](../quick-start/module-configuration-file.md).
    
        The following is an example of the **module.json5** file:
    
          ```json
              {
                "module": {
                  "name": "entry",
                  "type": "entry",
                  // ...
                  "appStartup": "$profile:startup_config," // AppStartup configuration file
                  // ...
                }
              }
          ```

### Setting Startup Parameters

In the startup parameter file (**ets/startup/StartupConfig.ets** in this example), call [StartupConfigEntry](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfigEntry.md) to set the common AppStartup parameters, including the timeout interval and listener.

- [StartupConfig](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfig.md): sets the task timeout interval and AppStartup listener.
- [StartupListener](../reference/apis-ability-kit/js-apis-app-appstartup-startupListener.md): listens for the execution result of the startup task.

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

### Adding a Startup Task for Each Component to Be Initialized

Through the preceding operations, you have configured the AppStartup configuration file and startup parameters. Now you need to implement [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) in each startup task file by calling the following two APIs:

- [init](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md#startuptaskinit): starts task initialization. Call **init** to initialize a task only after all startup tasks on which the task depends are executed, that is, after **onDependencyCompleted** is invoked.
- [onDependencyCompleted](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md#startuptaskondependencycompleted): invoked when the startup task on which the current task depends is complete.


The following uses the **StartupTask_001.ets** file in [startup_config.json](#defining-an-appstartup-configuration-file) as an example. You must add a startup task for each component to be initialized.

> **NOTE**
> 
> **StartupTask** follows the [Sendable](../arkts-utils/arkts-sendable.md) protocol. Therefore, the Sendable annotation must be added when this API is inherited.

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

### (Optional) Changing the Startup Mode

AppStartup provides automatic and manual mode. By default, the automatic mode is used. However, you can change the mode to manual as required.

- Automatic mode: After an AbilityStage is created, the startup task is automatically executed.
- Manual mode: After a UIAbility is created, you need to manually call the API to execute the startup task. Modules that are infrequently used do not need to be initialized when the application is started. You can change the startup mode of these modules to manual. After the application is started, you can call [startupManager.run](../reference/apis-ability-kit/js-apis-app-appstartup-startupManager.md#startupmanagerrun) to execute the startup task.

The following uses the **onCreate** lifecycle of the UIAbility as an example to describe how to manually trigger a startup task. The sample code is as follows:

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

You can also call the API to trigger the manual mode after a page is loaded. The sample code is as follows:

```ts
import { startupManager } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  @State message: string = 'Manual Mode'
  @State startParams: Array<string> = ['StartupTask_006'];

  build() {
    RelativeContainer() {
      Button(this.message)
        .id('AppStartup')
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          if (!startupManager.isStartupTaskInitialized("StartupTask_006")) { // Check whether the startup task finishes execution.
            startupManager.run(this.startParams)
          }
        })
        .alignRules({
          center: {anchor: '__container__', align: VerticalAlign.Center},
          middle: {anchor: '__container__', align: HorizontalAlign.Center}
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

