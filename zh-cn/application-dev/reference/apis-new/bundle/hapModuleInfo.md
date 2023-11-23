# hapModuleInfo    
Hap模块信息，未做特殊说明的属性，均通过[bundle.getBundleInfo](js-apis-Bundle.md#bundlegetbundleinfodeprecated)获取。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## HapModuleInfo<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.bundleManager.HapModuleInfo替代。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>模块名称。 |  
| description<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>模块描述信息。 |  
| descriptionId<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>描述信息ID。 |  
| icon<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>模块图标。 |  
| label<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>模块标签。 |  
| labelId<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>模块标签ID。 |  
| iconId<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>模块图标ID。 |  
| backgroundImg<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>模块背景图片。 |  
| supportedModes<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>模块支持的模式。 |  
| reqCapabilities<sup>(deprecated)</sup> | Array<string> | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>模块运行需要的能力。 |  
| deviceTypes<sup>(deprecated)</sup> | Array<string> | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>支持运行的设备类型。 |  
| abilityInfo<sup>(deprecated)</sup> | Array<AbilityInfo> | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability信息。 |  
| moduleName<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>模块名。 |  
| mainAbilityName<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>入口Ability名称。 |  
| installationFree<sup>(deprecated)</sup> | boolean | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>是否支持免安装。 |  
