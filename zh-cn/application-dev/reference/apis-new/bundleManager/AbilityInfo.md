# AbilityInfo    
Ability信息，未做特殊说明的属性，均通过[bundle.getAbilityInfo](js-apis-Bundle.md#bundlegetabilityinfodeprecated)获取。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## AbilityInfo  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | true | true | 应用Bundle名称。 |  
| moduleName | string | true | true | Ability所属的HAP的名称。 |  
| name | string | true | true | name |  
| label | string | true | true | Ability对用户显示的名称。 |  
| labelId | number | true | true | Ability的标签的资源id值。 |  
| description | string | true | true | Ability的描述。 |  
| descriptionId | number | true | true | Ability的描述的资源id值。 |  
| icon | string | true | true | Ability的图标资源文件索引。 |  
| iconId | number | true | true | Ability的图标的资源id值。 |  
| process | string | true | true | Ability的进程，如果不设置，默认为包的名称。 |  
| exported | boolean | true | true |  |  
| type | bundleManager.AbilityType | true | true | 模型约束：本模块接口仅可在FA模型下使用。<br>Ability类型。<br />此属性仅可在FA模型下使用。 |  
| orientation | bundleManager.DisplayOrientation | true | true | Ability的显示模式。 |  
| launchType | bundleManager.LaunchType | true | true |  |  
| permissions | Array<string> | true | true | 被其他应用Ability调用时需要申请的权限集合。<br />通过调用[bundle.getAbilityInfo](js-apis-Bundle.md#bundlegetabilityinfodeprecated)接口时，传入GET_ABILITY_INFO_WITH_PERMISSION获取。 |  
| readPermission | string | true | true | 模型约束：本模块接口仅可在FA模型下使用。<br>读取Ability数据所需的权限。<br />此属性仅可在FA模型下使用。 |  
| writePermission | string | true | true | 模型约束：本模块接口仅可在FA模型下使用。<br>向Ability写数据所需的权限。<br />此属性仅可在FA模型下使用。 |  
| uri | string | true | true | 模型约束：本模块接口仅可在FA模型下使用。<br>获取Ability的统一资源标识符（URI）。<br />此属性仅可在FA模型下使用。 |  
| deviceTypes | Array<string> | true | true | Ability支持的设备类型。 |  
| applicationInfo | ApplicationInfo | true | true | 应用程序的配置信息。<br />通过调用[bundle.getAbilityInfo](js-apis-Bundle.md#bundlegetabilityinfodeprecated)接口时，传入GET_ABILITY_INFO_WITH_APPLICATION获取。 |  
| metadata | Array<Metadata> | true | true | ability的元信息。<br />通过调用[bundle.getAbilityInfo](js-apis-Bundle.md#bundlegetabilityinfodeprecated)接口时，传入GET_ABILITY_INFO_WITH_METADATA获取。 |  
| enabled | boolean | true | true | ability是否可用。 |  
| supportWindowModes | Array<bundleManager.SupportWindowMode> | true | true |  |  
| windowSize | WindowSize | true | true |  |  
    
## WindowSize  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| maxWindowRatio | number | true | true |  |  
| minWindowRatio | number | true | true |  |  
| maxWindowWidth | number | true | true |  |  
| minWindowWidth | number | true | true |  |  
| maxWindowHeight | number | true | true |  |  
| minWindowHeight | number | true | true |  |  
