# bundleInfo    
应用包的信息，通过[bundle.getBundleInfo](js-apis-Bundle.md#bundlegetbundleinfodeprecated)获取。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## UsedScene<sup>(deprecated)</sup>    
描述权限使用的场景和时机。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.bundleManager.UsedScene替代。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| abilities<sup>(deprecated)</sup> | Array<string> | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>使用到该权限的Ability集合。 |  
| when<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>使用到该权限的Ability集合。 |  
    
## ReqPermissionDetail<sup>(deprecated)</sup>    
应用运行时需向系统申请的权限集合的详细信息。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.bundleManager.ReqPermissionDetail替代。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用运行时需向系统申请的权限集合的详细信息。 |  
| reason<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>描述申请权限的原因。 |  
| usedScene<sup>(deprecated)</sup> | UsedScene | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>权限使用的场景和时机。 |  
    
## BundleInfo<sup>(deprecated)</sup>    
应用包的信息，通过[bundle.getBundleInfo](js-apis-Bundle.md#bundlegetbundleinfodeprecated)获取。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.bundleManager.BundleInfo替代。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用包的名称。 |  
| type<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用包类型。 |  
| appId<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用包里应用程序的id。 |  
| uid<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用包里应用程序的uid。 |  
| installTime<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>HAP安装时间。 |  
| updateTime<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>HAP更新时间。 |  
| appInfo<sup>(deprecated)</sup> | ApplicationInfo | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用程序的配置信息。 |  
| abilityInfos<sup>(deprecated)</sup> | Array<AbilityInfo> | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability的配置信息<br />通过调用[bundle.getBundleInfo](js-apis-Bundle.md#bundlegetbundleinfodeprecated)接口时，传入GET_BUNDLE_WITH_ABILITIES获取。 |  
| reqPermissions<sup>(deprecated)</sup> | Array<string> | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用运行时需向系统申请的权限集合<br />通过调用[bundle.getBundleInfo](js-apis-Bundle.md#bundlegetbundleinfodeprecated)接口时，传入GET_BUNDLE_WITH_REQUESTED_PERMISSION获取。 |  
| reqPermissionDetails<sup>(deprecated)</sup> | Array<ReqPermissionDetail> | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用运行时需向系统申请的权限集合的详细信息<br />通过调用[bundle.getBundleInfo](js-apis-Bundle.md#bundlegetbundleinfodeprecated)接口时，传入GET_BUNDLE_WITH_REQUESTED_PERMISSION获取。 |  
| vendor<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用包的供应商。 |  
| versionCode<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用包的版本号。 |  
| versionName<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用包的版本文本描述信息。 |  
| compatibleVersion<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>运行应用包所需要最低的SDK版本号。 |  
| targetVersion<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>运行应用包所需要最高SDK版本号。 |  
| isCompressNativeLibs<sup>(deprecated)</sup> | boolean | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>是否压缩应用包的本地库，默认为true。  |  
| hapModuleInfos<sup>(deprecated)</sup> | Array<HapModuleInfo> | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>模块的配置信息。 |  
| entryModuleName<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Entry的模块名称。 |  
| cpuAbi<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用包的cpuAbi信息。 |  
| isSilentInstallation<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>是否通过静默安装。 |  
| minCompatibleVersionCode<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>分布式场景下的应用包兼容的最低版本。 |  
| entryInstallationFree<sup>(deprecated)</sup> | boolean | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Entry是否支持免安装。 |  
| reqPermissionStates<sup>(deprecated)</sup> | Array<number> | true | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>申请权限的授予状态。0表示申请成功，-1表示申请失败。。 |  
