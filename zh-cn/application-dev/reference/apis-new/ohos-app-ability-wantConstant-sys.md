# @ohos.app.ability.wantConstant    
wantConstant模块提供want中操作want常数和解释Flags说明的能力。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import wantConstant from '@ohos.app.ability.wantConstant'    
```  
    
## Params    
want的Params操作的常量。    
    
 **系统能力:**  SystemCapability.Ability.AbilityBase    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DLP_PARAMS_SANDBOX | ohos.dlp.params.sandbox | 指示沙盒标志的参数的操作。<br>**系统API**：该接口为系统接口，三方应用不支持调用。 |  
| DLP_PARAMS_BUNDLE_NAME | ohos.dlp.params.bundleName | 指示DLP Bundle名称的参数的操作。 <br>**系统API**：该接口为系统接口，三方应用不支持调用。 |  
| DLP_PARAMS_MODULE_NAME | ohos.dlp.params.moduleName | 指示DLP模块名称的参数的操作。 <br>**系统API**：该接口为系统接口，三方应用不支持调用。 |  
| DLP_PARAMS_ABILITY_NAME | ohos.dlp.params.abilityName | 指示DLP能力名称的参数的操作。 <br>**系统API**：该接口为系统接口，三方应用不支持调用。 |  
| DLP_PARAMS_INDEX | ohos.dlp.params.index | 指示DLP索引参数的操作。 <br>**系统API**：该接口为系统接口，三方应用不支持调用。 |  
    
## Flags    
Flags说明。用于表示处理Want的方式。    
    
 **系统能力:**  SystemCapability.Ability.AbilityBase    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION<sup>(10+)</sup> | 0x00000040 | 仅对PC应用有效，指示对URI进行永久授权。<br>**系统API**：该接口为系统接口，三方应用不支持调用。<br>当其与FLAG_AUTH_READ_URI_PERMISSION结合，表示授予永久读权限；<br>当其与FLAG_AUTH_WRITE_URI_PERMISSION结合表示授予永久写权限。<br>应用需配置PERMISSION_PROXY_AUTHORIZATION_URI权限该flag才会生效，否则将忽略。 |  
