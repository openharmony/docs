# @ohos.app.ability.abilityDelegatorRegistry    
AbilityDelegatorRegistry是[自动化测试框架使用指南](../../application-test/arkxtest-guidelines.md)模块，该模块用于获取[AbilityDelegator](js-apis-inner-application-abilityDelegator.md)和[AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md)对象，其中[AbilityDelegator](js-apis-inner-application-abilityDelegator.md)对象提供添加用于监视指定ability的生命周期状态更改的AbilityMonitor对象的能力，[AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md)对象提供获取当前测试参数的能力。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import abilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry'    
```  
    
## getAbilityDelegator    
获取应用程序的[AbilityDelegator](js-apis-inner-application-abilityDelegator.md)对象，该对象能够使用调度测试框架的相关功能。  
 **调用形式：**     
- getAbilityDelegator(): AbilityDelegator  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AbilityDelegator |  |  
    
 **示例代码：**   
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
import Want from '@ohos.app.ability.Want';  
  
let abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
  
let want: Want = {  
    bundleName: 'com.example.myapplication',  
    abilityName: 'EntryAbility'  
};  
abilityDelegator.startAbility(want, (err) => {  
    if (err) {  
        console.error(`Failed start ability, error: ${JSON.stringify(err)}`);  
    } else {  
        console.log('Success start ability.');  
    }  
});  
    
```    
  
    
## getArguments    
获取单元测试参数[AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md)对象。  
 **调用形式：**     
- getArguments(): AbilityDelegatorArgs  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AbilityDelegatorArgs |  |  
    
 **示例代码：**   
```ts    
<span style="letter-spacing: 0px;">import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';</span>  
  
let args = AbilityDelegatorRegistry.getArguments();console.info(`getArguments bundleName: ${args.bundleName}`);console.info(`getArguments parameters: ${JSON.stringify(args.parameters)}`);console.info(`getArguments testCaseNames: ${args.testCaseNames}`);console.info(`getArguments testRunnerClassName: ${args.testRunnerClassName}`);    
```    
  
    
## AbilityLifecycleState    
Ability生命周期状态，该类型为枚举，可配合[AbilityDelegator](js-apis-inner-application-abilityDelegator.md)的[getAbilityState(ability)](js-apis-inner-application-abilityDelegator.md#getabilitystate9)方法返回不同ability生命周期。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNINITIALIZED | 0 | 表示Ability处于无效状态。 |  
| CREATE | 1 | 表示Ability处于已创建状态。 |  
| FOREGROUND | 2 | 表示Ability处于前台状态。 |  
| BACKGROUND | 3 | 表示Ability处于后台状态。  |  
| DESTROY | 4 | 表示Ability处于已销毁状态。 |  
