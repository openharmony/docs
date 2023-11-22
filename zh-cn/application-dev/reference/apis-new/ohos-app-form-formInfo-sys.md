# @ohos.app.form.formInfo    
formInfo模块提供了卡片信息和状态等相关类型和枚举。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import formInfo from '@ohos.app.form.formInfo'    
```  
    
## FormParam    
卡片参数枚举。    
    
 **系统能力:**  SystemCapability.Ability.Form    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEVICE_ID_KEY | ohos.extra.param.key.device_id | 设备标识。 <br>**系统API**: 此接口为系统接口，三方应用不支持调用。 |  
    
## FormProviderFilter<sup>(10+)</sup>    
卡片提供方信息。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form    
### 属性    
 **系统能力:**  SystemCapability.Ability.Form    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName<sup>(10+)</sup> | string | false | true | 提供方卡片所属包的Bundle名称。 |  
| formName<sup>(10+)</sup> | string | false | false | 卡片名称。 |  
| moduleName<sup>(10+)</sup> | string | false | false | 卡片所属模块的模块名称。 |  
| abilityName<sup>(10+)</sup> | string | false | false | 卡片所属的Ability名称。 |  
    
## RunningFormInfo<sup>(10+)</sup>    
卡片使用方信息  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form    
### 属性    
 **系统能力:**  SystemCapability.Ability.Form    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| formId<sup>(10+)</sup> | string | true | true | 卡片标识。 |  
| bundleName<sup>(10+)</sup> | string | true | true | 提供方卡片所属包的Bundle名称。 |  
| hostBundleName<sup>(10+)</sup> | string | true | true | 使用方卡片所属包的Bundle名称。 |  
| visibilityType<sup>(10+)</sup> | VisibilityType | true | true | 卡片当前可见类型枚举。 |  
| moduleName<sup>(10+)</sup> | string | true | true | 卡片所属模块的模块名称。 |  
| abilityName<sup>(10+)</sup> | string | true | true | 卡片所属的Ability名称。 |  
| formName<sup>(10+)</sup> | string | true | true | 卡片名称。 |  
| dimension<sup>(10+)</sup> | number | true | true | 卡片规格。 |  
