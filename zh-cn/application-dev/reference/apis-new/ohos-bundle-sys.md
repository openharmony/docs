# @ohos.bundle    
本模块提供应用信息查询能力，支持[包信息](js-apis-bundle-BundleInfo.md)、[应用信息](js-apis-bundle-ApplicationInfo.md)、[Ability组件信息](js-apis-bundle-AbilityInfo.md)等信息的查询，以及应用禁用状态的查询、设置等。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import bundle from '@ohos.bundle'    
```  
    
## getBundleInstaller<sup>(deprecated)</sup>    
Promise对象，获取成功时返回包信息。  
 **调用形式：**     
- getBundleInstaller(callback: AsyncCallback\<BundleInstaller>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.installer#getBundleInstaller。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.INSTALL_BUNDLE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<BundleInstaller> | true | 回调函数，返回安装接口对象。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
bundle.getBundleInstaller().then((data) => {  
    console.info('getBundleInstaller successfully.');  
}).catch((error: BusinessError) => {  
    console.error('getBundleInstaller failed.');  
});  
    
```    
  
    
## getBundleInstaller<sup>(deprecated)</sup>    
获取用于安装包的接口，使用Promise异步回调，返回安装接口对象。  
 **调用形式：**     
- getBundleInstaller(): Promise\<BundleInstaller>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.installer#getBundleInstaller。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.INSTALL_BUNDLE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<BundleInstaller> | Promise对象，返回安装接口对象。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
bundle.getBundleInstaller().then((data) => {  
    console.info('getBundleInstaller successfully.');  
}).catch((error: BusinessError) => {  
    console.error('getBundleInstaller failed.');  
});  
    
```    
  
    
## cleanBundleCacheFiles<sup>(deprecated)</sup>    
清除指定应用程序的缓存数据，使用callback异步回调。  
 **调用形式：**     
- cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.bundleManager#cleanBundleCacheFiles。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.REMOVE_CACHE_FILES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 指示要清除其缓存数据的应用Bundle名称。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
  
let bundleName: string = "com.example.myapplication";  
  
bundle.cleanBundleCacheFiles(bundleName, err => {  
    if (err) {  
        console.error('cleanBundleCacheFiles failed.');  
    } else {  
        console.info('cleanBundleCacheFiles successfully.');  
    }  
});  
    
```    
  
    
## cleanBundleCacheFiles<sup>(deprecated)</sup>    
清除指定应用程序的缓存数据，使用Promise异步回调。  
 **调用形式：**     
