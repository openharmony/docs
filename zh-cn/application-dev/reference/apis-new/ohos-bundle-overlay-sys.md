# @ohos.bundle.overlay    
本模块提供[overlay特征应用](#overlay特征应用介绍)的安装，overlay特征应用的[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)信息的查询以及overlay特征应用的禁用使能的能力。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import overlay from '@ohos.bundle.overlay'    
```  
    
## setOverlayEnabledByBundleName    
以异步方法设置指定应用的overlay module的禁用使能状态。使用Promise异步回调，成功返回应用的处置状态，失败返回对应错误信息。  
 **调用形式：**     
    
- setOverlayEnabledByBundleName(bundleName: string,    moduleName: string, isEnabled: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setOverlayEnabledByBundleName(bundleName: string, moduleName: string, isEnabled: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Overlay  
 **需要权限：** ohos.permission.CHANGE_OVERLAY_ENABLED_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 指定应用的bundle名称。<br/> |  
| moduleName | string | true | 指定应用的overlay module的HAP名称。 |  
| isEnabled | boolean | true | 值为true表示使能，值为false表示禁用。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当设置指定应用的overlay module的禁用使能状态成功时，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象，返回OverlayModuleInfo |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700002 | The specified module name is not found. |  
| 17700032 | The specified bundle does not contain any overlay module. |  
| 17700033 | The specified module is not an overlay module. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import overlay from '@ohos.bundle.overlay';  
import { BusinessError } from '@ohos.base';  
let bundleName = "com.example.myapplication_xxxxx";  
let moduleName = "feature";  
let isEnabled = false;  
  
try {  
    overlay.setOverlayEnabledByBundleName(bundleName, moduleName, isEnabled, (err, data) => {  
        if (err) {  
            console.info('setOverlayEnabledByBundleName failed due to err code: ' + err.code + ' ' + 'message:' + err.message);  
            return;  
        }  
        console.info('setOverlayEnabledByBundleName successfully');  
    });  
} catch (err) {  
    let code = (err as BusinessError).code;  
    let message = (err as BusinessError).message;  
    console.info('setOverlayEnabledByBundleName failed due to err code: ' + code + ' ' + 'message:' + message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import overlay from '@ohos.bundle.overlay';  
import { BusinessError } from '@ohos.base';  
let bundleName = "com.example.myapplication_xxxxx";  
let moduleName = "feature";  
let isEnabled = false;  
  
try {  
    overlay.setOverlayEnabledByBundleName(bundleName, moduleName, isEnabled)  
        .then((data) => {  
            console.info('setOverlayEnabledByBundleName successfully');  
        }).catch((err: BusinessError) => {  
            console.info('setOverlayEnabledByBundleName failed due to err code: ' + err.code + ' ' + 'message:' + err.message);  
        });  
} catch (err) {  
    let code = (err as BusinessError).code;  
    let message = (err as BusinessError).message;  
    console.info('setOverlayEnabledByBundleName failed due to err code: ' + code + ' ' + 'message:' + message);  
}  
    
```    
  
    
## getOverlayModuleInfoByBundleName    
以异步方法获取指定应用中指定module的OverlayModuleInfo信息。使用promise异步回调，成功返回null，失败返回对应错误信息。  
 **调用形式：**     
    
- getOverlayModuleInfoByBundleName(bundleName: string,    callback: AsyncCallback\<Array\<OverlayModuleInfo>>): void    
起始版本： 10    
- getOverlayModuleInfoByBundleName(bundleName: string,    moduleName: string, callback: AsyncCallback\<Array\<OverlayModuleInfo>>): void    
起始版本： 10    
- getOverlayModuleInfoByBundleName(bundleName: string,    moduleName?: string): Promise\<Array\<OverlayModuleInfo>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Overlay  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 指定应用的bundle名称。<br/> |  
| moduleName | string | true | 指定应用中的overlay module的HAP名称。默认值：缺省该字段时，查询接口将查询指定应用中所有module的OverlayModuleInfo信息。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取指定应用中所有module的OverlayModuleInfo信息成功时，err返回null。否则回调函数返回具体错误对象。 |  
| Promise<Array<OverlayModuleInfo>> | Promise对象，返回<Array<OverlayModuleInfo> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700032 | The specified bundle does not contain any overlay module. |  
| 17700002 | The specified module name is not found. |  
| 17700033 | The specified module is not an overlay module. |  
    
 **示例代码1：**   
示例（callback）：  
  
```null    
import overlay from '@ohos.bundle.overlay';  
import { BusinessError } from '@ohos.base';  
let bundleName = "com.example.myapplication_xxxxx";  
let moduleName = "feature";  
  
try {  
    overlay.getOverlayModuleInfoByBundleName(bundleName, moduleName, (err, data) => {  
        if (err) {  
            console.log('getOverlayModuleInfoByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);  
            return;  
        }  
        console.log('overlayModuleInfo is ' + JSON.stringify(data));  
    });  
} catch (err) {  
    let code = (err as BusinessError).code;  
    let message = (err as BusinessError).message;  
    console.log('getOverlayModuleInfoByBundleName failed due to err code : ' + code + ' ' + 'message :' + message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import overlay from '@ohos.bundle.overlay';  
import { BusinessError } from '@ohos.base';  
let bundleName = "com.example.myapplication_xxxxx";  
let moduleName = "feature";  
  
(async() => {  
    try {  
        let overlayModuleInfos = await overlay.getOverlayModuleInfoByBundleName(bundleName, moduleName);  
        console.log('overlayModuleInfos are ' + JSON.stringify(overlayModuleInfos));  
    } catch(err) {  
        let code = (err as BusinessError).code;  
        let message = (err as BusinessError).message;  
        console.log('getTargetOverlayModuleInfos failed due to err code : ' + code + ' ' + 'message :' + message);  
    }  
})();  
    
```    
  
    
## getTargetOverlayModuleInfosByBundleName    
以异步方法获取指定应用中指定module关联的所有OverlayModuleInfo信息。使用promise异步回调，成功返回null，失败返回对应错误信息。  
 **调用形式：**     
    
- getTargetOverlayModuleInfosByBundleName(targetBundleName: string,    callback: AsyncCallback\<Array\<OverlayModuleInfo>>): void    
起始版本： 10    
- getTargetOverlayModuleInfosByBundleName(targetBundleName: string,    moduleName: string, callback: AsyncCallback\<Array\<OverlayModuleInfo>>): void    
起始版本： 10    
- getTargetOverlayModuleInfosByBundleName(targetBundleName: string,    moduleName?: string): Promise\<Array\<OverlayModuleInfo>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Overlay  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| targetBundleName | string | true | 指定目标应用的bundle名称。<br/> |  
| moduleName | string | true | 指定应用中的目标module的HAP名称。默认值：缺省该字段时，查询接口将查询指定应用中所有module所关联的OverlayModuleInfo信息。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取指定应用中所有module的OverlayModuleInfo信息成功时，err返回null。否则回调函数返回具体错误对象。 |  
| Promise<Array<OverlayModuleInfo>> | Promise对象，返回<Array<OverlayModuleInfo> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700035 | The specified bundle is an overlay bundle. |  
| 17700002 | The specified module name is not found. |  
| 17700034 | The specified module is an overlay module. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import overlay from '@ohos.bundle.overlay';  
import { BusinessError } from '@ohos.base';  
let targetBundleName = "com.example.myapplication_xxxxx";  
let moduleName = "feature";  
  
try {  
    overlay.getTargetOverlayModuleInfosByBundleName(targetBundleName, moduleName, (err, data) => {  
        if (err) {  
            console.log('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);  
            return;  
        }  
        console.log('overlayModuleInfo is ' + JSON.stringify(data));  
    });  
} catch (err) {  
    let code = (err as BusinessError).code;  
    let message = (err as BusinessError).message;  
    console.log('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + code + ' ' + 'message :' + message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import overlay from '@ohos.bundle.overlay';  
import { BusinessError } from '@ohos.base';  
let targetBundleName = "com.example.myapplication_xxxxx";  
let moduleName = "feature";  
  
(async() => {  
    try {  
        let overlayModuleInfos = await overlay.getTargetOverlayModuleInfosByBundleName(targetBundleName, moduleName);  
        console.log('overlayModuleInfos are ' + JSON.stringify(overlayModuleInfos));  
    } catch(err) {  
        let code = (err as BusinessError).code;  
        let message = (err as BusinessError).message;  
        console.log('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + code + ' ' + 'message :' + message);  
    }  
})();  
    
```    
  
