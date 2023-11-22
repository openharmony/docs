# @ohos.bundle.freeInstall    
本模块提供免安装相关的设置和查询能力，支持BundlePackInfo、DispatchInfo等信息的查询。本模块接口为系统接口。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import freeInstall from '@ohos.bundle.freeInstall'    
```  
    
## UpgradeFlag    
    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.FreeInstall    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NOT_UPGRADE | 0 | 模块无需升级。<br/> |  
| SINGLE_UPGRADE | 1 | 单个模块需要升级。<br/> |  
| RELATION_UPGRADE | 2 | 关系模块需要升级。<br/> |  
    
## BundlePackFlag    
    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.FreeInstall    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| GET_PACK_INFO_ALL | 0x00000000 | 获取应用包pack.info的所有信息。<br/> |  
| GET_PACKAGES | 0x00000001 | 获取应用包pack.info的package信息。<br/> |  
| GET_BUNDLE_SUMMARY | 0x00000002 | 获取应用包pack.info的bundle摘要信息。<br/> |  
| GET_MODULE_SUMMARY | 0x00000004 | 获取应用包pack.info的module摘要信息。<br/> |  
    
## setHapModuleUpgradeFlag    
设置指定模块是否升级。使用callback异步回调。  
 **调用形式：**     
    
- setHapModuleUpgradeFlag(bundleName: string,     moduleName: string, upgradeFlag: UpgradeFlag, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setHapModuleUpgradeFlag(bundleName: string, moduleName: string, upgradeFlag: UpgradeFlag): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.FreeInstall  
 **需要权限：** ohos.permission.INSTALL_BUNDLE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 应用Bundle名称。<br/> |  
| moduleName | string | true | 应用程序模块名称。<br/> |  
| upgradeFlag | UpgradeFlag | true | 仅供内部系统使用标志位<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当函数调用成功，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700001 | The specified bundle name is not found. |  
| 17700002 | The specified module name is not found. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import freeInstall from '@ohos.bundle.freeInstall';  
let bundleName = 'com.example.myapplication';  
let moduleName = 'entry';  
let upgradeFlag = freeInstall.UpgradeFlag.SINGLE_UPGRADE;  
try {  
    freeInstall.setHapModuleUpgradeFlag(bundleName, moduleName, upgradeFlag, err => {  
        if (err) {  
            console.error('Operation failed:' + JSON.stringify(err));  
        } else {  
            console.info('Operation succeed');  
        }  
    });  
} catch (err) {  
    console.error('Operation failed:' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import freeInstall from '@ohos.bundle.freeInstall';  
import { BusinessError } from '@ohos.base';  
let bundleName = 'com.example.myapplication';  
let moduleName = 'entry';  
let upgradeFlag = freeInstall.UpgradeFlag.SINGLE_UPGRADE;  
try {  
    freeInstall.setHapModuleUpgradeFlag(bundleName, moduleName, upgradeFlag).then(() => {  
        console.info('Operation succeed')  
    }).catch((err: BusinessError) => {  
        console.error('Operation failed:' + JSON.stringify(err));  
    });  
} catch (err) {  
    console.error('Operation failed:' + JSON.stringify(err));  
}  
    
```    
  
    
## isHapModuleRemovable    
查询指定模块是否可以被移除。使用callback异步回调。  
 **调用形式：**     
    
