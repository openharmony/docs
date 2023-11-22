# @ohos.application.StaticSubscriberExtensionAbility    
StaticSubscriberExtensionAbility模块提供静态订阅者ExtensionAbility的类别的能力。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## StaticSubscriberExtensionAbility    
StaticSubscriberExtensionAbility模块提供静态订阅者ExtensionAbility的类别的能力。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| context<sup>(10+)</sup> | StaticSubscriberExtensionContext | false | true | 上下文。 |  
    
### onReceiveEvent    
静态订阅者通用事件回调。  
 **调用形式：**     
- onReceiveEvent(event: CommonEventData): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | CommonEventData | true | 静态订阅者通用事件回调。 |  
    
 **示例代码：**   
```ts    
import StaticSubscriberExtensionAbility from '@ohos.application.StaticSubscriberExtensionAbility';  
  import CommonEventManager from '@ohos.commonEventManager';  
  
    class MyStaticSubscriberExtensionAbility extends StaticSubscriberExtensionAbility {  
        onReceiveEvent(event: CommonEventManager.CommonEventData) {  
            console.log(`onReceiveEvent, event: ${JSON.stringify(event)}`);  
        }  
    }  
    
```    
  
