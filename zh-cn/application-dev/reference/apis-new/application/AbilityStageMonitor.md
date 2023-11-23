# AbilityStageMonitor    
提供用于匹配满足指定条件的受监视的AbilityStage对象的方法。最近匹配的AbilityStage对象将保存在AbilityStageMonitor对象中。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import AbilityStageMonitor from 'AbilityStageMonitor'    
```  
    
## AbilityStageMonitor    
提供用于匹配满足指定条件的受监视的AbilityStage对象的方法。最近匹配的AbilityStage对象将保存在AbilityStageMonitor对象中。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| moduleName | string | false | true | 要监视的abilityStage的模块名。 |  
| srcEntrance | string | false | true | 要监视的abilityStage的源路径。 |  
    
 **示例代码：**   
```ts    
import common from '@ohos.app.ability.common';  
let context = getContext(this) as common.UIAbilityContext;  
let wantParam: Record<string, Object> = {  
  'time':'2023-10-23 20:45',  
};  
let abilityStartCallback: common.AbilityStartCallback = {  
  onError: (code, name, message) => {  
    console.log(`code:` + code + `name:` + name + `message:` + message);  
  }  
}  
context.startAbilityByType("photoEditor", wantParam, abilityStartCallback, (err) => {  
  if (err) {  
    console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);  
  } else {  
    console.log(`success`);  
  }  
});  
    
```    
  
