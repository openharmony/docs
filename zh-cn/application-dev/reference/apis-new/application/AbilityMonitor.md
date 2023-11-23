# AbilityMonitor    
AbilityMonitor模块提供匹配满足指定条件的受监视能力对象的方法的能力，最近匹配的ability对象将保存在AbilityMonitor对象中。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import AbilityMonitor from 'AbilityMonitor'    
```  
    
## AbilityMonitor    
Ability监听器。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| abilityName | string | false | true | 当前AbilityMonitor绑定的ability名称 |  
| moduleName | string | false | false | 当前AbilityMonitor绑定的模块名称 |  
| onAbilityCreate | (ability: UIAbility) => void | false | false | ability被启动初始化时的回调函数<br/>不设置该属性则不能收到该生命周期回调 |  
| onAbilityForeground | (ability: UIAbility) => void | false | false | ability状态变成前台时的回调函数<br/>不设置该属性则不能收到该生命周期回调 |  
| onAbilityBackground | (ability: UIAbility) => void | false | false | ability状态变成后台时的回调函数<br/>不设置该属性则不能收到该生命周期回调 |  
| onAbilityDestroy | (ability: UIAbility) => void | false | false | ability被销毁前的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/> |  
| onWindowStageCreate | (ability: UIAbility) => void | false | false | window stage被创建时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/> |  
| onWindowStageRestore | (ability: UIAbility) => void | false | false | window stage被重载时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/> |  
| onWindowStageDestroy | (ability: UIAbility) => void | false | false | window stage被销毁前的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>。 |  
    
 **示例代码：**   
```null    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import { BusinessError } from '@ohos.base';  
  
function onAbilityCreateCallback(data: UIAbility) {  
    console.info(`onAbilityCreateCallback, data: ${JSON.stringify(data)}`);  
}  
  
let monitor: AbilityDelegatorRegistry.AbilityMonitor = {  
    abilityName: 'abilityname',  
    moduleName: "moduleName",  
    onAbilityCreate: onAbilityCreateCallback  
}  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
abilityDelegator.addAbilityMonitor(monitor, (error : BusinessError) => {  
    if (error) {  
        console.error(`addAbilityMonitor fail, error: ${JSON.stringify(error)}`);  
    }  
});  
    
```    
  
