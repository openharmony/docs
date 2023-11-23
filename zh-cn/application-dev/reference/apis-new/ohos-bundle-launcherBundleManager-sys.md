# @ohos.bundle.launcherBundleManager    
本模块支持launcher应用所需的查询能力，支持[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)、[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)信息的查询。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import launcherBundleManager from '@ohos.bundle.launcherBundleManager'    
```  
    
## getLauncherAbilityInfo    
查询指定bundleName及用户的LauncherAbilityInfo。  
 **调用形式：**     
    
- getLauncherAbilityInfo(bundleName: string,    userId: number, callback: AsyncCallback\<Array\<LauncherAbilityInfo>>): void    
起始版本： 9    
- getLauncherAbilityInfo(bundleName: string, userId: number): Promise\<Array\<LauncherAbilityInfo>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Launcher  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 应用Bundle名称。<br/> |  
| userId | number | true | 被查询的用户id。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback形式返回指定用户下所有应用的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)。 |  
| Promise<Array<LauncherAbilityInfo>> | Promise形式返回bundle包含的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700001 | The specified bundle name is not found. |  
| 17700004 | The specified user ID is not found. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    launcherBundleManager.getLauncherAbilityInfo('com.example.demo', 100,  
        (errData: BusinessError, data: launcherBundleManager.LauncherAbilityInfo[]) => {  
        if (errData !== null) {  
            console.error(`errData is errCode:${errData.code}  message:${errData.message}`);  
        } else {  
            console.log("data is " + JSON.stringify(data));  
        }  
    })  
} catch (errData) {  
    let code = (errData as BusinessError).code;  
    let message = (errData as BusinessError).message;  
    console.error(`errData is errCode:${code}  message:${message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    launcherBundleManager.getLauncherAbilityInfo("com.example.demo", 100)  
        .then((data: launcherBundleManager.LauncherAbilityInfo[]) => {  
        console.log("data is " + JSON.stringify(data));  
    }).catch ((errData: BusinessError) => {  
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);  
    })  
} catch (errData) {  
    let code = (errData as BusinessError).code;  
    let message = (errData as BusinessError).message;  
    console.error(`errData is errCode:${code}  message:${message}`);  
}  
    
```    
  
    
## getLauncherAbilityInfoSync<sup>(10+)</sup>    
查询指定bundleName及用户的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)。  
 **调用形式：**     
- getLauncherAbilityInfoSync(bundleName: string, userId: number): Array\<LauncherAbilityInfo>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Launcher  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 应用Bundle名称。<br/> |  
| userId | number | true | 被查询的用户id。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<LauncherAbilityInfo> | Array形式返回bundle包含的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700001 | The specified bundle name is not found. |  
| 17700004 | The specified user ID is not found. |  
    
 **示例代码：**   
```ts    
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    let data = launcherBundleManager.getLauncherAbilityInfoSync("com.example.demo", 100);  
    console.log("data is " + JSON.stringify(data));  
} catch (errData) {  
    let code = (errData as BusinessError).code;  
    let message = (errData as BusinessError).message;  
    console.error(`errData is errCode:${code}  message:${message}`);  
}  
    
```    
  
    
## getAllLauncherAbilityInfo    
查询指定用户下所有应用的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)  
 **调用形式：**     
    
- getAllLauncherAbilityInfo(userId: number, callback: AsyncCallback\<Array\<LauncherAbilityInfo>>): void    
起始版本： 9    
- getAllLauncherAbilityInfo(userId: number): Promise\<Array\<LauncherAbilityInfo>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Launcher  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userId | number | true | 被查询的用户id。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback形式返回指定用户下所有应用的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)。 |  
| Promise<Array<LauncherAbilityInfo>> | Promise形式返回指定用户下所有应用的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700004 | The specified user ID is not found. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    launcherBundleManager.getAllLauncherAbilityInfo(100,  
        (errData: BusinessError, data: launcherBundleManager.LauncherAbilityInfo[]) => {  
        if (errData !== null) {  
            console.error(`errData is errCode:${errData.code}  message:${errData.message}`);  
        } else {  
            console.log("data is " + JSON.stringify(data));  
        }  
    });  
} catch (errData) {  
    let code = (errData as BusinessError).code;  
    let message = (errData as BusinessError).message;  
    console.error(`errData is errCode:${code}  message:${message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    launcherBundleManager.getAllLauncherAbilityInfo(100)  
        .then((data: launcherBundleManager.LauncherAbilityInfo[]) => {  
        console.log("data is " + JSON.stringify(data));  
    }).catch ((errData: BusinessError) => {  
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);  
    });  
} catch (errData) {  
    let code = (errData as BusinessError).code;  
    let message = (errData as BusinessError).message;  
    console.error(`errData is errCode:${code}  message:${message}`);  
}  
    
```    
  
    
## getShortcutInfo    
查询当前用户下指定应用的[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)。  
 **调用形式：**     
    
- getShortcutInfo(bundleName: string, callback: AsyncCallback\<Array\<ShortcutInfo>>): void    
起始版本： 9    
- getShortcutInfo(bundleName: string): Promise\<Array\<ShortcutInfo>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Launcher  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 应用Bundle名称。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback形式返回指定用户下所有应用的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)。 |  
| Promise<Array<ShortcutInfo>> | Promise形式返回指定用户下所有应用的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)。 |  
    
    
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
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    launcherBundleManager.getShortcutInfo("com.example.demo",  
        (errData: BusinessError, data: launcherBundleManager.ShortcutInfo[]) => {  
        if (errData !== null) {  
            console.error(`errData is errCode:${errData.code}  message:${errData.message}`);  
        } else {  
            console.log("data is " + JSON.stringify(data));  
        }  
    });  
} catch (errData) {  
    let code = (errData as BusinessError).code;  
    let message = (errData as BusinessError).message;  
    console.error(`errData is errCode:${code}  message:${message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    launcherBundleManager.getShortcutInfo("com.example.demo")  
        .then((data: launcherBundleManager.ShortcutInfo[]) => {  
        console.log("data is " + JSON.stringify(data));  
    }).catch ((errData: BusinessError) => {  
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);  
    });  
} catch (errData) {  
    let code = (errData as BusinessError).code;  
    let message = (errData as BusinessError).message;  
    console.error(`errData is errCode:${code}  message:${message}`);  
}  
    
```    
  
    
## getShortcutInfoSync<sup>(10+)</sup>    
查询当前用户下指定应用的[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)。  
 **调用形式：**     
- getShortcutInfoSync(bundleName: string): Array\<ShortcutInfo>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Launcher  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 应用Bundle名称。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<ShortcutInfo> | Array形式返回当前用户下指定应用的[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700001 | The specified bundle name is not found. |  
    
 **示例代码：**   
```ts    
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    let data = launcherBundleManager.getShortcutInfoSync("com.example.demo");  
    console.log("data is " + JSON.stringify(data));  
} catch (errData) {  
    let code = (errData as BusinessError).code;  
    let message = (errData as BusinessError).message;  
    console.error(`errData is errCode:${code}  message:${message}`);  
}  
    
```    
  
