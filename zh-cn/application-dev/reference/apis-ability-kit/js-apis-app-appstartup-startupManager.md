# @ohos.app.appstartup.startupManager (启动框架管理能力)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

本模块提供应用启动框架管理启动任务的能力，只能在主线程调用。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块从API version 18开始支持so预加载。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { startupManager }  from '@kit.AbilityKit';
```

## startupManager.run
run(startupTasks: Array\<string\>, config?: StartupConfig): Promise\<void\>

执行启动框架启动任务或加载so文件。

> **说明：**
>
> 如果需要执行feature类型HAP中的启动任务，不支持使用该接口，需要使用[startupManager.run](#startupmanagerrun20)接口。

**系统能力**：SystemCapability.Ability.AppStartup

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| startupTasks | Array\<string\> | 是 | 表示准备执行的启动任务[StartupTask](js-apis-app-appstartup-startupTask.md)的名称和预加载so名称的数组。 |
| config | [StartupConfig](./js-apis-app-appstartup-startupConfig.md) | 否 | 启动框架超时时间与启动任务监听器配置。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

  | 错误码ID | 错误信息 |
  | ------- | -------------------------------- |
  | 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
  | 16000050 | Internal error. |
  | 28800001 | Startup task or its dependency not found. |
  | 28800002  | The startup tasks have circular dependencies. |
  | 28800003 | An error occurred while running the startup tasks. |
  | 28800004 | Running startup tasks timeout. |

**示例：**

```ts
import { AbilityConstant, UIAbility, Want, startupManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    let startParams = ['StartupTask_001', 'libentry_001'];
    try {
      // 手动调用run方法
      startupManager.run(startParams).then(() => {
        console.log(`StartupTest startupManager run then, startParams = ${startParams}.`);
      }).catch((error: BusinessError) => {
        console.error(`StartupTest promise catch failed, error code: ${error.code}, error msg: ${error.message}.`);
      });
    } catch (error) {
      let errMsg = (error as BusinessError).message;
      let errCode = (error as BusinessError).code;
      console.error(`Startup.run failed, err code: ${errCode}, err msg: ${errMsg}.`);
    }
  }

  // ...
}
```

## startupManager.run<sup>20+</sup>

run(startupTasks: Array\<string\>, context: common.AbilityStageContext, config: StartupConfig): Promise\<void\>

执行启动框架启动任务或加载so文件。支持指定[AbilityStageContext](js-apis-inner-application-abilityStageContext.md)用于启动任务的加载。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AppStartup

**参数：**

| 参数名       | 类型                                                         | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| startupTasks | Array\<string\>                                              | 是   | 表示准备执行的启动任务[StartupTask](js-apis-app-appstartup-startupTask.md)的名称和预加载so名称的数组。 |
| context      | [common.AbilityStageContext](js-apis-inner-application-abilityStageContext.md) | 是   | 表示执行启动任务[StartupTask](js-apis-app-appstartup-startupTask.md)的AbilityStage上下文，作为入参传给启动任务的[init](js-apis-app-appstartup-startupTask.md#init)。 |
| config       | [StartupConfig](./js-apis-app-appstartup-startupConfig.md)   | 是   | 启动框架超时时间与启动任务监听器配置。                       |

**返回值：**

| 类型            | 说明                                   |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                           |
| -------- | -------------------------------------------------- |
| 16000050 | Internal error.                                    |
| 28800001 | Startup task or its dependency not found.          |
| 28800002 | The startup tasks have circular dependencies.      |
| 28800003 | An error occurred while running the startup tasks. |
| 28800004 | Running startup tasks timeout.                     |

**示例：**

```ts
import { AbilityStage, startupManager, StartupListener, StartupConfig } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class MyAbilityStage extends AbilityStage {
  onCreate(): void {
    hilog.info(0x0000, 'testTag', 'AbilityStage onCreate');
    let onCompletedCallback = (error: BusinessError<void>) => {
      if (error) {
        hilog.error(0x0000, 'testTag', 'onCompletedCallback error: %{public}s', JSON.stringify(error));
      } else {
        hilog.info(0x0000, 'testTag', 'onCompletedCallback: success.');
      }
    };
    let startupListener: StartupListener = {
      'onCompleted': onCompletedCallback
    };
    let config: StartupConfig = {
      'timeoutMs': 10000,
      'startupListener': startupListener
    };

    try {
      // 手动调用run方法
      startupManager.run(["StartupTask_001", "libentry_001"], this.context, config).then(() => {
        hilog.info(0x0000, 'testTag', '%{public}s', 'startupManager.run success');
      }).catch((error: BusinessError<void>) => {
        hilog.error(0x0000, 'testTag', 'startupManager.run promise catch error: %{public}s', JSON.stringify(error));
      })
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'startupManager.run catch error: %{public}s', JSON.stringify(error));
    }
  }
  // ...
}
```

## startupManager.removeAllStartupTaskResults

removeAllStartupTaskResults(): void

删除所有启动任务结果。

如果存在so预加载任务，则将对应so文件置为未加载状态。对于缓存中已加载的so文件，不会被移除。

**系统能力**：SystemCapability.Ability.AppStartup

**示例：**

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
    startupManager.removeAllStartupTaskResults(); // 移除所有启动任务结果

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

获取指定启动任务或so预加载任务的执行结果。

**系统能力**：SystemCapability.Ability.AppStartup

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | startupTask | string | 是 | 启动任务实现[StartupTask](./js-apis-app-appstartup-startupTask.md)接口的文件名或so文件名，所有启动任务都需要实现[StartupTask](./js-apis-app-appstartup-startupTask.md)接口的方法。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Object | 输入为启动任务名时，返回指定的启动任务结果。<br/> 输入为so文件名时，返回undefined。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | ------- | -------------------------------- |
  | 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

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
    let result = startupManager.getStartupTaskResult("StartupTask_001"); // 手动获取启动任务结果
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

获取指定启动任务或so预加载任务是否已初始化。

**系统能力**：SystemCapability.Ability.AppStartup

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | startupTask | string | 是 | 启动任务实现[StartupTask](js-apis-app-appstartup-startupTask.md)接口的类名称或so文件名称。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 返回布尔值，true表示该启动任务或so预加载任务已执行完成，false表示该启动任务或so预加载任务尚未执行完成。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | ------- | -------------------------------- |
  | 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

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

删除指定启动任务或so预加载任务的初始化结果。

- 输入为启动任务名时，删除指定启动任务的初始化结果。

- 输入为so文件时，将该so文件置为未加载，缓存中已加载的so文件不会被移除。

**系统能力**：SystemCapability.Ability.AppStartup

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | startupTask | string | 是 | 启动任务所实现[StartupTask](js-apis-app-appstartup-startupTask.md)接口的类名称或so文件名。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

  | 错误码ID | 错误信息 |
  | ------- | -------------------------------- |
  | 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

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