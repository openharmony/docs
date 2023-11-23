# @ohos.InputMethodExtensionContext    
InputMethodExtensionContext模块是InputMethodExtensionAbility的上下文环境，继承于ExtensionContext，提供InputMethodExtensionAbility具有的能力和接口，包括启动、停止、绑定、解绑Ability。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## InputMethodExtensionContext  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### destroy    
销毁输入法应用。使用异步回调。  
 **调用形式：**     
    
- destroy(callback: AsyncCallback\<void>): void    
起始版本： 9    
- destroy(): Promise\<void>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当销毁输入法应用成功时，err为undefined；否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
