# @ohos.ability.wantConstant    
wantConstant模块提供want中操作want常数和解释Flags说明的能力。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import wantConstant from '@ohos.ability.wantConstant'    
```  
    
## Flags<sup>(deprecated)</sup>    
Flags说明。用于表示处理Want的方式。    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantConstant/wantConstant#Flags替代。    
    
 **系统能力:**  SystemCapability.Ability.AbilityBase    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION<sup>(deprecated)</sup> | 0x00000040 | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示URI上可能持久化的授权。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。 |  
| FLAG_AUTH_PREFIX_URI_PERMISSION<sup>(deprecated)</sup> | 0x00000080 | 从API version 6 开始支持，从API version 9 开始废弃。<br>按照前缀匹配的方式验证URI权限。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。 |  
| FLAG_ABILITY_CONTINUATION_REVERSIBLE<sup>(deprecated)</sup> | 0x00000400 | 从API version 6 开始支持，从API version 9 开始废弃。<br>表示迁移是可拉回的。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。  |  
