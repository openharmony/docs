# BaseContext    
BaseContext抽象类用于表示继承的子类Context是Stage模型还是FA模型，是所有Context类型的父类。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import common from '@ohos.app.ability.common';  
    
```  
    
## BaseContext    
。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| stageMode | boolean | false | true | 表示是否Stage模型。<br>true：Stage模型<br>false：FA模型。 |  
