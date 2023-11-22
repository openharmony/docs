# @ohos.bundle.innerBundleManager    
本模块提供launcher应用使用的接口。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import innerBundleManager from '@ohos.bundle.innerBundleManager'    
```  
    
## getLauncherAbilityInfos<sup>(deprecated)</sup>    
以异步方法根据给定的Bundle名称获取LauncherAbilityInfos，使用callback形式返回结果。  
 **调用形式：**     
- getLauncherAbilityInfos(bundleName: string,     userId: number, callback: AsyncCallback\<Array\<LauncherAbilityInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.launcherBundleManager#getLauncherAbilityInfo。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用Bundle名称。 |  
| userId<sup>(deprecated)</sup> | number | true | 用户ID。取值范围：大于等于0。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<LauncherAbilityInfo>> | true | 程序启动作为入参的回调函数，返回程序信息。 |  
    
## getLauncherAbilityInfos<sup>(deprecated)</sup>    
以异步方法根据给定的Bundle名称获取LauncherAbilityInfos，使用Promise形式返回结果。  
  
 **调用形式：**     
- getLauncherAbilityInfos(bundleName: string, userId: number): Promise\<Array\<LauncherAbilityInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.launcherBundleManager#getLauncherAbilityInfo。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用Bundle名称。<br/> |  
| userId<sup>(deprecated)</sup> | number | true | 用户ID。取值范围：大于等于0。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<LauncherAbilityInfo>> | Promise形式返回程序信息。 |  
    
## on('BundleStatusChange')<sup>(deprecated)</sup>    
注册Callback。  
 **调用形式：**     
- on(type: 'BundleStatusChange',     bundleStatusCallback: BundleStatusCallback, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.bundleMonitor#on。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.LISTEN_BUNDLE_CHANGE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 指示应执行命令，只支持BundleStatusChange。 |  
| bundleStatusCallback<sup>(deprecated)</sup> | BundleStatusCallback | true | 指示要注册的回调。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 程序启动作为入参的回调函数，返回正确结果或错误信息。 |  
    
## on('BundleStatusChange')<sup>(deprecated)</sup>    
注册Callback。  
  
 **调用形式：**     
- on(type: 'BundleStatusChange', bundleStatusCallback: BundleStatusCallback): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.bundleMonitor#on。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.LISTEN_BUNDLE_CHANGE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 指示应执行命令，只支持BundleStatusChange。<br/> |  
| bundleStatusCallback<sup>(deprecated)</sup> | BundleStatusCallback | true | 指示要注册的回调。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise形式返回正确结果或错误信息。 |  
    
## off('BundleStatusChange')<sup>(deprecated)</sup>    
取消注册Callback。  
  
 **调用形式：**     
- off(type: 'BundleStatusChange', callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.bundleMonitor#off。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.LISTEN_BUNDLE_CHANGE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 指示应执行命令，只支持BundleStatusChange。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 程序启动作为入参的回调函数，返回正确结果或错误信息。<br/> |  
    
## off('BundleStatusChange')<sup>(deprecated)</sup>    
取消注册Callback。  
  
 **调用形式：**     
- off(type: 'BundleStatusChange'): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.bundleMonitor#off。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.LISTEN_BUNDLE_CHANGE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 指示应执行命令，只支持BundleStatusChange。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise形式返回正确结果或错误信息。 |  
    
## getAllLauncherAbilityInfos<sup>(deprecated)</sup>    
以异步方法获取所有的LauncherAbilityInfos，使用callback形式返回结果。  
  
 **调用形式：**     
- getAllLauncherAbilityInfos(userId: number, callback: AsyncCallback\<Array\<LauncherAbilityInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.launcherBundleManager#getAllLauncherAbilityInfos。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userId<sup>(deprecated)</sup> | number | true | 用户ID。取值范围：大于等于0。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<LauncherAbilityInfo>> | true | 程序启动作为入参的回调函数，返回程序信息。<br/> |  
    
## getAllLauncherAbilityInfos<sup>(deprecated)</sup>    
以异步方法获取所有的LauncherAbilityInfos，使用callback形式返回结果。  
  
 **调用形式：**     
- getAllLauncherAbilityInfos(userId: number): Promise\<Array\<LauncherAbilityInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.launcherBundleManager#getAllLauncherAbilityInfos。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userId<sup>(deprecated)</sup> | number | true | 用户ID。取值范围：大于等于0。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<LauncherAbilityInfo>> | Promise形式返回程序信息。 |  
    
## getShortcutInfos<sup>(deprecated)</sup>    
以异步方法根据给定的Bundle名称获取快捷方式信息，使用callback形式返回结果。  
  
 **调用形式：**     
- getShortcutInfos(bundleName: string, callback: AsyncCallback\<Array\<ShortcutInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.launcherBundleManager#getShortcutInfo。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用Bundle名称。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<ShortcutInfo>> | true | 程序启动作为入参的回调函数，返回快捷方式信息。<br/> |  
    
## getShortcutInfos<sup>(deprecated)</sup>    
以异步方法根据给定的Bundle名称获取快捷方式信息，使用callback形式返回结果。  
  
 **调用形式：**     
- getShortcutInfos(bundleName: string): Promise\<Array\<ShortcutInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.launcherBundleManager#getShortcutInfo。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用Bundle名称。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<ShortcutInfo>> | Promise形式返回快捷方式信息。 |  
