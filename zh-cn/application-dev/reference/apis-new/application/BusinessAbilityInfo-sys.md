# BusinessAbilityInfo    
包含基本业务路由信息。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## BusinessAbilityInfo  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | true | true | 表示应用程序的bundleName。 |  
| moduleName | string | true | true | 表示应用程序的moduleName。 |  
| name | string | true | true | 业务路由ability名。 |  
| labelId | number | true | true | 模块标签的资源id。 |  
| descriptionId | number | true | true | 描述信息的资源id。 |  
| iconId | number | true | true | 描述ability信息的图标id。 |  
| businessType | businessAbilityRouter.BusinessType | true | true | 标识枚举业务类型。 |  
| applicationInfo | ApplicationInfo | true | true | 应用程序的信息。。 |  
