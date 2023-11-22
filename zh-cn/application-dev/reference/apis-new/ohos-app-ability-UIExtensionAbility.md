# @ohos.app.ability.UIExtensionAbility    
UIExtensionAbility是特定场景下带界面扩展能力的基类，继承自[ExtensionAbility](js-apis-app-ability-extensionAbility.md)，新增带界面扩展能力相关的属性和方法。不支持开发者直接继承该基类。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## UIExtensionAbility  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| context | UIExtensionContext | false | true | 上下文。 |  
    
### onCreate    
UIExtensionAbility创建时回调，执行初始化业务逻辑操作。  
 **调用形式：**     
- onCreate(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### onSessionCreate    
当UIExtensionAbility界面内容对象创建后调用。  
 **调用形式：**     
- onSessionCreate(want: Want, session: UIExtensionContentSession): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 当前UIExtensionAbility的Want类型信息，包括ability名称、bundle名称等。 |  
| session | UIExtensionContentSession | true | UIExtensionAbility界面内容相关信息。 |  
    
### onSessionDestroy    
当UIExtensionAbility界面内容对象销毁后调用。  
 **调用形式：**     
- onSessionDestroy(session: UIExtensionContentSession): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| session | UIExtensionContentSession | true | UIExtensionAbility界面内容相关信息。 |  
    
### onForeground  
 **调用形式：**     
- onForeground(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
### onBackground    
UIExtensionAbility生命周期回调，当UIExtensionAbility从前台转到后台时触发。  
 **调用形式：**     
- onBackground(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
### onDestroy    
UIExtensionAbility生命周期回调，在销毁时回调，执行资源清理等操作。 在执行完onDestroy生命周期回调后，应用可能会退出，从而可能导致onDestroy中的异步函数未能正确执行，比如异步写入数据库。可以使用异步生命周期，以确保异步onDestroy完成后再继续后续的生命周期。  
 **调用形式：**     
    
- onDestroy(): void | Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| void | Promise<void> |  |  
