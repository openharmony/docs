# ElementName    
ElementName信息，通过接口[Context.getElementName](js-apis-inner-app-context.md)获取。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ElementName  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId | string | false | false | 设备ID。 |  
| bundleName | string | false | true | 应用Bundle名称。 |  
| moduleName | string | false | false | Ability所属的HAP的模块名称。 |  
| abilityName | string | false | true | Ability名称。 |  
| uri | string | false | false | Ability短名称。<span style="letter-spacing: 0px;">资源标识符。</span> |  
| shortName | string | false | false | Ability短名称。 |  
