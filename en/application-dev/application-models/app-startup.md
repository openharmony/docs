# AppStartup Framework


## Overview

The AppStartup framework provides a simpler and more efficient mode of initializing components. You only need to implement [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) for each component to be initialized and configure the dependency between components in the [startup_config](#adding-the-appstartup-framework-configuration-file) file. The AppStartup framework then uses directed acyclic graph (DAG) topological sorting to ensure that these components are initialized in the correct sequence. The AppStartup framework can be used only in the entry module.


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
      "name": "Sample_001",
      "srcEntry": "./ets/startup/Sample_001.ts",
      "dependencies": [
        "Sample_002",
        "Sample_003"
      ],
      "excludeFromAutoStart": true
    },
    {
      "name": "Sample_002",
      "srcEntry": "./ets/startup/Sample_002.ts",
      "excludeFromAutoStart": true
    },
    {
      "name": "Sample_003",
      "srcEntry": "./ets/startup/Sample_003.ts",
      "dependencies": [
        "Sample_004"
      ],
      "excludeFromAutoStart": true,
      "waitOnMainThread": false
    },
    {
      "name": "Sample_004",
      "srcEntry": "./ets/startup/Sample_004.ts",
      "excludeFromAutoStart": true,
      "waitOnMainThread": false,
      "runOnThread": "mainThread"
    }
  ],
  "configEntry": "./ets/startup/StartupConfig.ts"
}
```

Fields in the **startup_config** file:

| Field| Description| Data Type| Default Value Allowed|
| -------- | -------- | -------- | -------- |
| startupTasks | Information about the components to be initialized.| Object array| No|
| configEntry | Path of the [StartupConfig](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfig) file.| String| No|

Description of **startupTasks**:

| Field| Description| Data Type| Default Value Allowed|
| -------- | -------- | -------- | -------- |
| name | Class name of the [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) API implemented by the component to be initialized.| Object array| No|
| srcEntry | Path of the code file of the [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) API implemented by the component to be initialized.| String| No|
| dependencies | Array of class names of the [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) API implemented by the dependency components of the current component.| Object array| Yes (initial value: left empty)|
| excludeFromAutoStart | Indicates whether to exclude the automatic mode.<br>- **true**: manual mode.<br>- **false**: automatic mode.| Boolean| Yes (initial value: **false**)|
| waitOnMainThread | Indicates whether to wait in the main thread.<br>- **true**: The main thread waits for component initialization.<br>- **false**: The main thread does not wait for component initialization.| Boolean| Yes (initial value: **true**)|
| runOnThread | Thread where initialization is performed. Currently, only the main thread is supported.| String| Yes (initial value: **mainThread**)|


### Adding Components

All components to be initialized must implement the [StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md) API. The code file should be stored in the **startup** folder in the **ets** directory of the project.

```ts
import StartupTask from '@ohos.app.appstartup.StartupTask';

export default class Sample_001 extends StartupTask {
  async init(context) {
    console.info("StartupTest Sample_001 init");
    ...
  }

  onDependencyCompleted(dependence: string, result) {
    console.info("StartupTest Sample_001 onDependencyCompleted dependence=" + dependence);
    ...
  }
}
```

### Adding the AppStartup Framework Configuration

Add the AppStartup framework configuration to the **startup** folder in the **ets** directory of the project. You can configure the timeout interval and component initialization listener in the configuration file by setting [StartupConfig](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfig.md) and [StartupListener](../reference/apis-ability-kit/js-apis-app-appstartup-startupListener) in [StartupConfigEntry](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfigEntry.md).

```ts
import StartupConfig from '@ohos.app.appstartup.StartupConfig';
import StartupConfigEntry from '@ohos.app.appstartup.StartupConfigEntry';
import StartupListener from '@ohos.app.appstartup.StartupListener';

export default class MyStartupConfigEntry extends StartupConfigEntry {
  onConfig() {
    console.log('StartupTest MyStartupConfigEntry onConfig');
    let onCompletedCallback = (error) => {
      console.log('StartupTest MyStartupConfigEntry callback, error=' + JSON.stringify(error));
      if (error) {
        console.log('onCompletedCallback: %{public}d, mssage: %{public}s', error.code, error.mssage);
      } else {
        console.log('onCompletedCallback: success');
      }
    }
    let startupListener: StartupListener = {
      'onCompleted': onCompletedCallback
    }
    let config: StartupConfig = {
      'timeoutMs': 5000,
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
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import UIAbility from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import startupManager from '@ohos.app.appstartup.startupManager';
import StartupConfig from '@ohos.app.appstartup.StartupConfig';
import StartupListener from '@ohos.app.appstartup.StartupListener';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let startup = startupManager;
    let startParams = ['Sample_001'];
    try {
        startup.run(startParams).then(() => {
        console.log('StartupTest startupManager run then, startParams = ');
        }).catch(error => {
        console.info("StartupTest promise catch error, error = " + JSON.stringify(error));
        console.info("StartupTest promise catch error, startParams = "
            + JSON.stringify(startParams));
        })
    } catch (error) {
        let errmsg = JSON.stringify(error);
        let errCode = error.code;
        console.log('Startup catch error , errCode= ' + errCode);
        console.log('Startup catch error ,error= ' + errmsg);
  }
}
```

### Automatic Mode

In automatic mode, you only need to set **excludeFromAutoStart** in [startup_config](#adding-the-appstartup-framework-configuration-file) to **false**. During application launch, the AppStartup framework initializes the components before **onCreate** of **abilityStage** is invoked.

```json
{
  "startupTasks": [
    {
      "name": "Sample_001",
      ...
      "excludeFromAutoStart": false
    },
    ...
  ],
  ...
}
```
   
