# Resource Scheduler Subsystem Changelog

## cl.resourceschedule.workScheduler 

The WorkSchedulerExtensionAbility provides a default WorkSchedulerExtensionContext.

**Change Impact**

Applications developed based on OpenHarmony4.0.5.1 and later SDK versions can use the default context attribute as the context environment of a WorkSchedulerExtension.

**Key API/Component Changes**

The context attribute is added to **@ohos.WorkSchedulerExtensionAbility.d.ts**. The **application/WorkSchedulerExtensionContext.d.ts** file is added, which is inherited from ExtensionContext.

| Module| Class| Method/Attribute/Enum/Constant| Change Type| 
|  -- | -- | -- | -- |
| @ohos.WorkSchedulerExtensionAbility.d.ts | WorkSchedulerExtensionAbility | context: WorkSchedulerExtensionContext; | Added| 
| application/WorkSchedulerExtensionContext.d.ts | WorkSchedulerExtensionContext | - | Added| 

**Adaptation Guide**

The context is obtained through a WorkSchedulerExtensionAbility child class instance.

```ts
import WorkSchedulerExtensionAbility from '@ohos.WorkSchedulerExtensionAbility';

class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
    onWorkStart(workInfo) {
        let WorkSchedulerExtensionContext = this.context; // Obtain the WorkSchedulerExtensionContext.
    }
}
```