- isHapModuleRemovable(bundleName: string, moduleName: string, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isHapModuleRemovable(bundleName: string, moduleName: string): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.FreeInstall  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 应用Bundle名称。<br/> |  
| moduleName | string | true | 应用程序模块名称。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示可以移除；返回false表示不可移除。 |  
| Promise<boolean> | Promise对象。返回true表示可以移除；返回false表示不可移除。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700001 | The specified bundle name is not found. |  
| 17700002 | The specified module name is not found. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import freeInstall from '@ohos.bundle.freeInstall';  
let bundleName = 'com.example.myapplication';  
let moduleName = 'entry';  
try {  
    freeInstall.isHapModuleRemovable(bundleName, moduleName, (err, data) => {  
        if (err) {  
            console.error('Operation failed:' + JSON.stringify(err));  
        } else {  
            console.info('Operation succeed:' + JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    console.error('Operation failed:' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import freeInstall from '@ohos.bundle.freeInstall';  
import { BusinessError } from '@ohos.base';  
let bundleName = 'com.example.myapplication';  
let moduleName = 'entry';  
try {  
    freeInstall.isHapModuleRemovable(bundleName, moduleName).then(data => {  
        console.info('Operation succeed:' + JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        console.error('Operation failed:' + JSON.stringify(err));  
    });  
} catch (err) {  
    console.error('Operation failed:' + JSON.stringify(err));  
}  
    
```    
  
    
## getBundlePackInfo    
基于bundleName和bundlePackFlag来获取bundlePackInfo。使用callback异步回调。  
 **调用形式：**     
    
- getBundlePackInfo(bundleName: string,     bundlePackFlag: BundlePackFlag, callback: AsyncCallback\<BundlePackInfo>): void    
起始版本： 9    
- getBundlePackInfo(bundleName: string, bundlePackFlag: BundlePackFlag): Promise\<BundlePackInfo>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.FreeInstall  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 应用Bundle名称。<br/> |  
| bundlePackFlag | BundlePackFlag | true | 指示要查询的应用包标志。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当函数调用成功，err为null，data为获取到的BundlePackInfo信息。否则为错误对象。 |  
| Promise<BundlePackInfo> | Promise对象，返回BundlePackInfo信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700001 | The specified bundle name is not found. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import freeInstall from '@ohos.bundle.freeInstall';  
let bundleName = 'com.example.myapplication';  
let bundlePackFlag = freeInstall.BundlePackFlag.GET_PACK_INFO_ALL;  
try {  
    freeInstall.getBundlePackInfo(bundleName, bundlePackFlag, (err, data) => {  
        if (err) {  
            console.error('Operation failed:' + JSON.stringify(err));  
        } else {  
            console.info('Operation succeed:' + JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    console.error('Operation failed:' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import freeInstall from '@ohos.bundle.freeInstall';  
import { BusinessError } from '@ohos.base';  
let bundleName = 'com.example.myapplication';  
let bundlePackFlag = freeInstall.BundlePackFlag.GET_PACK_INFO_ALL;  
try {  
    freeInstall.getBundlePackInfo(bundleName, bundlePackFlag).then(data => {  
        console.info('Operation succeed:' + JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        console.error('Operation failed:' + JSON.stringify(err));  
    });  
} catch (err) {  
    console.error('Operation failed:' + JSON.stringify(err));  
}  
    
```    
  
    
## getDispatchInfo    
获取有关dispatch版本的信息。使用callback异步回调。  
 **调用形式：**     
    
- getDispatchInfo(callback: AsyncCallback\<DispatchInfo>): void    
起始版本： 9    
- getDispatchInfo(): Promise\<DispatchInfo>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.FreeInstall  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当函数调用成功，err为null，data为获取到的DispatchInfo信息。否则为错误对象。 |  
| Promise<DispatchInfo> | Promise对象，返回BundlePackInfo信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import freeInstall from '@ohos.bundle.freeInstall';  
try {  
    freeInstall.getDispatchInfo((err, data) => {  
        if (err) {  
            console.error('Operation failed:' + JSON.stringify(err));  
        } else {  
            console.info('Operation succeed:' + JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    console.error('Operation failed:' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import freeInstall from '@ohos.bundle.freeInstall';  
import { BusinessError } from '@ohos.base';  
try {  
    freeInstall.getDispatchInfo().then(data => {  
        console.info('Operation succeed:' + JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        console.error('Operation failed:' + JSON.stringify(err));  
    });  
} catch (err) {  
    console.error('Operation failed:' + JSON.stringify(err));  
}  
    
```    
  
