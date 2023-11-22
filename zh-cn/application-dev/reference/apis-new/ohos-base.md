# @ohos.base    
本模块定义了OpenHarmony ArkTS接口的公共回调类型，包括接口调用时出现的公共回调和公共错误信息。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## Callback    
通用回调函数。开发者在使用时，可自定义data的类型，回调将返回对应类型的信息。  
 **系统能力:**  SystemCapability.Base    
### null  
 **调用形式：**     
- (data: T): void  
  
 **系统能力:**  SystemCapability.Base    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data | T | true | 接口调用时的公共回调信息。 |  
    
## ErrorCallback    
通用回调函数，携带错误参数。  
回调返回的信息为[BusinessError](#businesserror)类型的信息。  
 **系统能力:**  SystemCapability.Base    
### null  
 **调用形式：**     
- (err: T): void  
  
 **系统能力:**  SystemCapability.Base    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| err | T | true | 接口调用失败的公共错误信息。 |  
    
## AsyncCallback    
通用回调函数，携带错误参数和异步返回值。  
错误参数为[BusinessError](#businesserror)类型的信息。异步返回值的类型由开发者自定义，回调将返回对应类型的信息。  
 **系统能力:**  SystemCapability.Base    
### null  
 **调用形式：**     
- (err: BusinessError\<E>, data: T): void  
  
 **系统能力:**  SystemCapability.Base    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| err | BusinessError<E> | true | 接口调用失败的公共错误信息。 |  
| data | T | true | 接口调用时的公共回调信息。 |  
    
## BusinessError    
错误参数。  
 **系统能力:**  SystemCapability.Base    
### 属性    
 **系统能力:**  SystemCapability.Base    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| code | number | false | true | 接口调用失败返回的错误码信息。  |  
| data<sup>(9+)</sup> | T | false | false | 接口调用时的公共回调信息。如果不填，则回调不返回相关信息。 |  
