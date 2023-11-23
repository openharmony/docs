# @ohos.bundle.overlay    
本模块提供[overlay特征应用](#overlay特征应用介绍)的安装，overlay特征应用的[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)信息的查询以及overlay特征应用的禁用使能的能力。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import overlay from '@ohos.bundle.overlay'    
```  
    
## setOverlayEnabled    
以异步方法设置当前应用中overlay特征module的禁用使能状态。使用Promise异步回调。成功返回null，失败返回对应错误信息。  
 **调用形式：**     
    
- setOverlayEnabled(moduleName: string, isEnabled: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setOverlayEnabled(moduleName: string, isEnabled: boolean): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Overlay    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| moduleName | string | true | overlay特征module的HAP名称。<br/> |  
| isEnabled | boolean | true | 值为true表示使能，值为false表示禁用。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当设置指定module的overlay禁用使能状态成功时，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17700002 | The specified module name is not found. |  
| 17700033 | The specified module is not an overlay module. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import overlay from '@ohos.bundle.overlay';  
import { BusinessError } from '@ohos.base';  
let moduleName = "feature";  
let isEnabled = false;  
  
try {  
    overlay.setOverlayEnabled(moduleName, isEnabled, (err, data) => {  
        if (err) {  
            console.info('setOverlayEnabled failed due to err code: ' + err.code + ' ' + 'message:' + err.message);  
            return;  
        }  
        console.info('setOverlayEnabled success');  
    });  
} catch (err) {  
    let code = (err as BusinessError).code;  
    let message = (err as BusinessError).message;  
    console.info('setOverlayEnabled failed due to err code: ' + code + ' ' + 'message:' + message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import overlay from '@ohos.bundle.overlay';  
import { BusinessError } from '@ohos.base';  
let moduleName = "feature";  
let isEnabled = false;  
  
try {  
    overlay.setOverlayEnabled(moduleName, isEnabled)  
        .then(() => {  
            console.info('setOverlayEnabled success');  
        }).catch((err: BusinessError) => {  
            console.info('setOverlayEnabled failed due to err code: ' + err.code + ' ' + 'message:' + err.message);  
        });  
} catch (err) {  
    let code = (err as BusinessError).code;  
    let message = (err as BusinessError).message;  
    console.info('setOverlayEnabled failed due to err code: ' + code + ' ' + 'message:' + message);  
}  
    
```    
  
    
## getOverlayModuleInfo    
以异步方法获取当前应用中指定的module的overlayModuleInfo信息。使用callback异步回调，成功返回null，失败返回对应错误信息。  
 **调用形式：**     
    
- getOverlayModuleInfo(moduleName: string, callback: AsyncCallback\<OverlayModuleInfo>): void    
起始版本： 10    
- getOverlayModuleInfo(moduleName: string): Promise\<OverlayModuleInfo>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Overlay    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| moduleName | string | true | 指定当前应用中的overlay特征module的HAP名称。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取当前应用中指定的module的overlayModuleInfo信息成功时，err返回null。否则回调函数返回具体错误对象。 |  
| Promise<OverlayModuleInfo> | Promise对象，返回OverlayModuleInfo |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17700002 | The specified module name is not found. |  
| 17700032 | The specified bundle does not contain any overlay module. |  
| 17700033 | The specified module is not an overlay module. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import overlay from '@ohos.bundle.overlay';  
import { BusinessError } from '@ohos.base';  
let moduleName = "feature";  
try {  
    overlay.getOverlayModuleInfo(moduleName, (err, data) => {  
        if (err) {  
            console.log('getOverlayModuleInfo failed due to err code : ' + err.code + ' ' + 'message :' + err.message);  
            return;  
        }  
        console.log('overlayModuleInfo is ' + JSON.stringify(data));  
    });  
} catch (err) {  
    let code = (err as BusinessError).code;  
    let message = (err as BusinessError).message;  
    console.log('getOverlayModuleInfo failed due to err code : ' + code + ' ' + 'message :' + message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import overlay from '@ohos.bundle.overlay';  
import { BusinessError } from '@ohos.base';  
let moduleName = "feature";  
  
(async() => {  
    try {  
        let overlayModuleInfo = await overlay.getOverlayModuleInfo(moduleName);  
        console.log('overlayModuleInfo is ' + JSON.stringify(overlayModuleInfo));  
    } catch(err) {  
        let code = (err as BusinessError).code;  
        let message = (err as BusinessError).message;  
        console.log('getOverlayModuleInfo failed due to err code : ' + code + ' ' + 'message :' + message);  
    }  
})();  
    
```    
  
    
## getTargetOverlayModuleInfos    
以异步方法获取指定的目标module的OverlayModuleInfo。使用promise异步回调，成功返回null，失败返回对应错误信息。  
 **调用形式：**     
    
- getTargetOverlayModuleInfos(targetModuleName: string,    callback: AsyncCallback\<Array\<OverlayModuleInfo>>): void    
起始版本： 10    
- getTargetOverlayModuleInfos(targetModuleName: string): Promise\<Array\<OverlayModuleInfo>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Overlay    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| targetModuleName | string | true | 指定当前应用中的目标module的HAP名称。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取指定的目标module的OverlayModuleInfo成功时，err返回null。否则回调函数返回具体错误对象。 |  
| Promise<Array<OverlayModuleInfo>> | Promise对象，返回<Array<OverlayModuleInfo>> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17700002 | The specified module name is not found. |  
| 17700034 | The specified module is an overlay module. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import overlay from '@ohos.bundle.overlay';  
import { BusinessError } from '@ohos.base';  
let targetModuleName = "feature";  
try {  
    overlay.getTargetOverlayModuleInfos(targetModuleName, (err, data) => {  
        if (err) {  
            console.log('getTargetOverlayModuleInfos failed due to err code : ' + err.code + ' ' + 'message :' + err.message);  
            return;  
        }  
        console.log('overlayModuleInfo is ' + JSON.stringify(data));  
    });  
} catch (err) {  
    let code = (err as BusinessError).code;  
    let message = (err as BusinessError).message;  
    console.log('getTargetOverlayModuleInfos failed due to err code : ' + code + ' ' + 'message :' + message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import overlay from '@ohos.bundle.overlay';  
import { BusinessError } from '@ohos.base';  
let targetModuleName = "feature";  
  
(async() => {  
    try {  
        let overlayModuleInfos = await overlay.getTargetOverlayModuleInfos(targetModuleName);  
        console.log('overlayModuleInfos are ' + JSON.stringify(overlayModuleInfos));  
    } catch(err) {  
        let code = (err as BusinessError).code;  
        let message = (err as BusinessError).message;  
        console.log('getTargetOverlayModuleInfos failed due to err code : ' + code + ' ' + 'message :' + message);  
    }  
})();  
    
```    
  
