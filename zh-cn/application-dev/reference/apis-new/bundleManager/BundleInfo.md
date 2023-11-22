# BundleInfo    
应用包的信息，通过[bundle.getBundleInfo](js-apis-Bundle.md#bundlegetbundleinfodeprecated)获取。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## BundleInfo  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | true | true | 应用包的名称。 |  
| vendor | string | true | true | 应用包的供应商。 |  
| versionCode | number | true | true | 应用包的版本号。 |  
| versionName | string | true | true | 应用包的版本文本描述信息。 |  
| minCompatibleVersionCode | number | true | true | 分布式场景下的应用包兼容的最低版本。 |  
| targetVersion | number | true | true | 运行应用包所需要最高SDK版本号。 |  
| appInfo | ApplicationInfo | true | true | 应用程序的配置信息。 |  
| hapModulesInfo | Array<HapModuleInfo> | true | true | 模块的配置信息。 |  
| reqPermissionDetails | Array<ReqPermissionDetail> | true | true | 应用运行时需向系统申请的权限集合的详细信息<br />通过调用[bundle.getBundleInfo](js-apis-Bundle.md#bundlegetbundleinfodeprecated)接口时，传入GET_BUNDLE_WITH_REQUESTED_PERMISSION获取。 |  
| permissionGrantStates | Array<bundleManager.PermissionGrantState> | true | true |  |  
| signatureInfo | SignatureInfo | true | true |  |  
| installTime | number | true | true | HAP安装时间。 |  
| updateTime | number | true | true | HAP更新时间。 |  
    
## ReqPermissionDetail    
应用运行时需向系统申请的权限集合的详细信息。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | false | true | 需要使用的权限名称。 |  
| moduleName<sup>(10+)</sup> | string | false | true |  |  
| reason | string | false | true | 描述申请权限的原因。 |  
| reasonId | number | false | true |  |  
| usedScene | UsedScene | false | true | 权限使用的场景和时机。 |  
    
## UsedScene    
描述权限使用的场景和时机。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| abilities | Array<string> | false | true | 使用到该权限的Ability集合。 |  
| when | string | false | true | 使用该权限的时机。 |  
    
## SignatureInfo  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| appId | string | true | true |  |  
| fingerprint | string | true | true |  |  
