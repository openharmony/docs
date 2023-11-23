# HapModuleInfo    
HAP信息，系统应用可以通过[bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo)获取自身或其他应用的HAP信息，三方应用可以通过[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取自身的HAP信息，其中入参[bundleFlags](js-apis-bundleManager.md#bundleflag)需要使用GET_BUNDLE_INFO_WITH_HAP_MODULE。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## HapModuleInfo  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | true | true | 模块名称。 |  
| icon | string | true | true | 模块图标。 |  
| iconId | number | true | true | 模块图标的资源id值。 |  
| label | string | true | true | 模块标签。 |  
| labelId | number | true | true | 模块标签的资源id值。 |  
| description | string | true | true | 模块描述信息。 |  
| descriptionId | number | true | true | 描述信息的资源id值。 |  
| mainElementName | string | true | true | 入口ability信息。 |  
| abilitiesInfo | Array<AbilityInfo> | true | true | Ability信息。 |  
| extensionAbilitiesInfo | Array<ExtensionAbilityInfo> | true | true | ExtensionAbility信息。 |  
| metadata | Array<Metadata> | true | true | Ability的元信息。 |  
| deviceTypes | Array<string> | true | true | 可以运行模块的设备类型。 |  
| installationFree | boolean | true | true | 模块是否支持免安装。 |  
| hashValue | string | true | true | 模块的Hash值。 |  
| type | bundleManager.ModuleType | true | true | 标识当前模块的类型。 |  
| dependencies | Array<Dependency> | true | true | 原子化服务中模块的预加载列表。 |  
| preloads | Array<PreloadItem> | true | true | 模块运行依赖的动态共享库列表。 |  
    
## Dependency  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| moduleName | string | true | true | 标识当前模块依赖的共享包模块名。 |  
| bundleName<sup>(10+)</sup> | string | true | true | 标识当前模块依赖的共享包包名。 |  
| versionCode<sup>(10+)</sup> | number | true | true | 标识当前共享包的版本号。 |  
    
## PreloadItem  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| moduleName | string | true | true | 模块运行时，由系统自动执行预加载的模块名称。 |  
