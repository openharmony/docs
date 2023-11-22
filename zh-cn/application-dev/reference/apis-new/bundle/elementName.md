# elementName    
ElementName信息，通过接口[Context.getElementName](js-apis-inner-app-context.md)获取。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ElementName<sup>(deprecated)</sup>    
ElementName信息，标识Ability的基本信息，通过接口[Context.getElementName](js-apis-inner-app-context.md)获取。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.bundleManager.ElementName替代。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>设备id值。 |  
| bundleName<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用Bundle的名称。 |  
| abilityName<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability的名称。 |  
| uri<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>资源标识符。 |  
| shortName<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>Ability的短名称。 |  
