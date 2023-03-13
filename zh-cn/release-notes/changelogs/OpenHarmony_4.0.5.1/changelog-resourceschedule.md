# 资源调度子系统ChangeLog

## cl.resourceschedule.workScheduler 

WorkSchedulerExtensionAbility提供默认的WorkSchedulerExtensionContext。

**变更影响**

基于OpenHarmony4.0.5.1及之后的SDK版本开发的应用，可使用默认的context属性作为WorkSchedulerExtension的上下文环境。

**关键接口/组件变更**

@ohos.WorkSchedulerExtensionAbility.d.ts中新增context属性。新增文件application/WorkSchedulerExtensionContext.d.ts，继承自ExtensionContext。

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 | 
|  -- | -- | -- | -- |
| @ohos.WorkSchedulerExtensionAbility.d.ts | WorkSchedulerExtensionAbility | context: WorkSchedulerExtensionContext; | 新增 | 
| application/WorkSchedulerExtensionContext.d.ts | WorkSchedulerExtensionContext | - | 新增 | 

**适配指导**<br>

通过WorkSchedulerExtensionAbility子类实例来获取WorkSchedulerExtensionContext。

```ts
import WorkSchedulerExtensionAbility from '@ohos.WorkSchedulerExtensionAbility';

class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
    onWorkStart(workInfo) {
        let WorkSchedulerExtensionContext = this.context; // 获取WorkSchedulerExtensionContext
    }
}
```