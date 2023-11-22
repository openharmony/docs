# @ohos.enterprise.bundleManager    
本模块提供包管理能力，包括添加包安装白名单、获取包安装白名单、移除包安装白名单等。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import bundleManager from '@ohos.enterprise.bundleManager'    
```  
    
## InstallParam    
应用包安装需指定的参数信息。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
### 属性    
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| userId | number | false | false | 指示用户id，默认值：调用方所在用户，取值范围：大于等于0。 |  
| installFlag | number | false | false | 安装标志。枚举值：0：应用初次安装，1：应用覆盖安装，2：应用免安装，默认值为应用初次安装。  |  
    
## addAllowedInstallBundles    
指定设备管理应用添加应用至包安装白名单，添加至白名单的应用允许在当前/指定用户下安装，否则不允许安装。  
 **调用形式：**     
    
- addAllowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- addAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- addAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。                |  
| appIds | Array<string> | true | 应用ID数组。                 |  
| userId | number | true | 用户ID，指定具体用户。取值范围：大于等于0。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当指定设备管理应用添加包安装白名单失败时，会抛出错误对象。 |  
    
    
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
let appIds: Array<string> = ['com.example.myapplication'];  
  
bundleManager.addAllowedInstallBundles(wantTemp, appIds, 100, (err) => {  
  if (err) {  
    console.error(`Failed to add allowed install bundles. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('Succeeded in adding allowed install bundles');  
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
let appIds: Array<string> = ['com.example.myapplication'];  
  
