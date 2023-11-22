# ExtensionAbilityInfo    
ExtensionAbility信息，系统应用可以通过[bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo)获取自身或其他应用的ExtensionAbility信息，三方应用可以通过[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取自身的ExtensionAbility信息，其中入参[bundleFlags](js-apis-bundleManager.md#bundleflag)需要使用 GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ExtensionAbilityInfo  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | true | true | 应用Bundle名称。 |  
| moduleName | string | true | true | ExtensionAbility所属的HAP的名称。 |  
| name | string | true | true | ExtensionAbility名称。 |  
| labelId | number | true | true | ExtensionAbility的标签资源ID。 |  
| descriptionId | number | true | true | ExtensionAbility的描述资源ID。 |  
| iconId | number | true | true | ExtensionAbility的图标资源ID。 |  
| exported | boolean | true | true | 判断ExtensionAbility是否可以被其他应用调用。 |  
| extensionAbilityType | bundleManager.ExtensionAbilityType | true | true | ExtensionAbility类型。 |  
| extensionAbilityTypeName<sup>(11+)</sup> | string | true | true |  |  
| permissions | Array<string> | true | true | 被其他应用ExtensionAbility调用时需要申请的权限集合。 |  
| applicationInfo | ApplicationInfo | true | true | 应用程序的配置信息。 |  
| metadata | Array<Metadata> | true | true | ExtensionAbility的元信息。 |  
| enabled | boolean | true | true | ExtensionAbility是否可用。 |  
| readPermission | string | true | true | 读取ExtensionAbility数据所需的权限。 |  
| writePermission | string | true | true | 向ExtensionAbility写数据所需的权限。 |  
