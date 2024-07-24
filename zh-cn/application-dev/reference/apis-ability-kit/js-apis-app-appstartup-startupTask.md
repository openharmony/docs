# @ohos.app.appstartup.StartupTask

本模块提供启动任务的相关能力。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```js
import { StartupTask } from '@kit.AbilityKit';
```

## StartupTask.onDependencyCompleted

onDependencyCompleted?(dependency: string, result: ESObject): void

当依赖的启动任务执行完成时该方法将会被调用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AppStartup

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| dependency | string | 是 | 依赖的启动任务名称。 |
| result | Object | 是 | 依赖启动任务执行的结果。 |

**示例：**：

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
    // ...
  }

  onDependencyCompleted(dependence: string, result: Object): void {
    hilog.info(0x0000, 'testTag', 'StartupTask_001 onDependencyCompleted, dependence: %{public}s, result: %{public}s',
      dependence, JSON.stringify(result));
    // ...
  }
}
```


## StartupTask.init

init(context: AbilityStageContext): Promise\<ESObject\>

启动任务执行的初始化业务。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AppStartup

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| context | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md) | 是 | AbilityStage的上下文环境 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Object | void\> | Promise对象，返回启动任务执行结果对象。 |

**示例：**：

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
    // ...
    
    return 'StartupTask_001';
  }

  onDependencyCompleted(dependence: string, result: Object): void {
    // ...
  }
}
```
