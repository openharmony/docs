# @ohos.app.appstartup.StartupTask (Startup Task)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

The module provides APIs related to startup tasks.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```js
import { StartupTask } from '@kit.AbilityKit';
```

## StartupTask

Provides capabilities related to startup tasks. It is decorated by [@Sendable](../../arkts-utils/arkts-sendable.md#sendable-decorator).

### onDependencyCompleted

onDependencyCompleted?(dependency: string, result: Object): void

Called when the dependent startup task is complete.

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| dependency | string | Yes| Name of the dependent startup task.|
| result | Object | Yes| Execution result of the dependent startup task.|

**Example**

```ts
import { StartupTask, common } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

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


### init

init(context: AbilityStageContext): Promise\<Object \| void\>

Initializes this startup task.

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md) | Yes| Context of the ability stage.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<Object \| void\> | Promise used to return the execution result.|

**Example**

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
    
    return "StartupTask_001";
  }

  onDependencyCompleted(dependence: string, result: Object): void {
    // ...
  }
}
```
