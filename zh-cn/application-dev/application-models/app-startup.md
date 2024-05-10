# 应用启动框架AppStartup


## 概述

`AppStartup`提供了一种更加简单高效的初始化组件的方式，支持异步初始化组件加速应用的启动时间。使用启动框架应用开发者只需要分别为待初始化的组件实现`AppStartup`提供的[StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md)接口，并在[startup_config](#添加启动框架配置文件)中配置`AppStartup`之间的依赖关系，启动框架将使用拓扑排序保证各个待初始化组件的初始化顺序。启动框架只支持在`entry`中使用。


### 添加配置

应用需要在[module.json5配置文件](../quick-start/module-configuration-file.md)中配置`appStartup`标签, 并指定启动框架的配置文件路径。

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

### 添加启动框架配置文件

应用需要在工程的`resource`目录下添加启动框架的配置文件，配置文件路径需要与[module.json5配置文件](../quick-start/module-configuration-file.md)中`appStartup`标签指定的路径一致。

示例代码如下所示。

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
      "runOnThread": "taskpool",
      "waitOnMainThread": false
    },
    {
      "name": "StartupTask_002",
      "srcEntry": "./ets/startup/StartupTask_002.ets",
      "dependencies": [
        "StartupTask_004"
      ],
      "runOnThread": "taskpool",
      "waitOnMainThread": false
    },
    {
      "name": "StartupTask_003",
      "srcEntry": "./ets/startup/StartupTask_003.ets",
      "runOnThread": "taskpool",
      "waitOnMainThread": false
    },
    {
      "name": "StartupTask_004",
      "srcEntry": "./ets/startup/StartupTask_004.ets",
      "runOnThread": "taskpool",
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

`startup_config`配置文件标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| startupTasks | 待初始化组件配置信息。 | 对象数组 | 该标签不可缺省。 |
| configEntry | [StartupConfig](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfig.md)文件路径。 | 字符串 | 该标签不可缺省。 |

`startupTasks`标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 待初始化组件实现[StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md)接口的类名称。 | 对象数组 | 该标签不可缺省。 |
| srcEntry | 需要加载的组件实现[StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md)接口的文件路径。 | 字符串 | 该标签不可缺省。 |
| dependencies | 当前组件所依赖组件实现[StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md)接口的类名称数组。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| excludeFromAutoStart | 是否排除自动模式。 <br/>-&nbsp;true：手动模式。 <br/>-&nbsp;false：自动模式。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| waitOnMainThread | 是否在主线程等待。 <br/>-&nbsp;true：主线程等待组件初始化。 <br/>-&nbsp;false：主线程不等待组件初始化。 | 布尔值 | 该标签可缺省，缺省值为true。 |
| runOnThread | 执行初始化所在的线程。<br/>-&nbsp;`mainThread`：在主线程中执行。<br/>-&nbsp;`taskpool`：在异步线程中执行。 | 字符串 | 该标签可缺省，缺省值为`mainThread`。 |


### 添加启动框架组件

所有待加载组件均要实现[StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md)接口，文件放置在工程的`ets`目录下的`startup`文件夹下，StartupTask必须添加[Sendable](../arkts-utils/arkts-sendable.md)注解。

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

### 添加启动框架配置

应用需要在工程的`ets`目录下的`startup`文件夹下添加启动框架配置,开发者可以在该文件中配置超时时间以及组件初始化的监听器，启动框架配置需要在[StartupConfigEntry](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfigEntry.md)中设置[StartupConfig](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfig.md)与[StartupListener](../reference/apis-ability-kit/js-apis-app-appstartup-startupListener.md)。

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

## 启动组件

`AppStartup`分别提供了自动和手动两种方式来初始化组件，应用开发者可以根据自己的需求选择合适的初始化方式。

### 手动模式

手动模式需要应用开发者手动调用[StartupManager](../reference/apis-ability-kit/js-apis-app-appstartup-startupManager.md)中的[run](../reference/apis-ability-kit/js-apis-app-appstartup-startupManager.md#startupmanagerrun)方法来手动启动组件的初始化。

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

### 自动模式

自动模式应用开发者需要将[startup_config](#添加启动框架配置文件)中的`excludeFromAutoStart`标签设置为`false`，当应用启动时启动框架会在abilityStage的onCreate前执行组件初始化。

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
   