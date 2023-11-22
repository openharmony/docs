# @ohos.enterprise.dateTimeManager    
本模块提供系统时间管理能力。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import dateTimeManager from '@ohos.enterprise.dateTimeManager'    
```  
    
## setDateTime    
指定设备管理应用设置系统时间。  
 **调用形式：**     
    
- setDateTime(admin: Want, time: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setDateTime(admin: Want, time: number): Promise\<void>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_DATETIME    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。  |  
| time | number | true | 时间戳(ms)。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import Want from '@ohos.app.ability.Want';  
let wantTemp: Want = {  
  bundleName: 'bundleName',  
  abilityName: 'abilityName',  
};  
  
dateTimeManager.setDateTime(wantTemp, 1526003846000, (err) => {  
  if (err) {  
    console.error(`Failed to set date time. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('Succeeded in setting date time');  
})    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'bundleName',  
  abilityName: 'abilityName',  
};  
  
dateTimeManager.setDateTime(wantTemp, 1526003846000).then(() => {  
  console.info('Succeeded in setting date time');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to set date time. Code is ${err.code}, message is ${err.message}`);  
})  
    
```    
  
    
## disallowModifyDateTime<sup>(10+)</sup>    
指定设备管理应用禁止设备修改系统时间。  
 **调用形式：**     
    
- disallowModifyDateTime(admin: Want, disallow: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- disallowModifyDateTime(admin: Want, disallow: boolean): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_DATETIME    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。  |  
| disallow | boolean | true |  true 表示禁止修改系统时间，false表示允许修改系统时间。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当指定设备管理应用禁止设备修改系统时间失败时，抛出错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import Want from '@ohos.app.ability.Want';  
let wantTemp: Want = {  
  bundleName: 'bundleName',  
  abilityName: 'abilityName',  
};  
  
dateTimeManager.disallowModifyDateTime(wantTemp, true, (err) => {  
  if (err) {  
    console.error(`Failed to disallow modify date time. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('Succeeded in disallowing modify date time');  
})    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'bundleName',  
  abilityName: 'abilityName',  
};  
  
dateTimeManager.disallowModifyDateTime(wantTemp, true).then(() => {  
  console.info('Succeeded in disallowing modify date time');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to disallow modify date time. Code is ${err.code}, message is ${err.message}`);  
})  
    
```    
  
    
## isModifyDateTimeDisallowed<sup>(10+)</sup>    
指定设备管理应用查询设备是否允许修改系统时间。  
 **调用形式：**     
    
- isModifyDateTimeDisallowed(admin: Want, callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- isModifyDateTimeDisallowed(admin: Want): Promise\<boolean>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_DATETIME    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，callbac方式返回是否禁止修改系统时间策略，true表示禁止修改系统时间，否则表示允许修改系统时间。 |  
| Promise<boolean> | Promise对象。promise方式返回是否禁止修改系统时间策略，true表示禁止修改系统时间，否则表示允许修改系统时间。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import Want from '@ohos.app.ability.Want';  
let wantTemp: Want = {  
  bundleName: 'bundleName',  
  abilityName: 'abilityName',  
};  
  
dateTimeManager.isModifyDateTimeDisallowed(wantTemp, (err, result) => {  
  if (err) {  
    console.error(`Failed to query modify date time is disallowed or not. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in querying modify date time is disallowed : ${result}`);  
})    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'bundleName',  
  abilityName: 'abilityName',  
};  
  
dateTimeManager.isModifyDateTimeDisallowed(wantTemp).then((result) => {  
  console.info(`Succeeded in querying modify date time is disallowed : ${result}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to query modify date time is disallowed or not. Code is ${err.code}, message is ${err.message}`);  
})  
    
```    
  
