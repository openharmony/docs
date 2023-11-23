# abilityDelegatorArgs    
AbilityDelegatorArgs模块提供在应用程序执行测试用例期间，获取测试用例参数AbilityDelegatorArgs对象的能力。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import AbilityDelegatorArgs from 'abilityDelegatorArgs'    
```  
    
## AbilityDelegatorArgs    
测试参数信息。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | false | true | 当前被测试应用的包名 |  
| parameters | object | false | true | 当前启动单元测试的参数 |  
| testCaseNames | string | false | true | 测试用例名称。 |  
| testRunnerClassName | string | false | true | 执行测试用例的测试执行器名称 |  
