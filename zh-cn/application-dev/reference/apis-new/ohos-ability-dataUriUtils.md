# @ohos.ability.dataUriUtils    
DataUriUtils模块提供用于处理uri对象的能力，包括获取、绑定、删除和更新指定uri对象的路径末尾的ID。本模块将被app.ability.dataUriUtils模块替代，建议优先使用[taUriUtils](js-apis-app-ability-dataUriUtils.md)模块。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import dataUriUtils from '@ohos.ability.dataUriUtils'    
```  
    
## getId<sup>(deprecated)</sup>    
获取指定uri路径末尾的ID。  
 **调用形式：**     
- getId(uri: string): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.dataUriUtils/dataUriUtils#getId。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | true | 表示uri对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回uri路径末尾的ID。 |  
    
 **示例代码：**   
```ts    
import dataUriUtils from '@ohos.ability.dataUriUtils';let id = dataUriUtils.getId('com.example.dataUriUtils/1221');    
```    
  
    
## attachId<sup>(deprecated)</sup>    
将ID附加到uri的路径末尾。  
 **调用形式：**     
- attachId(uri: string, id: number): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.dataUriUtils/dataUriUtils#attachId。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | true | 表示uri对象。 |  
| id<sup>(deprecated)</sup> | number | true | 表示要附加的ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回附加ID之后的uri对象。 |  
    
 **示例代码：**   
```ts    
import dataUriUtils from '@ohos.ability.dataUriUtils';  
let id = 1122;let uri = dataUriUtils.attachId(    'com.example.dataUriUtils',id,);    
```    
  
    
## deleteId<sup>(deprecated)</sup>    
删除指定uri路径末尾的ID。  
 **调用形式：**     
- deleteId(uri: string): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.dataUriUtils/dataUriUtils#deleteId。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | true | 表示要从中删除ID的uri对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回删除ID之后的uri对象。 |  
    
 **示例代码：**   
```ts    
import dataUriUtils from '@ohos.ability.dataUriUtils';let uri = dataUriUtils.deleteId('com.example.dataUriUtils/1221');    
```    
  
    
## updateId<sup>(deprecated)</sup>    
更新指定uri中的ID。  
 **调用形式：**     
- updateId(uri: string, id: number): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.dataUriUtils/dataUriUtils#updateId。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | true | 表示uri对象 。 |  
| id<sup>(deprecated)</sup> | number | true | 表示要更新的ID |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回更新ID之后的uri对象。 |  
    
 **示例代码：**   
```ts    
import dataUriUtils from '@ohos.ability.dataUriUtils';  
let id = 1122;let uri = dataUriUtils.updateId(    'com.example.dataUriUtils/1221',id);    
```    
  
