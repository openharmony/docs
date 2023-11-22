# @ohos.app.ability.AbilityStage    
AbilityStage是HAP的运行时类。  
  
AbilityStage类提供在HAP加载的时候，通知开发者，可以在此进行该HAP的初始化（如资源预加载，线程创建等）能力。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## AbilityStage  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| context | AbilityStageContext | false | true | 在Ability启动阶段进行初始化时回调，获取到该Ability的context值。 |  
    
### onCreate    
当应用创建时调用。  
 **调用形式：**     
- onCreate(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **示例代码：**   
```ts    
import AbilityStage from '@ohos.app.ability.AbilityStage';  
  
class MyAbilityStage extends AbilityStage {  
    onCreate() {  
        console.log('MyAbilityStage.onCreate is called');  
    }  
}  
    
```    
  
    
### onAcceptWant    
启动一个specified ability时触发的事件。  
 **调用形式：**     
- onAcceptWant(want: Want): string  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | Want类型参数，传入需要启动的ability的信息，如Ability名称，Bundle名称等。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回一个ability标识，如果之前启动过标识的ability，不创建新的实例并拉回栈顶，否则创建新的实例并启动。 |  
    
 **示例代码：**   
```ts    
import AbilityStage from '@ohos.app.ability.AbilityStage';  
import Want from '@ohos.app.ability.Want';  
  
class MyAbilityStage extends AbilityStage {  
    onAcceptWant(want: Want) {  
        console.log('MyAbilityStage.onAcceptWant called');  
        return 'com.example.test';  
    }  
}  
    
```    
  
    
### onConfigurationUpdate    
环境变化通知接口，发生全局配置变更时回调。  
 **调用形式：**     
- onConfigurationUpdate(newConfig: Configuration): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| newConfig | Configuration | true | 发生全局配置变更时触发回调，当前全局配置包括系统语言、深浅色模式。 |  
    
 **示例代码：**   
```ts    
import AbilityStage from '@ohos.app.ability.AbilityStage';  
import { Configuration } from '@ohos.app.ability.Configuration';  
  
class MyAbilityStage extends AbilityStage {  
    onConfigurationUpdate(config: Configuration) {  
        console.log('onConfigurationUpdate, language: ${config.language}');  
    }  
}  
    
```    
  
    
### onMemoryLevel    
当系统已决定调整内存时调用。例如，当该功能在后台运行时，没有足够的内存来运行尽可能多的后台进程时可以使用。  
 **调用形式：**     
- onMemoryLevel(level: AbilityConstant.MemoryLevel): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| level | AbilityConstant.MemoryLevel | true | 回调返回内存微调级别，显示当前内存使用状态。 |  
    
 **示例代码：**   
```ts    
import AbilityStage from '@ohos.app.ability.AbilityStage';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
  
class MyAbilityStage extends AbilityStage {  
    onMemoryLevel(level: AbilityConstant.MemoryLevel) {  
        console.log(`onMemoryLevel, level: ${JSON.stringify(level)}`);  
    }   
}  
    
```    
  
