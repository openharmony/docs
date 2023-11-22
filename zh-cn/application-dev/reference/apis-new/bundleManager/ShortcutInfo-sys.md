# ShortcutInfo    
应用配置文件中定义的快捷方式信息，可以通过[getShortcutInfo](js-apis-launcherBundleManager.md#launcherbundlemanagergetshortcutinfo9)获取。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ShortcutInfo  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Launcher    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Launcher    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id | string | true | true | 快捷方式所属应用程序的ID。 |  
| bundleName | string | true | true | 包含快捷方式的Bundle名称。 |  
| moduleName | string | true | true | 快捷方式的模块名。 |  
| hostAbility | string | true | true | 快捷方式的本地Ability名称。 |  
| icon | string | true | true | 快捷方式的图标。 |  
| iconId | number | true | true | 快捷方式的图标ID。 |  
| label | string | true | true | 快捷方式的标签。 |  
| labelId | number | true | true | 快捷方式的标签ID。 |  
| wants | Array<ShortcutWant> | true | true | 快捷方式所需要的信息。 |  
    
## ShortcutWant  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Launcher    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Launcher    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| targetBundle | string | true | true | 快捷方式的目标bundleName。 |  
| targetModule | string | true | true | 快捷方式的目标moduleName。 |  
| targetAbility | string | true | true | 快捷方式所需的目标abilityName。 |  
