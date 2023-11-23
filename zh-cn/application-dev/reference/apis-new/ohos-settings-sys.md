# @ohos.settings    
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import settings from '@ohos.settings'    
```  
    
## setValue<sup>(deprecated)</sup>    
将数据项名称及数据项的值保存到数据库中。将数据项名称及数据项的值保存到数据库中。使用callback异步回调。  
 **调用形式：**     
- setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.settings#setValue。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Applications.settings.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataAbilityHelper<sup>(deprecated)</sup> | DataAbilityHelper | true | 数据管理辅助类。  |  
| name<sup>(deprecated)</sup> | string | true | 数据项的名称。数据项名称分为以下两种：<br>- 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |  
| value<sup>(deprecated)</sup> | object | true | 数据项值。取值范围随业务变动。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。返回true表示操作成功，否则操作失败。   |  
    
## setValue<sup>(deprecated)</sup>    
将数据项名称及数据项的值保存到数据库中。使用Promise异步回调。  
 **调用形式：**     
- setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.settings#setValue。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Applications.settings.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataAbilityHelper<sup>(deprecated)</sup> | DataAbilityHelper | true | 数据管理辅助类。 |  
| name<sup>(deprecated)</sup> | string | true | 数据项的名称。数据项名称分为以下两种：<br>- 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |  
| value<sup>(deprecated)</sup> | object | true | 数据项值。取值范围随业务变动。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示操作成功，否则返回false。 |  
