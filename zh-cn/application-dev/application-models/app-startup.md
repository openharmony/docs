# 应用启动框架AppStartup


## 概述

`AppStartup`提供了一种简单高效的初始化组件的方式，开发者可以使用`AppStartup`来显示的设置组件的初始化顺序以及之间的依赖关系，支持异步初始化组件加速应用的启动时间。开发者需要分别为待初始化的组件实现`AppStartup`提供的[StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md)接口，并在[startup_config.json](#添加启动框架配置文件)中配置`AppStartup`之间的依赖关系，每个StartupTask都是一个等待执行的启动任务，启动框架将使用拓扑排序保证各个启动任务的执行顺序。

> **说明：**
>
> 启动框架只支持在`entry`中使用。

## 开发流程

1. [开启启动框架AppStartup](#开启启动框架appstartup)：在[module.json5配置文件](../quick-start/module-configuration-file.md)配置文件中appStartup标签中指定启动框架配置文件的路径。
2. [编写启动框架配置文件](#编写启动框架配置文件)：在启动框架配置文件中，依次添加各个待初始化组件的配置信息，并指定启动框架参数的文件路径。
3. [为每个待初始化组件添加启动任务](#为每个待初始化组件添加启动任务)：通过实现[StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md)接口，启动框架将会按顺序执行初始化流程。
4. [设置启动框架参数](#设置启动框架参数)：在启动框架参数文件中，设置超时时间和组件初始化的监听器等参数。

## 开发指导

### 开启启动框架AppStartup

开启启动框架后，当应用启动时系统将会读取开发者实现的配置文件并检查是否存在循环依赖，采用拓扑排序对其进行排序。开发者只需要在[module.json5配置文件](../quick-start/module-configuration-file.md)中配置`appStartup`标签, 并指定启动框架的配置文件路径即可开启启动框架。

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

### 编写启动框架配置文件

启动框架配置文件将为系统提供[StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md)的具体实现路径和参数设置，从而进行读取并执行相应的启动任务。该文件为JSON格式，应放在工程的`resource`目录下，配置文件路径需要与[module.json5配置文件](../quick-start/module-configuration-file.md)中`appStartup`标签指定的路径一致。启动任务之间不允许存在循环依赖，且每个启动任务的名称必须唯一。

示例代码如下。

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

**图1** 上述startup_config.json文件中启动任务依赖关系图  
![app-startup](figures/app-startup.png) 


`startup_config.json`配置文件标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| startupTasks | 待初始化组件配置信息。 | 对象数组 | 该标签不可缺省。 |
| configEntry | [StartupConfig](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfig.md)文件路径。 | 字符串 | 该标签不可缺省。 |

`startupTasks`标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 待初始化组件实现[StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md)接口的类名称。 | 字符串 | 该标签不可缺省。 |
| srcEntry | 需要加载的组件实现[StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md)接口的文件路径。 | 字符串 | 该标签不可缺省。 |
| dependencies | 当前组件所依赖组件实现[StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md)接口的类名称数组。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| excludeFromAutoStart | 是否排除自动模式，详细介绍可以查看[组件启动模式](#组件启动模式)。 <br/>-&nbsp;true：手动模式。 <br/>-&nbsp;false：自动模式。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| waitOnMainThread | 是否在主线程等待。 <br/>-&nbsp;true：主线程等待组件初始化。 <br/>-&nbsp;false：主线程不等待组件初始化。 | 布尔值 | 该标签可缺省，缺省值为true。 |
| runOnThread | 执行初始化所在的线程。<br/>-&nbsp;`mainThread`：在主线程中执行。<br/>-&nbsp;`taskPool`：在异步线程中执行。 | 字符串 | 该标签可缺省，缺省值为`mainThread`。 |


### 为每个待初始化组件添加启动任务

一个[StartupTask](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md)代表一个启动任务，启动框架通过StartupTask来执行组件初始化的逻辑，StartupTask有[init](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md#startuptaskinit)和[onDependencyCompleted](../reference/apis-ability-kit/js-apis-app-appstartup-startupTask.md#startuptaskondependencycompleted)两个方法。每个启动任务的功能应尽量单一，该文件路径应与[startup_config](#编写启动框架配置文件)中配置的路径一致。StartupTask必须添加[Sendable](../arkts-utils/arkts-sendable.md)注解。以`StartupTask_001`为例，示例代码如下。

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

### 设置启动框架参数

[StartupConfigEntry](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfigEntry.md)为启动框架的整体公用配置，可以设置超时时间和组件初始化的监听器等参数，监听器可以监听启动任务是否执行成功。启动框架需要分别实现[StartupConfig](../reference/apis-ability-kit/js-apis-app-appstartup-startupConfig.md)与[StartupListener](../reference/apis-ability-kit/js-apis-app-appstartup-startupListener.md)，文件路径需与[startup_config](#添加启动框架配置文件)中配置的`StartupConfig`标签路径一致。

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

## 组件启动模式

`AppStartup`分别提供了自动和手动两种方式来初始化组件，自动模式会在abilityStage的onCreate前执行组件初始化。当某些组件并不需要应用启动前就初始化，而是使用时才进行初始化，开发者可以根据业务需求在应用启动后进行手动调用执行初始化。

### 自动模式

采用自动模式开发者可以不设置[startup_config](#编写启动框架配置文件)中`excludeFromAutoStart`标签，或设置为`false`（`excludeFromAutoStart`默认为`false`）。

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

### 手动模式

手动模式开发者可以调用[StartupManager](../reference/apis-ability-kit/js-apis-app-appstartup-startupManager.md)中的[run](../reference/apis-ability-kit/js-apis-app-appstartup-startupManager.md#startupmanagerrun)方法来启动组件的初始化。以onCreate生命周期为例，示例代码如下。

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
   