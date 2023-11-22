# AbilityRunningInfo    
AbilityRunningInfo模块提供对Ability运行的相关信息和状态的定义。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import abilitymanager from '@ohos.app.ability.abilityManager';  
    
```  
    
## AbilityRunningInfo    
AbilityRunningInfo模块提供对Ability运行的相关信息和状态的定义。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ability | ElementName | false | true | Ability匹配信息 |  
| pid | number | false | true | 进程ID。 |  
| uid | number | false | true | 用户ID。 |  
| processName | string | false | true | 进程名称。 |  
| startTime | number | false | true | Ability启动时间。 |  
| abilityState | abilityManager.AbilityState | false | true | Ability状态。 |  
    
 **示例代码：**   
```ts    
import abilitymanager from '@ohos.app.ability.abilityManager';  
  
abilitymanager.getAbilityRunningInfos((error, data) => {   
    if (error) {  
        console.error(`getAbilityRunningInfos fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getAbilityRunningInfos success, data: ${JSON.stringify(data)}`);  
        for (let i = 0; i < data.length; i++) {  
            let abilityinfo = data[i];  
            console.log(`abilityinfo.ability: ${JSON.stringify(abilityinfo.ability)}`);  
            console.log(`abilityinfo.pid: ${JSON.stringify(abilityinfo.pid)}`);  
            console.log(`abilityinfo.uid: ${JSON.stringify(abilityinfo.uid)}`);  
            console.log(`abilityinfo.processName: ${JSON.stringify(abilityinfo.processName)}`);  
            console.log(`abilityinfo.startTime: ${JSON.stringify(abilityinfo.startTime)}`);  
            console.log(`abilityinfo.abilityState: ${JSON.stringify(abilityinfo.abilityState)}`);  
        }  
    }  
});  
    
```    
  
