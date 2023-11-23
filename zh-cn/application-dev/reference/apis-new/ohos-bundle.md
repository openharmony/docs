# @ohos.bundle    
本模块提供应用信息查询能力，支持[包信息](js-apis-bundle-BundleInfo.md)、[应用信息](js-apis-bundle-ApplicationInfo.md)、[Ability组件信息](js-apis-bundle-AbilityInfo.md)等信息的查询，以及应用禁用状态的查询、设置等。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import bundle from '@ohos.bundle'    
```  
    
## BundleFlag<sup>(deprecated)</sup>    
<span style="letter-spacing: 0px;">包信息标志，指示需要获取的包信息的内容。</span>  
  
当接口与标志不匹配时，该标志会被忽略，例如获取application时使用GET_ABILITY_INFO_WITH_PERMISSION对结果不会产生影响。  
标志可以叠加使用，例如使用GET_APPLICATION_INFO_WITH_PERMISSION + GET_APPLICATION_INFO_WITH_DISABLE可以使结果同时包含应用权限信息和被禁用的应用信息。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.bundleManager.BundleFlag替代。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| GET_BUNDLE_DEFAULT | 0x00000000 | 获取默认的应用信息 |  
| GET_BUNDLE_WITH_ABILITIES | 0x00000001 | 获取默认的应用信息 |  
| GET_ABILITY_INFO_WITH_PERMISSION | 0x00000002 | 获取包括权限的Ability信息 |  
| GET_ABILITY_INFO_WITH_APPLICATION | 0x00000004 | 获取包括Application的ability信息 |  
| GET_APPLICATION_INFO_WITH_PERMISSION | 0x00000008 | 获取包括权限的应用信息 |  
| GET_BUNDLE_WITH_REQUESTED_PERMISSION | 0x00000010 | 获取包括所需权限的包信息 |  
| GET_ALL_APPLICATION_INFO | 0xFFFF0000 | 获取应用所有的信息 |  
| GET_ABILITY_INFO_WITH_METADATA<sup>(deprecated)</sup> | 0x00000020 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.BundleManager.BundleFramework<br>获取ability的元数据信息 |  
| GET_APPLICATION_INFO_WITH_METADATA<sup>(deprecated)</sup> | 0x00000040 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.BundleManager.BundleFramework<br>获取应用的元数据信息 |  
| GET_ABILITY_INFO_SYSTEMAPP_ONLY<sup>(deprecated)</sup> | 0x00000080 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.BundleManager.BundleFramework<br>获取仅包括系统应用的ability信息 |  
| GET_ABILITY_INFO_WITH_DISABLE<sup>(deprecated)</sup> | 0x00000100 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.BundleManager.BundleFramework<br>获取包括被禁用的ability信息 |  
| GET_APPLICATION_INFO_WITH_DISABLE<sup>(deprecated)</sup> | 0x00000200 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.BundleManager.BundleFramework<br>获取包括被禁用的应用信息 |  
    
## ColorMode<sup>(deprecated)</sup>    
应用、卡片等的颜色模式。    
从API version 7 开始支持，从API version 9 开始废弃。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| AUTO_MODE | -1 | 自动模式 |  
| DARK_MODE | 0 | 黑色模式 |  
| LIGHT_MODE | 1 | 亮度模式 |  
    
## GrantStatus<sup>(deprecated)</sup>    
权限授予状态。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.bundleManager.PermissionGrantState替代。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PERMISSION_DENIED | -1 | 拒绝授予权限 |  
| PERMISSION_GRANTED | 0 | 授予权限 |  
    
## AbilityType<sup>(deprecated)</sup>    
Ability组件类型。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.bundleManager.AbilityType替代。    
    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNKNOWN<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。<br>未知Ability类型 |  
| PAGE<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示基于Page模板开发的FA，用于提供与用户交互的能力 |  
| SERVICE<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示基于Service模板开发的PA，用于提供后台运行任务的能力 |  
| DATA<sup>(deprecated)</sup> | 3 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示基于Data模板开发的PA，用于对外部提供统一的数据访问对象 |  
    
## AbilitySubType<sup>(deprecated)</sup>    
Ability组件的子类型。    
从API version 7 开始支持，从API version 9 开始废弃。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNSPECIFIED | 0 | 未定义Ability子类型 |  
| CA | 1 | Ability子类型是带有 UI 的服务 |  
    
## DisplayOrientation<sup>(deprecated)</sup>    
屏幕显示方向。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.bundleManager.DisplayOrientation替代。    
    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNSPECIFIED<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。<br>屏幕方向--不指定 |  
| LANDSCAPE<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。<br>屏幕方向--横屏 |  
| PORTRAIT<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。<br>屏幕方向--竖屏 |  
| FOLLOW_RECENT<sup>(deprecated)</sup> | 3 | 从API version 7 开始支持，从API version 9 开始废弃。<br>屏幕方向--紧跟上一个组件 |  
    
## LaunchMode<sup>(deprecated)</sup>    
Ability组件的启动模式。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.bundleManager.LaunchType替代。    
    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SINGLETON<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability只有一个实例 |  
| STANDARD<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability有多个实例 |  
    
## BundleOptions<sup>(deprecated)</sup>    
查询选项，包含userId。    
从API version 7 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| userId<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |  
    
## InstallErrorCode<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SUCCESS | 0 | 安装成功 |  
| STATUS_INSTALL_FAILURE | 1 | 安装失败（不存在安装的应用） |  
| STATUS_INSTALL_FAILURE_ABORTED | 2 | 安装中止 |  
| STATUS_INSTALL_FAILURE_INVALID | 3 | 安装参数无效 |  
| STATUS_INSTALL_FAILURE_CONFLICT | 4 | 安装冲突 （常见于升级和已有应用基本信息不一致） |  
| STATUS_INSTALL_FAILURE_STORAGE | 5 | 存储包信息失败 |  
| STATUS_INSTALL_FAILURE_INCOMPATIBLE | 6 | 安装不兼容（常见于版本降级安装或者签名信息错误） |  
| STATUS_UNINSTALL_FAILURE | 7 | 卸载失败 （不存在卸载的应用） |  
| STATUS_UNINSTALL_FAILURE_BLOCKED | 8 | 卸载中止 （没有使用） |  
| STATUS_UNINSTALL_FAILURE_ABORTED | 9 | 卸载中止 （参数无效导致） |  
| STATUS_UNINSTALL_FAILURE_CONFLICT | 10 | 卸载冲突 （卸载系统应用失败， 结束应用进程失败） |  
| STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT | 0x0B | 安装失败 （下载超时） |  
| STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED | 0x0C | 安装失败 （下载失败） |  
| STATUS_RECOVER_FAILURE_INVALID<sup>(deprecated)</sup> | 0x0D | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.BundleManager.BundleFramework<br>恢复预置应用失败 |  
| STATUS_ABILITY_NOT_FOUND<sup>(deprecated)</sup> | 0x40 | 从API version 7 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.BundleManager.BundleFramework<br>Ability未找到 |  
| STATUS_BMS_SERVICE_ERROR<sup>(deprecated)</sup> | 0x41 | 从API version 7 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.BundleManager.BundleFramework<br>BMS服务错误 |  
| STATUS_FAILED_NO_SPACE_LEFT<sup>(deprecated)</sup> | 0x42 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.BundleManager.BundleFramework<br>设备空间不足 |  
| STATUS_GRANT_REQUEST_PERMISSIONS_FAILED<sup>(deprecated)</sup> | 0x43 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.BundleManager.BundleFramework<br>应用授权失败 |  
| STATUS_INSTALL_PERMISSION_DENIED<sup>(deprecated)</sup> | 0x44 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.BundleManager.BundleFramework<br>缺少安装权限 |  
| STATUS_UNINSTALL_PERMISSION_DENIED<sup>(deprecated)</sup> | 0x45 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.BundleManager.BundleFramework<br>缺少卸载权限 |  
    
## getBundleInfo<sup>(deprecated)</sup>    
以异步方法根据给定的Bundle名称获取BundleInfo，使用callback异步回调。获取调用方自己的信息时不需要权限。  
 **调用形式：**     
- getBundleInfo(bundleName: string,    bundleFlags: number, options: BundleOptions, callback: AsyncCallback\<BundleInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用Bundle名称。 |  
| bundleFlags<sup>(deprecated)</sup> | number | true | 用于指定返回的应用信息对象中包含信息的标记。取值范围：参考[BundleFlag说明](#bundleflagdeprecated)中包信息相关flag。 |  
| options<sup>(deprecated)</sup> | BundleOptions | true | 包含userid。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<BundleInfo> | true | 程序启动作为入参的回调函数，返回包信息。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
let bundleName: string = "com.example.myapplication";  
let bundleFlags: number = 1;  
let options: bundle.BundleOptions = {  
    "userId": 100  
};  
bundle.getBundleInfo(bundleName, bundleFlags, options)  
.then((data) => {  
    console.info('Operation successful. Data: ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
})  
    
```    
  
    
## getBundleInfo<sup>(deprecated)</sup>    
以异步方法根据给定的Bundle名称获取BundleInfo，使用callback异步回调。获取调用方自己的信息时不需要权限。  
 **调用形式：**     
- getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 需要查询的应用Bundle名称。 |  
| bundleFlags<sup>(deprecated)</sup> | number | true | 用于指定返回的应用信息对象中包含信息的标记。取值范围：参考[BundleFlag说明](#bundleflagdeprecated)中包信息相关flag。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<BundleInfo> | true | 程序启动作为入参的回调函数，返回包信息。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
let bundleName: string = "com.example.myapplication";let bundleFlags: number = 1;bundle.getBundleInfo(bundleName, bundleFlags, (err, data) => {    if (err) {        console.error('Operation failed. Cause: ' + JSON.stringify(err));        return;    }    console.info('Operation successful. Data:' + JSON.stringify(data));})    
```    
  
    
## getBundleInfo<sup>(deprecated)</sup>    
以异步方法根据给定的Bundle名称获取BundleInfo，使用Promise异步回调。获取调用方自己的信息时不需要权限。  
 **调用形式：**     
- getBundleInfo(bundleName: string, bundleFlags: number, options?: BundleOptions): Promise\<BundleInfo>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用Bundle名称。 |  
| bundleFlags<sup>(deprecated)</sup> | number | true | 用于指定返回的应用信息对象中包含信息的标记。取值范围：参考[BundleFlag说明](#bundleflagdeprecated)中包信息相关flag。 |  
| options<sup>(deprecated)</sup> | BundleOptions | false | 包含userid的查询选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<BundleInfo> | Promise对象，获取成功时返回包信息。 |  
    
 **示例代码：**   
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
let bundleName: string = "com.example.myapplication";  
let bundleFlags: number = 1;  
let options: bundle.BundleOptions = {  
    "userId": 100  
};  
bundle.getBundleInfo(bundleName, bundleFlags, options)  
.then((data) => {  
    console.info('Operation successful. Data: ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
})  
    
```    
  
    
## getAbilityInfo<sup>(deprecated)</sup>    
通过Bundle名称和组件名获取Ability组件信息，使用callback形式返回结果。获取调用方自己的信息时不需要权限。  
 **调用形式：**     
- getAbilityInfo(bundleName: string, abilityName: string, callback: AsyncCallback\<AbilityInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 应用Bundle名称。 |  
| abilityName<sup>(deprecated)</sup> | string | true | Ability名称。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<AbilityInfo> | true | 程序启动作为入参的回调函数，返回Ability信息。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
let bundleName: string = "com.example.myapplication";let abilityName: string = "EntryAbility";bundle.getAbilityInfo(bundleName, abilityName, (err, data) => {    if (err) {        console.error('Operation failed. Cause: ' + JSON.stringify(err));        return;    }    console.info('Operation successful. Data:' + JSON.stringify(data));})    
```    
  
    
## getAbilityInfo<sup>(deprecated)</sup>    
通过Bundle名称和组件名获取Ability组件信息，使用Promise形式异步回调。获取调用方自己的信息时不需要权限。  
 **调用形式：**     
- getAbilityInfo(bundleName: string, abilityName: string): Promise\<AbilityInfo>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 应用Bundle名称。 |  
| abilityName<sup>(deprecated)</sup> | string | true | Ability组件名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<AbilityInfo> | Promise形式返回Ability信息。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
let bundleName: string = "com.example.myapplication";  
let abilityName: string = "EntryAbility";  
bundle.getAbilityInfo(bundleName, abilityName)  
.then((data) => {  
    console.info('Operation successful. Data: ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
})  
    
```    
  
    
## getApplicationInfo<sup>(deprecated)</sup>    
以异步方法根据给定的Bundle名称获取指定用户下的ApplicationInfo，使用callback形式返回结果。获取调用方自己的信息时不需要权限。  
 **调用形式：**     
- getApplicationInfo(bundleName: string,    bundleFlags: number, userId: number, callback: AsyncCallback\<ApplicationInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用Bundle名称。 |  
| bundleFlags<sup>(deprecated)</sup> | number | true | 用于指定返回的应用信息对象中包含信息的标记。取值范围：参考[BundleFlag说明](#bundleflagdeprecated)中应用信息相关flag。 |  
| userId<sup>(deprecated)</sup> | number | true | 用户ID。取值范围：大于等于0。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<ApplicationInfo> | true | 程序启动作为入参的回调函数，返回应用程序信息。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
let bundleName: string = "com.example.myapplication";let bundleFlags: number = 0;let userId: number = 100;bundle.getApplicationInfo(bundleName, bundleFlags, userId, (err, data) => {    if (err) {        console.error('Operation failed. Cause: ' + JSON.stringify(err));        return;    }    console.info('Operation successful. Data:' + JSON.stringify(data)); })    
```    
  
    
## getApplicationInfo<sup>(deprecated)</sup>    
以异步方法根据给定的Bundle名称获取ApplicationInfo，使用callback形式返回结果。获取调用方自己的信息时不需要权限。  
 **调用形式：**     
- getApplicationInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<ApplicationInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用Bundle名称。 |  
| bundleFlags<sup>(deprecated)</sup> | number | true | 用于指定返回的应用信息对象中包含信息的标记。取值范围：参考[BundleFlag说明](#bundleflagdeprecated)中应用信息相关flag。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<ApplicationInfo> | true | 程序启动作为入参的回调函数，返回应用程序信息。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
let bundleName: string = "com.example.myapplication";let bundleFlags: number = 0;bundle.getApplicationInfo(bundleName, bundleFlags, (err, data) => {    if (err) {        console.error('Operation failed. Cause: ' + JSON.stringify(err));        return;    }    console.info('Operation successful. Data:' + JSON.stringify(data)); })    
```    
  
    
## getApplicationInfo<sup>(deprecated)</sup>    
以异步方法根据给定的Bundle名称获取ApplicationInfo。使用Promise异步回调。获取调用方自己的信息时不需要权限。  
 **调用形式：**     
- getApplicationInfo(bundleName: string, bundleFlags: number, userId?: number): Promise\<ApplicationInfo>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用Bundle名称。 |  
| bundleFlags<sup>(deprecated)</sup> | number | true | 用于指定返回的应用信息对象中包含信息的标记。取值范围请参考[BundleFlag说明](#bundleflagdeprecated)中应用信息相关flag。 |  
| userId<sup>(deprecated)</sup> | number | false | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<ApplicationInfo> | Promise形式返回应用程序信息。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';   
  
let bundleName: string = "com.example.myapplication";  
let bundleFlags: number = 0;  
let userId: number = 100;  
bundle.getApplicationInfo(bundleName, bundleFlags, userId)  
.then((data) => {  
    console.info('Operation successful. Data: ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
})  
    
```    
  
    
## queryAbilityByWant<sup>(deprecated)</sup>    
以异步方法根据给定的意图获取指定用户下Ability信息，使用callback形式返回结果。获取调用方自己的信息时不需要权限。  
 **调用形式：**     
- queryAbilityByWant(want: Want,    bundleFlags: number, userId: number, callback: AsyncCallback\<Array\<AbilityInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want<sup>(deprecated)</sup> | Want | true |  |  
| bundleFlags<sup>(deprecated)</sup> | number | true | 用于指定返回abilityInfo信息。取值范围：参考[BundleFlag说明](#bundleflagdeprecated)中Ability信息相关flag。 |  
| userId<sup>(deprecated)</sup> | number | true | 用户ID。取值范围：大于等于0。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<AbilityInfo>> | true | 程序启动作为入参的回调函数，返回Ability信息。 |  
    
 **示例代码：**   
示例（callback）：  
  
```null    
import bundle from '@ohos.bundle';import Want from '@ohos.app.ability.Want';  
let bundleFlags: number = 0;let userId: number = 100;let want: Want = {    bundleName : "com.example.myapplication",    abilityName : "EntryAbility"};bundle.queryAbilityByWant(want, bundleFlags, userId, (err, data) => {    if (err) {        console.error('Operation failed. Cause: ' + JSON.stringify(err));        return;    }    console.info('Operation successful. Data:' + JSON.stringify(data));})    
```    
  
    
## queryAbilityByWant<sup>(deprecated)</sup>    
以异步方法根据给定的意图获取Ability组件信息，使用Promise形式返回结果。获取调用方自己的信息时不需要权限。  
 **调用形式：**     
- queryAbilityByWant(want: Want, bundleFlags: number, callback: AsyncCallback\<Array\<AbilityInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want<sup>(deprecated)</sup> | Want | true | 指示包含要查询的应用Bundle名称的意图。 |  
| bundleFlags<sup>(deprecated)</sup> | number | true | 用于指定返回abilityInfo信息。取值范围：参考[BundleFlag说明](#bundleflagdeprecated)中Ability信息相关flag。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<AbilityInfo>> | true | 程序启动作为入参的回调函数，返回Ability信息。 |  
    
 **示例代码：**   
示例（callback）：  
  
```null    
import bundle from '@ohos.bundle';import Want from '@ohos.app.ability.Want';  
let bundleFlags: number = 0;let want: Want = {    bundleName : "com.example.myapplication",    abilityName : "EntryAbility"};bundle.queryAbilityByWant(want, bundleFlags, (err, data) => {    if (err) {        console.error('Operation failed. Cause: ' + JSON.stringify(err));        return;    }    console.info('Operation successful. Data:' + JSON.stringify(data));})    
```    
  
    
## queryAbilityByWant<sup>(deprecated)</sup>    
以异步方法根据给定的意图获取Ability组件信息，使用Promise形式返回结果。获取调用方自己的信息时不需要权限。  
 **调用形式：**     
- queryAbilityByWant(want: Want, bundleFlags: number, userId?: number): Promise\<Array\<AbilityInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want<sup>(deprecated)</sup> | Want | true | 指示包含要查询的应用Bundle名称的意图。 |  
| bundleFlags<sup>(deprecated)</sup> | number | true | 用于指定返回abilityInfo信息。取值范围：参考[BundleFlag说明](#bundleflagdeprecated)中Ability信息相关flag。 |  
| userId<sup>(deprecated)</sup> | number | false | 用户ID。取值范围：大于等于0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<AbilityInfo>> | Promise形式返回Ability信息。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
import Want from '@ohos.app.ability.Want';  
  
let bundleFlags: number = 0;  
let userId: number = 100;  
let want: Want = {  
    bundleName : "com.example.myapplication",  
    abilityName : "EntryAbility"  
};  
bundle.queryAbilityByWant(want, bundleFlags, userId)  
.then((data) => {  
    console.info('Operation successful. Data: ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
})  
    
```    
  
    
## getAllBundleInfo<sup>(deprecated)</sup>    
以异步方法获取当前用户所有的BundleInfo，使用callback形式返回结果。  
 **调用形式：**     
- getAllBundleInfo(bundleFlag: BundleFlag, userId: number, callback: AsyncCallback\<Array\<BundleInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleFlag<sup>(deprecated)</sup> | BundleFlag | true | 用于指定返回的应用信息对象中包含信息的标记。取值范围：参考[BundleFlag说明](#bundleflagdeprecated)中包信息相关flag。 |  
| userId<sup>(deprecated)</sup> | number | true | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<BundleInfo>> | true | 程序启动作为入参的回调函数，返回所有可用的BundleInfo。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
let bundleFlag: number = 0;let userId: number = 100;bundle.getAllBundleInfo(bundleFlag, userId, (err, data) => {    if (err) {        console.error('Operation failed. Cause: ' + JSON.stringify(err));        return;    }    console.info('Operation successful. Data:' + JSON.stringify(data)); })    
```    
  
    
## getAllBundleInfo<sup>(deprecated)</sup>    
以异步方法获取当前用户所有的BundleInfo，使用callback形式返回结果。  
 **调用形式：**     
- getAllBundleInfo(bundleFlag: BundleFlag, callback: AsyncCallback\<Array\<BundleInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleFlag<sup>(deprecated)</sup> | BundleFlag | true | 用于指定返回的应用信息对象中包含信息的标记。取值范围：参考[BundleFlag说明](#bundleflagdeprecated)中包信息相关flag。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<BundleInfo>> | true | 程序启动作为入参的回调函数，返回所有可用的BundleInfo。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
let bundleFlag: number = 0;bundle.getAllBundleInfo(bundleFlag, (err, data) => {    if (err) {        console.error('Operation failed. Cause: ' + JSON.stringify(err));        return;    }    console.info('Operation successful. Data:' + JSON.stringify(data)); })    
```    
  
    
## getAllBundleInfo<sup>(deprecated)</sup>    
以异步方法获取指定用户所有的BundleInfo，使用Promise形式异步回调，。  
 **调用形式：**     
- getAllBundleInfo(bundleFlag: BundleFlag, userId?: number): Promise\<Array\<BundleInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleFlag<sup>(deprecated)</sup> | BundleFlag | true | 用于指定返回的应用信息对象中包含信息的标记。取值范围：参考[BundleFlag说明](#bundleflagdeprecated)中包信息相关flag。 |  
| userId<sup>(deprecated)</sup> | number | false | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<BundleInfo>> | Promise形式返回所有可用的BundleInfo |  
    
 **示例代码：**   
示例（promise）：  
  
```null    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
let bundleFlag: number = 0;  
let userId: number = 100;  
  
bundle.getAllBundleInfo(bundleFlag, userId)  
.then((data) => {  
    console.info('Operation successful. Data: ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
})  
    
```    
  
    
## getAllApplicationInfo<sup>(deprecated)</sup>    
获取指定用户下所有已安装的应用信息，使用callback异步回调。  
 **调用形式：**     
- getAllApplicationInfo(bundleFlags: number,    userId: number, callback: AsyncCallback\<Array\<ApplicationInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleFlags<sup>(deprecated)</sup> | number | true | 用于指定返回的应用信息对象中包含信息的标记。取值范围：参考[BundleFlag说明](#bundleflagdeprecated)中应用信息相关flag。 |  
| userId<sup>(deprecated)</sup> | number | true | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<ApplicationInfo>> | true | 程序启动作为入参的回调函数，返回应用信息列表。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
let bundleFlags: number = bundle.BundleFlag.GET_APPLICATION_INFO_WITH_PERMISSION;let userId: number = 100;bundle.getAllApplicationInfo(bundleFlags, userId, (err, data) => {    if (err) {        console.error('Operation failed. Cause: ' + JSON.stringify(err));        return;    }    console.info('Operation successful. Data:' + JSON.stringify(data));})    
```    
  
    
## getAllApplicationInfo<sup>(deprecated)</sup>    
获取指定用户下所有已安装的应用信息，使用callback异步回调。  
 **调用形式：**     
- getAllApplicationInfo(bundleFlags: number, callback: AsyncCallback\<Array\<ApplicationInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleFlags<sup>(deprecated)</sup> | number | true | 用于指定返回的应用信息对象中包含信息的标记。取值范围：参考[BundleFlag说明](#bundleflagdeprecated)中应用信息相关flag。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<ApplicationInfo>> | true | 程序启动作为入参的回调函数，返回应用信息列表。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
let bundleFlags: number = bundle.BundleFlag.GET_APPLICATION_INFO_WITH_PERMISSION;bundle.getAllApplicationInfo(bundleFlags, (err, data) => {    if (err) {        console.error('Operation failed. Cause: ' + JSON.stringify(err));        return;    }    console.info('Operation successful. Data:' + JSON.stringify(data));})    
```    
  
    
## getAllApplicationInfo<sup>(deprecated)</sup>    
获取指定用户下所有已安装的应用信息，使用promise异步回调。  
 **调用形式：**     
- getAllApplicationInfo(bundleFlags: number, userId?: number): Promise\<Array\<ApplicationInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleFlags<sup>(deprecated)</sup> | number | true | 用于指定返回的应用信息对象中包含信息的标记。取值范围：参考[BundleFlag说明](#bundleflagdeprecated)中应用信息相关flag。 |  
| userId<sup>(deprecated)</sup> | number | false | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<ApplicationInfo>> | Promise对象，获取成功时返回应用信息列表。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
let bundleFlags: number = 8;  
let userId: number = 100;  
bundle.getAllApplicationInfo(bundleFlags, userId)  
.then((data) => {  
    console.info('Operation successful. Data: ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
})  
    
```    
  
    
## getNameForUid<sup>(deprecated)</sup>    
以异步方法通过uid获取对应的Bundle名称，使用callback形式返回结果。  
 **调用形式：**     
- getNameForUid(uid: number, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid<sup>(deprecated)</sup> | number | true | 要查询的uid。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 程序启动作为入参的回调函数，返回指定uid的Bundle名称。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
let uid: number = 20010005;  
bundle.getNameForUid(uid)  
.then((data) => {  
    console.info('Operation successful. Data: ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
})  
    
```    
  
    
## getNameForUid<sup>(deprecated)</sup>    
以异步方法通过uid获取对应的Bundle名称，使用Promise形式返回结果。  
 **调用形式：**     
- getNameForUid(uid: number): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid<sup>(deprecated)</sup> | number | true | 要查询的uid。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | 返回值为Promise对象，Promise中包含指定uid的Bundle名称。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
let uid: number = 20010005;  
bundle.getNameForUid(uid)  
.then((data) => {  
    console.info('Operation successful. Data: ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
})  
    
```    
  
    
## getBundleArchiveInfo<sup>(deprecated)</sup>    
以异步方法获取有关HAP中包含的应用程序包的信息，使用callback形式返回结果。  
 **调用形式：**     
- getBundleArchiveInfo(hapFilePath: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| hapFilePath<sup>(deprecated)</sup> | string | true | HAP存放路径，支持当前应用程序的绝对路径和数据目录沙箱路径。 |  
| bundleFlags<sup>(deprecated)</sup> | number | true | 用于指定要返回的BundleInfo对象中包含信息的标记。取值范围：参考[BundleFlag说明](#bundleflagdeprecated)中包信息相关flag。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<BundleInfo> | true | 程序启动作为入参的回调函数，返回HAP中包含的应用程序包的信息。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
let hapFilePath: string = "/data/storage/el2/base/test.hap";let bundleFlags: number = 0;bundle.getBundleArchiveInfo(hapFilePath, bundleFlags, (err, data) => {    if (err) {        console.error('Operation failed. Cause: ' + JSON.stringify(err));        return;    }    console.info('Operation successful. Data:' + JSON.stringify(data));})    
```    
  
    
## getBundleArchiveInfo<sup>(deprecated)</sup>    
获取有关HAP中包含的应用程序包的信息，使用Promise形式返回结果。  
 **调用形式：**     
- getBundleArchiveInfo(hapFilePath: string, bundleFlags: number): Promise\<BundleInfo>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| hapFilePath<sup>(deprecated)</sup> | string | true | HAP存放路径。支持当前应用程序的绝对路径和数据目录沙箱路径。 |  
| bundleFlags<sup>(deprecated)</sup> | number | true | 用于指定要返回的BundleInfo对象中包含信息的标记。取值范围：参考[BundleFlag说明](#bundleflagdeprecated)中包信息相关flag。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<BundleInfo> | 返回值为Promise对象，Promise中包含有关HAP中包含的应用程序的信息。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
let bundleName: string = "com.example.myapplication";  
let abilityName: string = "EntryAbility";  
bundle.getAbilityInfo(bundleName, abilityName)  
.then((data) => {  
    console.info('Operation successful. Data: ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
})  
    
```    
  
    
## getLaunchWantForBundle<sup>(deprecated)</sup>    
以异步方法查询拉起指定应用的want对象，使用callback形式返回结果。  
 **调用形式：**     
- getLaunchWantForBundle(bundleName: string, callback: AsyncCallback\<Want>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用Bundle名称。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Want> | true | 程序启动作为入参的回调函数，返回拉起指定应用的want对象。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
let bundleName: string = "com.example.myapplication";bundle.getLaunchWantForBundle(bundleName, (err, data) => {    if (err) {        console.error('Operation failed. Cause: ' + JSON.stringify(err));        return;    }    console.info('Operation successful. Data:' + JSON.stringify(data));})    
```    
  
    
## getLaunchWantForBundle<sup>(deprecated)</sup>    
以异步方法查询拉起指定应用的want对象，使用Promise形式返回结果。  
 **调用形式：**     
- getLaunchWantForBundle(bundleName: string): Promise\<Want>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用Bundle名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Want> | 返回值为Promise对象，Promise中包含拉起指定应用的Want对象。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
let bundleName: string = "com.example.myapplication";  
bundle.getLaunchWantForBundle(bundleName)  
.then((data) => {  
    console.info('Operation successful. Data: ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
})  
    
```    
  
    
## getAbilityLabel<sup>(deprecated)</sup>    
通过Bundle名称和Ability组件名获取应用名称，使用callback形式返回结果。获取调用方自己的信息时不需要权限。  
 **调用形式：**     
- getAbilityLabel(bundleName: string, abilityName: string, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 应用Bundle名称。 |  
| abilityName<sup>(deprecated)</sup> | string | true | Ability名称。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 程序启动作为入参的回调函数，返回应用名称信息。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
let bundleName: string = "com.example.myapplication";let abilityName: string = "EntryAbility";bundle.getAbilityLabel(bundleName, abilityName, (err, data) => {    if (err) {        console.error('Operation failed. Cause: ' + JSON.stringify(err));        return;    }    console.info('Operation successful. Data:' + JSON.stringify(data));})    
```    
  
    
## getAbilityLabel<sup>(deprecated)</sup>    
通过Bundle名称和ability名称获取应用名称，使用Promise形式返回结果。获取调用方自己的信息时不需要权限。  
 **调用形式：**     
- getAbilityLabel(bundleName: string, abilityName: string): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 应用Bundle名称。 |  
| abilityName<sup>(deprecated)</sup> | string | true | Ability名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise形式返回应用名称信息。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
let bundleName: string = "com.example.myapplication";  
let abilityName: string = "EntryAbility";  
bundle.getAbilityLabel(bundleName, abilityName)  
.then((data) => {  
    console.info('Operation successful. Data: ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
})  
    
```    
  
    
## getAbilityIcon<sup>(deprecated)</sup>    
以异步方法通过bundleName和abilityName获取对应Icon的[PixelMap](js-apis-image.md)，使用callback形式返回结果。获取调用方自己的信息时不需要权限。  
 **调用形式：**     
- getAbilityIcon(bundleName: string, abilityName: string, callback: AsyncCallback\<image.PixelMap>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager#getMediaContent。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用Bundle名称。 |  
| abilityName<sup>(deprecated)</sup> | string | true | 要查询的Ability组件名。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<image.PixelMap> | true | 程序启动作为入参的回调函数，返回指定[PixelMap](js-apis-image.md)。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
let bundleName: string = "com.example.myapplication";let abilityName: string = "EntryAbility";bundle.getAbilityIcon(bundleName, abilityName, (err, data) => {    if (err) {        console.error('Operation failed. Cause: ' + JSON.stringify(err));        return;    }    console.info('Operation successful. Data:' + JSON.stringify(data));})    
```    
  
    
## getAbilityIcon<sup>(deprecated)</sup>    
以异步方法通过bundleName和abilityName获取对应Icon的[PixelMap](js-apis-image.md)，使用Promise形式返回结果。获取调用方自己的信息时不需要权限。  
 **调用形式：**     
- getAbilityIcon(bundleName: string, abilityName: string): Promise\<image.PixelMap>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager#getMediaContent。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用Bundle名称。 |  
| abilityName<sup>(deprecated)</sup> | string | true | 要查询的Ability组件名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<image.PixelMap> | 返回值为[PixelMap](js-apis-image.md)。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
let bundleName: string = "com.example.myapplication";  
let abilityName: string = "EntryAbility";  
bundle.getAbilityIcon(bundleName, abilityName)  
.then((data) => {  
    console.info('Operation successful. Data: ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
})  
    
```    
  
    
## isAbilityEnabled<sup>(deprecated)</sup>    
以异步方法根据给定的AbilityInfo查询ability是否已经启用，使用callback形式返回结果。  
 **调用形式：**     
- isAbilityEnabled(info: AbilityInfo, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| info<sup>(deprecated)</sup> | AbilityInfo | true | Ability的配置信息。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数，返回boolean代表是否启用。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
let bundleName: string = "com.example.myapplication";let abilityName: string = "EntryAbility";bundle.getAbilityInfo(bundleName, abilityName).then((abilityInfo)=>{    bundle.isAbilityEnabled(abilityInfo, (err, data) => {    if (err) {        console.error('Operation failed. Cause: ' + JSON.stringify(err));        return;    }    console.info('Operation successful. Data:' + JSON.stringify(data));    })})    
```    
  
    
## isAbilityEnabled<sup>(deprecated)</sup>    
以异步方法根据给定的AbilityInfo查询ability是否已经启用，使用Promise形式返回结果。  
 **调用形式：**     
- isAbilityEnabled(info: AbilityInfo): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| info<sup>(deprecated)</sup> | AbilityInfo | true | Ability的配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise形式返回boolean代表是否启用。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import bundle from '@ohos.bundle';  
import { BusinessError } from '@ohos.base';  
  
let bundleName: string = "com.example.myapplication";  
let abilityName: string = "EntryAbility";  
bundle.getAbilityInfo(bundleName, abilityName).then((abilityInfo)=>{  
    bundle.isAbilityEnabled(abilityInfo).then((data) => {  
        console.info('Operation successful. Data: ' + JSON.stringify(data));  
    }).catch((error: BusinessError) => {  
        console.error('Operation failed. Cause: ' + JSON.stringify(error));  
    })  
})  
    
```    
  
    
## isApplicationEnabled<sup>(deprecated)</sup>    
以异步方法根据给定的bundleName查询指定应用程序是否已经启用，使用callback形式返回结果。  
 **调用形式：**     
- isApplicationEnabled(bundleName: string, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用Bundle名称。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数，返回boolean代表是否启用。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundle from '@ohos.bundle';  
let bundleName: string = "com.example.myapplication";bundle.isApplicationEnabled(bundleName, (err, data) => {    if (err) {        console.error('Operation failed. Cause: ' + JSON.stringify(err));        return;    }    console.info('Operation successful. Data:' + JSON.stringify(data));})    
```    
  
    
## isApplicationEnabled<sup>(deprecated)</sup>    
以异步方法根据给定的bundleName查询指定应用程序是否已经启用，使用Promise形式返回结果。  
 **调用形式：**     
- isApplicationEnabled(bundleName: string): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用Bundle名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise形式返回boolean代表是否启用。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import bundle from '@ohos.bundle';  
    import { BusinessError } from '@ohos.base';  
  
    let bundleName: string = "com.example.myapplication";  
    bundle.isApplicationEnabled(bundleName)  
    .then((data) => {  
        console.info('Operation successful. Data: ' + JSON.stringify(data));  
    }).catch((error: BusinessError) => {  
        console.error('Operation failed. Cause: ' + JSON.stringify(error));  
    })  
    
```    
  
