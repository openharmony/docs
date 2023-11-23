# @ohos.application.abilityDelegatorRegistry    
AbilityDelegatorRegistry模块提供用于存储已注册的AbilityDelegator和AbilityDelegatorArgs对象的全局寄存器的能力，包括获取应用程序的AbilityDelegator对象、获取单元测试参数AbilityDelegatorArgs对象。该模块中的接口只能用于测试框架中。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import abilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'    
```  
    
## getAbilityDelegator<sup>(deprecated)</sup>    
获取应用程序的AbilityDelegator对象。  
 **调用形式：**     
- getAbilityDelegator(): AbilityDelegator  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.abilityDelegatorRegistry/abilityDelegatorRegistry#getAbilityDelegator。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AbilityDelegator | [AbilityDelegator](js-apis-inner-application-abilityDelegator.md#AbilityDelegator)对象。可以用来调度测试框架相关功能。 |  
    
 **示例代码：**   
```ts    
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry';let abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();    
```    
  
    
## getArguments<sup>(deprecated)</sup>  
 **调用形式：**     
- getArguments(): AbilityDelegatorArgs  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.abilityDelegatorRegistry/abilityDelegatorRegistry#getArguments。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AbilityDelegatorArgs | 获取单元测试参数AbilityDelegatorArgs对象 |  
    
 **示例代码：**   
```ts    
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry';  
let args = AbilityDelegatorRegistry.getArguments();console.info('getArguments bundleName: ${args.bundleName}');console.info('getArguments testCaseNames: ${args.testCaseNames}');console.info('getArguments testRunnerClassName: ${args.testRunnerClassName}');    
```    
  
    
## AbilityLifecycleState<sup>(deprecated)</sup>    
Ability生命周期状态。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.abilityDelegatorRegistry/abilityDelegatorRegistry#AbilityLifecycleState替代。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNINITIALIZED<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.abilityDelegatorRegistry/abilityDelegatorRegistry.AbilityLifecycleState替代。<br>表示无效状态。 |  
| CREATE<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.abilityDelegatorRegistry/abilityDelegatorRegistry.AbilityLifecycleState#CREATE替代。<br>表示Ability处于已创建状态。 |  
| FOREGROUND<sup>(deprecated)</sup> | 2 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.abilityDelegatorRegistry/abilityDelegatorRegistry.AbilityLifecycleState#FOREGROUND替代。<br>表示Ability处于前台状态。 |  
| BACKGROUND<sup>(deprecated)</sup> | 3 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.abilityDelegatorRegistry/abilityDelegatorRegistry.AbilityLifecycleState#BACKGROUND替代。<br>表示Ability处于后台状态。 |  
| DESTROY<sup>(deprecated)</sup> | 4 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.abilityDelegatorRegistry/abilityDelegatorRegistry.AbilityLifecycleState#DESTROY替代。<br>表示Ability处于已销毁状态。 |  
