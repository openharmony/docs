# RemoteAbilityInfo    
包含远程的ability信息，通过接口[distributedBundle.getRemoteAbilityInfo](js-apis-distributedBundleManager.md#distributedbundlegetremoteabilityinfo)获取。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## RemoteAbilityInfo  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.DistributedBundleFramework    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.DistributedBundleFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| elementName | ElementName | true | true | 指明远程ability的ElementName信息。 |  
| label | string | true | true | 指明远程ability的标签信息。 |  
| icon | string | true | true | 指明的远程ability的图标信息。 |  
