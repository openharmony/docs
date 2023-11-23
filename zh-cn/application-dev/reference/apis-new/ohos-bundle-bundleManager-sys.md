# @ohos.bundle.bundleManager    
本模块提供应用信息查询能力，支持BundleInfo、ApplicationInfo、Ability、ExtensionAbility等信息的查询。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import bundleManager from '@ohos.bundle.bundleManager'    
```  
    
## ApplicationFlag    
应用信息标志，指示需要获取的应用信息的内容。    
    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| GET_APPLICATION_INFO_DEFAULT | 0x00000000 | 用于获取默认的applicationInfo，获取的applicationInfo不包含permission和metadata信息。 |  
| GET_APPLICATION_INFO_WITH_PERMISSION | 0x00000001 | 用于获取包含permission的applicationInfo。 |  
| GET_APPLICATION_INFO_WITH_METADATA | 0x00000002 | 用于获取包含metadata的applicationInfo。 |  
| GET_APPLICATION_INFO_WITH_DISABLE | 0x00000004 | 用于获取包含禁用应用程序的applicationInfo。 |  
    
## AbilityFlag    
Ability组件信息标志，指示需要获取的Ability组件信息的内容。    
    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| GET_ABILITY_INFO_DEFAULT | 0x00000000 | 用于获取默认abilityInfo，获取的abilityInfo不包含permission、metadata和禁用的abilityInfo。 |  
| GET_ABILITY_INFO_WITH_PERMISSION | 0x00000001 | 用于获取包含permission的abilityInfo。 |  
| GET_ABILITY_INFO_WITH_APPLICATION | 0x00000002 | 用于获取包含applicationInfo的abilityInfo。 |  
| GET_ABILITY_INFO_WITH_METADATA | 0x00000004 | 用于获取包含metadata的abilityInfo。 |  
| GET_ABILITY_INFO_WITH_DISABLE | 0x00000008 | 用于获取包含禁用的abilityInfo的abilityInfo。 |  
| GET_ABILITY_INFO_ONLY_SYSTEM_APP | 0x00000010 | 用于仅为系统应用程序获取abilityInfo。 |  
    
## ExtensionAbilityFlag    
扩展组件信息标志，指示需要获取的扩展组件信息的内容。    
    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| GET_EXTENSION_ABILITY_INFO_DEFAULT | 0x00000000 | 用于获取默认extensionAbilityInfo。获取的extensionAbilityInfo不包含permission、metadata |  
| GET_EXTENSION_ABILITY_INFO_WITH_PERMISSION | 0x00000001 | 用于获取包含permission的extensionAbilityInfo。 |  
| GET_EXTENSION_ABILITY_INFO_WITH_APPLICATION | 0x00000002 | 用于获取包含applicationInfo的extensionAbilityInfo。 |  
| GET_EXTENSION_ABILITY_INFO_WITH_METADATA | 0x00000004 | 用于获取包含metadata的extensionAbilityInfo。 |  
    
## ProfileType<sup>(11+)</sup>    
标识配置文件类型。    
    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| INTENT_PROFILE | 1 | 意图框架配置文件。 |  
    
## getBundleInfo    
以异步方法根据给定的bundleName、bundleFlags和userId获取BundleInfo，使用callback形式返回结果。  
 **调用形式：**     
    
- getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void    
起始版本： 9    
- getBundleInfo(bundleName: string,    bundleFlags: number, userId: number, callback: AsyncCallback\<BundleInfo>): void    
起始版本： 9    
- getBundleInfo(bundleName: string, bundleFlags: number, userId?: number): Promise\<BundleInfo>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 表示要查询的应用Bundle名称。 |  
| bundleFlags | number | true | 指定返回的BundleInfo所包含的信息。 |  
| userId | number | true | 表示用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取成功时，err为null，data为获取到的bundleInfo；否则为错误对象。 |  
| Promise<BundleInfo> | Promise对象，返回BundleInfo。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700026 | The specified user ID is not found. |  
| 17700004 | he specified bundle is disabled. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
// 额外获取extensionAbility  
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY;  
  
try {  
    bundleManager.getBundleInfo(bundleName, bundleFlags, (err, data) => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'getBundleInfo successfully: %{public}s', JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
// 额外获取ApplicationInfo和SignatureInfo  
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;  
let userId = 100;  
  
try {  
    bundleManager.getBundleInfo(bundleName, bundleFlags, userId).then((data) => {  
        hilog.info(0x0000, 'testTag', 'getBundleInfo successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', message);  
}  
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;  
  
try {  
    bundleManager.getBundleInfo(bundleName, bundleFlags).then((data) => {  
        hilog.info(0x0000, 'testTag', 'getBundleInfo successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getApplicationInfo    
以异步方法根据给定的bundleName、appFlags和userId获取ApplicationInfo，使用callback形式返回结果。  
 **调用形式：**     
    
- getApplicationInfo(bundleName: string, appFlags: number, callback: AsyncCallback\<ApplicationInfo>): void    
起始版本： 9    
- getApplicationInfo(bundleName: string,    appFlags: number, userId: number, callback: AsyncCallback\<ApplicationInfo>): void    
起始版本： 9    
- getApplicationInfo(bundleName: string, appFlags: number, userId?: number): Promise\<ApplicationInfo>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 表示要查询的应用Bundle名称。 |  
| appFlags | number | true | 指定返回的ApplicationInfo所包含的信息。 |  
| userId | number | true | 表示用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取成功时，err为null，data为获取到的ApplicationInfo；否则为错误对象。 |  
| Promise<ApplicationInfo> | Promise对象，返回ApplicationInfo。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700026 | The specified user ID is not found. |  
| 17700004 | The specified bundle is disabled. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_WITH_PERMISSION;  
  
try {  
    bundleManager.getApplicationInfo(bundleName, appFlags, (err, data) => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'getApplicationInfo successfully: %{public}s', JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', message);  
}<span style="font-size: 14px; letter-spacing: 0px;">import bundleManager from '@ohos.bundle.bundleManager';</span>  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_WITH_PERMISSION;  
  
try {  
    bundleManager.getApplicationInfo(bundleName, appFlags, (err, data) => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'getApplicationInfo successfully: %{public}s', JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', message);  
}    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_WITH_PERMISSION;  
let userId = 100;  
  
try {  
    bundleManager.getApplicationInfo(bundleName, appFlags, userId).then((data) => {  
        hilog.info(0x0000, 'testTag', 'getApplicationInfo successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'getApplicationInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getApplicationInfo failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getAllBundleInfo    
以异步方法根据给定的bundleFlags和userId获取系统中所有的BundleInfo，使用callback形式返回结果。  
 **调用形式：**     
    
- getAllBundleInfo(bundleFlags: number, callback: AsyncCallback\<Array\<BundleInfo>>): void    
起始版本： 9    
- getAllBundleInfo(bundleFlags: number, userId: number, callback: AsyncCallback\<Array\<BundleInfo>>): void    
起始版本： 9    
- getAllBundleInfo(bundleFlags: number, userId?: number): Promise\<Array\<BundleInfo>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_INSTALLED_BUNDLE_LIST    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleFlags | number | true | 指定返回的BundleInfo所包含的信息。 |  
| userId | number | true | 表示用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取成功时，err为null，data为获取到的Array\<BundleInfo>；否则为错误对象。 |  
| Promise<Array<BundleInfo>> | Promise对象，返回Array\<BundleInfo>。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700004 | The specified user ID is not found. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;  
  
try {  
    bundleManager.getAllBundleInfo(bundleFlags, (err, data) => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'getAllBundleInfo failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'getAllBundleInfo successfully: %{public}s', JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getAllBundleInfo failed: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;  
  
try {  
    bundleManager.getAllBundleInfo(bundleFlags).then((data) => {  
        hilog.info(0x0000, 'testTag', 'getAllBundleInfo successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'getAllBundleInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getAllBundleInfo failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getAllApplicationInfo    
以异步方法根据给定的appFlags和userId获取系统中所有的ApplicationInfo，使用callback形式返回结果。  
 **调用形式：**     
    
- getAllApplicationInfo(appFlags: number, callback: AsyncCallback\<Array\<ApplicationInfo>>): void    
起始版本： 9    
- getAllApplicationInfo(appFlags: number,    userId: number, callback: AsyncCallback\<Array\<ApplicationInfo>>): void    
起始版本： 9    
- getAllApplicationInfo(appFlags: number, userId?: number): Promise\<Array\<ApplicationInfo>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_INSTALLED_BUNDLE_LIST    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appFlags | number | true | 指定返回的ApplicationInfo所包含的信息。 |  
| userId | number | true | 表示用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取成功时，err为null，data为获取到的Array\<ApplicationInfo>；否则为错误对象。 |  
| Promise<Array<ApplicationInfo>> | Promise对象，返回Array\<ApplicationInfo>。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700004 | The specified user ID is not found. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;  
  
try {  
    bundleManager.getAllApplicationInfo(appFlags, (err, data) => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'getAllApplicationInfo failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'getAllApplicationInfo successfully: %{public}s', JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getAllApplicationInfo failed: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;  
  
try {  
    bundleManager.getAllApplicationInfo(appFlags).then((data) => {  
        hilog.info(0x0000, 'testTag', 'getAllApplicationInfo successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'getAllApplicationInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getAllApplicationInfo failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## queryAbilityInfo    
以异步方法根据给定的want、abilityFlags和userId获取多个AbilityInfo，使用callback形式返回结果。  
 **调用形式：**     
    
- queryAbilityInfo(want: Want, abilityFlags: number, callback: AsyncCallback\<Array\<AbilityInfo>>): void    
起始版本： 9    
- queryAbilityInfo(want: Want,    abilityFlags: number, userId: number, callback: AsyncCallback\<Array\<AbilityInfo>>): void    
起始版本： 9    
- queryAbilityInfo(want: Want, abilityFlags: number, userId?: number): Promise\<Array\<AbilityInfo>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 表示包含要查询的应用Bundle名称的Want。 |  
| abilityFlags | number | true | 指定返回的AbilityInfo所包含的信息。 |  
| userId | number | true | 表示用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取成功时，err为null，data为获取到的Array\<AbilityInfo>；否则为错误对象。 |  
| Promise<Array<AbilityInfo>> | Promise对象，返回Array\<AbilityInfo>。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700003 | The specified ability is not found. |  
| 17700026 | The specified userId is invalid. |  
| 17700029 | The specified bundle is disabled. |  
| 17700004 | The specified ability is disabled. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;  
let want: Want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
    bundleManager.queryAbilityInfo(want, abilityFlags, (err, data) => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully: %{public}s', JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;  
let userId = 100;  
let want: Want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((data) => {  
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);  
}  
  
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;  
let want: Want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
    bundleManager.queryAbilityInfo(want, abilityFlags).then((data) => {  
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);  
    })  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## queryAbilityInfoSync<sup>(10+)</sup>    
以异步方法根据给定的want和abilityFlags获取一个或多个AbilityInfo，使用callback形式返回结果。  
 **调用形式：**     
- queryAbilityInfoSync(want: Want, abilityFlags: number, userId?: number): Array\<AbilityInfo>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 表示包含要查询的应用Bundle名称的Want。 |  
| abilityFlags | number | true | 指定返回的AbilityInfo所包含的信息。 |  
| userId | number | false | 表示用户ID，默认值：调用方所在用户，取值范围：大于等于0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<AbilityInfo> | 回调函数，当获取成功时，err为null，data为获取到的Array\<AbilityInfo>；否则为错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700003 | The specified ability is not found. |  
| 17700004 |  |  
| 17700026 | The specified bundle is disabled. |  
| 17700029 | he specified ability is disabled. |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;  
let userId = 100;  
let want: Want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
  
    let infos = bundleManager.queryAbilityInfoSync(want, abilityFlags, userId);  
    hilog.info(0x0000, 'testTag', 'queryAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(infos));  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'queryAbilityInfoSync failed. Cause: %{public}s', message);  
}  
  
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;  
let want: Want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
    let infos = bundleManager.queryAbilityInfoSync(want, abilityFlags);  
    hilog.info(0x0000, 'testTag', 'queryAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(infos));  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'queryAbilityInfoSync failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## queryExtensionAbilityInfo    
以异步方法根据给定的want、extensionAbilityType、extensionAbilityFlags和userId获取一个或多个ExtensionAbilityInfo，使用callback形式返回结果。  
 **调用形式：**     
    
- queryExtensionAbilityInfo(want: Want, extensionAbilityType: ExtensionAbilityType,    extensionAbilityFlags: number, callback: AsyncCallback\<Array\<ExtensionAbilityInfo>>): void    
起始版本： 9    
- queryExtensionAbilityInfo(want: Want, extensionAbilityType: ExtensionAbilityType,    extensionAbilityFlags: number, userId: number, callback: AsyncCallback\<Array\<ExtensionAbilityInfo>>): void    
起始版本： 9    
- queryExtensionAbilityInfo(want: Want, extensionAbilityType: ExtensionAbilityType,    extensionAbilityFlags: number, userId?: number): Promise\<Array\<ExtensionAbilityInfo>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 表示包含要查询的应用Bundle名称的Want。 |  
| extensionAbilityType | ExtensionAbilityType | true | 标识extensionAbility的类型。 |  
| extensionAbilityFlags | number | true | 表示用于指定将返回的ExtensionInfo对象中包含的信息的标志。 |  
| userId | number | true | 表示用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取成功时，err为null，data为获取到Array\<ExtensionAbilityInfo>；否则为错误对象。 |  
| Promise<Array<ExtensionAbilityInfo>> | Promise对象，返回Array\<ExtensionAbilityInfo>。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700003 | The specified extensionAbility is not found. |  
| 17700026 | The specified userId is invalid. |  
| 17700004 | he specified bundle is disabled. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;  
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;  
let want: Want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags, (err, data) => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfo successfully: %{public}s', JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
  
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;  
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;  
let userId = 100;  
let want: Want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags, userId).then((data) => {  
        hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfo successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## queryExtensionAbilityInfoSync<sup>(10+)</sup>    
根据给定的want、extensionAbilityType、extensionAbilityFlags和userId获取ExtensionAbilityInfo，使用同步方式返回结果。  
 **调用形式：**     
- queryExtensionAbilityInfoSync(want: Want, extensionAbilityType: ExtensionAbilityType,    extensionAbilityFlags: number, userId?: number): Array\<ExtensionAbilityInfo>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 表示包含要查询的应用Bundle名称的Want。 |  
| extensionAbilityType | ExtensionAbilityType | true | 标识extensionAbility的类型。 |  
| extensionAbilityFlags | number | true | 表示用于指定将返回的ExtensionInfo对象中包含的信息的标志。 |  
| userId | number | false | 表示用户ID，默认值：调用方所在用户，取值范围：大于等于0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<ExtensionAbilityInfo> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 |  |  
| 17700003 |  |  
| 17700004 |  |  
| 17700026 |  |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
  
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;  
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;  
let userId = 100;  
let want: Want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
    let extenInfos = bundleManager.queryExtensionAbilityInfoSync(want, extensionAbilityType, extensionFlags, userId);  
    hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(extenInfos));  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfoSync failed. Cause: %{public}s', message);  
}  
  
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;  
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;  
let want: Want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
    let extenInfos = bundleManager.queryExtensionAbilityInfoSync(want, extensionAbilityType, extensionFlags);  
    hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(extenInfos));  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfoSync failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## queryExtensionAbilityInfoSync<sup>(11+)</sup>    
根据给定的want、extensionAbilityType、extensionAbilityFlags和userId获取ExtensionAbilityInfo，使用同步方式返回结果。  
 **调用形式：**     
- queryExtensionAbilityInfoSync(want: Want, extensionAbilityType: string,    extensionAbilityFlags: number, userId?: number): Array\<ExtensionAbilityInfo>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 表示包含要查询的应用Bundle名称的Want。 |  
| extensionAbilityType | string | true | 表示自定义extensionAbility的类型。 |  
| extensionAbilityFlags | number | true | 表示返回的ExtensionInfo对象中需要包含的信息标志。 |  
| userId | number | false | 表示用户ID，默认值：调用方所在用户，取值范围：大于等于0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<ExtensionAbilityInfo> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 |  |  
| 17700003 |  |  
| 17700004 |  |  
| 17700026 |  |  
    
 **示例代码：**   
```ts    
// 示例接口带userId参数查询  
import bundleManager from '@ohos.bundle.bundleManager';  
import hilog from '@ohos.hilog';  
  
