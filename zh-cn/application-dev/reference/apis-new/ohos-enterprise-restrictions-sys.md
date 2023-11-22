# @ohos.enterprise.restrictions    
本模块提供设置通用限制类策略能力，包括禁用或启用设备打印、HDC等能力。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import restrictions from '@ohos.enterprise.restrictions'    
```  
    
## setPrinterDisabled    
指定设备管理应用使设备禁用或启用打印能力。  
 **调用形式：**     
    
- setPrinterDisabled(admin: Want, disabled: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setPrinterDisabled(admin: Want, disabled: boolean): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_RESTRICT_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。  |  
| disabled | boolean | true | true表示禁止使用打印能力，false表示允许使用打印能力。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当指定设备管理应用禁止或允许使用打印能力失败时抛出错误对象。 |  
    
    
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
  
restrictions.setPrinterDisabled(wantTemp, true, (err) => {  
  if (err) {  
    console.error(`Failed to set printer disabled. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('Succeeded in setting printer disabled');  
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
  
restrictions.setPrinterDisabled(wantTemp, true).then(() => {  
  console.info('Succeeded in setting printer disabled');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to set printer disabled. Code is ${err.code}, message is ${err.message}`);  
})  
    
```    
  
    
## isPrinterDisabled    
指定设备管理应用查询设备打印能力是否被禁用。  
 **调用形式：**     
    
- isPrinterDisabled(admin: Want, callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- isPrinterDisabled(admin: Want): Promise\<boolean>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_RESTRICT_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，callback方式返回设备打印能力是否被禁用，true表示设备打印能力被禁用，false表示设备打印能力未被禁用。 |  
| Promise<boolean> | Promise对象。promise方式返回设备打印能力是否被禁用，true表示设备打印能力被禁用，false表示设备打印能力未被禁用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. | |  
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
  
restrictions.isPrinterDisabled(wantTemp, (err, result) => {  
  if (err) {  
    console.error(`Failed to query is the printing function disabled or not. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in querying is the printing function disabled : ${result}`);  
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
  
restrictions.isPrinterDisabled(wantTemp).then((result) => {  
  console.info(`Succeeded in querying is the printing function disabled : ${result}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to query is the printing function disabled or not. Code is ${err.code}, message is ${err.message}`);  
})  
    
```    
  
    
## setHdcDisabled    
指定设备管理应用使设备禁用或启用HDC。  
 **调用形式：**     
    
- setHdcDisabled(admin: Want, disabled: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setHdcDisabled(admin: Want, disabled: boolean): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_RESTRICT_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。  |  
| disabled | boolean | true | true表示禁止使用HDC，false表示允许使用HDC。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当指定设备管理应用禁止或允许使用HDC失败时，抛出错误对象。 |  
    
    
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
  
restrictions.setHdcDisabled(wantTemp, true, (err) => {  
  if (err) {  
    console.error(`Failed to set hdc disabled. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('Succeeded in setting hdc disabled');  
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
  
restrictions.setHdcDisabled(wantTemp, true).then(() => {  
  console.info('Succeeded in setting hdc disabled');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to set hdc disabled. Code is ${err.code}, message is ${err.message}`);  
})  
    
```    
  
    
## isHdcDisabled    
指定设备管理应用查询HDC是否被禁用。  
 **调用形式：**     
    
- isHdcDisabled(admin: Want, callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- isHdcDisabled(admin: Want): Promise\<boolean>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_RESTRICT_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，callbac方式返回HDC是否被禁用，true表示HDC被禁用，false表示HDC未被禁用。 |  
| Promise<boolean> | Promise对象。promise方式返回HDC是否被禁用，true表示HDC被禁用，false表示HDC未被禁用。 |  
    
    
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
  
restrictions.isHdcDisabled(wantTemp, (err, result) => {  
  if (err) {  
    console.error(`Failed to query is hdc disabled or not. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in querying is hdc disabled : ${result}`);  
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
  
restrictions.isHdcDisabled(wantTemp).then((result) => {  
  console.info(`Succeeded in querying is hdc disabled : ${result}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to query is hdc disabled or not. Code is ${err.code}, message is ${err.message}`);  
})  
    
```    
  
