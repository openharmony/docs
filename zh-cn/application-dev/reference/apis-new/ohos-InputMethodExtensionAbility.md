# @ohos.InputMethodExtensionAbility    
本模块支持开发者自行开发输入法应用，以及管理输入法应用的生命周期。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## InputMethodExtensionAbility  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| context | InputMethodExtensionContext | false | true | InputMethodExtension的上下文环境，继承于ExtensionContext。 |  
    
### onCreate    
Extension生命周期回调，在拉起Extension输入法应用时调用，执行初始化输入法应用操作。  
 **调用形式：**     
- onCreate(want: Want): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import InputMethodExtensionAbility from '@ohos.InputMethodExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
class InputMethodExt extends InputMethodExtensionAbility {  
  onCreate(want: Want): void {  
    console.log('onCreate, want:' + want.abilityName);  
  }  
}  
    
```    
  
    
### onDestroy    
Extension生命周期回调，在销毁输入法应用时回调，执行资源清理等操作。  
 **调用形式：**     
- onDestroy(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import InputMethodExtensionAbility from '@ohos.InputMethodExtensionAbility';  
class InputMethodExt extends InputMethodExtensionAbility {  
  onDestroy(): void {  
    console.log('onDestroy');  
  }  
}  
    
```    
  
