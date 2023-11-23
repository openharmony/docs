# @ohos.enterprise.deviceSettings    
本模块提供企业设备设置能力，包括获取设备息屏时间等。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import deviceSettings from '@ohos.enterprise.deviceSettings'    
```  
    
## CertBlob    
证书信息。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
### 属性    
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| inData | Uint8Array | false | true | 证书的二进制内容。  |  
| alias | string | false | true | 证书别名。  |  
    
## getScreenOffTime    
指定设备管理应用获取设备息屏时间  
 **调用形式：**     
    
- getScreenOffTime(admin: Want, callback: AsyncCallback\<number>): void    
起始版本： 10    
- getScreenOffTime(admin: Want): Promise\<number>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_GET_SETTINGS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。       |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，data为设备息屏时间，否则err为错误对象。 |  
| Promise<number> | Promise对象，返回设备息屏时间。 |  
    
    
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
  
deviceSettings.getScreenOffTime(wantTemp, (err, result) => {  
  if (err) {  
    console.error(`Failed to get screen off time. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in getting screen off time, result : ${result}`);  
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
  
deviceSettings.getScreenOffTime(wantTemp).then((result) => {  
  console.info(`Succeeded in getting screen off time, result : ${result}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to get screen off time. Code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## installUserCertificate    
指定设备管理应用安装用户证书  
 **调用形式：**     
    
- installUserCertificate(admin: Want, certificate: CertBlob, callback: AsyncCallback\<string>): void    
起始版本： 10    
- installUserCertificate(admin: Want, certificate: CertBlob): Promise\<string>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。               。 |  
| certificate | CertBlob | true | 证书信息。              |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当接口调用成功，err为null，否则为错误对象。 |  
| Promise<string> | Promise对象，返回当前证书安装后的uri，用于卸载证书。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 9201001 | manage certificate failed |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
let certFileArray: Uint8Array = new Uint8Array();  
// The variable context needs to be initialized in MainAbility's onCreate callback function  
// test.cer needs to be placed in the rawfile directory  
getContext().resourceManager.getRawFileContent("test.cer").then((value) => {  
  certFileArray = value;  
  deviceSettings.installUserCertificate(wantTemp, { inData: certFileArray, alias: "cert_alias_xts" }, (err, result) => {  
    if (err) {  
      console.error(`Failed to install user certificate. Code: ${err.code}, message: ${err.message}`);  
    } else {  
      console.info(`Succeeded in installing user certificate, result : ${JSON.stringify(result)}`);  
    }  
  });  
}).catch((error: BusinessError) => {  
  console.error(`Failed to get row file content. message: ${error.message}`);  
  return  
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
let certFileArray: Uint8Array = new Uint8Array();  
// The variable context needs to be initialized in MainAbility's onCreate callback function  
// test.cer needs to be placed in the rawfile directory  
getContext().resourceManager.getRawFileContent("test.cer").then((value) => {  
  certFileArray = value  
  deviceSettings.installUserCertificate(wantTemp, { inData: certFileArray, alias: "cert_alias_xts" })  
    .then((result) => {  
      console.info(`Succeeded in installing user certificate, result : ${JSON.stringify(result)}`);  
    }).catch((err: BusinessError) => {  
    console.error(`Failed to install user certificate. Code: ${err.code}, message: ${err.message}`);  
  })  
}).catch((error: BusinessError) => {  
  console.error(`Failed to get row file content. message: ${error.message}`);  
  return  
});  
    
```    
  
    
## uninstallUserCertificate    
指定设备管理应用卸载用户证书  
 **调用形式：**     
    
- uninstallUserCertificate(admin: Want, certUri: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- uninstallUserCertificate(admin: Want, certUri: string): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。       |  
| certUri | string | true | 证书uri，由安装用户证书接口返回。        |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当指定设备管理应用卸载用户证书失败时会抛出错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 9201001 | manage certificate failed |  
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
let aliasStr = "certName"  
deviceSettings.uninstallUserCertificate(wantTemp, aliasStr, (err) => {  
  if (err) {  
    console.error(`Failed to uninstall user certificate. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in uninstalling user certificate`);  
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
let aliasStr = "certName"  
deviceSettings.uninstallUserCertificate(wantTemp, aliasStr).then(() => {  
  console.info(`Succeeded in uninstalling user certificate`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to uninstall user certificate. Code is ${err.code}, message is ${err.message}`);  
});  
    
```    
  
