# @ohos.app.ability.ApplicationStateChangeCallback    
ApplicationStateChangeCallback模块提供应用上下文ApplicationContext对当前应用前后台变化监听回调的能力，包括onApplicationForeground、onApplicationBackground方法。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ApplicationStateChangeCallback  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
### onApplicationForeground    
注册当前应用前后台变化的监听后，在当前应用从后台切换到前台时触发回调。  
 **调用形式：**     
- onApplicationForeground(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import ApplicationStateChangeCallback from '@ohos.app.ability.ApplicationStateChangeCallback';  
  
let applicationStateChangeCallback: ApplicationStateChangeCallback = {  
    onApplicationForeground() {  
        console.info('applicationStateChangeCallback onApplicationForeground');  
    },  
    onApplicationBackground() {  
        console.info('applicationStateChangeCallback onApplicationBackground');  
    }  
}  
  
export default class MyAbility extends UIAbility {  
    onCreate() {  
        console.log('MyAbility onCreate');  
        // 1.获取applicationContext  
        let applicationContext = this.context.getApplicationContext();  
        // 2.通过applicationContext注册应用前后台状态监听  
        if (applicationContext != undefined) {  
            applicationContext.on('applicationStateChange', applicationStateChangeCallback);  
        }  
    }  
    onDestroy() {  
        let applicationContext = this.context.getApplicationContext();  
        // 1.通过applicationContext解除注册应用前后台状态监听  
        if (applicationContext != undefined) {  
            applicationContext.off('applicationStateChange', applicationStateChangeCallback);  
        }  
    }  
}  
    
```    
  
    
### onApplicationBackground    
注册当前应用前后台变化的监听后，在当前应用从前台切换到后台时触发回调。  
 **调用形式：**     
- onApplicationBackground(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import ApplicationStateChangeCallback from '@ohos.app.ability.ApplicationStateChangeCallback';  
  
let applicationStateChangeCallback: ApplicationStateChangeCallback = {  
    onApplicationForeground() {  
        console.info('applicationStateChangeCallback onApplicationForeground');  
    },  
    onApplicationBackground() {  
        console.info('applicationStateChangeCallback onApplicationBackground');  
    }  
}  
  
export default class MyAbility extends UIAbility {  
    onCreate() {  
        console.log('MyAbility onCreate');  
        // 1.获取applicationContext  
        let applicationContext = this.context.getApplicationContext();  
        // 2.通过applicationContext注册应用前后台状态监听  
        if (applicationContext != undefined) {  
            applicationContext.on('applicationStateChange', applicationStateChangeCallback);  
        }  
        console.log('Resgiter applicationStateChangeCallback');  
    }  
    onDestroy() {  
        let applicationContext = this.context.getApplicationContext();  
        // 1.通过applicationContext解除注册应用前后台状态监听  
        if (applicationContext != undefined) {  
            applicationContext.off('applicationStateChange', applicationStateChangeCallback);  
        }  
    }  
}  
    
```    
  
