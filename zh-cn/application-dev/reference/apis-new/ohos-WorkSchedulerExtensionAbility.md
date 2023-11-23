# @ohos.WorkSchedulerExtensionAbility    
本模块提供延迟任务回调能力。开发者可重写模块接口，在延迟任务触发时，系统可通过本模块接口回调应用，在回调里处理任务逻辑。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## WorkSchedulerExtensionAbility  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
### 属性    
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| context<sup>(10+)</sup> | WorkSchedulerExtensionContext | false | true | WorkSchedulerExtension的上下文环境，继承自ExtensionContext。 |  
    
### onWorkStart    
开始延迟任务调度回调。  
 **调用形式：**     
- onWorkStart(work: workScheduler.WorkInfo): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| work | workScheduler.WorkInfo | true | 要添加到执行队列的任务。 |  
    
 **示例代码：**   
```ts    
import workScheduler from '@ohos.resourceschedule.workScheduler';  
  
  export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {  
    onWorkStart(workInfo: workScheduler.WorkInfo) {  
        console.log('MyWorkSchedulerExtensionAbility onWorkStart' + JSON.stringify(workInfo));  
    }  
  }  
    
```    
  
    
### onWorkStop    
结束延迟任务调度回调。  
 **调用形式：**     
- onWorkStop(work: workScheduler.WorkInfo): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| work | workScheduler.WorkInfo | true |  执行队列中要结束回调的任务。 |  
    
 **示例代码：**   
```ts    
import workScheduler from '@ohos.resourceschedule.workScheduler';  
  
  export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {  
    onWorkStop(workInfo: workScheduler.WorkInfo) {  
        console.log('MyWorkSchedulerExtensionAbility onWorkStop' + JSON.stringify(workInfo));  
    }  
  }  
    
```    
  
