# Metadata    
元数据对象，可以通过[bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo)获取，此对象在[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)、[HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md)、[AbilityInfo](js-apis-bundleManager-abilityInfo.md)、[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)中均包含。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## Metadata  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | false | true | 元数据名称。 |  
| value | string | false | true | 元数据值。 |  
| resource | string | false | true | 元数据资源。 |  
