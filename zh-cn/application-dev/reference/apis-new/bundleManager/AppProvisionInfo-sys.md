# AppProvisionInfo    
应用[HarmonyAppProvision配置文件](../../security/app-provision-structure.md)中的信息，可以通过[getAppProvisionInfo](js-apis-bundleManager.md#bundlemanagergetappprovisioninfo10)获取。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## AppProvisionInfo  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| versionCode | number | true | true | 配置文件的版本号。 |  
| versionName | string | true | true | 配置文件的版本名称。 |  
| uuid | string | true | true | 配置文件中的uuid。 |  
| type | string | true | true | 配置文件的类型，为debug或者release。 |  
| appDistributionType | string | true | true | 配置文件中的分发类型，为app_gallery、enterprise、os_integration和crowdtesting其中之一。 |  
| validity | Validity | true | true | 配置文件中的有效期。 |  
| developerId | string | true | true | 配置文件中的开发者ID。 |  
| certificate | string | true | true | 配置文件中的证书公钥。 |  
| apl | string | true | true | 配置文件中的apl字段，为normal、system_basic和system_core其中之一。 |  
| issuer | string | true | true | 配置文件中的发行者名称。 |  
    
## Validity  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| notBefore | number | true | true | 配置文件的最早有效日期。 |  
| notAfter | number | true | true | 配置文件的最晚有效日期。 |  