let extensionAbilityType = "form";  
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;  
let userId = 100;  
let want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
    var data = bundleManager.queryExtensionAbilityInfoSync(want, extensionAbilityType, extensionFlags, userId)  
    hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(data));  
} catch (err) {  
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfoSync failed.');  
}  
  
// 示例接口不带userId参数查询  
import bundleManager from '@ohos.bundle.bundleManager';  
import hilog from '@ohos.hilog';  
  
let extensionAbilityType = "form";  
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;  
let want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
    let data = bundleManager.queryExtensionAbilityInfoSync(want, extensionAbilityType, extensionFlags);  
    hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(data));  
} catch (err) {  
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfoSync failed.');  
}  
    
```    
  
    
## getBundleNameByUid    
以异步方法根据给定的uid获取对应的bundleName，使用callback形式返回结果。  
 **调用形式：**     
    
- getBundleNameByUid(uid: number, callback: AsyncCallback\<string>): void    
起始版本： 9    
- getBundleNameByUid(uid: number): Promise\<string>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid | number | true | 表示应用程序的UID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取成功时，err为null，data为获取到的BundleName；否则为错误对象。 |  
| Promise<string> | Promise对象，返回bundleName。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700021 | The uid is not found. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let uid = 20010005;  
try {  
    bundleManager.getBundleNameByUid(uid, (err, data) => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'getBundleNameByUid successfully: %{public}s', JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let uid = 20010005;  
try {  
    bundleManager.getBundleNameByUid(uid).then((data) => {  
        hilog.info(0x0000, 'testTag', 'getBundleNameByUid successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getBundleNameByUidSync<sup>(10+)</sup>    
以同步方法根据给定的uid获取对应的bundleName。  
 **调用形式：**     
- getBundleNameByUidSync(uid: number): string  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid | number | true | 表示应用程序的UID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 以同步方法根据给定的uid获取对应的bundleName。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700021 | e uid is not found. |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let uid = 20010005;  
try {  
    let data = bundleManager.getBundleNameByUidSync(uid);  
    hilog.info(0x0000, 'testTag', 'getBundleNameByUidSync successfully. Data: %{public}s', JSON.stringify(data));  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getBundleNameByUidSync failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getBundleArchiveInfo    
以异步方法根据给定的hapFilePath和bundleFlags获取BundleInfo，使用callback形式返回结果。  
 **调用形式：**     
    
- getBundleArchiveInfo(hapFilePath: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void    
起始版本： 9    
- getBundleArchiveInfo(hapFilePath: string, bundleFlags: number): Promise\<BundleInfo>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| hapFilePath | string | true | 表示存储HAP的路径，路径应该是当前应用程序数据目录的相对路径。 |  
| bundleFlags | number | true | 表示用于指定要返回的BundleInfo对象中包含的信息的标志。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取成功时，err为null，data为获取到的BundleInfo；否则为错误对象。 |  
| Promise<BundleInfo> | Promise对象，返回BundleInfo。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700022 | The hapFilePath is invalid. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
mport bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let hapFilePath = "/data/xxx/test.hap";  
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;  
  
try {  
    bundleManager.getBundleArchiveInfo(hapFilePath, bundleFlags, (err, data) => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'getBundleArchiveInfo failed. Cause: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'getBundleArchiveInfo successfully: %{public}s', JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getBundleArchiveInfo failed. Cause: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let hapFilePath = "/data/xxx/test.hap";  
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;  
  
try {  
    bundleManager.getBundleArchiveInfo(hapFilePath, bundleFlags).then((data) => {  
        hilog.info(0x0000, 'testTag', 'getBundleArchiveInfo successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'getBundleArchiveInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getBundleArchiveInfo failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getBundleArchiveInfoSync<sup>(10+)</sup>    
以同步方法根据给定的hapFilePath和bundleFlags获取BundleInfo对象。  
 **调用形式：**     
- getBundleArchiveInfoSync(hapFilePath: string, bundleFlags: number): BundleInfo  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| hapFilePath | string | true | 表示存储HAP的路径，路径应该是当前应用程序数据目录的相对路径。 |  
| bundleFlags | number | true | 表示用于指定要返回的BundleInfo对象中包含的信息的标志。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| BundleInfo | 返回BundleInfo对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700022 | The hapFilePath is invalid. |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let hapFilePath = "/data/xxx/test.hap";  
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;  
  
try {  
    let data = bundleManager.getBundleArchiveInfoSync(hapFilePath, bundleFlags)  
    hilog.info(0x0000, 'testTag', 'getBundleArchiveInfoSync successfully. Data: %{public}s', JSON.stringify(data));  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getBundleArchiveInfoSync failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## cleanBundleCacheFiles    
以异步方法根据给定的bundleName清理BundleCache，使用callback形式返回结果。  
 **调用形式：**     
    
- cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- cleanBundleCacheFiles(bundleName: string): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.REMOVE_CACHE_FILES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 表示要清理其缓存数据的应用程序的bundleName。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当清理应用缓存目录数据成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当清理应用缓存目录数据失败会抛出错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | he specified bundleName is not found. |  
| 17700030 | he specified bundle does not support clearing of cache files. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = "com.ohos.myapplication";  
  
try {  
    bundleManager.cleanBundleCacheFiles(bundleName, err => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'cleanBundleCacheFiles failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'cleanBundleCacheFiles successfully.');  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'cleanBundleCacheFiles failed: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = "com.ohos.myapplication";  
  
try {  
    bundleManager.cleanBundleCacheFiles(bundleName).then(() => {  
        hilog.info(0x0000, 'testTag', 'cleanBundleCacheFiles successfully.');  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'cleanBundleCacheFiles failed: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'cleanBundleCacheFiles failed: %{public}s', message);  
}  
    
```    
  
    
## setApplicationEnabled    
设置指定应用的禁用或使能状态，使用callback形式返回结果。  
 **调用形式：**     
    
