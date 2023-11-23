# SharedBundleInfo    
共享包信息，通过接口[bundleManager.getSharedBundleInfo](js-apis-bundleManager.md)获取。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## SharedBundleInfo  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | true | true | 应用共享包名称。 |  
| compatiblePolicy | bundleManager.CompatiblePolicy | true | true | 共享包兼容策略的类型。 |  
| sharedModuleInfo | Array<SharedModuleInfo> | true | true | 应用共享模块信息。 |  
    
## SharedModuleInfo  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | true | true | 共享包模块名称。 |  
| versionCode | number | true | true | 共享包的版本号。 |  
| versionName | string | true | true | 共享包的版本文本描述信息。 |  
| description | string | true | true | 共享包的模块描述信息。 |  
| descriptionId | number | true | true | 共享包描述的资源id值。 |  
