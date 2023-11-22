# abilityInfo    
bility信息，未做特殊说明的属性，均通过[bundle.getAbilityInfo](js-apis-Bundle.md#bundlegetabilityinfodeprecated)获取。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## AbilityInfo<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.bundleManager.AbilityInfo替代。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用Bundle名称。 |  
| name<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability名称。 |  
| label<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability对用户显示的名称。 |  
| description<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability的描述。 |  
| icon<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability的图标资源文件索引。 |  
| labelId<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability的描述的资源id值。 |  
| descriptionId<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability的图标的资源id值。 |  
| iconId<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability的图标的资源id值。 |  
| moduleName<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability所属的HAP的名称。 |  
| process<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability的进程，如果不设置，默认为包的名称。 |  
| targetAbility<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。模型约束：本模块接口仅可在FA模型下使用。<br>当前Ability重用的目标Ability。<br />此属性仅可在FA模型下使用。 |  
| backgroundModes<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。模型约束：本模块接口仅可在FA模型下使用。<br>表示后台服务的类型。<br />此属性仅可在FA模型下使用。   |  
| isVisible<sup>(deprecated)</sup> | boolean | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>判断Ability是否可以被其他应用调用。 |  
| formEnabled<sup>(deprecated)</sup> | boolean | true | true | 从API version 7 开始支持，从API version 9 开始废弃。模型约束：本模块接口仅可在FA模型下使用。<br>判断Ability是否提供卡片能力。<br />此属性仅可在FA模型下使用。 |  
| type<sup>(deprecated)</sup> | bundle.AbilityType | true | true | 从API version 7 开始支持，从API version 9 开始废弃。模型约束：本模块接口仅可在FA模型下使用。<br>Ability类型。<br />此属性仅可在FA模型下使用。 |  
| subType<sup>(deprecated)</sup> | bundle.AbilitySubType | true | true | 从API version 7 开始支持，从API version 9 开始废弃。模型约束：本模块接口仅可在FA模型下使用。<br>Ability的显示模式。 |  
| orientation<sup>(deprecated)</sup> | bundle.DisplayOrientation | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability的显示模式。<br/> |  
| launchMode<sup>(deprecated)</sup> | bundle.LaunchMode | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability的启动模式。   |  
| permissions<sup>(deprecated)</sup> | Array<string> | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>被其他应用Ability调用时需要申请的权限集合。<br />通过调用[bundle.getAbilityInfo](js-apis-Bundle.md#bundlegetabilityinfodeprecated)接口时，传入GET_ABILITY_INFO_WITH_PERMISSION获取。 |  
| deviceTypes<sup>(deprecated)</sup> | Array<string> | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability支持的设备类型。 |  
| deviceCapabilities<sup>(deprecated)</sup> | Array<string> | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability需要的设备能力。 |  
| readPermission<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。模型约束：本模块接口仅可在FA模型下使用。<br>读取Ability数据所需的权限。<br />此属性仅可在FA模型下使用。 |  
| writePermission<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。模型约束：本模块接口仅可在FA模型下使用。<br>向Ability写数据所需的权限。<br />此属性仅可在FA模型下使用。 |  
| applicationInfo<sup>(deprecated)</sup> | ApplicationInfo | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用程序的配置信息。<br />通过调用[bundle.getAbilityInfo](js-apis-Bundle.md#bundlegetabilityinfodeprecated)接口时，传入GET_ABILITY_INFO_WITH_APPLICATION获取。 |  
| uri<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。模型约束：本模块接口仅可在FA模型下使用。<br>获取Ability的统一资源标识符（URI）。<br />此属性仅可在FA模型下使用。 |  
| metaData<sup>(deprecated)</sup> | Array<CustomizeData> | true | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>ability的元信息。<br />通过调用[bundle.getAbilityInfo](js-apis-Bundle.md#bundlegetabilityinfodeprecated)接口时，传入GET_ABILITY_INFO_WITH_METADATA获取 |  
| enabled<sup>(deprecated)</sup> | boolean | true | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>ability是否可用。 |  