- cleanBundleCacheFiles(bundleName: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.bundleManager#cleanBundleCacheFiles。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.REMOVE_CACHE_FILES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 指示要清除其缓存数据的应用Bundle名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象，无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
let bundleName: string = "com.example.myapplication";  
  
bundle.cleanBundleCacheFiles(bundleName).then(()=> {  
    console.info('cleanBundleCacheFiles successfully.');  
}).catch((error: BusinessError) => {  
    console.error('cleanBundleCacheFiles failed.');  
});  
    
```    
  
    
## setApplicationEnabled<sup>(deprecated)</sup>    
设置是否启用指定的应用程序，使用callback异步回调。  
 **调用形式：**     
- setApplicationEnabled(bundleName: string, isEnable: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.bundleManager#setApplicationEnabled。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 指示需要启用或禁用的应用Bundle名称。 |  
| isEnable<sup>(deprecated)</sup> | boolean | true | 指定是否启用应用程序。true表示启用，false表示禁用。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
  
let bundleName: string = "com.example.myapplication";  
  
bundle.setApplicationEnabled(bundleName, false, err => {  
    if (err) {  
        console.error('setApplicationEnabled failed.');  
    } else {  
        console.info('setApplicationEnabled successfully.');  
    }  
});  
    
```    
  
    
## setApplicationEnabled<sup>(deprecated)</sup>    
设置是否启用指定的应用程序，使用Promise异步回调。  
 **调用形式：**     
- setApplicationEnabled(bundleName: string, isEnable: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.bundleManager#setApplicationEnabled。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 指示需要启用或禁用的应用Bundle名称。 |  
| isEnable<sup>(deprecated)</sup> | boolean | true | 指定是否启用应用程序。true表示启用，false禁用。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象，无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
let bundleName: string = "com.example.myapplication";  
  
bundle.setApplicationEnabled(bundleName, false).then(()=> {  
    console.info('setApplicationEnabled successfully.');  
}).catch((error: BusinessError) => {  
    console.error('setApplicationEnabled failed.');  
});  
    
```    
  
    
## setAbilityEnabled<sup>(deprecated)</sup>    
设置是否启用指定的Ability组件，使用callback异步回调。  
 **调用形式：**     
- setAbilityEnabled(info: AbilityInfo, isEnable: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.bundleManager#setAbilityEnabled。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| info<sup>(deprecated)</sup> | AbilityInfo | true | Ability信息，指示需要设置启用状态的Ability。 |  
| isEnable<sup>(deprecated)</sup> | boolean | true | 指定是否启用应用程序。true表示启用，false禁用。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 为返回操作结果而调用的回调。 |  
    
 **示例代码：**   
示例（callback）：  
  
    
## setAbilityEnabled<sup>(deprecated)</sup>    
设置是否启用指定的Ability组件，使用Promise异步回调。  
 **调用形式：**     
- setAbilityEnabled(info: AbilityInfo, isEnable: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.bundleManager#setAbilityEnabled。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| info<sup>(deprecated)</sup> | AbilityInfo | true | Ability信息，指示需要设置启用状态的Ability。 |  
| isEnable<sup>(deprecated)</sup> | boolean | true | 指定是否启用应用程序。true表示启用，false禁用。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象，无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
let bundleName: string = "com.example.myapplication";  
let abilityName: string = "EntryAbility";  
  
bundle.getAbilityInfo(bundleName, abilityName).then((abilityInfo) => {  
    console.info('getAbilityInfo successfully. Data: ' + JSON.stringify(abilityInfo));  
  
    bundle.setAbilityEnabled(abilityInfo, false).then(data => {  
        console.info('setAbilityEnabled successfully.');  
    }).catch((error: BusinessError) => {  
        console.error('setAbilityEnabled failed:' + JSON.stringify(error));  
    })  
}).catch((error: BusinessError) => {  
    console.error('getAbilityInfo failed. Cause: ' + JSON.stringify(error));  
});  
    
```    
  
    
## getPermissionDef<sup>(deprecated)</sup>    
按权限名称获取权限的详细信息，使用callback异步回调。  
 **调用形式：**     
- getPermissionDef(permissionName: string, callback: AsyncCallback\<PermissionDef>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.bundleManager#getPermissionDef。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| permissionName<sup>(deprecated)</sup> | string | true | 需要查询的权限的名称。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<PermissionDef> | true | 程序启动作为入参的回调函数，返回定义的权限信息。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
  
let permission: string = "ohos.permission.GET_BUNDLE_INFO";  
bundle.getPermissionDef(permission, (err, data) => {  
    if (err) {  
        console.error('getPermissionDef failed:' + err.message);  
    } else {  
        console.info('getPermissionDef successfully:' + JSON.stringify(data));  
    }  
});  
    
```    
  
    
## getPermissionDef<sup>(deprecated)</sup>    
按权限名称获取权限的详细信息，使用promise异步回调。。  
 **调用形式：**     
- getPermissionDef(permissionName: string): Promise\<PermissionDef>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.bundleManager#getPermissionDef。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| permissionName<sup>(deprecated)</sup> | string | true | 需要查询的权限的名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<PermissionDef> | Promise对象，获取成功时返回权限详细信息。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
let permissionName: string = "ohos.permission.GET_BUNDLE_INFO";  
bundle.getPermissionDef(permissionName).then((data) => {  
    console.info('getPermissionDef successfully. Data: ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.error('getPermissionDef failed. Cause: ' + error.message);  
});  
    
```    
  
