# 延迟任务调度回调

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import workSchedulerExtension from '@ohos.WorkSchedulerExtension'
```

## WorkSchedulerExtension.onWorkStart
- **系统能力**：
SystemCapability.ResourceSchedule.WorkScheduler

- **接口**：
onWorkStart(workInfo: WorkInfo);

- **说明**：
延迟任务调度开始回调。

- **示例**：

  ```
    export default class MyWorkSchedulerExtension extends WorkSchedulerExtension {
        onWorkStart(workInfo) {
            console.log('MyWorkSchedulerExtension onWorkStart' + JSON.stringify(workInfo));
        }
    }
  ```

## WorkSchedulerExtension.onWorkStop
- **系统能力**：
SystemCapability.ResourceSchedule.WorkScheduler

- **接口**：
onWorkStop(workInfo: WorkInfo);

- **说明**：
延迟任务调度结束回调。

- **示例**：

  ```
    export default class MyWorkSchedulerExtension extends WorkSchedulerExtension {
        onWorkStop(workInfo) {
            console.log('MyWorkSchedulerExtension onWorkStop' + JSON.stringify(workInfo));
        }
    }
  ```