# shortcutInfo    
应用配置文件中定义的快捷方式信息，FA模型配置在[config.json](../../quick-start/application-configuration-file-overview-fa.md)文件中进行配置，Stage模型在开发视图的resources/base/profile下面定义配置文件即可。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ShortcutWant<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.launcherBundleManager.ShortcutWant替代。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| targetBundle<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>快捷方式的目标捆绑包。 |  
| targetClass<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>快捷方式所需的目标类 |  
