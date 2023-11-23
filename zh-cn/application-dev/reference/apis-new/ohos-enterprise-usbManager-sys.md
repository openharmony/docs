# @ohos.enterprise.usbManager    
本模块提供USB管理能力。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import usbManager from '@ohos.enterprise.usbManager'    
```  
    
## UsbPolicy    
USB读写策略的枚举。    
    
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| READ_WRITE | 0 | 可读可写。 |  
| READ_ONLY | 1 | 只读。 |  
    
## setUsbPolicy    
指定设备管理应用设置USB的读写策略。  
 **调用形式：**     
    
- setUsbPolicy(admin: Want, usbPolicy: UsbPolicy, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setUsbPolicy(admin: Want, usbPolicy: UsbPolicy): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。 |  
| usbPolicy | UsbPolicy | true | USB读写策略。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当指定设备管理应用设置USB策略失败时抛出错误对象。 |  
    
    
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
import Want from '@ohos.app.ability.Want';let wantTemp: Want = {  bundleName: 'bundleName',  abilityName: 'abilityName',};let policy: usbManager.UsbPolicy = usbManager.UsbPolicy.READ_WRITE  
usbManager.setUsbPolicy(wantTemp, policy, (err) => {  if (err) {    console.error(`Failed to set usb policy. Code is ${err.code}, message is ${err.message}`);    return;  }  console.info('Succeeded in setting usb policy');})    
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
let policy: usbManager.UsbPolicy = usbManager.UsbPolicy.READ_WRITE  
  
usbManager.setUsbPolicy(wantTemp, policy).then(() => {  
  console.info('Succeeded in setting usb policy');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to set usb policy. Code is ${err.code}, message is ${err.message}`);  
})  
    
```    
  
