# @ohos.enterprise.deviceInfo    
本模块提供企业设备信息管理能力，包括获取设备序列号等。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import deviceInfo from '@ohos.enterprise.deviceInfo'    
```  
    
## getDeviceSerial    
指定设备管理应用获取设备序列号  
 **调用形式：**     
    
- getDeviceSerial(admin: Want, callback: AsyncCallback\<string>): void    
起始版本： 10    
- getDeviceSerial(admin: Want): Promise\<string>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_GET_DEVICE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。                   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，data为设备序列号，否则err为错误对象。 |  
| Promise<string> | Promise对象，返回设备序列号。 |  
    
    
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
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
deviceInfo.getDeviceSerial(wantTemp, (err, result) => {  
  if (err) {  
    console.error(`Failed to get device serial. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in getting device serial, result : ${result}`);  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
deviceInfo.getDeviceSerial(wantTemp).then((result) => {  
  console.info(`Succeeded in getting device serial, result : ${result}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to get device serial. Code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## getDisplayVersion    
指定设备管理应用获取设备版本号  
 **调用形式：**     
    
- getDisplayVersion(admin: Want, callback: AsyncCallback\<string>): void    
起始版本： 10    
- getDisplayVersion(admin: Want): Promise\<string>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_GET_DEVICE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，data为设备版本号，否则err为错误对象。 |  
| Promise<string> | Promise对象，返回设备版本号。 |  
    
    
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
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
deviceInfo.getDisplayVersion(wantTemp, (err, result) => {  
  if (err) {  
    console.error(`Failed to get display version. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in getting display version, result : ${result}`);  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
deviceInfo.getDisplayVersion(wantTemp).then((result) => {  
  console.info(`Succeeded in getting display version, result : ${result}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to get display version. Code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## getDeviceName    
指定设备管理应用获取设备名称  
 **调用形式：**     
    
- getDeviceName(admin: Want, callback: AsyncCallback\<string>): void    
起始版本： 10    
- getDeviceName(admin: Want): Promise\<string>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_GET_DEVICE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，data为设备名称，否则err为错误对象。 |  
| Promise<string> | Promise结果，返回设备名称。 |  
    
    
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
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
deviceInfo.getDeviceName(wantTemp, (err, result) => {  
  if (err) {  
    console.error(`Failed to get device name. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in getting device name, result : ${result}`);  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
deviceInfo.getDeviceName(wantTemp).then((result) => {  
  console.info(`Succeeded in getting device name, result : ${result}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to get device name. Code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
