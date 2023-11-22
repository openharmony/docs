# OverlayModuleInfo    
OverlayModuleInfo信息，系统应用可以通过[overlay.getOverlayModuleInfoByBundleName](js-apis-overlay.md#overlaygetoverlaymoduleinfobybundlename)获取指定应用的overlay特征module的OverlayModuleInfo信息，三方应用可以通过[overlay.getOverlayModuleInfo](js-apis-overlay.md#overlaygetoverlaymoduleinfo)获取当前应用中overlay特征module的OverlayModuleInfo信息。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## OverlayModuleInfo  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | true | true | overlay特征module所属的应用的bundle名称。 |  
| moduleName | string | true | true | overlay特征module的HAP名称。 |  
| targetModuleName | string | true | true | overlay特征module指定的目标module的HAP名称。 |  
| priority | number | true | true | overlay特征module的优先级。 |  
| state | number | true | true | overlay特征module的禁用使能状态。0代表禁用状态; 1代表使能状态。。 |  
