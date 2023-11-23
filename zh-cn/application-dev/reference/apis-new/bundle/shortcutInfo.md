# shortcutInfo    
应用配置文件中定义的快捷方式信息，FA模型配置在[config.json](../../quick-start/application-configuration-file-overview-fa.md)文件中进行配置，Stage模型在开发视图的resources/base/profile下面定义配置文件即可。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ShortcutInfo<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>快捷方式所属应用程序的Id。 |  
| bundleName<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>包含该快捷方式的Bundle名称。 |  
| hostAbility<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>快捷方式的本地Ability信息。 |  
| icon<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>快捷方式的图标。 |  
| iconId<sup>(deprecated)</sup> | number | true | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>快捷方式的图标Id。 |  
| label<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>快捷方式的名称。 |  
| labelId<sup>(deprecated)</sup> | number | true | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>快捷方式的名称Id。 |  
| disableMessage<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>快捷方式的禁用消息。 |  
| wants<sup>(deprecated)</sup> | Array<ShortcutWant> | true | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>快捷方式意图列表。 |  
| isStatic<sup>(deprecated)</sup> | boolean | true | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>快捷方式是否为静态。 |  
| isHomeShortcut<sup>(deprecated)</sup> | boolean | true | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>快捷方式是否为主页面快捷方式。 |  
| isEnabled<sup>(deprecated)</sup> | boolean | true | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>是否启用快捷方式。 |  
