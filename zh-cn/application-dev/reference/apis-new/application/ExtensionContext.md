# ExtensionContext    
ExtensionContext是Extension的上下文环境，继承自Context。  
ExtensionContext模块提供访问特定Extension的资源的能力，对于拓展的Extension，可直接将ExtensionContext作为上下文环境，或者定义一个继承自ExtensionContext的类型作为上下文环境。如：ServiceExtension提供了ServiceExtensionContext，它在ExtensionContext的基础上扩展了启动、停止、绑定、解绑Ability的能力，详见[ServiceExtensionContext](js-apis-inner-application-serviceExtensionContext.md)。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ExtensionContext  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| currentHapModuleInfo | HapModuleInfo | false | true | 所属Hap包的信息。<br>(详见SDK目录下的 `api\bundle\hapModuleInfo.d.ts`) |  
| config | Configuration | false | true | 所属Module的配置信息。<br>(详见SDK目录下的 `api\nfiguration.d.ts`)。 |  
| extensionAbilityInfo | ExtensionAbilityInfo | false | true | 所属Extension的信息。<br>(详见SDK目录下的 `api\bundle\extensionAbilityInfo.d.ts`) |  
