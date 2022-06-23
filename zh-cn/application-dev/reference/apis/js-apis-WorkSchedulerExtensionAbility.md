# 延迟任务调度回调

本模块提供延迟任务回调能力。

开发者在开发应用时，通过覆写该接口，在延迟任务触发的时候，系统会通过该模块的接口回调应用，开发者在回调接口里面可以处理自己的任务逻辑。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。API 9当前为Canary版本，仅供试用，不保证接口可稳定调用。


## 导入模块

```
import WorkSchedulerExtensionAbility from '@ohos.WorkSchedulerExtensionAbility'
```

## WorkSchedulerExtensionAbility.onWorkStart

onWorkStart(work: workScheduler.WorkInfo): void

延迟任务调度开始回调。

**系统能力：** SystemCapability.ResourceSchedule.WorkScheduler

**参数**：

| 参数名  | 类型                    | 必填   | 说明             |
| ---- | --------------------- | ---- | -------------- |
| work | [workScheduler.WorkInfo](js-apis-workScheduler.md#workinfo) | 是    | 指示要添加到执行队列的工作。 |

**示例：** 

  ```
    export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
        onWorkStart(workInfo) {
            console.log('MyWorkSchedulerExtensionAbility onWorkStart' + JSON.stringify(workInfo));
        }
    }
  ```

## WorkSchedulerExtensionAbility.onWorkStop

onWorkStop(work: workScheduler.WorkInfo): void

延迟任务调度结束回调。

**系统能力：** SystemCapability.ResourceSchedule.WorkScheduler

**参数**：

| 参数名  | 类型                    | 必填   | 说明             |
| ---- | --------------------- | ---- | -------------- |
| work | [workScheduler.WorkInfo](js-apis-workScheduler.md#workinfo) | 是    | 指示要添加到执行队列的工作。 |


**示例：** 

  ```
    export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
        onWorkStop(workInfo) {
            console.log('MyWorkSchedulerExtensionAbility onWorkStop' + JSON.stringify(workInfo));
        }
    }
  ```