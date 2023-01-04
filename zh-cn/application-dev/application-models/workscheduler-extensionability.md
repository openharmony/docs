# WorkSchedulerExtensionAbility（延迟任务调度回调）

## 延迟任务概述

对于实时性要求不高的任务或持久性任务，可以使用延迟调度任务，该机制在满足应用设定条件的时候，会根据系统当前状态，如内存、功耗、温度等统一决策调度时间。

WorkSchedulerExtensionAbility提供了延迟任务回调能力，在延迟任务开始和结束时，系统会通过接口回调应用，开发者可在回调接口里面处理自己的任务逻辑。

## 运作机制

延迟任务调度运作机制如图1所示。

  **图1** 延迟任务调度运作机制 
![form-extension](figures/form-extension.png)

应用通过[延迟任务API](../reference/apis/js-apis-resourceschedule-workScheduler.md)注册、删除、查询任务。
应用服务侧进行条件检测和判断，若满足条件，则回调WorkSchedulerExtensionAbility拉起应用，执行onWorkStart、onWorkStop回调接口。

## 接口说明

WorkSchedulerExtensionAbility类拥有如下API接口，具体的API介绍详见[接口文档](../reference/apis/js-apis-app-form-formExtensionAbility.md)。

| 接口名 | 描述 |
| -------- | -------- |
| onWorkStart(work: workScheduler.WorkInfo): void | 延迟任务调度开始回调。 |
| onWorkStop(work: workScheduler.WorkInfo): void | 延迟任务调度结束回调。 |

## 开发步骤

在DevEco Studio工程中手动新建一个WorkSchedulerExtensionAbility工程，具体步骤如下。

1. 在工程Module对应的ets目录下，右键选择“New &gt; Directory”，新建一个目录并命名为WorkSchedulerExtension。

2. 在WorkSchedulerExtension目录，右键选择“New &gt; TypeScript File”，新建一个TypeScript文件并命名为WorkSchedulerExtension.ts。

3. 打开WorkSchedulerExtension.ts文件，导入模块。

```ts
import WorkSchedulerExtensionAbility from '@ohos.WorkSchedulerExtensionAbility'
```

4. 在WorkSchedulerExtension.ts中，实现WorkSchedulerExtension生命周期接口。

  ```ts
    export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
        onWorkStart(workInfo) {
            console.log('MyWorkSchedulerExtensionAbility onWorkStart' + JSON.stringify(workInfo));
        }
        onWorkStop(workInfo) {
            console.log('MyWorkSchedulerExtensionAbility onWorkStop' + JSON.stringify(workInfo));
        }
    }
  ```

5. 在工程Module对应的[module.json5配置文件](../quick-start/module-configuration-file.md)中注册WorkSchedulerExtensionAbility，type标签需要设置为“workScheduler”，srcEntrance标签表示当前ExtensionAbility组件所对应的代码路径。
   
   ```json
   {
     "module": {
       // ...
       "extensionAbilities": [
         {
           "name": "ServiceExtAbility",
           "description": "workScheduler",
           "type": "workScheduler",
           "srcEntrance": "./ets/WorkSchedulerExtension/WorkSchedulerExtension.ts"
         }
       ]
     }
   }
   ```

6. 在工程中实现延迟任务注册、删除等功能，延迟任务接口说明见[延迟任务API](../reference/apis/js-apis-resourceschedule-workScheduler.md)。

## 相关实例

针对WorkSchedulerExtensionAbility开发，有以下相关示例可供参考：

[WorkSchedulerExtensionAbility的创建与使用（ArkTS）（API9）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/WorkSchedExtAbility)