- setApplicationEnabled(bundleName: string, isEnabled: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setApplicationEnabled(bundleName: string, isEnabled: boolean): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 指定应用的bundleName。 |  
| isEnabled | boolean | true | 值为true表示使能，值为false表示禁用。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当设置应用禁用或使能状态成功时，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = "com.ohos.myapplication";  
  
try {  
    bundleManager.setApplicationEnabled(bundleName, false, err => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'setApplicationEnabled failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'setApplicationEnabled successfully.');  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'setApplicationEnabled failed: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = "com.ohos.myapplication";  
  
try {  
    bundleManager.setApplicationEnabled(bundleName, false).then(() => {  
        hilog.info(0x0000, "testTag", "setApplicationEnabled successfully.");  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'setApplicationEnabled failed: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'setApplicationEnabled failed: %{public}s', message);  
}  
    
```    
  
    
## setApplicationEnabledSync<sup>(10+)</sup>    
以同步方法设置指定应用的禁用或使能状态。  
 **调用形式：**     
- setApplicationEnabledSync(bundleName: string, isEnabled: boolean): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 指定应用的bundleName。 |  
| isEnabled | boolean | true | 值为true表示使能，值为false表示禁用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | he specified bundleName is not found. |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = "com.ohos.myapplication";  
  
try {  
    bundleManager.setApplicationEnabledSync(bundleName, false);  
    hilog.info(0x0000, 'testTag', 'setApplicationEnabledSync successfully.');  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'setApplicationEnabledSync failed: %{public}s', message);  
}  
    
```    
  
    
## setAbilityEnabled    
设置指定组件的禁用或使能状态，使用callback形式返回结果。  
 **调用形式：**     
    
- setAbilityEnabled(info: AbilityInfo, isEnabled: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setAbilityEnabled(info: AbilityInfo, isEnabled: boolean): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| info | AbilityInfo | true | 需要被设置的组件。 |  
| isEnabled | boolean | true | 值为true表示使能，值为false表示禁用。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当设置组件禁用或使能状态成功时，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700003 | The specified abilityInfo is not found. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;  
let userId = 100;  
let want: Want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {  
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));  
        let info = abilitiesInfo[0];  
  
        bundleManager.setAbilityEnabled(info, false, err => {  
            if (err) {  
                hilog.error(0x0000, 'testTag', 'setAbilityEnabled failed: %{public}s', err.message);  
            } else {  
                hilog.info(0x0000, "testTag", "setAbilityEnabled successfully.");  
            }  
        });  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;  
let userId = 100;  
let want: Want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {  
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));  
        let info = abilitiesInfo[0];  
  
        bundleManager.setAbilityEnabled(info, false).then(() => {  
            hilog.info(0x0000, "testTag", "setAbilityEnabled successfully.");  
        }).catch((err: BusinessError) => {  
            hilog.error(0x0000, 'testTag', 'setAbilityEnabled failed: %{public}s', err.message);  
        });  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## setAbilityEnabledSync<sup>(10+)</sup>    
以同步方法设置指定组件的禁用或使能状态。  
 **调用形式：**     
- setAbilityEnabledSync(info: AbilityInfo, isEnabled: boolean): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| info | AbilityInfo | true | 需要被设置的组件。 |  
| isEnabled | boolean | true | 值为true表示使能，值为false表示禁用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700003 | The specified abilityInfo is not found. |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;  
let userId = 100;  
let want: Want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {  
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));  
        let info = abilitiesInfo[0];  
  
        try {  
            bundleManager.setAbilityEnabledSync(info, false);  
            hilog.info(0x0000, "testTag", "setAbilityEnabledSync successfully.");  
        } catch (err) {  
            let message = (err as BusinessError).message;  
            hilog.error(0x0000, 'testTag', 'setAbilityEnabledSync failed: %{public}s', message);  
        }  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## isApplicationEnabled    
以异步的方法获取指定应用的禁用或使能状态，使用callback形式返回结果。  
 **调用形式：**     
    
- isApplicationEnabled(bundleName: string, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isApplicationEnabled(bundleName: string): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 表示应用程序的bundleName。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回true表示当前应用为使能状态，返回false表示应用为禁用状态。 |  
| Promise<boolean> | Promise对象，返回true表示当前应用为使能状态，返回false表示当前应用为禁用状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
  
try {  
    bundleManager.isApplicationEnabled(bundleName, (err, data) => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'isApplicationEnabled failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'isApplicationEnabled successfully: %{public}s', JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'isApplicationEnabled failed: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
  
try {  
    bundleManager.isApplicationEnabled(bundleName).then((data) => {  
        hilog.info(0x0000, 'testTag', 'isApplicationEnabled successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'isApplicationEnabled failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'isApplicationEnabled failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## isApplicationEnabledSync<sup>(10+)</sup>    
以同步方法获取指定应用的禁用或使能状态。  
 **调用形式：**     
- isApplicationEnabledSync(bundleName: string): boolean  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 表示应用程序的bundleName。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示当前应用为使能状态，返回false表示当前应用为禁用状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 17700001 | he specified bundleName is not found. |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
  
try {  
    let data = bundleManager.isApplicationEnabledSync(bundleName);  
    hilog.info(0x0000, 'testTag', 'isApplicationEnabledSync successfully: %{public}s', JSON.stringify(data));  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'isApplicationEnabledSync failed: %{public}s', message);  
}  
    
```    
  
    
## isAbilityEnabled    
以异步的方法获取指定组件的禁用或使能状态，使用callback形式返回结果。  
 **调用形式：**     
    
- isAbilityEnabled(info: AbilityInfo, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isAbilityEnabled(info: AbilityInfo): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| info | AbilityInfo | true | 表示关于检查ability的信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回true表示当前应用组件为使能状态，返回false表示应用组件为禁用状态。 |  
| Promise<boolean> | Promise对象，返回true表示当前应用组件为使能状态，返回false表示当前应用组件为禁用状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700003 | The specified abilityName is not found. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;  
let userId = 100;  
let want: Want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {  
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));  
        let info = abilitiesInfo[0];  
  
        bundleManager.isAbilityEnabled(info, (err, data) => {  
            if (err) {  
                hilog.error(0x0000, 'testTag', 'isAbilityEnabled failed: %{public}s', err.message);  
            } else {  
                hilog.info(0x0000, 'testTag', 'isAbilityEnabled successfully: %{public}s', JSON.stringify(data));  
            }  
        });  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;  
let userId = 100;  
let want: Want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {  
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));  
        let info = abilitiesInfo[0];  
  
        bundleManager.isAbilityEnabled(info).then((data) => {  
            hilog.info(0x0000, 'testTag', 'isAbilityEnabled successfully. Data: %{public}s', JSON.stringify(data));  
        }).catch((err: BusinessError) => {  
            hilog.error(0x0000, 'testTag', 'isAbilityEnabled failed. Cause: %{public}s', err.message);  
        });  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    
```    
  
    
## isAbilityEnabledSync<sup>(10+)</sup>    
以同步方法获取指定组件的禁用或使能状态。  
 **调用形式：**     
- isAbilityEnabledSync(info: AbilityInfo): boolean  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| info | AbilityInfo | true | 表示关于检查ability的信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示当前应用组件为使能状态，返回false表示当前应用组件为禁用状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700003 | The specified abilityName is not found. |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;  
let userId = 100;  
let want: Want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
  
try {  
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {  
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));  
        let info = abilitiesInfo[0];  
  
        try {  
            let data = bundleManager.isAbilityEnabledSync(info);  
            hilog.info(0x0000, 'testTag', 'isAbilityEnabledSync successfully: %{public}s', JSON.stringify(data));  
        } catch (err) {  
            let message = (err as BusinessError).message;  
            hilog.error(0x0000, 'testTag', 'isAbilityEnabledSync failed: %{public}s', message);  
        }  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getLaunchWantForBundle    
以异步方法根据给定的bundleName和userId获取用于启动应用程序的Want参数，使用callback形式返回结果。  
 **调用形式：**     
    
- getLaunchWantForBundle(bundleName: string, userId: number, callback: AsyncCallback\<Want>): void    
起始版本： 9    
- getLaunchWantForBundle(bundleName: string, callback: AsyncCallback\<Want>): void    
起始版本： 9    
- getLaunchWantForBundle(bundleName: string, userId?: number): Promise\<Want>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 表示应用程序的bundleName。 |  
| userId | number | true | 表示用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取成功时，err为null，data为获取到的Want；否则为错误对象。 |  
| Promise<Want> | Promise对象，返回Want对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | e specified bundleName is not found. |  
| 17700004 | The specified user ID is not found. |  
| 17700026 | The specified bundle is disabled. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
  
try {  
    bundleManager.getLaunchWantForBundle(bundleName, (err, data) => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'getLaunchWantForBundle failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'getLaunchWantForBundle successfully: %{public}s', JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getLaunchWantForBundle failed: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
let userId = 100;  
  
try {  
    bundleManager.getLaunchWantForBundle(bundleName, userId).then((data) => {  
        hilog.info(0x0000, 'testTag', 'getLaunchWantForBundle successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'getLaunchWantForBundle failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getLaunchWantForBundle failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getLaunchWantForBundleSync<sup>(10+)</sup>    
以同步方法根据给定的bundleName和userId获取用于启动应用程序的Want参数。  
 **调用形式：**     
- getLaunchWantForBundleSync(bundleName: string, userId?: number): Want  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 表示应用程序的bundleName。 |  
| userId | number | false | 表示用户ID，默认值：调用方所在用户，取值范围：大于等于0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Want | Want对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700004 | The specified user ID is not found. |  
| 17700026 | The specified bundle is disabled. |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
let bundleName = 'com.example.myapplication';  
let userId = 100;  
  
try {  
    let want: Want = bundleManager.getLaunchWantForBundleSync(bundleName, userId);  
    hilog.info(0x0000, 'testTag', 'getLaunchWantForBundleSync successfully. Data: %{public}s', JSON.stringify(want));  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getLaunchWantForBundleSync failed. Cause: %{public}s', message);  
}  
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
import Want from '@ohos.app.ability.Want';  
let bundleName = 'com.example.myapplication';  
let userId = 100;  
  
try {  
    let want: Want = bundleManager.getLaunchWantForBundleSync(bundleName);  
    hilog.info(0x0000, 'testTag', 'getLaunchWantForBundleSync successfully. Data: %{public}s', JSON.stringify(want));  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getLaunchWantForBundleSync failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getPermissionDef    
以异步方法根据给定的permissionName获取权限定义结构体PermissionDef信息，使用callback形式返回结果。  
 **调用形式：**     
    
- getPermissionDef(permissionName: string, callback: AsyncCallback\<PermissionDef>): void    
起始版本： 9    
- getPermissionDef(permissionName: string): Promise\<PermissionDef>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| permissionName | string | true | 表示权限名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取成功时，err为null，data为获取到的Array\<PermissionDef>；否则为错误对象。 |  
| Promise<PermissionDef> | Promise对象，返回Array\<PermissionDef>对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700006 | The specified permission is not found. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let permission = "ohos.permission.GET_BUNDLE_INFO";  
try {  
    bundleManager.getPermissionDef(permission, (err, data) => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'getPermissionDef failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'getPermissionDef successfully: %{public}s', JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getPermissionDef failed: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let permissionName = "ohos.permission.GET_BUNDLE_INFO";  
try {  
    bundleManager.getPermissionDef(permissionName).then((data) => {  
        hilog.info(0x0000, 'testTag', 'getPermissionDef successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'getPermissionDef failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getPermissionDef failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getPermissionDefSync<sup>(10+)</sup>    
以同步方法根据给定的permissionName获取权限定义结构体PermissionDef信息。  
 **调用形式：**     
- getPermissionDefSync(permissionName: string): PermissionDef  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| permissionName | string | true | 表示权限参数名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PermissionDef | PermissionDef对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700006 | The specified permission is not found. |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let permissionName = "ohos.permission.GET_BUNDLE_INFO";  
try {  
    let PermissionDef = bundleManager.getPermissionDefSync(permissionName);  
    hilog.info(0x0000, 'testTag', 'getPermissionDefSync successfully. Data: %{public}s', JSON.stringify(PermissionDef));  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getPermissionDefSync failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getAbilityLabel    
以异步的方法获取指定bundleName、moduleName和abilityName的label，使用callback形式返回结果。  
 **调用形式：**     
    
- getAbilityLabel(bundleName: string, moduleName: string, abilityName: string, callback: AsyncCallback\<string>): void    
起始版本： 9    
- getAbilityLabel(bundleName: string, moduleName: string, abilityName: string): Promise\<string>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Resource  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 表示应用程序的bundleName。 |  
| moduleName | string | true | 表示应用程序的moduleName。 |  
| abilityName | string | true | 表示应用程序的abilityName。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取成功时，err为null，data为获指定组件的Label值；否则为错误对象。 |  
| Promise<string> | Promise对象，返回指定组件的Lablel值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700002 | The specified moduleName is not found. |  
| 17700003 | The specified abilityName is not found |  
| 17700026 | The specified bundle is disabled. |  
| 17700029 | The specified ability is disabled. |  
    
 **示例代码1：**   
  
示例(callback):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
let moduleName = 'entry';  
let abilityName = 'EntryAbility';  
  
try {  
    bundleManager.getAbilityLabel(bundleName, moduleName, abilityName, (err, data) => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'getAbilityLabel failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'getAbilityLabel successfully: %{public}s', JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getAbilityLabel failed: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
let moduleName = 'entry';  
let abilityName = 'EntryAbility';  
  
try {  
    bundleManager.getAbilityLabel(bundleName, moduleName, abilityName).then((data) => {  
        hilog.info(0x0000, 'testTag', 'getAbilityLabel successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'getAbilityLabel failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getAbilityLabel failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getAbilityLabelSync<sup>(10+)</sup>    
以同步的方法获取指定bundleName、moduleName和abilityName的label。  
 **调用形式：**     
- getAbilityLabelSync(bundleName: string, moduleName: string, abilityName: string): string  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Resource  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 表示应用程序的bundleName。 |  
| moduleName | string | true | 表示应用程序的moduleName。 |  
| abilityName | string | true | 表示应用程序的abilityName。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 指定组件的Lablel值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700002 | The specified moduleName is not found. |  
| 17700003 | The specified abilityName is not found |  
| 17700026 | The specified bundle is disabled. |  
| 17700029 | The specified ability is disabled. |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
let moduleName = 'entry';  
let abilityName = 'EntryAbility';  
  
try {  
    let abilityLabel = bundleManager.getAbilityLabelSync(bundleName, moduleName, abilityName);  
    hilog.info(0x0000, 'testTag', 'getAbilityLabelSync successfully. Data: %{public}s', abilityLabel);  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getAbilityLabelSync failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getApplicationInfoSync    
以同步方法根据给定的bundleName、applicationFlags和userId获取ApplicationInfo。  
 **调用形式：**     
- getApplicationInfoSync(bundleName: string, applicationFlags: number, userId: number): ApplicationInfo  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 表示应用程序的bundleName。 |  
| applicationFlags | number | true | 表示用于指定将返回的ApplicationInfo对象中包含的信息。 |  
| userId | number | true | 表示用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ApplicationInfo | 返回ApplicationInfo对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700004 | The specified user ID is not found. |  
| 17700026 | The specified bundle is disabled. |  
    
 **示例代码：**   
```ts    
mport bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
let applicationFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;  
let userId = 100;  
  
try {  
    let data = bundleManager.getApplicationInfoSync(bundleName, applicationFlags, userId);  
    hilog.info(0x0000, 'testTag', 'getApplicationInfoSync successfully: %{public}s', JSON.stringify(data));  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getApplicationInfoSync failed: %{public}s', message);  
}  
    
```    
  
    
## getApplicationInfoSync  
 **调用形式：**     
- getApplicationInfoSync(bundleName: string, applicationFlags: number): ApplicationInfo  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true |  |  
| applicationFlags | number | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ApplicationInfo |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 |  |  
| 17700026 |  |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
let applicationFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;  
  
try {  
    let data = bundleManager.getApplicationInfoSync(bundleName, applicationFlags);  
    hilog.info(0x0000, 'testTag', 'getApplicationInfoSync successfully: %{public}s', JSON.stringify(data));  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getApplicationInfoSync failed: %{public}s', message);  
}  
    
```    
  
    
## getBundleInfoSync    
以同步方法根据给定的bundleName、applicationFlags获取ApplicationInfo。  
 **调用形式：**     
- getBundleInfoSync(bundleName: string, bundleFlags: number, userId: number): BundleInfo  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 表示应用程序的bundleName。 |  
| bundleFlags | number | true | 表示用于指定将返回的BundleInfo对象中包含的信息的标志。 |  
| userId | number | true | 表示用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| BundleInfo | 返回BundleInfo对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700004 | The specified user ID is not found. |  
| 17700026 | The specified bundle is disabled. |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;  
let userId = 100;  
  
try {  
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);  
    hilog.info(0x0000, 'testTag', 'getBundleInfoSync successfully: %{public}s', JSON.stringify(data));  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getBundleInfoSync failed: %{public}s', message);  
}  
    
```    
  
    
## getBundleInfoSync  
 **调用形式：**     
- getBundleInfoSync(bundleName: string, bundleFlags: number): BundleInfo  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true |  |  
| bundleFlags | number | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| BundleInfo |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 |  |  
| 17700026 |  |  
    
## getAllSharedBundleInfo<sup>(10+)</sup>    
以异步的方法获取所有的共享包信息，使用callback形式返回结果。  
 **调用形式：**     
    
- getAllSharedBundleInfo(callback: AsyncCallback\<Array\<SharedBundleInfo>>): void    
起始版本： 10    
- getAllSharedBundleInfo(): Promise\<Array\<SharedBundleInfo>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取成功时，err为null，data为获所有的共享包信息。 |  
| Promise<Array<SharedBundleInfo>> | Promise对象，返回所有的共享包信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
```ts  
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
  
try {  
    bundleManager.getAllSharedBundleInfo((err, data) => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'getAllSharedBundleInfo failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'getAllSharedBundleInfo successfully: %{public}s', JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getAllSharedBundleInfo failed: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
  
try {  
    bundleManager.getAllSharedBundleInfo().then((data) => {  
        hilog.info(0x0000, 'testTag', 'getAllSharedBundleInfo successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'getAllSharedBundleInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getAllSharedBundleInfo failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getSharedBundleInfo<sup>(10+)</sup>    
以异步的方法获取指定的共享包信息，使用callback形式返回结果。  
 **调用形式：**     
    
- getSharedBundleInfo(bundleName: string, moduleName: string, callback: AsyncCallback\<Array\<SharedBundleInfo>>): void    
起始版本： 10    
- getSharedBundleInfo(bundleName: string, moduleName: string): Promise\<Array\<SharedBundleInfo>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 表示应用程序的bundleName。 |  
| moduleName | string | true | 表示被查询的module的name。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取成功时，err为null，data为获取的指定共享包信息。 |  
| Promise<Array<SharedBundleInfo>> | Promise对象，返回指定的共享包信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700002 | The specified moduleName is not found. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
let moduleName = 'library';  
  
try {  
    bundleManager.getSharedBundleInfo(bundleName, moduleName, (err, data) => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'getSharedBundleInfo failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'getSharedBundleInfo successfully: %{public}s', JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getSharedBundleInfo failed: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = 'com.example.myapplication';  
let moduleName = 'library';  
  
try {  
    bundleManager.getSharedBundleInfo(bundleName, moduleName).then((data) => {  
        hilog.info(0x0000, 'testTag', 'getSharedBundleInfo successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'getSharedBundleInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getSharedBundleInfo failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getAppProvisionInfo<sup>(10+)</sup>    
以异步的方法获取指定bundleName的provision配置文件信息，使用callback形式返回结果。  
 **调用形式：**     
    
- getAppProvisionInfo(bundleName: string, callback: AsyncCallback\<AppProvisionInfo>): void    
起始版本： 10    
- getAppProvisionInfo(bundleName: string, userId: number, callback: AsyncCallback\<AppProvisionInfo>): void    
起始版本： 10    
- getAppProvisionInfo(bundleName: string, userId?: number): Promise\<AppProvisionInfo>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 指定应用的bundleName。 |  
| userId | number | true | 指定用户ID, 可以通过接口[getOsAccountLocalId](js-apis-osAccount.md#getosaccountlocalid9)获取当前设备上的用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当获取成功时，err为null，data为指定bundleName的provision配置文件信息。 |  
| Promise<AppProvisionInfo> | Promise对象，返回应用的provision配置文件信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700004 | The specified user ID is not found. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = "com.ohos.myapplication";  
  
try {  
    bundleManager.getAppProvisionInfo(bundleName, (err, data) => {  
        if (err) {  
            hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed: %{public}s', err.message);  
        } else {  
            hilog.info(0x0000, 'testTag', 'getAppProvisionInfo successfully: %{public}s', JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed: %{public}s', message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = "com.ohos.myapplication";  
let userId = 100;  
  
try {  
    bundleManager.getAppProvisionInfo(bundleName).then((data) => {  
        hilog.info(0x0000, 'testTag', 'getAppProvisionInfo successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed. Cause: %{public}s', message);  
}  
  
try {  
    bundleManager.getAppProvisionInfo(bundleName, userId).then((data) => {  
        hilog.info(0x0000, 'testTag', 'getAppProvisionInfo successfully. Data: %{public}s', JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
        hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed. Cause: %{public}s', err.message);  
    });  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getAppProvisionInfoSync<sup>(10+)</sup>    
以同步方法根据bundleName和userId获取应用的provision配置文件信息并返回结果。  
 **调用形式：**     
- getAppProvisionInfoSync(bundleName: string, userId?: number): AppProvisionInfo  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 指定的bundleName。 |  
| userId | number | false | 表示用户ID，默认值：调用方所在用户，取值范围：大于等于0，可以通过接口[getOsAccountLocalId](js-apis-osAccount.md#getosaccountlocalid9)获取当前设备上的用户ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AppProvisionInfo | AppProvisionInfo对象，返回应用的provision配置文件信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700004 | The specified user ID is not found. |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
import hilog from '@ohos.hilog';  
let bundleName = "com.ohos.myapplication";  
let userId = 100;  
  
try {  
    let data = bundleManager.getAppProvisionInfoSync(bundleName);  
    hilog.info(0x0000, 'testTag', 'getAppProvisionInfoSync successfully. Data: %{public}s', JSON.stringify(data));  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfoSync failed. Cause: %{public}s', message);  
}  
  
try {  
    let data = bundleManager.getAppProvisionInfoSync(bundleName, userId);  
    hilog.info(0x0000, 'testTag', 'getAppProvisionInfoSync successfully. Data: %{public}s', JSON.stringify(data));  
} catch (err) {  
    let message = (err as BusinessError).message;  
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfoSync failed. Cause: %{public}s', message);  
}  
    
```    
  
    
## getSpecifiedDistributionType<sup>(10+)</sup>    
以同步的方法查询指定bundleName的分发类型，该返回值是在调用install接口时传入的[InstallParam](./js-apis-installer.md#installparam)中的specifiedDistributionType字段。  
 **调用形式：**     
- getSpecifiedDistributionType(bundleName: string): string  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 指定的bundleName。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回指定bundleName的分发类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
let bundleName = "com.example.myapplication";  
  
try {  
    let type = bundleManager.getSpecifiedDistributionType(bundleName);  
    console.info('getSpecifiedDistributionType successfully, type:' + type);  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('getSpecifiedDistributionType failed. Cause: ' + message);  
}  
    
```    
  
    
## getAdditionalInfo<sup>(10+)</sup>    
以同步接口查询指定bundleName的额外信息。该返回值是在调用install接口时传入的[InstallParam](./js-apis-installer.md#installparam)中的additionalInfo字段。  
 **调用形式：**     
- getAdditionalInfo(bundleName: string): string  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 指定的bundleName。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回指定bundleName的额外信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
let bundleName = "com.example.myapplication";  
  
try {  
    let info = bundleManager.getAdditionalInfo(bundleName);  
    console.info('getAdditionalInfo successfully, additionInfo:' + info);  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('getAdditionalInfo failed. Cause: ' + message);  
}  
    
```    
  
    
## getJsonProfile<sup>(11+)</sup>    
以同步的方法根据给定的profileType、bundleName和moduleName查询相应配置文件的JSON字符串。  
 **调用形式：**     
- getJsonProfile(profileType: ProfileType, bundleName: string, moduleName?: string): string  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| profileType | ProfileType | true | 表示要查询的配置文件类型。 |  
| bundleName | string | true | 表示要查询应用程序的bundleName。 |  
| moduleName | string | false | 表示要查询应用程序的moduleName，缺省时在入口模块中查找。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回配置文件的JSON字符串。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundleName is not found. |  
| 17700002 | The specified moduleName is not found. |  
| 17700024 | Failed to get the profile because the specified profile is not found in the HAP. |  
| 17700026 | The specified bundle is disabled. |  
    
 **示例代码：**   
```ts    
import bundleManager from '@ohos.bundle.bundleManager';  
import hilog from '@ohos.hilog';  
  
let bundleName = 'com.example.myapplication';  
let moduleName = 'entry';  
let profileType = bundleManager.ProfileType.INTENT_PROFILE;  
  
try {  
    let data = bundleManager.getJsonProfile(profileType, bundleName, moduleName)  
    hilog.info(0x0000, 'testTag', 'getJsonProfile successfully. Data: %{public}s', data);  
} catch (err) {  
    hilog.error(0x0000, 'testTag', 'getJsonProfile failed.');  
}  
    
```    
  
