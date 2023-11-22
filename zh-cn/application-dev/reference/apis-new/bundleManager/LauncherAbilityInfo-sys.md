# LauncherAbilityInfo    
桌面应用的Ability信息，可以通过[bundleManager.getLauncherAbilityInfo](js-apis-launcherBundleManager.md#launcherbundlemanagergetlauncherabilityinfo9)获取。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## LauncherAbilityInfo  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Launcher    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Launcher    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| applicationInfo | ApplicationInfo | true | true | launcher ability的应用程序的配置信息。 |  
| elementName | ElementName | true | true | launcher ability的ElementName信息。 |  
| labelId | number | true | true | launcher ability的标签ID。 |  
| iconId | number | true | true | launcher ability的图标ID。 |  
| userId | number | true | true | launcher ability的用户ID。 |  
| installTime | number | true | true | launcher ability的安装时间。。 |  