bundleManager.addAllowedInstallBundles(wantTemp, appIds, 100).then(() => {  
  console.info('Succeeded in adding allowed install bundles');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to add allowed install bundles. Code is ${err.code}, message is ${err.message}`);  
});  
    
```    
  
    
## removeAllowedInstallBundles    
指定设备管理应用在包安装白名单中移除应用，在白名单存在的情况下，不在包安装白名单中的应用不允许在当前/指定用户下安装。  
 **调用形式：**     
    
- removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。      |  
| appIds | Array<string> | true | 应用ID数组。       |  
| userId | number | true | 用户ID，取值范围：大于等于0。<br> - 调用接口时，若传入userId，表示指定用户。<br> - 调用接口时，若未传入userId，表示当前用户。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当指定设备管理应用移除包安装白名单失败时，会抛出错误对象。 |  
    
    
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
let appIds: Array<string> = ['com.example.myapplication'];  
  
bundleManager.removeAllowedInstallBundles(wantTemp, appIds, 100, (err) => {  
  if (err) {  
    console.error(`Failed to remove allowed install bundles. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('Succeeded in removing allowed install bundles');  
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
let appIds: Array<string> = ['com.example.myapplication'];  
  
bundleManager.removeAllowedInstallBundles(wantTemp, appIds, 100).then(() => {  
  console.info('Succeeded in removing allowed install bundles');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to remove allowed install bundles. Code is ${err.code}, message is ${err.message}`);  
});  
    
```    
  
    
## getAllowedInstallBundles    
指定设备管理应用获取当前/指定用户下的包安装白名单  
 **调用形式：**     
    
- getAllowedInstallBundles(admin: Want, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 10    
- getAllowedInstallBundles(admin: Want, userId: number, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 10    
- getAllowedInstallBundles(admin: Want, userId?: number): Promise\<Array\<string>>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。             |  
| userId | number | true | 用户ID，指定具体用户。取值范围：大于等于0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当接口调用成功，err为null，否则为错误对象。 |  
| Promise<Array<string>> | Promise对象，返回当前用户下的包安装白名单。 |  
    
    
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
  
bundleManager.getAllowedInstallBundles(wantTemp, 100, (err, result) => {  
  if (err) {  
    console.error(`Failed to get allowed install bundles. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in getting allowed install bundles, result : ${JSON.stringify(result)}`);  
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
  
bundleManager.getAllowedInstallBundles(wantTemp, 100).then((result) => {  
  console.info(`Succeeded in getting allowed install bundles, result : ${JSON.stringify(result)}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to get allowed install bundles. Code is ${err.code}, message is ${err.message}`);  
});  
    
```    
  
    
## addDisallowedInstallBundles    
指定设备管理应用添加应用至包安装黑名单，添加至黑名单的应用不允许在当前/指定用户下安装。  
 **调用形式：**     
    
- addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。                 |  
| appIds | Array<string> | true | 应用ID数组。              |  
| userId | number | true | 用户ID，指定具体用户。取值范围：大于等于0。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当指定设备管理应用添加包安装黑名单失败时，会抛出错误对象。 |  
    
    
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
let appIds: Array<string> = ['com.example.myapplication'];  
  
bundleManager.addDisallowedInstallBundles(wantTemp, appIds, 100, (err) => {  
  if (err) {  
    console.error(`Failed to add disallowed install bundles. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('Succeeded in adding disallowed install bundles');  
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
let appIds: Array<string> = ['com.example.myapplication'];  
  
bundleManager.addDisallowedInstallBundles(wantTemp, appIds, 100).then(() => {  
  console.info('Succeeded in adding disallowed install bundles');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to add disallowed install bundles. Code is ${err.code}, message is ${err.message}`);  
});  
    
```    
  
    
## removeDisallowedInstallBundles    
指定设备管理应用在包安装黑名单中移除应用，在黑名单存在的情况下，在包安装黑名单中的应用不允许在指定用户（通过userId指定）下安装  
 **调用形式：**     
    
- removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。          |  
| appIds | Array<string> | true | 应用ID数组。        |  
| userId | number | true | 用户ID，指定具体用户。取值范围：大于等于0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当指定设备管理应用移除包安装黑名单失败时，会抛出错误对象。 |  
    
    
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
let appIds: Array<string> = ['com.example.myapplication'];  
  
bundleManager.removeDisallowedInstallBundles(wantTemp, appIds, 100, (err) => {  
  if (err) {  
    console.error(`Failed to remove disallowed install bundles. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('Succeeded in removing disallowed install bundles');  
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
let appIds: Array<string> = ['com.example.myapplication'];  
  
bundleManager.removeDisallowedInstallBundles(wantTemp, appIds, 100).then(() => {  
  console.info('Succeeded in removing disallowed install bundles');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to remove disallowed install bundles. Code is ${err.code}, message is ${err.message}`);  
});  
    
```    
  
    
## getDisallowedInstallBundles    
指定设备管理应用获取当前/指定用户下的包安装黑名单  
 **调用形式：**     
    
- getDisallowedInstallBundles(admin: Want, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 10    
- getDisallowedInstallBundles(admin: Want, userId: number, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 10    
- getDisallowedInstallBundles(admin: Want, userId?: number): Promise\<Array\<string>>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。<br/> |  
| userId | number | true | 用户ID，指定具体用户。取值范围：大于等于0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当接口调用成功，err为null，否则为错误对象。 |  
| Promise<Array<string>> | Promise对象，返回当前用户下的包安装白名单。 |  
    
    
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
  
bundleManager.getDisallowedInstallBundles(wantTemp, 100, (err, result) => {  
  if (err) {  
    console.error(`Failed to get disallowed install bundles. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in getting disallowed install bundles, result : ${JSON.stringify(result)}`);  
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
  
bundleManager.getDisallowedInstallBundles(wantTemp, 100).then((result) => {  
  console.info(`Succeeded in getting disallowed install bundles, result : ${JSON.stringify(result)}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to get disallowed install bundles. Code is ${err.code}, message is ${err.message}`);  
});  
    
```    
  
    
## addDisallowedUninstallBundles    
指定设备管理应用添加应用至包卸载黑名单，添加至黑名单的应用不允许在当前/指定用户下卸载。  
 **调用形式：**     
    
- addDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- addDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- addDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。<br/> |  
| appIds | Array<string> | true | 应用ID数组。<br/> |  
| userId | number | true | 用户ID，指定具体用户。取值范围：大于等于0。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当指定设备管理应用添加包卸载黑名单失败时，会抛出错误对象。 |  
    
    
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
let appIds: Array<string> = ['com.example.myapplication'];  
  
bundleManager.addDisallowedUninstallBundles(wantTemp, appIds, 100, (err) => {  
  if (err) {  
    console.error(`Failed to add disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('Succeeded in adding disallowed uninstall bundles');  
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
let appIds: Array<string> = ['com.example.myapplication'];  
  
bundleManager.addDisallowedUninstallBundles(wantTemp, appIds, 100).then(() => {  
  console.info('Succeeded in adding disallowed uninstall bundles');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to add disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);  
});<span style="font-size: 14px; letter-spacing: 0px;">import Want from '@ohos.app.ability.Want';</span>  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
let appIds: Array<string> = ['com.example.myapplication'];  
  
bundleManager.addDisallowedUninstallBundles(wantTemp, appIds, 100).then(() => {  
  console.info('Succeeded in adding disallowed uninstall bundles');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to add disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);  
});    
```    
  
    
## removeDisallowedUninstallBundles    
指定设备管理应用在包卸载黑名单中移除应用。在黑名单存在的情况下，在包卸载黑名单中的应用不允许在当前/指定用户下卸载。  
 **调用形式：**     
    
- removeDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- removeDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- removeDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。<br/> |  
| appIds | Array<string> | true | 应用ID数组。<br/> |  
| userId | number | true | 用户ID，指定具体用户。取值范围：大于等于0。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当指定设备管理应用移除包卸载黑名单失败时会抛出错误对象。 |  
    
    
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
let appIds: Array<string> = ['com.example.myapplication'];  
  
bundleManager.removeDisallowedUninstallBundles(wantTemp, appIds, 100, (err) => {  
  if (err) {  
    console.error(`Failed to remove disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('Succeeded in removing disallowed uninstall bundles');  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```null    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
let appIds: Array<string> = ['com.example.myapplication'];  
  
bundleManager.removeDisallowedUninstallBundles(wantTemp, appIds, 100).then(() => {  
  console.info('Succeeded in removing disallowed uninstall bundles');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to remove disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);  
});  
    
```    
  
    
## getDisallowedUninstallBundles    
指定设备管理应用获取当前/指定用户下包卸载黑名单接口  
 **调用形式：**     
    
- getDisallowedUninstallBundles(admin: Want, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 10    
- getDisallowedUninstallBundles(admin: Want, userId: number, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 10    
- getDisallowedUninstallBundles(admin: Want, userId?: number): Promise\<Array\<string>>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。<br/> |  
| userId | number | true | 用户ID，指定具体用户。取值范围：大于等于0。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当接口调用成功，err为null，否则为错误对象。 |  
| Promise<Array<string>> | Promise对象，返回当前用户下的包卸载白名单。 |  
    
    
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
  
bundleManager.getDisallowedUninstallBundles(wantTemp, 100, (err, result) => {  
  if (err) {  
    console.error(`Failed to get disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in getting disallowed uninstall bundles, result : ${JSON.stringify(result)}`);  
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
  
bundleManager.getDisallowedUninstallBundles(wantTemp, 100).then((result) => {  
  console.info(`Succeeded in getting disallowed uninstall bundles, result : ${JSON.stringify(result)}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to get disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);  
});  
    
```    
  
    
## uninstall    
指定设备管理应用卸载当前/指定用户下的指定包接口，选择是否保留包数据（由isKeepData指定）。  
 **调用形式：**     
    
- uninstall(admin: Want, bundleName: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- uninstall(admin: Want, bundleName: string, userId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- uninstall(admin: Want, bundleName: string, isKeepData: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- uninstall(admin: Want, bundleName: string, userId: number, isKeepData: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- uninstall(admin: Want, bundleName: string, userId?: number, isKeepData?: boolean): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_INSTALL_BUNDLE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。<br/> |  
| bundleName | string | true | 包名。<br/> |  
| userId | number | true | 用户ID，指定具体用户。取值范围：大于等于0。<br/> |  
| isKeepData | boolean | true | 是否保留包数据，true表示保留，false表示不保留。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当包卸载失败时抛出错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the application install failed. |  
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
  
bundleManager.uninstall(wantTemp, 'bundleName', 100, true, (err) => {  
  if (err) {  
    console.error(`Failed to uninstall bundles. Code is ${err.code}, message is ${err.message}`);  
  }  
  console.info('Succeeded in uninstalling bundles');  
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
  
bundleManager.uninstall(wantTemp, 'bundleName', 100, true).then(() => {  
  console.info('Succeeded in uninstalling bundles');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to uninstall bundles. Code is ${err.code}, message is ${err.message}`);  
});  
    
```    
  
    
## install    
指定设备管理应用安装指定路径下的应用包。  
 **调用形式：**     
    
- install(admin: Want, hapFilePaths: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- install(admin: Want, hapFilePaths: Array\<string>, installParam: InstallParam, callback: AsyncCallback\<void>): void    
起始版本： 10    
- install(admin: Want, hapFilePaths: Array\<string>, installParam?: InstallParam): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_INSTALL_BUNDLE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。<br/> |  
| hapFilePaths | Array<string> | true | 待安装应用包路径数组。<br/> |  
| installParam | InstallParam | true | 应用包安装参数。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当包安装失败时，抛出错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 9201002 | the application install failed. |  
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
let hapFilePaths: Array<string> = ['/data/storage/el2/base/haps/entry/testinstall/ExtensionTest.hap']  
let installParam: bundleManager.InstallParam = {  
  userId: 100,  
  installFlag: 1,  
};  
  
bundleManager.install(wantTemp, hapFilePaths, installParam, (err) => {  
  if (err) {  
    console.error(`Failed to install bundles. Code is ${err.code}, message is ${err.message}`);  
  }  
  console.info('Succeeded in installing bundles');  
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
let hapFilePaths: Array<string> = ['/data/storage/el2/base/haps/entry/testinstall/ExtensionTest.hap']  
  
bundleManager.install(wantTemp, hapFilePaths).then(() => {  
  console.info('Succeeded in installing bundles');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to install bundles. Code is ${err.code}, message is ${err.message}`);  
});  
    
```    
  
